#include "cdjpeg.h"		/* Common decls for cjpeg/djpeg applications */
#ifdef TARGA_SUPPORTED
#if BITS_IN_JSAMPLE != 8
#endif
typedef struct {
  struct djpeg_dest_struct pub;	/* public fields */

  char *iobuffer;		/* physical I/O buffer */
  JDIMENSION buffer_width;	/* width of one row */
} tga_dest_struct;
typedef tga_dest_struct * tga_dest_ptr;


LOCAL(void)
write_header (j_decompress_ptr cinfo, djpeg_dest_ptr dinfo, int num_colors)
/* Create and write a Targa header */
{
  char targaheader[18];

  /* Set unused fields of header to 0 */
  MEMZERO(targaheader, SIZEOF(targaheader));

  if (num_colors > 0) {
    targaheader[1] = 1;		/* color map type 1 */
    targaheader[5] = (char) (num_colors & 0xFF);
    targaheader[6] = (char) (num_colors >> 8);
    targaheader[7] = 24;	/* 24 bits per cmap entry */
  }
#endif /* TARGA_SUPPORTED */
