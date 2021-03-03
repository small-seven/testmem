#include <ft2build.h>
#include FT_INTERNAL_DEBUG_H
#include FT_CONFIG_CONFIG_H
#include FT_INTERNAL_STREAM_H
#include FT_INTERNAL_SFNT_H
#include FT_TRUETYPE_TAGS_H
#include FT_TRUETYPE_IDS_H
#include FT_MULTIPLE_MASTERS_H
#include FT_LIST_H
#include "ttpload.h"
#include "ttgxvar.h"
#include "tterrors.h"
#ifdef TT_CONFIG_OPTION_GX_VAR_SUPPORT
#define FT_Stream_FTell( stream )                         \
#define FT_Stream_SeekSet( stream, off )                               \
#define FT_fdot14ToFixed( x )                  \
#define FT_intToFixed( i )                      \
#define FT_fdot6ToFixed( i )                    \
#define FT_fixedToInt( x )                          \
#define FT_fixedToFdot6( x )                    \
#undef  FT_COMPONENT
#define FT_COMPONENT  ttgxvar
#define ALL_POINTS  (FT_UShort*)~(FT_PtrDist)0
#define GX_PT_POINTS_ARE_WORDS      0x80U
#define GX_PT_POINT_RUN_COUNT_MASK  0x7FU
#define GX_DT_DELTAS_ARE_ZERO       0x80U
#define GX_DT_DELTAS_ARE_WORDS      0x40U
#define GX_DT_DELTA_RUN_COUNT_MASK  0x3FU
#define GX_VALUE_SIZE  8
#define GX_VALUE_CASE( tag, dflt )      \
#define GX_GASP_CASE( idx )                                       \
#ifdef FT_DEBUG_LEVEL_TRACE
#endif
  typedef struct  GX_GVar_Head_
  {
    FT_Long    version;
    FT_UShort  axisCount;
    FT_UShort  globalCoordCount;
    FT_ULong   offsetToCoord;
    FT_UShort  glyphCount;
    FT_UShort  flags;
    FT_ULong   offsetToData;

  } GX_GVar_Head;
#undef  FT_STRUCTURE
#define FT_STRUCTURE  GX_GVar_Head
  typedef struct  GX_FVar_Head_
  {
    FT_Long    version;
    FT_UShort  offsetToData;
    FT_UShort  axisCount;
    FT_UShort  axisSize;
    FT_UShort  instanceCount;
    FT_UShort  instanceSize;

  } GX_FVar_Head;
  typedef struct  fvar_axis_
  {
    FT_ULong   axisTag;
    FT_Fixed   minValue;
    FT_Fixed   defaultValue;
    FT_Fixed   maxValue;
    FT_UShort  flags;
    FT_UShort  nameID;

  } GX_FVar_Axis;
#undef  FT_STRUCTURE
#define FT_STRUCTURE  GX_FVar_Head
#undef  FT_STRUCTURE
#define FT_STRUCTURE  GX_FVar_Axis
#undef  ALIGN_SIZE
#define ALIGN_SIZE( n ) \
#ifdef FT_DEBUG_LEVEL_TRACE
#endif
#ifdef FT_DEBUG_LEVEL_TRACE
#endif
#ifdef FT_DEBUG_LEVEL_TRACE
#endif
#ifdef FT_DEBUG_LEVEL_TRACE
#endif /* FT_DEBUG_LEVEL_TRACE */
#ifdef FT_DEBUG_LEVEL_TRACE
#endif
#ifdef FT_DEBUG_LEVEL_TRACE
#endif
#ifdef FT_DEBUG_LEVEL_TRACE
#endif
#ifdef FT_DEBUG_LEVEL_TRACE
#endif
#ifdef FT_DEBUG_LEVEL_TRACE
#endif
#ifdef FT_DEBUG_LEVEL_TRACE
#endif
#ifdef FT_DEBUG_LEVEL_TRACE
#endif
#ifdef FT_DEBUG_LEVEL_TRACE
#endif
#ifdef FT_DEBUG_LEVEL_TRACE
#endif
#ifdef FT_DEBUG_LEVEL_TRACE
#endif
#ifdef FT_DEBUG_LEVEL_TRACE
#endif
#ifdef FT_DEBUG_LEVEL_TRACE
#endif
#else /* !TT_CONFIG_OPTION_GX_VAR_SUPPORT */
