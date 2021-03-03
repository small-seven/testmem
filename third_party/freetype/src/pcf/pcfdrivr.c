#include <ft2build.h>
#include FT_INTERNAL_DEBUG_H
#include FT_INTERNAL_STREAM_H
#include FT_INTERNAL_OBJECTS_H
#include FT_GZIP_H
#include FT_LZW_H
#include FT_BZIP2_H
#include FT_ERRORS_H
#include FT_BDF_H
#include FT_TRUETYPE_IDS_H
#include "pcf.h"
#include "pcfdrivr.h"
#include "pcfread.h"
#include "pcferror.h"
#include "pcfutil.h"
#undef  FT_COMPONENT
#define FT_COMPONENT  pcfread
#include FT_SERVICE_BDF_H
#include FT_SERVICE_FONT_FORMAT_H
#include FT_SERVICE_PROPERTIES_H
#include FT_DRIVER_H
#undef  FT_COMPONENT
#define FT_COMPONENT  pcfdriver
  typedef struct  PCF_CMapRec_
  {
    FT_CMapRec  root;
    PCF_Enc     enc;

  } PCF_CMapRec, *PCF_CMap;
#if defined( FT_CONFIG_OPTION_USE_ZLIB )  || \
#ifdef FT_CONFIG_OPTION_USE_ZLIB
#endif /* FT_CONFIG_OPTION_USE_ZLIB */
#ifdef FT_CONFIG_OPTION_USE_LZW
#endif /* FT_CONFIG_OPTION_USE_LZW */
#ifdef FT_CONFIG_OPTION_USE_BZIP2
#endif /* FT_CONFIG_OPTION_USE_BZIP2 */
#else /* !(FT_CONFIG_OPTION_USE_ZLIB ||
#endif
#ifdef PCF_CONFIG_OPTION_LONG_FAMILY_NAMES
#ifndef FT_CONFIG_OPTION_ENVIRONMENT_PROPERTIES
#endif
#ifdef FT_CONFIG_OPTION_ENVIRONMENT_PROPERTIES
#endif
#else /* !PCF_CONFIG_OPTION_LONG_FAMILY_NAMES */
#ifndef FT_DEBUG_LEVEL_TRACE
#endif
#endif /* !PCF_CONFIG_OPTION_LONG_FAMILY_NAMES */
#ifdef PCF_CONFIG_OPTION_LONG_FAMILY_NAMES
#else /* !PCF_CONFIG_OPTION_LONG_FAMILY_NAMES */
#ifndef FT_DEBUG_LEVEL_TRACE
#endif
#endif /* !PCF_CONFIG_OPTION_LONG_FAMILY_NAMES */
#ifdef PCF_CONFIG_OPTION_LONG_FAMILY_NAMES
#else
#endif
