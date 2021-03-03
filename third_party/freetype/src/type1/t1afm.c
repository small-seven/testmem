#include <ft2build.h>
#include "t1afm.h"
#include FT_INTERNAL_DEBUG_H
#include FT_INTERNAL_STREAM_H
#include FT_INTERNAL_POSTSCRIPT_AUX_H
#include "t1errors.h"
#ifndef T1_CONFIG_OPTION_NO_AFM
#undef  FT_COMPONENT
#define FT_COMPONENT  t1afm
#undef  KERN_INDEX
#define KERN_INDEX( g1, g2 )  ( ( (FT_ULong)(g1) << 16 ) | (g2) )
#else /* T1_CONFIG_OPTION_NO_AFM */
