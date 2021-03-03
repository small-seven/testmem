#include <ft2build.h>
#include FT_INTERNAL_DEBUG_H
#include FT_INTERNAL_OBJECTS_H
#include FT_SERVICE_POSTSCRIPT_CMAPS_H
#include "psmodule.h"
#include "pstables.h"
#define  DEFINE_PS_TABLES
#define  DEFINE_PS_TABLES_DATA
#include "pstables.h"
#include "psnamerr.h"
#ifdef FT_CONFIG_OPTION_POSTSCRIPT_NAMES
#ifdef FT_CONFIG_OPTION_ADOBE_GLYPH_LIST
#define VARIANT_BIT         0x80000000UL
#define BASE_GLYPH( code )  ( (FT_UInt32)( (code) & ~VARIANT_BIT ) )
#define EXTRA_GLYPH_LIST_SIZE  10
#endif /* FT_CONFIG_OPTION_ADOBE_GLYPH_LIST */
#ifdef FT_CONFIG_OPTION_ADOBE_GLYPH_LIST
#else
#endif /* FT_CONFIG_OPTION_ADOBE_GLYPH_LIST */
#endif /* FT_CONFIG_OPTION_POSTSCRIPT_NAMES */
#ifndef FT_CONFIG_OPTION_POSTSCRIPT_NAMES
#define PUT_PS_NAMES_SERVICE( a )  NULL
#else
#define PUT_PS_NAMES_SERVICE( a )  a
#endif
