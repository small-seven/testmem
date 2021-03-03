#include "t42parse.h"
#include "t42error.h"
#include FT_INTERNAL_DEBUG_H
#include FT_INTERNAL_STREAM_H
#include FT_INTERNAL_POSTSCRIPT_AUX_H
#undef  FT_COMPONENT
#define FT_COMPONENT  t42
#undef  FT_STRUCTURE
#define FT_STRUCTURE  T1_FontInfo
#undef  T1CODE
#define T1CODE        T1_FIELD_LOCATION_FONT_INFO
#undef  FT_STRUCTURE
#define FT_STRUCTURE  PS_FontExtraRec
#undef  T1CODE
#define T1CODE        T1_FIELD_LOCATION_FONT_EXTRA
#undef  FT_STRUCTURE
#define FT_STRUCTURE  T1_FontRec
#undef  T1CODE
#define T1CODE        T1_FIELD_LOCATION_FONT_DICT
#undef  FT_STRUCTURE
#define FT_STRUCTURE  FT_BBox
#undef  T1CODE
#define T1CODE        T1_FIELD_LOCATION_BBOX
#define T1_Add_Table( p, i, o, l )  (p)->funcs.add( (p), i, o, l )
#define T1_Release_Table( p )          \
#define T1_Skip_Spaces( p )    (p)->root.funcs.skip_spaces( &(p)->root )
#define T1_Skip_PS_Token( p )  (p)->root.funcs.skip_PS_token( &(p)->root )
#define T1_ToInt( p )                          \
#define T1_ToBytes( p, b, m, n, d )                          \
#define T1_ToFixedArray( p, m, f, t )                           \
#define T1_ToToken( p, t )                          \
#define T1_Load_Field( p, f, o, m, pf )                         \
#define T1_Load_Field_Table( p, f, o, m, pf )                         \
  typedef enum  T42_Load_Status_
  {
    BEFORE_START,
    BEFORE_TABLE_DIR,
    OTHER_TABLES

  } T42_Load_Status;
