#define JPEG_INTERNALS
#include "jinclude.h"
#include "jpeglib.h"
typedef struct {
  struct jpeg_input_controller pub; /* public fields */

  int inheaders;		/* Nonzero until first SOS is reached */
} my_input_controller;
typedef my_input_controller * my_inputctl_ptr;


/* Forward declarations */
METHODDEF(int) consume_markers JPP((j_decompress_ptr cinfo));


/*
 * Routines to calculate various quantities related to the size of the image.
 */


/*
 * Compute output image dimensions and related values.
 * NOTE: this is exported for possible use by application.
 * Hence it mustn't do anything that can't be done twice.
 */

GLOBAL(void)
jpeg_core_output_dimensions (j_decompress_ptr cinfo)
/* Do computations that are needed before master selection phase.
 * This function is used for transcoding and full decompression.
 */
{
#ifdef IDCT_SCALING_SUPPORTED
  int ci;
  jpeg_component_info *compptr;

  /* Compute actual output image dimensions and DCT scaling choices. */
  if (cinfo->scale_num * cinfo->block_size <= cinfo->scale_denom) {
    /* Provide 1/block_size scaling */
    cinfo->output_width = (JDIMENSION)
      jdiv_round_up((long) cinfo->image_width, (long) cinfo->block_size);
    cinfo->output_height = (JDIMENSION)
      jdiv_round_up((long) cinfo->image_height, (long) cinfo->block_size);
    cinfo->min_DCT_h_scaled_size = 1;
    cinfo->min_DCT_v_scaled_size = 1;
  } else if (cinfo->scale_num * cinfo->block_size <= cinfo->scale_denom * 2) {
#else /* !IDCT_SCALING_SUPPORTED */
#endif /* IDCT_SCALING_SUPPORTED */
