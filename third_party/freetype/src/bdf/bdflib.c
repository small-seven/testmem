#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_INTERNAL_DEBUG_H
#include FT_INTERNAL_STREAM_H
#include FT_INTERNAL_OBJECTS_H
#include "bdf.h"
#include "bdferror.h"
#undef  FT_COMPONENT
#define FT_COMPONENT  bdflib
#define _bdf_strncmp( name, property, n )      \
#define ACMSG1   "FONT_ASCENT property missing.  " \
#define ACMSG2   "FONT_DESCENT property missing.  " \
#define ACMSG3   "Font width != actual width.  Old: %hd New: %hd.\n"
#define ACMSG4   "Font left bearing != actual left bearing.  " \
#define ACMSG5   "Font ascent != actual ascent.  Old: %hd New: %hd.\n"
#define ACMSG6   "Font descent != actual descent.  Old: %hd New: %hd.\n"
#define ACMSG7   "Font height != actual height. Old: %hd New: %hd.\n"
#define ACMSG8   "Glyph scalable width (SWIDTH) adjustments made.\n"
#define ACMSG9   "SWIDTH field missing at line %ld.  Set automatically.\n"
#define ACMSG10  "DWIDTH field missing at line %ld.  Set to glyph width.\n"
#define ACMSG11  "SIZE bits per pixel field adjusted to %hd.\n"
#define ACMSG13  "Glyph %lu extra rows removed.\n"
#define ACMSG14  "Glyph %lu extra columns removed.\n"
#define ACMSG15  "Incorrect glyph count: %ld indicated but %ld found.\n"
#define ACMSG16  "Glyph %lu missing columns padded with zero bits.\n"
#define ACMSG17  "Adjusting number of glyphs to %ld.\n"
#define ERRMSG1  "[line %ld] Missing `%s' line.\n"
#define ERRMSG2  "[line %ld] Font header corrupted or missing fields.\n"
#define ERRMSG3  "[line %ld] Font glyphs corrupted or missing fields.\n"
#define ERRMSG4  "[line %ld] BBX too big.\n"
#define ERRMSG5  "[line %ld] `%s' value too big.\n"
#define ERRMSG6  "[line %ld] Input line too long.\n"
#define ERRMSG7  "[line %ld] Font name too long.\n"
#define ERRMSG8  "[line %ld] Invalid `%s' value.\n"
#define ERRMSG9  "[line %ld] Invalid keyword.\n"
#define DBGMSG1  "  [%6ld] %s" /* no \n */
#define DBGMSG2  " (0x%lX)\n"
  typedef FT_Error
  (*_bdf_line_func_t)( char*          line,
                       unsigned long  linelen,
                       unsigned long  lineno,
                       void*          call_data,
                       void*          client_data );


  /* List structure for splitting lines into fields. */

  typedef struct  _bdf_list_t_
  {
    char**         field;
    unsigned long  size;
    unsigned long  used;
    FT_Memory      memory;

  } _bdf_list_t;
  typedef struct  _bdf_parse_t_
  {
    unsigned long   flags;
    unsigned long   cnt;
    unsigned long   row;

    short           minlb;
    short           maxlb;
    short           maxrb;
    short           maxas;
    short           maxds;

    short           rbearing;

    char*           glyph_name;
    long            glyph_enc;

    bdf_font_t*     font;
    bdf_options_t*  opts;

    _bdf_list_t     list;

    FT_Memory       memory;
    unsigned long   size;        /* the stream size */

  } _bdf_parse_t;
#define setsbit( m, cc ) \
#define sbitset( m, cc ) \
#define NO_SKIP  256  /* this value cannot be stored in a 'char' */
#define BDF_START_      0x0001U
#define BDF_FONT_NAME_  0x0002U
#define BDF_SIZE_       0x0004U
#define BDF_FONT_BBX_   0x0008U
#define BDF_PROPS_      0x0010U
#define BDF_GLYPHS_     0x0020U
#define BDF_GLYPH_      0x0040U
#define BDF_ENCODING_   0x0080U
#define BDF_SWIDTH_     0x0100U
#define BDF_DWIDTH_     0x0200U
#define BDF_BBX_        0x0400U
#define BDF_BITMAP_     0x0800U
#define BDF_SWIDTH_ADJ_  0x1000U
#define BDF_GLYPH_BITS_ ( BDF_GLYPH_    | \
#define BDF_GLYPH_WIDTH_CHECK_   0x40000000UL
#define BDF_GLYPH_HEIGHT_CHECK_  0x80000000UL
