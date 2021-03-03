#include <ft2build.h>
#include FT_INTERNAL_DEBUG_H
#include "sferrors.h"           /* must come before FT_INTERNAL_VALIDATE_H */
#include FT_INTERNAL_VALIDATE_H
#include FT_INTERNAL_STREAM_H
#include FT_SERVICE_POSTSCRIPT_CMAPS_H
#include "ttload.h"
#include "ttcmap.h"
#include "ttpost.h"
#undef  FT_COMPONENT
#define FT_COMPONENT  ttcmap
#define TT_PEEK_SHORT   FT_PEEK_SHORT
#define TT_PEEK_USHORT  FT_PEEK_USHORT
#define TT_PEEK_UINT24  FT_PEEK_UOFF3
#define TT_PEEK_LONG    FT_PEEK_LONG
#define TT_PEEK_ULONG   FT_PEEK_ULONG
#define TT_NEXT_SHORT   FT_NEXT_SHORT
#define TT_NEXT_USHORT  FT_NEXT_USHORT
#define TT_NEXT_UINT24  FT_NEXT_UOFF3
#define TT_NEXT_LONG    FT_NEXT_LONG
#define TT_NEXT_ULONG   FT_NEXT_ULONG
#ifdef TT_CONFIG_CMAP_FORMAT_0
#endif /* TT_CONFIG_CMAP_FORMAT_0 */
#ifdef TT_CONFIG_CMAP_FORMAT_2
#endif /* TT_CONFIG_CMAP_FORMAT_2 */
#ifdef TT_CONFIG_CMAP_FORMAT_4
  typedef struct  TT_CMap4Rec_
  {
    TT_CMapRec  cmap;
    FT_UInt32   cur_charcode;   /* current charcode */
    FT_UInt     cur_gindex;     /* current glyph index */

    FT_UInt     num_ranges;
    FT_UInt     cur_range;
    FT_UInt     cur_start;
    FT_UInt     cur_end;
    FT_Int      cur_delta;
    FT_Byte*    cur_values;

  } TT_CMap4Rec, *TT_CMap4;
#endif /* TT_CONFIG_CMAP_FORMAT_4 */
#ifdef TT_CONFIG_CMAP_FORMAT_6
#endif /* TT_CONFIG_CMAP_FORMAT_6 */
#ifdef TT_CONFIG_CMAP_FORMAT_8
#endif /* TT_CONFIG_CMAP_FORMAT_8 */
#ifdef TT_CONFIG_CMAP_FORMAT_10
#endif /* TT_CONFIG_CMAP_FORMAT_10 */
#ifdef TT_CONFIG_CMAP_FORMAT_12
  typedef struct  TT_CMap12Rec_
  {
    TT_CMapRec  cmap;
    FT_Bool     valid;
    FT_ULong    cur_charcode;
    FT_UInt     cur_gindex;
    FT_ULong    cur_group;
    FT_ULong    num_groups;

  } TT_CMap12Rec, *TT_CMap12;
#endif /* TT_CONFIG_CMAP_FORMAT_12 */
#ifdef TT_CONFIG_CMAP_FORMAT_13
  typedef struct  TT_CMap13Rec_
  {
    TT_CMapRec  cmap;
    FT_Bool     valid;
    FT_ULong    cur_charcode;
    FT_UInt     cur_gindex;
    FT_ULong    cur_group;
    FT_ULong    num_groups;

  } TT_CMap13Rec, *TT_CMap13;
#endif /* TT_CONFIG_CMAP_FORMAT_13 */
#ifdef TT_CONFIG_CMAP_FORMAT_14
  typedef struct  TT_CMap14Rec_
  {
    TT_CMapRec  cmap;
    FT_ULong    num_selectors;

    /* This array is used to store the results of various
     * cmap 14 query functions.  The data is overwritten
     * on each call to these functions.
     */
    FT_UInt32   max_results;
    FT_UInt32*  results;
    FT_Memory   memory;

  } TT_CMap14Rec, *TT_CMap14;
#endif /* TT_CONFIG_CMAP_FORMAT_14 */
#ifdef FT_CONFIG_OPTION_POSTSCRIPT_NAMES
#endif /* FT_CONFIG_OPTION_POSTSCRIPT_NAMES */
#define TTCMAPCITEM( a )  &a,
#include "ttcmapc.h"
