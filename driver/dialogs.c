
/*
** Generated by X-Designer 
*/
/*
**LIBS: -lXm -lXt -lX11
*/

#if !__STDC__
# define _NO_PROTO
#endif

#include <X11/Xatom.h>
#include <X11/Intrinsic.h>
#include <X11/Shell.h>

#include <Xm/Xm.h>
#include <Xm/DialogS.h>
#include <Xm/DrawnB.h>
#include <Xm/Form.h>
#include <Xm/Label.h>
#include <Xm/List.h>
#include <Xm/PushB.h>
#include <Xm/ScrollBar.h>
#include <Xm/Separator.h>
#include <Xm/TextF.h>
#include <Xm/ToggleB.h>


Widget passwd_dialog;
Widget passwd_form;
Widget roger_label;
Widget passwd_label1;
Widget passwd_label3;
Widget passwd_text;
Widget passwd_done;
Widget passwd_cancel;

Widget resources_dialog;
Widget resources_form;
Widget timeout_text;
Widget cycle_text;
Widget fade_text;
Widget ticks_text;
Widget lock_time_text;
Widget passwd_time_text;
Widget verbose_toggle;
Widget cmap_toggle;
Widget fade_toggle;
Widget unfade_toggle;
Widget lock_toggle;
Widget res_done;
Widget res_cancel;

Widget demo_dialog;
Widget demo_form;
Widget label1;
Widget label2;
Widget text_area;
Widget demo_list;
Widget text_line;
Widget vline;
Widget next;
Widget prev;
Widget edit;
Widget done;
Widget restart;
Widget spacer;


create_passwd_dialog( parent )
Widget parent;
{
	Display *display = XtDisplay ( parent );
	Widget children[8];      /* Children to manage */
	Arg al[64];           /* Arg List */
	register int ac = 0;      /* Arg Count */
	char from_s [256];    /* For font list conversion */
	XrmValue from_value, to_value; /* ditto */
	int fg, bg;           /* colour values for pixmaps */ 
	XmString *list_items; /* For list items */
	int list_item;        /* Index for list_items */
	XmString xmstrings[15];    /* temporary storage for XmStrings */
	Widget widget4;
	Widget widget7;

	passwd_dialog = XmCreateDialogShell ( parent, "passwdDialog", al, ac );
	passwd_form = XmCreateForm ( passwd_dialog, "passwdForm", al, ac );
	roger_label = XmCreateDrawnButton ( passwd_form, "rogerLabel", al, ac );
	passwd_label1 = XmCreateLabel ( passwd_form, "passwdLabel1", al, ac );
	widget4 = XmCreateLabel ( passwd_form, "passwdLabel2", al, ac );
	passwd_label3 = XmCreateLabel ( passwd_form, "passwdLabel3", al, ac );
	passwd_text = XmCreateTextField ( passwd_form, "passwdText", al, ac );
	widget7 = XmCreateSeparator ( passwd_form, "widget7", al, ac );
	passwd_done = XmCreatePushButton ( passwd_form, "passwdDone", al, ac );
	passwd_cancel = XmCreatePushButton ( passwd_form, "passwdCancel", al, ac );

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNtopOffset, 4); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNbottomOffset, 4); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNleftOffset, 4); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_NONE); ac++;
        XtSetValues ( roger_label,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNtopOffset, 4); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_WIDGET); ac++;
	XtSetArg(al[ac], XmNbottomOffset, 4); ac++;
	XtSetArg(al[ac], XmNbottomWidget, widget4); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_WIDGET); ac++;
	XtSetArg(al[ac], XmNleftOffset, 4); ac++;
	XtSetArg(al[ac], XmNleftWidget, roger_label); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNrightOffset, 4); ac++;
        XtSetValues ( passwd_label1,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_NONE); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_WIDGET); ac++;
	XtSetArg(al[ac], XmNbottomOffset, 4); ac++;
	XtSetArg(al[ac], XmNbottomWidget, passwd_label3); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_WIDGET); ac++;
	XtSetArg(al[ac], XmNleftOffset, 4); ac++;
	XtSetArg(al[ac], XmNleftWidget, roger_label); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNrightOffset, 4); ac++;
        XtSetValues ( widget4,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_NONE); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_WIDGET); ac++;
	XtSetArg(al[ac], XmNbottomOffset, 4); ac++;
	XtSetArg(al[ac], XmNbottomWidget, passwd_text); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_WIDGET); ac++;
	XtSetArg(al[ac], XmNleftOffset, 4); ac++;
	XtSetArg(al[ac], XmNleftWidget, roger_label); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNrightOffset, 30); ac++;
        XtSetValues ( passwd_label3,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_NONE); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_WIDGET); ac++;
	XtSetArg(al[ac], XmNbottomOffset, 4); ac++;
	XtSetArg(al[ac], XmNbottomWidget, widget7); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_WIDGET); ac++;
	XtSetArg(al[ac], XmNleftOffset, 4); ac++;
	XtSetArg(al[ac], XmNleftWidget, roger_label); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNrightOffset, 4); ac++;
        XtSetValues ( passwd_text,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_NONE); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_WIDGET); ac++;
	XtSetArg(al[ac], XmNbottomOffset, 4); ac++;
	XtSetArg(al[ac], XmNbottomWidget, passwd_done); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_WIDGET); ac++;
	XtSetArg(al[ac], XmNleftOffset, 0); ac++;
	XtSetArg(al[ac], XmNleftWidget, roger_label); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNrightOffset, 0); ac++;
        XtSetValues ( widget7,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_NONE); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNbottomOffset, 4); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_WIDGET); ac++;
	XtSetArg(al[ac], XmNleftOffset, 4); ac++;
	XtSetArg(al[ac], XmNleftWidget, roger_label); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_NONE); ac++;
        XtSetValues ( passwd_done,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_NONE); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNbottomOffset, 4); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_WIDGET); ac++;
	XtSetArg(al[ac], XmNleftOffset, 4); ac++;
	XtSetArg(al[ac], XmNleftWidget, passwd_done); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_NONE); ac++;
        XtSetValues ( passwd_cancel,al, ac );
	ac = 0;
	children[ac++] = roger_label;
	children[ac++] = passwd_label1;
	children[ac++] = widget4;
	children[ac++] = passwd_label3;
	children[ac++] = passwd_text;
	children[ac++] = widget7;
	children[ac++] = passwd_done;
	children[ac++] = passwd_cancel;
	XtManageChildren(children, ac);
	ac = 0;
}



create_resources_dialog( parent )
Widget parent;
{
	Display *display = XtDisplay ( parent );
	Widget children[22];      /* Children to manage */
	Arg al[64];           /* Arg List */
	register int ac = 0;      /* Arg Count */
	char from_s [256];    /* For font list conversion */
	XrmValue from_value, to_value; /* ditto */
	int fg, bg;           /* colour values for pixmaps */ 
	XmString *list_items; /* For list items */
	int list_item;        /* Index for list_items */
	XmString xmstrings[15];    /* temporary storage for XmStrings */
	Widget widget12;
	Widget widget13;
	Widget widget14;
	Widget widget15;
	Widget widget16;
	Widget widget17;
	Widget widget18;
	Widget widget48;
	Widget widget29;

	resources_dialog = XmCreateDialogShell ( parent, "resourcesDialog", al, ac );
	resources_form = XmCreateForm ( resources_dialog, "resourcesForm", al, ac );
	widget12 = XmCreateLabel ( resources_form, "resourcesLabel", al, ac );
	widget13 = XmCreateSeparator ( resources_form, "widget13", al, ac );
	XtSetArg(al[ac], XmNalignment, XmALIGNMENT_END); ac++;
	widget14 = XmCreateLabel ( resources_form, "timeoutLabel", al, ac );
	ac = 0;
	XtSetArg(al[ac], XmNalignment, XmALIGNMENT_END); ac++;
	widget15 = XmCreateLabel ( resources_form, "cycleLabel", al, ac );
	ac = 0;
	XtSetArg(al[ac], XmNalignment, XmALIGNMENT_END); ac++;
	widget16 = XmCreateLabel ( resources_form, "fadeSecondsLabel", al, ac );
	ac = 0;
	XtSetArg(al[ac], XmNalignment, XmALIGNMENT_END); ac++;
	widget17 = XmCreateLabel ( resources_form, "fadeTicksLabel", al, ac );
	ac = 0;
	XtSetArg(al[ac], XmNalignment, XmALIGNMENT_END); ac++;
	widget18 = XmCreateLabel ( resources_form, "lockLabel", al, ac );
	ac = 0;
	XtSetArg(al[ac], XmNalignment, XmALIGNMENT_END); ac++;
	widget48 = XmCreateLabel ( resources_form, "passwdLabel", al, ac );
	ac = 0;
	timeout_text = XmCreateTextField ( resources_form, "timeoutText", al, ac );
	cycle_text = XmCreateTextField ( resources_form, "cycleText", al, ac );
	fade_text = XmCreateTextField ( resources_form, "fadeSecondsText", al, ac );
	ticks_text = XmCreateTextField ( resources_form, "fadeTicksText", al, ac );
	lock_time_text = XmCreateTextField ( resources_form, "passwdText", al, ac );
	passwd_time_text = XmCreateTextField ( resources_form, "lockText", al, ac );
	XtSetArg(al[ac], XmNalignment, XmALIGNMENT_BEGINNING); ac++;
	verbose_toggle = XmCreateToggleButton ( resources_form, "verboseToggle", al, ac );
	ac = 0;
	XtSetArg(al[ac], XmNalignment, XmALIGNMENT_BEGINNING); ac++;
	cmap_toggle = XmCreateToggleButton ( resources_form, "cmapToggle", al, ac );
	ac = 0;
	XtSetArg(al[ac], XmNalignment, XmALIGNMENT_BEGINNING); ac++;
	fade_toggle = XmCreateToggleButton ( resources_form, "fadeToggle", al, ac );
	ac = 0;
	XtSetArg(al[ac], XmNalignment, XmALIGNMENT_BEGINNING); ac++;
	unfade_toggle = XmCreateToggleButton ( resources_form, "unfadeToggle", al, ac );
	ac = 0;
	XtSetArg(al[ac], XmNalignment, XmALIGNMENT_BEGINNING); ac++;
	lock_toggle = XmCreateToggleButton ( resources_form, "lockToggle", al, ac );
	ac = 0;
	widget29 = XmCreateSeparator ( resources_form, "widget29", al, ac );
	res_done = XmCreatePushButton ( resources_form, "resourcesDone", al, ac );
	res_cancel = XmCreatePushButton ( resources_form, "resourcesCancel", al, ac );

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNtopOffset, 4); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNleftOffset, 4); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNrightOffset, 4); ac++;
        XtSetValues ( widget12,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_WIDGET); ac++;
	XtSetArg(al[ac], XmNtopOffset, 4); ac++;
	XtSetArg(al[ac], XmNtopWidget, widget12); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_NONE); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNleftOffset, 0); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNrightOffset, 0); ac++;
        XtSetValues ( widget13,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_WIDGET); ac++;
	XtSetArg(al[ac], XmNtopOffset, 4); ac++;
	XtSetArg(al[ac], XmNtopWidget, widget13); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_OPPOSITE_WIDGET); ac++;
	XtSetArg(al[ac], XmNbottomWidget, timeout_text); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNleftOffset, 20); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_WIDGET); ac++;
	XtSetArg(al[ac], XmNrightOffset, 4); ac++;
	XtSetArg(al[ac], XmNrightWidget, timeout_text); ac++;
        XtSetValues ( widget14,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_OPPOSITE_WIDGET); ac++;
	XtSetArg(al[ac], XmNtopOffset, 0); ac++;
	XtSetArg(al[ac], XmNtopWidget, cycle_text); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_OPPOSITE_WIDGET); ac++;
	XtSetArg(al[ac], XmNbottomOffset, 0); ac++;
	XtSetArg(al[ac], XmNbottomWidget, cycle_text); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNleftOffset, 20); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_WIDGET); ac++;
	XtSetArg(al[ac], XmNrightOffset, 4); ac++;
	XtSetArg(al[ac], XmNrightWidget, cycle_text); ac++;
        XtSetValues ( widget15,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_OPPOSITE_WIDGET); ac++;
	XtSetArg(al[ac], XmNtopOffset, 0); ac++;
	XtSetArg(al[ac], XmNtopWidget, fade_text); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_OPPOSITE_WIDGET); ac++;
	XtSetArg(al[ac], XmNbottomOffset, 0); ac++;
	XtSetArg(al[ac], XmNbottomWidget, fade_text); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNleftOffset, 20); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_WIDGET); ac++;
	XtSetArg(al[ac], XmNrightOffset, 4); ac++;
	XtSetArg(al[ac], XmNrightWidget, fade_text); ac++;
        XtSetValues ( widget16,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_OPPOSITE_WIDGET); ac++;
	XtSetArg(al[ac], XmNtopOffset, 0); ac++;
	XtSetArg(al[ac], XmNtopWidget, ticks_text); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_OPPOSITE_WIDGET); ac++;
	XtSetArg(al[ac], XmNbottomOffset, 0); ac++;
	XtSetArg(al[ac], XmNbottomWidget, ticks_text); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNleftOffset, 20); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_WIDGET); ac++;
	XtSetArg(al[ac], XmNrightOffset, 4); ac++;
	XtSetArg(al[ac], XmNrightWidget, ticks_text); ac++;
        XtSetValues ( widget17,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_OPPOSITE_WIDGET); ac++;
	XtSetArg(al[ac], XmNtopOffset, 0); ac++;
	XtSetArg(al[ac], XmNtopWidget, lock_time_text); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_OPPOSITE_WIDGET); ac++;
	XtSetArg(al[ac], XmNbottomOffset, 0); ac++;
	XtSetArg(al[ac], XmNbottomWidget, lock_time_text); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNleftOffset, 19); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_WIDGET); ac++;
	XtSetArg(al[ac], XmNrightOffset, 4); ac++;
	XtSetArg(al[ac], XmNrightWidget, lock_time_text); ac++;
        XtSetValues ( widget18,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_OPPOSITE_WIDGET); ac++;
	XtSetArg(al[ac], XmNtopOffset, 0); ac++;
	XtSetArg(al[ac], XmNtopWidget, passwd_time_text); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_OPPOSITE_WIDGET); ac++;
	XtSetArg(al[ac], XmNbottomOffset, 0); ac++;
	XtSetArg(al[ac], XmNbottomWidget, passwd_time_text); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNleftOffset, 14); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_WIDGET); ac++;
	XtSetArg(al[ac], XmNrightOffset, 4); ac++;
	XtSetArg(al[ac], XmNrightWidget, passwd_time_text); ac++;
        XtSetValues ( widget48,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_WIDGET); ac++;
	XtSetArg(al[ac], XmNtopOffset, 4); ac++;
	XtSetArg(al[ac], XmNtopWidget, widget13); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_NONE); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNleftOffset, 141); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_NONE); ac++;
        XtSetValues ( timeout_text,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_WIDGET); ac++;
	XtSetArg(al[ac], XmNtopOffset, 2); ac++;
	XtSetArg(al[ac], XmNtopWidget, timeout_text); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_NONE); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_OPPOSITE_WIDGET); ac++;
	XtSetArg(al[ac], XmNleftOffset, 0); ac++;
	XtSetArg(al[ac], XmNleftWidget, timeout_text); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_NONE); ac++;
        XtSetValues ( cycle_text,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_WIDGET); ac++;
	XtSetArg(al[ac], XmNtopOffset, 2); ac++;
	XtSetArg(al[ac], XmNtopWidget, cycle_text); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_NONE); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_OPPOSITE_WIDGET); ac++;
	XtSetArg(al[ac], XmNleftOffset, 0); ac++;
	XtSetArg(al[ac], XmNleftWidget, cycle_text); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_NONE); ac++;
        XtSetValues ( fade_text,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_WIDGET); ac++;
	XtSetArg(al[ac], XmNtopOffset, 2); ac++;
	XtSetArg(al[ac], XmNtopWidget, fade_text); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_NONE); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_OPPOSITE_WIDGET); ac++;
	XtSetArg(al[ac], XmNleftOffset, 0); ac++;
	XtSetArg(al[ac], XmNleftWidget, fade_text); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_NONE); ac++;
        XtSetValues ( ticks_text,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_WIDGET); ac++;
	XtSetArg(al[ac], XmNtopOffset, 2); ac++;
	XtSetArg(al[ac], XmNtopWidget, ticks_text); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_NONE); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_OPPOSITE_WIDGET); ac++;
	XtSetArg(al[ac], XmNleftOffset, 0); ac++;
	XtSetArg(al[ac], XmNleftWidget, ticks_text); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_NONE); ac++;
        XtSetValues ( lock_time_text,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_WIDGET); ac++;
	XtSetArg(al[ac], XmNtopOffset, 4); ac++;
	XtSetArg(al[ac], XmNtopWidget, lock_time_text); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_NONE); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_OPPOSITE_WIDGET); ac++;
	XtSetArg(al[ac], XmNleftOffset, 0); ac++;
	XtSetArg(al[ac], XmNleftWidget, lock_time_text); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_NONE); ac++;
        XtSetValues ( passwd_time_text,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_WIDGET); ac++;
	XtSetArg(al[ac], XmNtopOffset, 4); ac++;
	XtSetArg(al[ac], XmNtopWidget, widget13); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_OPPOSITE_WIDGET); ac++;
	XtSetArg(al[ac], XmNbottomOffset, 0); ac++;
	XtSetArg(al[ac], XmNbottomWidget, timeout_text); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_WIDGET); ac++;
	XtSetArg(al[ac], XmNleftOffset, 20); ac++;
	XtSetArg(al[ac], XmNleftWidget, timeout_text); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNrightOffset, 20); ac++;
        XtSetValues ( verbose_toggle,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_OPPOSITE_WIDGET); ac++;
	XtSetArg(al[ac], XmNtopOffset, 0); ac++;
	XtSetArg(al[ac], XmNtopWidget, cycle_text); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_OPPOSITE_WIDGET); ac++;
	XtSetArg(al[ac], XmNbottomOffset, 0); ac++;
	XtSetArg(al[ac], XmNbottomWidget, cycle_text); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_OPPOSITE_WIDGET); ac++;
	XtSetArg(al[ac], XmNleftOffset, 0); ac++;
	XtSetArg(al[ac], XmNleftWidget, verbose_toggle); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNrightOffset, 20); ac++;
        XtSetValues ( cmap_toggle,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_OPPOSITE_WIDGET); ac++;
	XtSetArg(al[ac], XmNtopOffset, 0); ac++;
	XtSetArg(al[ac], XmNtopWidget, fade_text); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_OPPOSITE_WIDGET); ac++;
	XtSetArg(al[ac], XmNbottomOffset, 0); ac++;
	XtSetArg(al[ac], XmNbottomWidget, fade_text); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_OPPOSITE_WIDGET); ac++;
	XtSetArg(al[ac], XmNleftOffset, 0); ac++;
	XtSetArg(al[ac], XmNleftWidget, cmap_toggle); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNrightOffset, 20); ac++;
        XtSetValues ( fade_toggle,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_OPPOSITE_WIDGET); ac++;
	XtSetArg(al[ac], XmNtopOffset, 0); ac++;
	XtSetArg(al[ac], XmNtopWidget, ticks_text); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_OPPOSITE_WIDGET); ac++;
	XtSetArg(al[ac], XmNbottomOffset, 0); ac++;
	XtSetArg(al[ac], XmNbottomWidget, ticks_text); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_OPPOSITE_WIDGET); ac++;
	XtSetArg(al[ac], XmNleftOffset, 0); ac++;
	XtSetArg(al[ac], XmNleftWidget, fade_toggle); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNrightOffset, 20); ac++;
        XtSetValues ( unfade_toggle,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_OPPOSITE_WIDGET); ac++;
	XtSetArg(al[ac], XmNtopOffset, 0); ac++;
	XtSetArg(al[ac], XmNtopWidget, lock_time_text); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_OPPOSITE_WIDGET); ac++;
	XtSetArg(al[ac], XmNbottomOffset, 0); ac++;
	XtSetArg(al[ac], XmNbottomWidget, lock_time_text); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_OPPOSITE_WIDGET); ac++;
	XtSetArg(al[ac], XmNleftOffset, 0); ac++;
	XtSetArg(al[ac], XmNleftWidget, unfade_toggle); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNrightOffset, 20); ac++;
        XtSetValues ( lock_toggle,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_WIDGET); ac++;
	XtSetArg(al[ac], XmNtopOffset, 0); ac++;
	XtSetArg(al[ac], XmNtopWidget, passwd_time_text); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_WIDGET); ac++;
	XtSetArg(al[ac], XmNbottomOffset, 4); ac++;
	XtSetArg(al[ac], XmNbottomWidget, res_done); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_FORM); ac++;
        XtSetValues ( widget29,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_NONE); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNbottomOffset, 4); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNleftOffset, 4); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_NONE); ac++;
        XtSetValues ( res_done,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_NONE); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNbottomOffset, 4); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_WIDGET); ac++;
	XtSetArg(al[ac], XmNleftOffset, 4); ac++;
	XtSetArg(al[ac], XmNleftWidget, res_done); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_NONE); ac++;
        XtSetValues ( res_cancel,al, ac );
	ac = 0;
	children[ac++] = widget12;
	children[ac++] = widget13;
	children[ac++] = widget14;
	children[ac++] = widget15;
	children[ac++] = widget16;
	children[ac++] = widget17;
	children[ac++] = widget18;
	children[ac++] = widget48;
	children[ac++] = timeout_text;
	children[ac++] = cycle_text;
	children[ac++] = fade_text;
	children[ac++] = ticks_text;
	children[ac++] = lock_time_text;
	children[ac++] = passwd_time_text;
	children[ac++] = verbose_toggle;
	children[ac++] = cmap_toggle;
	children[ac++] = fade_toggle;
	children[ac++] = unfade_toggle;
	children[ac++] = lock_toggle;
	children[ac++] = widget29;
	children[ac++] = res_done;
	children[ac++] = res_cancel;
	XtManageChildren(children, ac);
	ac = 0;
}



create_demo_dialog( parent )
Widget parent;
{
	Display *display = XtDisplay ( parent );
	Widget children[11];      /* Children to manage */
	Arg al[64];           /* Arg List */
	register int ac = 0;      /* Arg Count */
	char from_s [256];    /* For font list conversion */
	XrmValue from_value, to_value; /* ditto */
	int fg, bg;           /* colour values for pixmaps */ 
	XmString *list_items; /* For list items */
	int list_item;        /* Index for list_items */
	XmString xmstrings[15];    /* temporary storage for XmStrings */

	demo_dialog = XmCreateDialogShell ( parent, "demoDialog", al, ac );
	demo_form = XmCreateForm ( demo_dialog, "demoForm", al, ac );
	label1 = XmCreateLabel ( demo_form, "label1", al, ac );
	label2 = XmCreateLabel ( demo_form, "label2", al, ac );
	demo_list = XmCreateScrolledList ( demo_form, "demoList", al, ac );
	text_area = XtParent ( demo_list );

	text_line = XmCreateTextField ( demo_form, "textLine", al, ac );
	vline = XmCreateSeparator ( demo_form, "vline", al, ac );
	next = XmCreatePushButton ( demo_form, "next", al, ac );
	prev = XmCreatePushButton ( demo_form, "prev", al, ac );
	edit = XmCreatePushButton ( demo_form, "edit", al, ac );
	done = XmCreatePushButton ( demo_form, "done", al, ac );
	restart = XmCreatePushButton ( demo_form, "restart", al, ac );
	xmstrings[0] = XmStringCreateLtoR(" ", (XmStringCharSet)XmSTRING_DEFAULT_CHARSET);
	XtSetArg(al[ac], XmNlabelString, xmstrings[0]); ac++;
	spacer = XmCreateLabel ( demo_form, "spacer", al, ac );
	ac = 0;
	XmStringFree ( xmstrings [ 0 ] );

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNtopOffset, 5); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_NONE); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNleftOffset, 4); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNrightOffset, 4); ac++;
        XtSetValues ( label1,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_WIDGET); ac++;
	XtSetArg(al[ac], XmNtopOffset, 4); ac++;
	XtSetArg(al[ac], XmNtopWidget, label1); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_NONE); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNleftOffset, 4); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNrightOffset, 4); ac++;
        XtSetValues ( label2,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_WIDGET); ac++;
	XtSetArg(al[ac], XmNtopOffset, 4); ac++;
	XtSetArg(al[ac], XmNtopWidget, label2); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_WIDGET); ac++;
	XtSetArg(al[ac], XmNbottomOffset, 4); ac++;
	XtSetArg(al[ac], XmNbottomWidget, text_line); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNleftOffset, 4); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNrightOffset, 4); ac++;
        XtSetValues ( text_area,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_NONE); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_WIDGET); ac++;
	XtSetArg(al[ac], XmNbottomOffset, 4); ac++;
	XtSetArg(al[ac], XmNbottomWidget, vline); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNleftOffset, 4); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNrightOffset, 4); ac++;
        XtSetValues ( text_line,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_NONE); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_WIDGET); ac++;
	XtSetArg(al[ac], XmNbottomOffset, 4); ac++;
	XtSetArg(al[ac], XmNbottomWidget, next); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNleftOffset, 4); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNrightOffset, 4); ac++;
        XtSetValues ( vline,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_NONE); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNbottomOffset, 4); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNleftOffset, 3); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_NONE); ac++;
        XtSetValues ( next,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_OPPOSITE_WIDGET); ac++;
	XtSetArg(al[ac], XmNtopOffset, 0); ac++;
	XtSetArg(al[ac], XmNtopWidget, next); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNbottomOffset, 4); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_WIDGET); ac++;
	XtSetArg(al[ac], XmNleftOffset, 4); ac++;
	XtSetArg(al[ac], XmNleftWidget, next); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_NONE); ac++;
        XtSetValues ( prev,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_OPPOSITE_WIDGET); ac++;
	XtSetArg(al[ac], XmNtopOffset, 0); ac++;
	XtSetArg(al[ac], XmNtopWidget, prev); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNbottomOffset, 4); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_WIDGET); ac++;
	XtSetArg(al[ac], XmNleftOffset, 4); ac++;
	XtSetArg(al[ac], XmNleftWidget, prev); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_NONE); ac++;
        XtSetValues ( edit,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_OPPOSITE_WIDGET); ac++;
	XtSetArg(al[ac], XmNtopOffset, 0); ac++;
	XtSetArg(al[ac], XmNtopWidget, edit); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNbottomOffset, 4); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_WIDGET); ac++;
	XtSetArg(al[ac], XmNleftOffset, 4); ac++;
	XtSetArg(al[ac], XmNleftWidget, edit); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_NONE); ac++;
        XtSetValues ( done,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_OPPOSITE_WIDGET); ac++;
	XtSetArg(al[ac], XmNtopOffset, 0); ac++;
	XtSetArg(al[ac], XmNtopWidget, done); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNbottomOffset, 4); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_WIDGET); ac++;
	XtSetArg(al[ac], XmNleftOffset, 4); ac++;
	XtSetArg(al[ac], XmNleftWidget, done); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_NONE); ac++;
        XtSetValues ( restart,al, ac );
	ac = 0;

	XtSetArg(al[ac], XmNtopAttachment, XmATTACH_OPPOSITE_WIDGET); ac++;
	XtSetArg(al[ac], XmNtopOffset, 0); ac++;
	XtSetArg(al[ac], XmNtopWidget, restart); ac++;
	XtSetArg(al[ac], XmNbottomAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNbottomOffset, 4); ac++;
	XtSetArg(al[ac], XmNleftAttachment, XmATTACH_WIDGET); ac++;
	XtSetArg(al[ac], XmNleftOffset, 4); ac++;
	XtSetArg(al[ac], XmNleftWidget, restart); ac++;
	XtSetArg(al[ac], XmNrightAttachment, XmATTACH_FORM); ac++;
	XtSetArg(al[ac], XmNrightOffset, 4); ac++;
        XtSetValues ( spacer,al, ac );
	ac = 0;
	XtManageChild(demo_list);
	children[ac++] = label1;
	children[ac++] = label2;
	children[ac++] = text_line;
	children[ac++] = vline;
	children[ac++] = next;
	children[ac++] = prev;
	children[ac++] = edit;
	children[ac++] = done;
	children[ac++] = restart;
	children[ac++] = spacer;
	XtManageChildren(children, ac);
	ac = 0;
}

