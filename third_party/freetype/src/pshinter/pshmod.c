#include <ft2build.h>
#include FT_INTERNAL_OBJECTS_H
#include "pshrec.h"
#include "pshalgo.h"
  typedef struct  PS_Hinter_Module_Rec_
  {
    FT_ModuleRec          root;
    PS_HintsRec           ps_hints;

    PSH_Globals_FuncsRec  globals_funcs;
    T1_Hints_FuncsRec     t1_funcs;
    T2_Hints_FuncsRec     t2_funcs;

  } PS_Hinter_ModuleRec, *PS_Hinter_Module;
