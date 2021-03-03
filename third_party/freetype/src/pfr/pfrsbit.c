#include "pfrsbit.h"
#include "pfrload.h"
#include FT_INTERNAL_DEBUG_H
#include FT_INTERNAL_STREAM_H
#include "pfrerror.h"
#undef  FT_COMPONENT
#define FT_COMPONENT  pfr
  typedef struct  PFR_BitWriter_
  {
    FT_Byte*  line;      /* current line start               */
    FT_Int    pitch;     /* line size in bytes               */
    FT_UInt   width;     /* width in pixels/bits             */
    FT_UInt   rows;      /* number of remaining rows to scan */
    FT_UInt   total;     /* total number of bits to draw     */

  } PFR_BitWriterRec, *PFR_BitWriter;
