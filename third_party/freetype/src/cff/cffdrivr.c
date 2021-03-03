#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_INTERNAL_DEBUG_H
#include FT_INTERNAL_STREAM_H
#include FT_INTERNAL_SFNT_H
#include FT_INTERNAL_POSTSCRIPT_AUX_H
#include FT_INTERNAL_POSTSCRIPT_PROPS_H
#include FT_SERVICE_CID_H
#include FT_SERVICE_POSTSCRIPT_INFO_H
#include FT_SERVICE_POSTSCRIPT_NAME_H
#include FT_SERVICE_TT_CMAP_H
#include FT_SERVICE_CFF_TABLE_LOAD_H
#include "cffdrivr.h"
#include "cffgload.h"
#include "cffload.h"
#include "cffcmap.h"
#include "cffparse.h"
#include "cffobjs.h"
#ifdef TT_CONFIG_OPTION_GX_VAR_SUPPORT
#include FT_SERVICE_MULTIPLE_MASTERS_H
#include FT_SERVICE_METRICS_VARIATIONS_H
#endif
#include "cfferrs.h"
#include FT_SERVICE_FONT_FORMAT_H
#include FT_SERVICE_GLYPH_DICT_H
#include FT_SERVICE_PROPERTIES_H
#include FT_DRIVER_H
#undef  FT_COMPONENT
#define FT_COMPONENT  cffdriver
#ifdef TT_CONFIG_OPTION_GX_VAR_SUPPORT
#endif
#ifdef TT_CONFIG_OPTION_GX_VAR_SUPPORT
#endif
#ifdef TT_CONFIG_OPTION_GX_VAR_SUPPORT
#endif
#if !defined FT_CONFIG_OPTION_NO_GLYPH_NAMES && \
#elif !defined FT_CONFIG_OPTION_NO_GLYPH_NAMES
#elif defined TT_CONFIG_OPTION_GX_VAR_SUPPORT
#else
#endif
#ifdef TT_CONFIG_OPTION_EMBEDDED_BITMAPS
#define CFF_SIZE_SELECT cff_size_select
#else
#define CFF_SIZE_SELECT 0
#endif
