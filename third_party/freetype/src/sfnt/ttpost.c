#include <ft2build.h>
#include FT_INTERNAL_DEBUG_H
#include FT_INTERNAL_STREAM_H
#include FT_TRUETYPE_TAGS_H
#ifdef TT_CONFIG_OPTION_POSTSCRIPT_NAMES
#include "ttpost.h"
#include "sferrors.h"
#undef  FT_COMPONENT
#define FT_COMPONENT  ttpost
#ifdef FT_CONFIG_OPTION_POSTSCRIPT_NAMES
#include FT_SERVICE_POSTSCRIPT_CMAPS_H
#define MAC_NAME( x )  (FT_String*)psnames->macintosh_name( (FT_UInt)(x) )
#else /* FT_CONFIG_OPTION_POSTSCRIPT_NAMES */
#define MAC_NAME( x )  (FT_String*)tt_post_default_names[x]
#endif /* FT_CONFIG_OPTION_POSTSCRIPT_NAMES */
#ifdef FT_CONFIG_OPTION_POSTSCRIPT_NAMES
#endif
#ifdef FT_CONFIG_OPTION_POSTSCRIPT_NAMES
#endif
#else /* !TT_CONFIG_OPTION_POSTSCRIPT_NAMES */
