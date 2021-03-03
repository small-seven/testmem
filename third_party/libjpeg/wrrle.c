#include "cdjpeg.h"		/* Common decls for cjpeg/djpeg applications */
#ifdef RLE_SUPPORTED
#include <rle.h>
#if BITS_IN_JSAMPLE != 8
#endif
#define CMAPBITS	8
#define CMAPLENGTH	(1<<(CMAPBITS))
typedef struct {
  struct djpeg_dest_struct pub; /* public fields */

  jvirt_sarray_ptr image;	/* virtual array to store the output image */
  rle_map *colormap;	 	/* RLE-style color map, or NULL if none */
  rle_pixel **rle_row;		/* To pass rows to rle_putrow() */

} rle_dest_struct;
typedef rle_dest_struct * rle_dest_ptr;


/* Forward declarations */
METHODDEF(void) rle_put_pixel_rows
    JPP((j_decompress_ptr cinfo, djpeg_dest_ptr dinfo,
	 JDIMENSION rows_supplied));


/*
 * Write the file header.
 *
 * In this module it's easier to wait till finish_output to write anything.
 */

METHODDEF(void)
start_output_rle (j_decompress_ptr cinfo, djpeg_dest_ptr dinfo)
{
  rle_dest_ptr dest = (rle_dest_ptr) dinfo;
  size_t cmapsize;
  int ci, i;
#ifdef PROGRESS_REPORT
  cd_progress_ptr progress = (cd_progress_ptr) cinfo->progress;
#endif

  /*
   * Make sure the image can be stored in RLE format.
   *
   * - RLE stores image dimensions as *signed* 16 bit integers.  JPEG
   *   uses unsigned, so we have to check the width.
   *
   * - Colorspace is expected to be grayscale or RGB.
   *
   * - The number of channels (components) is expected to be 1 (grayscale/
   *   pseudocolor) or 3 (truecolor/directcolor).
   *   (could be 2 or 4 if using an alpha channel, but we aren't)
   */

  if (cinfo->output_width > 32767 || cinfo->output_height > 32767)
    ERREXIT2(cinfo, JERR_RLE_DIMENSIONS, cinfo->output_width, 
	     cinfo->output_height);

  if (cinfo->out_color_space != JCS_GRAYSCALE &&
      cinfo->out_color_space != JCS_RGB)
    ERREXIT(cinfo, JERR_RLE_COLORSPACE);

  if (cinfo->output_components != 1 && cinfo->output_components != 3)
    ERREXIT1(cinfo, JERR_RLE_TOOMANYCHANNELS, cinfo->num_components);

  /* Convert colormap, if any, to RLE format. */

  dest->colormap = NULL;

  if (cinfo->quantize_colors) {
    /* Allocate storage for RLE-style cmap, zero any extra entries */
    cmapsize = cinfo->out_color_components * CMAPLENGTH * SIZEOF(rle_map);
    dest->colormap = (rle_map *) (*cinfo->mem->alloc_small)
      ((j_common_ptr) cinfo, JPOOL_IMAGE, cmapsize);
    MEMZERO(dest->colormap, cmapsize);

    /* Save away data in RLE format --- note 8-bit left shift! */
    /* Shifting would need adjustment for JSAMPLEs wider than 8 bits. */
    for (ci = 0; ci < cinfo->out_color_components; ci++) {
      for (i = 0; i < cinfo->actual_number_of_colors; i++) {
	dest->colormap[ci * CMAPLENGTH + i] =
	  GETJSAMPLE(cinfo->colormap[ci][i]) << 8;
      }
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
