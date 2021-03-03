#include <ft2build.h>
#include FT_INTERNAL_CALC_H
#include FT_INTERNAL_DEBUG_H
#include FT_INTERNAL_STREAM_H
#include FT_TRUETYPE_IDS_H
#include FT_DRIVER_H
#include "t1gload.h"
#include "t1load.h"
#include "t1errors.h"
#ifndef T1_CONFIG_OPTION_NO_AFM
#include "t1afm.h"
#endif
#include FT_SERVICE_POSTSCRIPT_CMAPS_H
#include FT_INTERNAL_POSTSCRIPT_AUX_H
#undef  FT_COMPONENT
#define FT_COMPONENT  t1objs
#ifndef T1_CONFIG_OPTION_NO_MM_SUPPORT
#endif
#ifndef T1_CONFIG_OPTION_NO_AFM
#endif
#if 0
#endif
#ifdef T1_CONFIG_OPTION_OLD_ENGINE
#else
#endif
