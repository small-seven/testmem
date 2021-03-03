#include <ft2build.h>
#include FT_INTERNAL_OBJECTS_H
#include FT_INTERNAL_DEBUG_H
#include FT_CACHE_H
#include "ftcglyph.h"
#include "ftcimage.h"
#include "ftcsbits.h"
#include "ftccback.h"
#include "ftcerror.h"
#define FT_COMPONENT  cache
  typedef struct  FTC_BasicAttrRec_
  {
    FTC_ScalerRec  scaler;
    FT_UInt        load_flags;

  } FTC_BasicAttrRec, *FTC_BasicAttrs;
#define FTC_BASIC_ATTR_COMPARE( a, b )                                 \
#define FTC_BASIC_ATTR_HASH( a )                                     \
  typedef struct  FTC_BasicQueryRec_
  {
    FTC_GQueryRec     gquery;
    FTC_BasicAttrRec  attrs;

  } FTC_BasicQueryRec, *FTC_BasicQuery;
  typedef struct  FTC_BasicFamilyRec_
  {
    FTC_FamilyRec     family;
    FTC_BasicAttrRec  attrs;

  } FTC_BasicFamilyRec, *FTC_BasicFamily;
#if 0xFFFFFFFFUL > FT_UINT_MAX
#endif
#if 1  /* inlining is about 50% faster! */
#else
#endif
#if FT_ULONG_MAX > FT_UINT_MAX
#endif
#if 0xFFFFFFFFUL > FT_UINT_MAX
#endif
#if 1  /* inlining is about 50% faster! */
#else
#endif
#if FT_ULONG_MAX > FT_UINT_MAX
#endif
