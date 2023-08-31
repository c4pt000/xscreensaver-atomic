/* ffmpeg-out, Copyright © 2023 Jamie Zawinski <jwz@jwz.org>
 *
 * Permission to use, copy, modify, distribute, and sell this software and its
 * documentation for any purpose is hereby granted without fee, provided that
 * the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation.  No representations are made about the suitability of this
 * software for any purpose.  It is provided "as is" without express or 
 * implied warranty.
 *
 * Writing a sequence of XImages to an output MP4 file.
 * Created: 28 Apr 2023 by dmo2118@gmail.com
 */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#ifndef HAVE_FFMPEG
# error HAVE_FFMPEG is required
#endif

#include <stdio.h>
#include <stdlib.h>

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>

#include "screenhackI.h"
#include "ffmpeg-out.h"

#if (__GNUC__ >= 4)	/* Ignore useless warnings generated by ffmpeg */
# pragma GCC diagnostic ignored "-Wpragmas"
# pragma GCC diagnostic ignored "-Wc99-extensions"
# pragma GCC diagnostic ignored "-Wlong-long"
  /* No "diagnostic pop" because some macrose use c99 features. */
#endif

#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
#include <libswresample/swresample.h>

struct av_stream {
  AVCodec *codec;
  AVStream *st;
  AVCodecContext *ctx;
  AVFrame *frame;
};

struct ffmpeg_out_state {
  const char *outfile;
  const char *audiofile;
  struct av_stream video_ost;
  struct av_stream audio_ost;
  struct av_stream audio_ist;
  struct SwsContext *sws_ctx;
  AVFormatContext *audio_fmt_ctx;
  AVPacket *audio_pkt;
  struct SwrContext *swr_ctx;
  AVFormatContext *oc;
  int frames_written;
  uint64_t samples_written; /* At 48 kHz, 2**31 samples is only 12.4 hours. */
};


static void
av_fail (int averror)
{
  fprintf (stderr, "%s: %s\n", progname, av_err2str (averror));
  exit (1);
}


static int
av_check (int averror)
{
  if (averror < 0)
    av_fail (averror);
  return averror;
}


static void
flush_packets (AVFormatContext *oc, struct av_stream *ost)
{
  while (1)
    {
      AVPacket pkt = {0};

      int ret = avcodec_receive_packet (ost->ctx, &pkt);
      if (ret == AVERROR(EAGAIN) || ret == AVERROR_EOF)
        return;
      av_check (ret);

      av_packet_rescale_ts (&pkt, ost->ctx->time_base, ost->st->time_base);
      pkt.stream_index = ost->st->index;

      av_check (av_interleaved_write_frame (oc, &pkt));
    }
}


static void
write_frame (AVFormatContext *oc, struct av_stream *ost)
{
  av_check (avcodec_send_frame (ost->ctx, ost->frame));
  flush_packets (oc, ost);
}


static uint64_t
guess_channel_layout (int channels)
{
  return (channels <= 1 ? AV_CH_LAYOUT_MONO : AV_CH_LAYOUT_STEREO);
}


static void
get_audio_frame (AVFormatContext *audio_fmt_ctx,
                 struct av_stream *audio_ist, AVPacket *audio_pkt,
                 struct SwrContext *swr_ctx,
                 struct av_stream *audio_ost)
{
  int ret;
  for (;;)
    {
      if (swr_is_initialized (swr_ctx) &&
          swr_get_delay (swr_ctx, audio_ost->ctx->sample_rate) >
          audio_ost->frame->nb_samples)
        {
          av_check (swr_convert_frame (swr_ctx, audio_ost->frame, NULL));
          break;
        }
      else
        {
          ret = avcodec_receive_frame (audio_ist->ctx, audio_ist->frame);

          if (ret >= 0)
            {
              if (!audio_ist->frame->channel_layout)
                {
                  audio_ist->frame->channel_layout =
                    guess_channel_layout (audio_ist->frame->channels);
                }

              if (!swr_is_initialized (swr_ctx))
                {
                  av_check (swr_config_frame (swr_ctx, audio_ost->frame,
                                              audio_ist->frame));
                  av_check (swr_init (swr_ctx));
                }

              av_check (swr_convert_frame (swr_ctx, NULL, audio_ist->frame));

              av_frame_unref (audio_ist->frame);
            }
          else if (ret == AVERROR_EOF || ret == AVERROR(EAGAIN))
            {
              av_frame_unref (audio_ist->frame);

              for (;;)
                {
                  av_packet_unref (audio_pkt);

                  /* This reads a packet, which can be many frames. */
                  ret = av_read_frame (audio_fmt_ctx, audio_pkt);
                  if (ret < 0)
                    {
                      unsigned long nb_samples = audio_ost->frame->nb_samples;
                      av_check (swr_convert_frame (swr_ctx, audio_ost->frame,
                                                   NULL));
                      av_samples_set_silence (audio_ost->frame->data,
                                              audio_ost->frame->nb_samples,
                                              nb_samples -
                                              audio_ost->frame->nb_samples,
                                              audio_ost->frame->channels,
                                              audio_ost->frame->format);
                      audio_ost->frame->nb_samples = nb_samples;
                      return;
                    }

                  if (audio_pkt->stream_index == audio_ist->st->index)
                    break;
                }

              av_check (avcodec_send_packet (audio_ist->ctx, audio_pkt));
            }
          else
            {
              av_fail (ret);
            }
        }
    }
}


static void
add_stream (struct av_stream *ost, AVFormatContext *oc,
            enum AVCodecID codec_id)
{
  ost->codec = avcodec_find_encoder (codec_id);
  if (!ost->codec)
    {
      fprintf (stderr, "%s: could not find encoder for '%s'\n", progname,
               avcodec_get_name (codec_id));
      exit (1);
    }

  ost->st = avformat_new_stream (oc, ost->codec);
  if (!ost->st)
    {
      fprintf (stderr, "%s: could not allocate stream\n", progname);
      exit (1);
    }
  ost->st->id = oc->nb_streams - 1;

  ost->ctx = avcodec_alloc_context3(ost->codec);
  if (!ost->ctx)
    {
      fprintf (stderr, "%s: could not alloc an encoding context\n", progname);
      exit (1);
    }

  if(oc->oformat->flags & AVFMT_GLOBALHEADER)
    ost->ctx->flags |= AV_CODEC_FLAG_GLOBAL_HEADER;
}


/* Assumes ownership of opt. */
static void
open_stream (struct av_stream *ost, AVDictionary *opt)
{
  av_check (avcodec_open2 (ost->ctx, ost->codec, &opt));
  av_dict_free (&opt);

  ost->frame = av_frame_alloc();
  if (!ost->frame)
    {
      fprintf (stderr, "%s: could not allocate frame\n", progname);
      exit (1);
    }

  av_check (avcodec_parameters_from_context(ost->st->codecpar, ost->ctx));
}


static void
close_stream (struct av_stream *ost)
{
  avcodec_free_context (&ost->ctx);
  av_frame_free (&ost->frame);
}


ffmpeg_out_state *
ffmpeg_out_init (const char *outfile, const char *audiofile,
                 int output_width, int output_height, int bpp,
                 Bool fast_p)
{
  ffmpeg_out_state *ffst = (ffmpeg_out_state *) calloc (1, sizeof(*ffst));

  const enum AVCodecID video_codec = AV_CODEC_ID_H264;
  const enum AVCodecID audio_codec = AV_CODEC_ID_AAC;
  const enum AVPixelFormat pix_fmt = AV_PIX_FMT_YUV420P;
  const unsigned framerate = 30;
  int audio_bitrate = 96000;
  const char *video_preset = (fast_p ? "ultrafast" : "veryslow");
  const char *video_crf =    (fast_p ? "24" : "18");

  ffst->outfile   = strdup (outfile);
  ffst->audiofile = audiofile ? strdup (audiofile) : NULL;

  av_check (avformat_alloc_output_context2 (&ffst->oc, NULL, "mp4", outfile));

  add_stream (&ffst->video_ost, ffst->oc, video_codec);

  ffst->video_ost.ctx->codec_id     = video_codec;
  ffst->video_ost.ctx->width        = output_width;
  ffst->video_ost.ctx->height       = output_height;
  ffst->video_ost.st->time_base.num = 1;
  ffst->video_ost.st->time_base.den = framerate;
  ffst->video_ost.ctx->time_base    = ffst->video_ost.st->time_base;
  ffst->video_ost.ctx->gop_size     = 250;
  ffst->video_ost.ctx->pix_fmt      = pix_fmt;
  ffst->video_ost.ctx->profile      = FF_PROFILE_H264_HIGH;

  av_log_set_level (AV_LOG_ERROR);  /* Before open_stream */

  if (audiofile)
    {
      int audio_stream_idx;
      av_check (avformat_open_input (&ffst->audio_fmt_ctx, audiofile,
                                     NULL, NULL));
      av_check (avformat_find_stream_info (ffst->audio_fmt_ctx, NULL));
      audio_stream_idx = av_check (av_find_best_stream (ffst->audio_fmt_ctx,
                                                        AVMEDIA_TYPE_AUDIO,
                                                        -1, -1, NULL, 0));
      ffst->audio_ist.st = ffst->audio_fmt_ctx->streams[audio_stream_idx];

      ffst->audio_ist.codec =
        avcodec_find_decoder (ffst->audio_ist.st->codecpar->codec_id);
      if (! ffst->audio_ist.codec)
        {
          fprintf (stderr, "%s: failed to find audio codec\n", progname);
          exit (1);
        }

      ffst->audio_ist.ctx = avcodec_alloc_context3 (ffst->audio_ist.codec);
      if (! ffst->audio_ist.ctx)
        {
          fprintf (stderr, "%s: failed to allocate the audio codec context\n",
                   progname);
          exit (1);
        }

      av_check (avcodec_parameters_to_context (ffst->audio_ist.ctx,
                                               ffst->audio_ist.st->codecpar));

      /* Makes "Could not update timestamps for skipped samples." go away.
         Apparently not otherwise needed.
         Not mentioned in the example code. :)
      */
      ffst->audio_ist.ctx->pkt_timebase = ffst->audio_ist.st->time_base;

      av_check (avcodec_open2 (ffst->audio_ist.ctx, ffst->audio_ist.codec,
                               NULL));

      add_stream (&ffst->audio_ost, ffst->oc, audio_codec);
      ffst->audio_ost.ctx->sample_fmt =
        (ffst->audio_ost.codec->sample_fmts
         ? ffst->audio_ost.codec->sample_fmts[0]
         : AV_SAMPLE_FMT_FLTP);
      ffst->audio_ost.ctx->bit_rate = audio_bitrate;

      if (! ffst->audio_ost.codec->supported_samplerates)
        {
          ffst->audio_ost.ctx->sample_rate = ffst->audio_ist.ctx->sample_rate;
        }
      else
        {
          const int *r = ffst->audio_ost.codec->supported_samplerates;
          int best = *r;
          ++r;

          while (*r)
            {
              if ((*r >= ffst->audio_ist.ctx->sample_rate)
                  ? *r < best
                  : *r > best)
                best = *r;
              ++r;
            }
          ffst->audio_ost.ctx->sample_rate = best;
        }

      if (! ffst->audio_ost.codec->channel_layouts)
        {
          if (! ffst->audio_ist.ctx->channel_layout)
            {
              ffst->audio_ost.ctx->channel_layout =
                guess_channel_layout (ffst->audio_ost.ctx->channels);
            }
          else
            {
              ffst->audio_ost.ctx->channel_layout =
                ffst->audio_ist.ctx->channel_layout;
            }
        }
      else
        {
          /* XXX: This may or may not work. With AAC, it doesn't matter. */
          const uint64_t *c = ffst->audio_ost.codec->channel_layouts;
          unsigned int best_lost =
            av_popcount64 (ffst->audio_ost.ctx->channel_layout);
          unsigned int best_added = 0;
          uint64_t best = 0;
          while (*c)
            {
              if (*c == ffst->audio_ist.ctx->channel_layout)
                {
                  unsigned int lost =
                    av_popcount64 (ffst->audio_ist.ctx->channel_layout & ~*c);
                  unsigned int added =
                    av_popcount64 (*c & ~ffst->audio_ist.ctx->channel_layout);
                  if (lost < best_lost ||
                      (lost == best_lost &&
                       added < best_added)) {
                    best = *c;
                    best_lost = lost;
                    best_added = added;
                  }
                }
              ++c;
            }

          ffst->audio_ost.ctx->channel_layout = best;
        }

      ffst->audio_ost.ctx->channels =
        av_get_channel_layout_nb_channels (ffst->audio_ost.ctx->channel_layout);
      ffst->audio_ost.st->time_base.num = 1;
      ffst->audio_ost.st->time_base.den = ffst->audio_ost.ctx->sample_rate;

      ffst->audio_ist.frame = av_frame_alloc();
      if (! ffst->audio_ist.frame)
        {
          fprintf (stderr, "%s: could not allocate frame\n", progname);
          exit (1);
        }

      ffst->audio_pkt = av_packet_alloc();
      if (! ffst->audio_pkt)
        {
          fprintf (stderr, "%s: could not allocate packet\n", progname);
          exit (1);
        }
    }

  {
    AVDictionary *opt = NULL;
    av_check (av_dict_set (&opt, "preset", video_preset, 0));
    av_check (av_dict_set (&opt, "crf", video_crf, 0));
    open_stream (&ffst->video_ost, opt);

    ffst->video_ost.frame->format = ffst->video_ost.ctx->pix_fmt;
    ffst->video_ost.frame->width  = ffst->video_ost.ctx->width;
    ffst->video_ost.frame->height = ffst->video_ost.ctx->height;
    av_check (av_frame_get_buffer (ffst->video_ost.frame, 0));
  }

  if (audiofile)
    {
      open_stream (&ffst->audio_ost, NULL);

      ffst->audio_ost.frame->format = ffst->audio_ost.ctx->sample_fmt;
      ffst->audio_ost.frame->channel_layout =
        ffst->audio_ost.ctx->channel_layout;
      ffst->audio_ost.frame->sample_rate = ffst->audio_ost.ctx->sample_rate;
      ffst->audio_ost.frame->nb_samples =
        (ffst->audio_ost.ctx->codec->capabilities &
         AV_CODEC_CAP_VARIABLE_FRAME_SIZE
         ? ((av_rescale (ffst->audio_ist.ctx->frame_size,
                         ffst->audio_ost.ctx->sample_rate,
                         ffst->audio_ist.ctx->sample_rate) + 15)
            & ~(int64_t) 15)
         : ffst->audio_ost.ctx->frame_size);

      av_check (av_frame_get_buffer (ffst->audio_ost.frame, 0));

      ffst->swr_ctx = swr_alloc();
      if (! ffst->swr_ctx)
        {
          fprintf (stderr, "%s: could not allocate resampler context\n",
                   progname);
          exit (1);
        }
    }

  /* assert (!(ffst->oc->oformat->flags & AVFMT_NOFILE)); */
  av_check (avio_open (&ffst->oc->pb, outfile, AVIO_FLAG_WRITE));

  {
    AVDictionary *no_opt = NULL;
    av_check (avformat_write_header (ffst->oc, &no_opt));
  }

  if (bpp != 3 && bpp != 4) abort();
  ffst->sws_ctx = sws_getContext (output_width, output_height,
                                  (bpp == 4
                                   ? AV_PIX_FMT_BGR32
                                   : AV_PIX_FMT_BGR24),
                                  ffst->video_ost.ctx->width,
                                  ffst->video_ost.ctx->height,
                                  ffst->video_ost.ctx->pix_fmt,
                                  SWS_BICUBIC, NULL, NULL, NULL);

# if LIBAVFORMAT_VERSION_MAJOR < 58
  av_register_all();
# endif

  return ffst;
}


void
ffmpeg_out_add_frame (ffmpeg_out_state *ffst, XImage *img)
{
  const uint8_t *img_data = (const uint8_t *) img->data;

  if (ffst->audiofile)
    {
      while (av_compare_ts (ffst->frames_written, 
                            ffst->video_ost.ctx->time_base,
                            ffst->samples_written,
                            ffst->audio_ost.ctx->time_base) > 0)
        {
          av_check (av_frame_make_writable (ffst->audio_ost.frame));
          get_audio_frame (ffst->audio_fmt_ctx, &ffst->audio_ist,
                           ffst->audio_pkt, ffst->swr_ctx, &ffst->audio_ost);
          ffst->audio_ost.frame->pts = ffst->samples_written;
          ffst->samples_written += ffst->audio_ost.frame->nb_samples;

          write_frame (ffst->oc, &ffst->audio_ost);
        }
    }

  av_check (av_frame_make_writable (ffst->video_ost.frame));

  sws_scale (ffst->sws_ctx, &img_data, &img->bytes_per_line, 0,
             ffst->video_ost.frame->height,
             ffst->video_ost.frame->data,
             ffst->video_ost.frame->linesize);
  ffst->video_ost.frame->pts = ffst->frames_written;

  write_frame (ffst->oc, &ffst->video_ost);

  ffst->frames_written++;
}


void
ffmpeg_out_close (ffmpeg_out_state *ffst)
{
  av_check (avcodec_send_frame (ffst->video_ost.ctx, NULL));
  flush_packets (ffst->oc, &ffst->video_ost);

  if (ffst->audiofile) {
    av_check (avcodec_send_frame (ffst->audio_ost.ctx, NULL));
    flush_packets (ffst->oc, &ffst->audio_ost);
  }

  av_check (av_write_trailer (ffst->oc));

  close_stream (&ffst->video_ost);
  /* Not present in 1.1.100 */
  /* sws_freeContext (ffst->sws_ctx); */
  if (ffst->audiofile)
    {
      close_stream (&ffst->audio_ost);
      swr_free (&ffst->swr_ctx);

      close_stream (&ffst->audio_ist);
      avformat_close_input (&ffst->audio_fmt_ctx);
      av_packet_free(&ffst->audio_pkt);
    }

  avio_closep (&ffst->oc->pb);
  avformat_free_context (ffst->oc);
}

