#include <ft2build.h>
#include FT_INTERNAL_DEBUG_H
#include FT_INTERNAL_STREAM_H
#include FT_INTERNAL_RFORK_H
#include "ftbase.h"
#undef  FT_COMPONENT
#define FT_COMPONENT  raccess
#ifdef FT_CONFIG_OPTION_GUESSING_EMBEDDED_RFORK
#if defined( FT_CONFIG_OPTION_MAC_FONTS ) && !defined( FT_MACINTOSH )
#endif
#else   /* !FT_CONFIG_OPTION_GUESSING_EMBEDDED_RFORK */
#endif  /* !FT_CONFIG_OPTION_GUESSING_EMBEDDED_RFORK */