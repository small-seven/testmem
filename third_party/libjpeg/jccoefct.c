#define JPEG_INTERNALS
#include "jinclude.h"
#include "jpeglib.h"
#ifdef ENTROPY_OPT_SUPPORTED
#define FULL_COEF_BUFFER_SUPPORTED
#else
#ifdef C_MULTISCAN_FILES_SUPPORTED
#define FULL_COEF_BUFFER_SUPPORTED
#endif
#endif
typedef struct {
  struct jpeg_c_coef_controller pub; /* public fields */

  JDIMENSION iMCU_row_num;	/* iMCU row # within image */
  JDIMENSION mcu_ctr;		/* counts MCUs processed in current row */
  int MCU_vert_offset;		/* counts MCU rows within iMCU row */
  int MCU_rows_per_iMCU_row;	/* number of such rows needed */

  /* For single-pass compression, it's sufficient to buffer just one MCU
   * (although this may prove a bit slow in practice).  We allocate a
   * workspace of C_MAX_BLOCKS_IN_MCU coefficient blocks, and reuse it for each
   * MCU constructed and sent.  (On 80x86, the workspace is FAR even though
   * it's not really very big; this is to keep the module interfaces unchanged
   * when a large coefficient buffer is necessary.)
   * In multi-pass modes, this array points to the current MCU's blocks
   * within the virtual arrays.
   */
  JBLOCKROW MCU_buffer[C_MAX_BLOCKS_IN_MCU];

  /* In multi-pass modes, we need a virtual block array for each component. */
  jvirt_barray_ptr whole_image[MAX_COMPONENTS];
} my_coef_controller;
typedef my_coef_controller * my_coef_ptr;


/* Forward declarations */
METHODDEF(boolean) compress_data
    JPP((j_compress_ptr cinfo, JSAMPIMAGE input_buf));
#ifdef FULL_COEF_BUFFER_SUPPORTED
METHODDEF(boolean) compress_first_pass
    JPP((j_compress_ptr cinfo, JSAMPIMAGE input_buf));
METHODDEF(boolean) compress_output
    JPP((j_compress_ptr cinfo, JSAMPIMAGE input_buf));
#endif


LOCAL(void)
start_iMCU_row (j_compress_ptr cinfo)
/* Reset within-iMCU-row counters for a new row */
{
  my_coef_ptr coef = (my_coef_ptr) cinfo->coef;

  /* In an interleaved scan, an MCU row is the same as an iMCU row.
   * In a noninterleaved scan, an iMCU row has v_samp_factor MCU rows.
   * But at the bottom of the image, process only what's left.
   */
  if (cinfo->comps_in_scan > 1) {
    coef->MCU_rows_per_iMCU_row = 1;
  } else {
#ifdef FULL_COEF_BUFFER_SUPPORTED
#endif
#ifdef FULL_COEF_BUFFER_SUPPORTED
#endif /* FULL_COEF_BUFFER_SUPPORTED */
#ifdef FULL_COEF_BUFFER_SUPPORTED
#else
#endif
