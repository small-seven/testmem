#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_INTERNAL_DEBUG_H
#include FT_INTERNAL_POSTSCRIPT_AUX_H
#ifndef T1_CONFIG_OPTION_NO_AFM
#include "afmparse.h"
#include "psconv.h"
#include "psauxerr.h"
  typedef struct  AFM_StreamRec_
  {
    FT_Byte*  cursor;
    FT_Byte*  base;
    FT_Byte*  limit;

    FT_Int    status;

  } AFM_StreamRec;
#ifndef EOF
#define EOF -1
#endif
#define AFM_IS_NEWLINE( ch )  ( (ch) == '\r' || (ch) == '\n' )
#define AFM_IS_EOF( ch )      ( (ch) == EOF  || (ch) == '\x1a' )
#define AFM_IS_SPACE( ch )    ( (ch) == ' '  || (ch) == '\t' )
#define AFM_IS_SEP( ch )      ( (ch) == ';' )
#define AFM_GETC()                                                       \
#define AFM_STREAM_KEY_BEGIN( stream )    \
#define AFM_STREAM_KEY_LEN( stream, key )           \
#define AFM_STATUS_EOC( stream ) \
#define AFM_STATUS_EOL( stream ) \
#define AFM_STATUS_EOF( stream ) \
  typedef enum  AFM_Token_
  {
    AFM_TOKEN_ASCENDER,
    AFM_TOKEN_AXISLABEL,
    AFM_TOKEN_AXISTYPE,
    AFM_TOKEN_B,
    AFM_TOKEN_BLENDAXISTYPES,
    AFM_TOKEN_BLENDDESIGNMAP,
    AFM_TOKEN_BLENDDESIGNPOSITIONS,
    AFM_TOKEN_C,
    AFM_TOKEN_CC,
    AFM_TOKEN_CH,
    AFM_TOKEN_CAPHEIGHT,
    AFM_TOKEN_CHARWIDTH,
    AFM_TOKEN_CHARACTERSET,
    AFM_TOKEN_CHARACTERS,
    AFM_TOKEN_DESCENDER,
    AFM_TOKEN_ENCODINGSCHEME,
    AFM_TOKEN_ENDAXIS,
    AFM_TOKEN_ENDCHARMETRICS,
    AFM_TOKEN_ENDCOMPOSITES,
    AFM_TOKEN_ENDDIRECTION,
    AFM_TOKEN_ENDFONTMETRICS,
    AFM_TOKEN_ENDKERNDATA,
    AFM_TOKEN_ENDKERNPAIRS,
    AFM_TOKEN_ENDTRACKKERN,
    AFM_TOKEN_ESCCHAR,
    AFM_TOKEN_FAMILYNAME,
    AFM_TOKEN_FONTBBOX,
    AFM_TOKEN_FONTNAME,
    AFM_TOKEN_FULLNAME,
    AFM_TOKEN_ISBASEFONT,
    AFM_TOKEN_ISCIDFONT,
    AFM_TOKEN_ISFIXEDPITCH,
    AFM_TOKEN_ISFIXEDV,
    AFM_TOKEN_ITALICANGLE,
    AFM_TOKEN_KP,
    AFM_TOKEN_KPH,
    AFM_TOKEN_KPX,
    AFM_TOKEN_KPY,
    AFM_TOKEN_L,
    AFM_TOKEN_MAPPINGSCHEME,
    AFM_TOKEN_METRICSSETS,
    AFM_TOKEN_N,
    AFM_TOKEN_NOTICE,
    AFM_TOKEN_PCC,
    AFM_TOKEN_STARTAXIS,
    AFM_TOKEN_STARTCHARMETRICS,
    AFM_TOKEN_STARTCOMPOSITES,
    AFM_TOKEN_STARTDIRECTION,
    AFM_TOKEN_STARTFONTMETRICS,
    AFM_TOKEN_STARTKERNDATA,
    AFM_TOKEN_STARTKERNPAIRS,
    AFM_TOKEN_STARTKERNPAIRS0,
    AFM_TOKEN_STARTKERNPAIRS1,
    AFM_TOKEN_STARTTRACKKERN,
    AFM_TOKEN_STDHW,
    AFM_TOKEN_STDVW,
    AFM_TOKEN_TRACKKERN,
    AFM_TOKEN_UNDERLINEPOSITION,
    AFM_TOKEN_UNDERLINETHICKNESS,
    AFM_TOKEN_VV,
    AFM_TOKEN_VVECTOR,
    AFM_TOKEN_VERSION,
    AFM_TOKEN_W,
    AFM_TOKEN_W0,
    AFM_TOKEN_W0X,
    AFM_TOKEN_W0Y,
    AFM_TOKEN_W1,
    AFM_TOKEN_W1X,
    AFM_TOKEN_W1Y,
    AFM_TOKEN_WX,
    AFM_TOKEN_WY,
    AFM_TOKEN_WEIGHT,
    AFM_TOKEN_WEIGHTVECTOR,
    AFM_TOKEN_XHEIGHT,
    N_AFM_TOKENS,
    AFM_TOKEN_UNKNOWN

  } AFM_Token;
#undef  KERN_INDEX
#define KERN_INDEX( g1, g2 )  ( ( (FT_ULong)g1 << 16 ) | g2 )
#else /* T1_CONFIG_OPTION_NO_AFM */
