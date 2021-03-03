#include <ft2build.h>
#include FT_LIST_H
#include FT_OUTLINE_H
#include FT_FONT_FORMATS_H
#include FT_INTERNAL_VALIDATE_H
#include FT_INTERNAL_OBJECTS_H
#include FT_INTERNAL_DEBUG_H
#include FT_INTERNAL_RFORK_H
#include FT_INTERNAL_STREAM_H
#include FT_INTERNAL_SFNT_H            /* for SFNT_Load_Table_Func */
#include FT_INTERNAL_POSTSCRIPT_AUX_H  /* for PS_Driver            */
#include FT_TRUETYPE_TABLES_H
#include FT_TRUETYPE_TAGS_H
#include FT_TRUETYPE_IDS_H
#include FT_SERVICE_PROPERTIES_H
#include FT_SERVICE_SFNT_H
#include FT_SERVICE_POSTSCRIPT_NAME_H
#include FT_SERVICE_GLYPH_DICT_H
#include FT_SERVICE_TT_CMAP_H
#include FT_SERVICE_KERNING_H
#include FT_SERVICE_TRUETYPE_ENGINE_H
#include FT_DRIVER_H
#ifdef FT_CONFIG_OPTION_MAC_FONTS
#include "ftbase.h"
#endif
#ifdef FT_DEBUG_LEVEL_TRACE
#include FT_BITMAP_H
#if defined( _MSC_VER )      /* Visual C++ (and Intel C++)   */
#pragma warning( push )
#pragma warning( disable : 4244 )
#endif /* _MSC_VER */
#define MD5_u32plus  FT_MD5_u32plus
#define MD5_CTX      FT_MD5_CTX
#define MD5_Init     FT_MD5_Init
#define MD5_Update   FT_MD5_Update
#define MD5_Final    FT_MD5_Final
#undef  HAVE_OPENSSL
#include "md5.c"
#if defined( _MSC_VER )
#pragma warning( pop )
#endif
#endif /* FT_DEBUG_LEVEL_TRACE */
#define GRID_FIT_METRICS
#ifndef FT_CONFIG_OPTION_DISABLE_STREAM_SUPPORT
#endif
#undef  FT_COMPONENT
#define FT_COMPONENT  objs
#if 1
#else
#endif
#ifdef GRID_FIT_METRICS
#endif /* GRID_FIT_METRICS */
#ifdef GRID_FIT_METRICS
#endif
#ifdef FT_DEBUG_LEVEL_TRACE
#endif
#ifdef FT_CONFIG_OPTION_INCREMENTAL
#endif
#ifndef FT_MACINTOSH
#endif
#ifdef FT_CONFIG_OPTION_MAC_FONTS
#ifdef FT_MACINTOSH
#endif
#ifdef FT_MACINTOSH
#else
#endif
#ifndef FT_MACINTOSH
#if 0
#endif /* 0 */
#undef  FT_COMPONENT
#define FT_COMPONENT  raccess
#undef  FT_COMPONENT
#define FT_COMPONENT  objs
#undef  FT_COMPONENT
#define FT_COMPONENT  raccess
#ifdef FT_DEBUG_LEVEL_TRACE
#endif
#undef  FT_COMPONENT
#define FT_COMPONENT  objs
#endif
#endif  /* !FT_MACINTOSH && FT_CONFIG_OPTION_MAC_FONTS */
#ifndef FT_CONFIG_OPTION_MAC_FONTS
#endif
#ifdef FT_DEBUG_LEVEL_TRACE
#endif
#ifdef FT_CONFIG_OPTION_MAC_FONTS
#endif
#if !defined( FT_MACINTOSH ) && defined( FT_CONFIG_OPTION_MAC_FONTS )
#endif  /* !FT_MACINTOSH && FT_CONFIG_OPTION_MAC_FONTS */
#ifdef FT_CONFIG_OPTION_SUBPIXEL_RENDERING
#endif
#ifdef FT_DEBUG_LEVEL_TRACE
#endif
#ifdef GRID_FIT_METRICS
#else /* !GRID_FIT_METRICS */
#endif /* !GRID_FIT_METRICS */
#ifdef FT_DEBUG_LEVEL_TRACE
#endif
#ifdef FT_DEBUG_LEVEL_TRACE
#endif
#ifdef FT_DEBUG_LEVEL_TRACE
#endif
#ifdef FT_CONFIG_OPTION_SUBPIXEL_RENDERING
#else
#endif
#ifdef FT_DEBUG_LEVEL_TRACE
#undef  FT_COMPONENT
#define FT_COMPONENT  checksum
#undef  FT_COMPONENT
#define FT_COMPONENT  objs
#endif /* FT_DEBUG_LEVEL_TRACE */
#define FREETYPE_VER_FIXED  ( ( (FT_Long)FREETYPE_MAJOR << 16 ) | \
#ifdef FT_DEBUG_LEVEL_ERROR
#endif
#ifdef FT_CONFIG_OPTION_ENVIRONMENT_PROPERTIES
#endif
#ifdef FT_DEBUG_LEVEL_ERROR
#endif
#if 1
#else
#endif
