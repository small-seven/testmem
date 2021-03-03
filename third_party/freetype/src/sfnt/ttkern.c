#include <ft2build.h>
#include FT_INTERNAL_DEBUG_H
#include FT_INTERNAL_STREAM_H
#include FT_TRUETYPE_TAGS_H
#include "ttkern.h"
#include "sferrors.h"
#undef  FT_COMPONENT
#define FT_COMPONENT  ttkern
#undef  TT_KERN_INDEX
#define TT_KERN_INDEX( g1, g2 )  ( ( (FT_ULong)(g1) << 16 ) | (g2) )
#undef TT_KERN_INDEX
