#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_INTERNAL_DEBUG_H
#include FT_INTERNAL_SERVICE_H
#include FT_SERVICE_CFF_TABLE_LOAD_H
#include "cffdecode.h"
#include "psobjs.h"
#include "psauxerr.h"
#undef  FT_COMPONENT
#define FT_COMPONENT  cffdecode
#ifdef CFF_CONFIG_OPTION_OLD_ENGINE
  typedef enum  CFF_Operator_
  {
    cff_op_unknown = 0,

    cff_op_rmoveto,
    cff_op_hmoveto,
    cff_op_vmoveto,

    cff_op_rlineto,
    cff_op_hlineto,
    cff_op_vlineto,

    cff_op_rrcurveto,
    cff_op_hhcurveto,
    cff_op_hvcurveto,
    cff_op_rcurveline,
    cff_op_rlinecurve,
    cff_op_vhcurveto,
    cff_op_vvcurveto,

    cff_op_flex,
    cff_op_hflex,
    cff_op_hflex1,
    cff_op_flex1,

    cff_op_endchar,

    cff_op_hstem,
    cff_op_vstem,
    cff_op_hstemhm,
    cff_op_vstemhm,

    cff_op_hintmask,
    cff_op_cntrmask,
    cff_op_dotsection,  /* deprecated, acts as no-op */

    cff_op_abs,
    cff_op_add,
    cff_op_sub,
    cff_op_div,
    cff_op_neg,
    cff_op_random,
    cff_op_mul,
    cff_op_sqrt,

    cff_op_blend,

    cff_op_drop,
    cff_op_exch,
    cff_op_index,
    cff_op_roll,
    cff_op_dup,

    cff_op_put,
    cff_op_get,
    cff_op_store,
    cff_op_load,

    cff_op_and,
    cff_op_or,
    cff_op_not,
    cff_op_eq,
    cff_op_ifelse,

    cff_op_callsubr,
    cff_op_callgsubr,
    cff_op_return,

    /* Type 1 opcodes: invalid but seen in real life */
    cff_op_hsbw,
    cff_op_closepath,
    cff_op_callothersubr,
    cff_op_pop,
    cff_op_seac,
    cff_op_sbw,
    cff_op_setcurrentpoint,

    /* do not remove */
    cff_op_max

  } CFF_Operator;
#define CFF_COUNT_CHECK_WIDTH  0x80
#define CFF_COUNT_EXACT        0x40
#define CFF_COUNT_CLEAR_STACK  0x20
#ifdef FT_CONFIG_OPTION_INCREMENTAL
#endif /* FT_CONFIG_OPTION_INCREMENTAL */
#endif /* CFF_CONFIG_OPTION_OLD_ENGINE */
#if 0
#endif
#ifdef CFF_CONFIG_OPTION_OLD_ENGINE
#ifdef FT_DEBUG_LEVEL_TRACE
#endif
#ifdef FT_DEBUG_LEVEL_TRACE
#else
#endif
#endif /* CFF_CONFIG_OPTION_OLD_ENGINE */
