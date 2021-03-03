#include <ft2build.h>
#include FT_INTERNAL_DEBUG_H
#include FT_INTERNAL_STREAM_H
#include FT_TRUETYPE_TAGS_H
#include "ttbdf.h"
#include "sferrors.h"
#ifdef TT_CONFIG_OPTION_BDF
#undef  FT_COMPONENT
#define FT_COMPONENT  ttbdf
#else /* !TT_CONFIG_OPTION_BDF */
