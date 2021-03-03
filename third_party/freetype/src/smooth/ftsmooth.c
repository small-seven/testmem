#include <ft2build.h>
#include FT_INTERNAL_DEBUG_H
#include FT_INTERNAL_OBJECTS_H
#include FT_OUTLINE_H
#include "ftsmooth.h"
#include "ftgrays.h"
#include "ftsmerrs.h"
#ifndef FT_CONFIG_OPTION_SUBPIXEL_RENDERING
#elif 0   /* or else, once ClearType patents expire */
#endif
#ifdef FT_CONFIG_OPTION_SUBPIXEL_RENDERING
#else /* !FT_CONFIG_OPTION_SUBPIXEL_RENDERING */
#endif /* !FT_CONFIG_OPTION_SUBPIXEL_RENDERING */
