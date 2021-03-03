#include "cdjpeg.h"		/* Common decls for cjpeg/djpeg applications */
#ifdef RLE_SUPPORTED
#include <rle.h>
#if BITS_IN_JSAMPLE != 8
#endif
typedef enum
  { GRAYSCALE, MAPPEDGRAY, PSEUDOCOLOR, TRUECOLOR, DIRECTCOLOR } rle_kind;
typedef struct _rle_source_struct * rle_source_ptr;

typedef struct _rle_source_struct {
  struct cjpeg_source_struct pub; /* public fields */

  rle_kind visual;              /* actual type of input file */
  jvirt_sarray_ptr image;       /* virtual array to hold the image */
  JDIMENSION row;		/* current row # in the virtual array */
  rle_hdr header;               /* Input file information */
  rle_pixel **rle_row;          /* holds a row returned by rle_getrow() */

} rle_source_struct;
#ifdef PROGRESS_REPORT
#endif
#ifdef PROGRESS_REPORT
#endif
#ifdef PROGRESS_REPORT
#endif
#ifdef PROGRESS_REPORT
#endif
#ifdef PROGRESS_REPORT
#endif
#ifdef PROGRESS_REPORT
#endif
#ifdef PROGRESS_REPORT
#endif
#ifdef PROGRESS_REPORT
#endif
#endif /* RLE_SUPPORTED */
