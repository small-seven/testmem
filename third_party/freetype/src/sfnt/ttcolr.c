#include <ft2build.h>
#include FT_INTERNAL_DEBUG_H
#include FT_INTERNAL_STREAM_H
#include FT_TRUETYPE_TAGS_H
#include FT_COLOR_H
#ifdef TT_CONFIG_OPTION_COLOR_LAYERS
#include "ttcolr.h"
#define BASE_GLYPH_SIZE            6
#define LAYER_SIZE                 4
#define COLR_HEADER_SIZE          14
  typedef struct BaseGlyphRecord_
  {
    FT_UShort  gid;
    FT_UShort  first_layer_index;
    FT_UShort  num_layers;

  } BaseGlyphRecord;
  typedef struct Colr_
  {
    FT_UShort  version;
    FT_UShort  num_base_glyphs;
    FT_UShort  num_layers;

    FT_Byte*  base_glyphs;
    FT_Byte*  layers;

    /* The memory which backs up the `COLR' table. */
    void*     table;
    FT_ULong  table_size;

  } Colr;
#undef  FT_COMPONENT
#define FT_COMPONENT  ttcolr
#else /* !TT_CONFIG_OPTION_COLOR_LAYERS */
