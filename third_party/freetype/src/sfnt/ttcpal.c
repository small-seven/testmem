#include <ft2build.h>
#include FT_INTERNAL_DEBUG_H
#include FT_INTERNAL_STREAM_H
#include FT_TRUETYPE_TAGS_H
#include FT_COLOR_H
#ifdef TT_CONFIG_OPTION_COLOR_LAYERS
#include "ttcpal.h"
#define CPAL_V0_HEADER_BASE_SIZE  12
#define COLOR_SIZE                 4
  typedef struct Cpal_
  {
    FT_UShort  version;        /* Table version number (0 or 1 supported). */
    FT_UShort  num_colors;               /* Total number of color records, */
                                         /* combined for all palettes.     */
    FT_Byte*  colors;                              /* RGBA array of colors */
    FT_Byte*  color_indices; /* Index of each palette's first color record */
                             /* in the combined color record array.        */

    /* The memory which backs up the `CPAL' table. */
    void*     table;
    FT_ULong  table_size;

  } Cpal;
#undef  FT_COMPONENT
#define FT_COMPONENT  ttcpal
#else /* !TT_CONFIG_OPTION_COLOR_LAYERS */
