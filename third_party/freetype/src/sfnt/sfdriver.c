#include <ft2build.h>
#include FT_INTERNAL_DEBUG_H
#include FT_INTERNAL_SFNT_H
#include FT_INTERNAL_OBJECTS_H
#include FT_TRUETYPE_IDS_H
#include "sfdriver.h"
#include "ttload.h"
#include "sfobjs.h"
#include "sferrors.h"
#ifdef TT_CONFIG_OPTION_EMBEDDED_BITMAPS
#include "ttsbit.h"
#endif
#ifdef TT_CONFIG_OPTION_COLOR_LAYERS
#include "ttcolr.h"
#include "ttcpal.h"
#endif
#ifdef TT_CONFIG_OPTION_POSTSCRIPT_NAMES
#include "ttpost.h"
#endif
#ifdef TT_CONFIG_OPTION_BDF
#include "ttbdf.h"
#include FT_SERVICE_BDF_H
#endif
#include "ttcmap.h"
#include "ttkern.h"
#include "ttmtx.h"
#include FT_SERVICE_GLYPH_DICT_H
#include FT_SERVICE_POSTSCRIPT_NAME_H
#include FT_SERVICE_SFNT_H
#include FT_SERVICE_TT_CMAP_H
#ifdef TT_CONFIG_OPTION_GX_VAR_SUPPORT
#include FT_MULTIPLE_MASTERS_H
#include FT_SERVICE_MULTIPLE_MASTERS_H
#endif
#undef  FT_COMPONENT
#define FT_COMPONENT  sfdriver
#ifdef TT_CONFIG_OPTION_POSTSCRIPT_NAMES
#endif /* TT_CONFIG_OPTION_POSTSCRIPT_NAMES */
#ifdef TT_CONFIG_OPTION_GX_VAR_SUPPORT
#define ROTL32( x, r )  ( x << r ) | ( x >> ( 32 - r ) )
#endif /* TT_CONFIG_OPTION_GX_VAR_SUPPORT */
  typedef int (*char_type_func)( int  c );


  /* Handling of PID/EID 3/0 and 3/1 is the same. */
#define IS_WIN( n )  ( (n)->platformID == 3                             && \
                       ( (n)->encodingID == 1 || (n)->encodingID == 0 ) )

#define IS_APPLE( n )  ( (n)->platformID == 1 && \
                         (n)->encodingID == 0 )

  static char*
  get_win_string( FT_Memory       memory,
                  FT_Stream       stream,
                  TT_Name         entry,
                  char_type_func  char_type,
                  FT_Bool         report_invalid_characters )
  {
    FT_Error  error = FT_Err_Ok;

    char*       result = NULL;
    FT_String*  r;
    FT_Char*    p;
    FT_UInt     len;

    FT_UNUSED( error );


    if ( FT_ALLOC( result, entry->stringLength / 2 + 1 ) )
      return NULL;

    if ( FT_STREAM_SEEK( entry->stringOffset ) ||
         FT_FRAME_ENTER( entry->stringLength ) )
      goto get_win_string_error;

    r = (FT_String*)result;
    p = (FT_Char*)stream->cursor;

    for ( len = entry->stringLength / 2; len > 0; len--, p += 2 )
    {
      if ( p[0] == 0 && char_type( p[1] ) )
        *r++ = p[1];
      else
      {
        if ( report_invalid_characters )
          FT_TRACE0(( "get_win_string:"
                      " Character 0x%X invalid in PS name string\n",
                      ((unsigned)p[0])*256 + (unsigned)p[1] ));
        break;
      }
#ifdef TT_CONFIG_OPTION_GX_VAR_SUPPORT
#define MAX_VALUE_DESCRIPTOR_LEN  ( 1 + 5 + 1 + 5 + 1 + 4 )
#define MAX_PS_NAME_LEN  127
#endif /* TT_CONFIG_OPTION_GX_VAR_SUPPORT */
#ifdef TT_CONFIG_OPTION_GX_VAR_SUPPORT
#endif
#ifdef TT_CONFIG_OPTION_BDF
#endif /* TT_CONFIG_OPTION_BDF */
#if defined TT_CONFIG_OPTION_POSTSCRIPT_NAMES && defined TT_CONFIG_OPTION_BDF
#elif defined TT_CONFIG_OPTION_POSTSCRIPT_NAMES
#elif defined TT_CONFIG_OPTION_BDF
#else
#endif
#ifdef TT_CONFIG_OPTION_EMBEDDED_BITMAPS
#define PUT_EMBEDDED_BITMAPS( a )  a
#else
#define PUT_EMBEDDED_BITMAPS( a )  NULL
#endif
#ifdef TT_CONFIG_OPTION_COLOR_LAYERS
#define PUT_COLOR_LAYERS( a )  a
#else
#define PUT_COLOR_LAYERS( a )  NULL
#endif
#ifdef TT_CONFIG_OPTION_POSTSCRIPT_NAMES
#define PUT_PS_NAMES( a )  a
#else
#define PUT_PS_NAMES( a )  NULL
#endif
