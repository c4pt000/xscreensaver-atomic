 $ def sys sys$library: $ CC/DEFINE=VMS ATTRACTION.C $ CC/DEFINE=VMS BLITSPIN.C $ CC/DEFINE=VMS DECAYSCREEN.C  $ CC/DEFINE=VMS FLAME.C  $ CC/DEFINE=VMS GREYNETIC.C  $ CC/DEFINE=VMS HALO.C $ CC/DEFINE=VMS HELIX.C  $ CC/DEFINE=VMS HOPALONG.C $ CC/DEFINE=VMS HYPERCUBE.C  $ CC/DEFINE=VMS IMSMAP.C $ CC/DEFINE=VMS MAZE.C $ CC/DEFINE=VMS NOSEGUY.C  $ CC/DEFINE=VMS PYRO.C $ CC/DEFINE=VMS QIX.C  $ CC/DEFINE=VMS ROCKS.C  $ CC/DEFINE=VMS RORSCHACH.C / $ CC/DEFINE=(VMS,"XPointer=char*") SCREENHACK.C  $ CC/DEFINE=VMS SLIDESCREEN.C  $ CC/DEFINE=VMS XROGER-HACK.C 