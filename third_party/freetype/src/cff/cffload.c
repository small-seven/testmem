#include <ft2build.h>
#include FT_INTERNAL_DEBUG_H
#include FT_INTERNAL_OBJECTS_H
#include FT_INTERNAL_STREAM_H
#include FT_TRUETYPE_TAGS_H
#include FT_TYPE1_TABLES_H
#include FT_INTERNAL_POSTSCRIPT_AUX_H
#ifdef TT_CONFIG_OPTION_GX_VAR_SUPPORT
#include FT_MULTIPLE_MASTERS_H
#include FT_SERVICE_MULTIPLE_MASTERS_H
#endif
#include "cffload.h"
#include "cffparse.h"
#include "cfferrs.h"
#define FT_FIXED_ONE  ( (FT_Fixed)0x10000 )
#if 1
#endif /* 1 */
#undef  FT_COMPONENT
#define FT_COMPONENT  cffload
#ifdef TT_CONFIG_OPTION_GX_VAR_SUPPORT
#endif /* TT_CONFIG_OPTION_GX_VAR_SUPPORT */
#undef  FT_STRUCTURE
#define FT_STRUCTURE  CFF_FontRec
