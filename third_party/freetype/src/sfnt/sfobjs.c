#include <ft2build.h>
#include "sfobjs.h"
#include "ttload.h"
#include "ttcmap.h"
#include "ttkern.h"
#include "sfwoff.h"
#include FT_INTERNAL_SFNT_H
#include FT_INTERNAL_DEBUG_H
#include FT_TRUETYPE_IDS_H
#include FT_TRUETYPE_TAGS_H
#include FT_SERVICE_POSTSCRIPT_CMAPS_H
#include FT_SFNT_NAMES_H
#ifdef TT_CONFIG_OPTION_GX_VAR_SUPPORT
#include FT_SERVICE_MULTIPLE_MASTERS_H
#include FT_SERVICE_METRICS_VARIATIONS_H
#endif
#include "sferrors.h"
#ifdef TT_CONFIG_OPTION_BDF
#include "ttbdf.h"
#endif
#undef  FT_COMPONENT
#define FT_COMPONENT  sfobjs
  typedef FT_String*  (*TT_Name_ConvertFunc)( TT_Name    entry,
                                              FT_Memory  memory );


  /* documentation is in sfnt.h */

  FT_LOCAL_DEF( FT_Error )
  tt_face_get_name( TT_Face      face,
                    FT_UShort    nameid,
                    FT_String**  name )
  {
    FT_Memory   memory = face->root.memory;
    FT_Error    error  = FT_Err_Ok;
    FT_String*  result = NULL;
    FT_UShort   n;
    TT_Name     rec;

    FT_Int  found_apple         = -1;
    FT_Int  found_apple_roman   = -1;
    FT_Int  found_apple_english = -1;
    FT_Int  found_win           = -1;
    FT_Int  found_unicode       = -1;

    FT_Bool  is_english = 0;

    TT_Name_ConvertFunc  convert;


    FT_ASSERT( name );

    rec = face->name_table.names;
    for ( n = 0; n < face->num_names; n++, rec++ )
    {
      /* According to the OpenType 1.3 specification, only Microsoft or  */
      /* Apple platform IDs might be used in the `name' table.  The      */
      /* `Unicode' platform is reserved for the `cmap' table, and the    */
      /* `ISO' one is deprecated.                                        */
      /*                                                                 */
      /* However, the Apple TrueType specification doesn't say the same  */
      /* thing and goes to suggest that all Unicode `name' table entries */
      /* should be coded in UTF-16 (in big-endian format I suppose).     */
      /*                                                                 */
      if ( rec->nameID == nameid && rec->stringLength > 0 )
      {
        switch ( rec->platformID )
        {
        case TT_PLATFORM_APPLE_UNICODE:
        case TT_PLATFORM_ISO:
          /* there is `languageID' to check there.  We should use this */
          /* field only as a last solution when nothing else is        */
          /* available.                                                */
          /*                                                           */
          found_unicode = n;
          break;

        case TT_PLATFORM_MACINTOSH:
          /* This is a bit special because some fonts will use either    */
          /* an English language id, or a Roman encoding id, to indicate */
          /* the English version of its font name.                       */
          /*                                                             */
          if ( rec->languageID == TT_MAC_LANGID_ENGLISH )
            found_apple_english = n;
          else if ( rec->encodingID == TT_MAC_ID_ROMAN )
            found_apple_roman = n;
          break;

        case TT_PLATFORM_MICROSOFT:
          /* we only take a non-English name when there is nothing */
          /* else available in the font                            */
          /*                                                       */
          if ( found_win == -1 || ( rec->languageID & 0x3FF ) == 0x009 )
          {
            switch ( rec->encodingID )
            {
            case TT_MS_ID_SYMBOL_CS:
            case TT_MS_ID_UNICODE_CS:
            case TT_MS_ID_UCS_4:
              is_english = FT_BOOL( ( rec->languageID & 0x3FF ) == 0x009 );
              found_win  = n;
              break;

            default:
              ;
            }
    typedef struct  TEncoding_
    {
      int          platform_id;
      int          encoding_id;
      FT_Encoding  encoding;

    } TEncoding;
#undef  FT_STRUCTURE
#define FT_STRUCTURE  TTC_HeaderRec
#ifdef TT_CONFIG_OPTION_GX_VAR_SUPPORT
#endif
#ifdef TT_CONFIG_OPTION_GX_VAR_SUPPORT
#endif
#define LOAD_( x )                                          \
#define LOADM_( x, vertical )                               \
#define GET_NAME( id, field )                                   \
#ifdef TT_CONFIG_OPTION_POSTSCRIPT_NAMES
#endif
#ifdef FT_CONFIG_OPTION_INCREMENTAL
#else
#endif
#ifdef TT_CONFIG_OPTION_POSTSCRIPT_NAMES
#endif
#ifdef FT_CONFIG_OPTION_INCREMENTAL
#endif
#ifdef FT_CONFIG_OPTION_INCREMENTAL
#endif
#ifdef TT_CONFIG_OPTION_POSTSCRIPT_NAMES
#endif
#ifdef TT_CONFIG_OPTION_GX_VAR_SUPPORT
#endif
#ifdef FT_CONFIG_OPTION_POSTSCRIPT_NAMES
#endif
#ifdef FT_CONFIG_OPTION_POSTSCRIPT_NAMES
#endif /* FT_CONFIG_OPTION_POSTSCRIPT_NAMES */
#ifdef TT_CONFIG_OPTION_EMBEDDED_BITMAPS
#endif /* TT_CONFIG_OPTION_EMBEDDED_BITMAPS */
#undef LOAD_
#undef LOADM_
#undef GET_NAME
#ifdef TT_CONFIG_OPTION_BDF
#endif
#ifdef TT_CONFIG_OPTION_GX_VAR_SUPPORT
#endif
