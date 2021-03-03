#include <ft2build.h>
#include FT_INTERNAL_DEBUG_H
#include FT_LCD_FILTER_H
#include FT_IMAGE_H
#include FT_INTERNAL_OBJECTS_H
#ifdef FT_CONFIG_OPTION_SUBPIXEL_RENDERING
#define  USE_LEGACY
#define FT_SHIFTCLAMP( x )  ( x >>= 8, (FT_Byte)( x > 255 ? 255 : x ) )
#ifdef USE_LEGACY
#endif /* USE_LEGACY */
#ifdef USE_LEGACY
#endif
#else /* !FT_CONFIG_OPTION_SUBPIXEL_RENDERING */
#endif /* !FT_CONFIG_OPTION_SUBPIXEL_RENDERING */
