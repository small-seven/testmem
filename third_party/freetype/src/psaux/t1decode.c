#include <ft2build.h>
#include FT_INTERNAL_CALC_H
#include FT_INTERNAL_DEBUG_H
#include FT_INTERNAL_POSTSCRIPT_HINTS_H
#include FT_INTERNAL_HASH_H
#include FT_OUTLINE_H
#include "t1decode.h"
#include "psobjs.h"
#include "psauxerr.h"
#define Fix2Int( f )  ( (FT_Int)(FT_Short)( (f) >> 16 ) )
#undef  FT_COMPONENT
#define FT_COMPONENT  t1decode
  typedef enum  T1_Operator_
  {
    op_none = 0,
    op_endchar,
    op_hsbw,
    op_seac,
    op_sbw,
    op_closepath,
    op_hlineto,
    op_hmoveto,
    op_hvcurveto,
    op_rlineto,
    op_rmoveto,
    op_rrcurveto,
    op_vhcurveto,
    op_vlineto,
    op_vmoveto,
    op_dotsection,
    op_hstem,
    op_hstem3,
    op_vstem,
    op_vstem3,
    op_div,
    op_callothersubr,
    op_callsubr,
    op_pop,
    op_return,
    op_setcurrentpoint,
    op_unknown15,

    op_max    /* never remove this one */

  } T1_Operator;
#ifdef T1_CONFIG_OPTION_OLD_ENGINE
#if 0
#endif
#ifdef FT_CONFIG_OPTION_INCREMENTAL
#endif
#ifdef FT_CONFIG_OPTION_INCREMENTAL
#else
#endif /* FT_CONFIG_OPTION_INCREMENTAL */
#ifdef FT_CONFIG_OPTION_INCREMENTAL
#endif
#ifdef FT_DEBUG_LEVEL_TRACE
#endif
#ifdef FT_DEBUG_LEVEL_TRACE
#endif
#ifdef FT_DEBUG_LEVEL_TRACE
#endif
#ifdef FT_DEBUG_LEVEL_TRACE
#endif
#if 0
#endif
#ifdef FT_DEBUG_LEVEL_TRACE
#endif /* FT_DEBUG_LEVEL_TRACE */
#ifdef FT_DEBUG_LEVEL_TRACE
#endif /* FT_DEBUG_LEVEL_TRACE */
#if 0
#endif
#ifdef FT_DEBUG_LEVEL_TRACE
#endif
#else /* !T1_CONFIG_OPTION_OLD_ENGINE */
#ifdef FT_DEBUG_LEVEL_TRACE
#endif
#ifdef FT_DEBUG_LEVEL_TRACE
#endif
#ifdef FT_DEBUG_LEVEL_TRACE
#endif
#ifdef FT_DEBUG_LEVEL_TRACE
#endif /* FT_DEBUG_LEVEL_TRACE */
#endif /* !T1_CONFIG_OPTION_OLD_ENGINE */
