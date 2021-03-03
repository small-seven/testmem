#define JPEG_INTERNALS
#include "jinclude.h"
#include "jpeglib.h"
#ifdef INPUT_SMOOTHING_SUPPORTED
#define CONTEXT_ROWS_SUPPORTED
#endif
typedef struct {
  struct jpeg_c_prep_controller pub; /* public fields */

  /* Downsampling input buffer.  This buffer holds color-converted data
   * until we have enough to do a downsample step.
   */
  JSAMPARRAY color_buf[MAX_COMPONENTS];

  JDIMENSION rows_to_go;	/* counts rows remaining in source image */
  int next_buf_row;		/* index of next row to store in color_buf */

#ifdef CONTEXT_ROWS_SUPPORTED	/* only needed for context case */
  int this_row_group;		/* starting row index of group to process */
  int next_buf_stop;		/* downsample when we reach this index */
#endif
} my_prep_controller;
typedef my_prep_controller * my_prep_ptr;


/*
 * Initialize for a processing pass.
 */

METHODDEF(void)
start_pass_prep (j_compress_ptr cinfo, J_BUF_MODE pass_mode)
{
  my_prep_ptr prep = (my_prep_ptr) cinfo->prep;

  if (pass_mode != JBUF_PASS_THRU)
    ERREXIT(cinfo, JERR_BAD_BUFFER_MODE);

  /* Initialize total-height counter for detecting bottom of image */
  prep->rows_to_go = cinfo->image_height;
  /* Mark the conversion buffer empty */
  prep->next_buf_row = 0;
#ifdef CONTEXT_ROWS_SUPPORTED
  /* Preset additional state variables for context mode.
   * These aren't used in non-context mode, so we needn't test which mode.
   */
  prep->this_row_group = 0;
  /* Set next_buf_stop to stop after two row groups have been read in. */
  prep->next_buf_stop = 2 * cinfo->max_v_samp_factor;
#endif
}
#ifdef CONTEXT_ROWS_SUPPORTED
#endif /* CONTEXT_ROWS_SUPPORTED */
#ifdef CONTEXT_ROWS_SUPPORTED
#else
#endif
