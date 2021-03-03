#define JPEG_INTERNALS
#include "jinclude.h"
#include "jpeglib.h"
#ifndef D_PROGRESSIVE_SUPPORTED
#undef BLOCK_SMOOTHING_SUPPORTED
#endif
typedef struct {
  struct jpeg_d_coef_controller pub; /* public fields */

  /* These variables keep track of the current location of the input side. */
  /* cinfo->input_iMCU_row is also used for this. */
  JDIMENSION MCU_ctr;		/* counts MCUs processed in current row */
  int MCU_vert_offset;		/* counts MCU rows within iMCU row */
  int MCU_rows_per_iMCU_row;	/* number of such rows needed */

  /* The output side's location is represented by cinfo->output_iMCU_row. */

  /* In single-pass modes, it's sufficient to buffer just one MCU.
   * We allocate a workspace of D_MAX_BLOCKS_IN_MCU coefficient blocks,
   * and let the entropy decoder write into that workspace each time.
   * (On 80x86, the workspace is FAR even though it's not really very big;
   * this is to keep the module interfaces unchanged when a large coefficient
   * buffer is necessary.)
   * In multi-pass modes, this array points to the current MCU's blocks
   * within the virtual arrays; it is used only by the input side.
   */
  JBLOCKROW MCU_buffer[D_MAX_BLOCKS_IN_MCU];

#ifdef D_MULTISCAN_FILES_SUPPORTED
  /* In multi-pass modes, we need a virtual block array for each component. */
  jvirt_barray_ptr whole_image[MAX_COMPONENTS];
#endif

#ifdef BLOCK_SMOOTHING_SUPPORTED
  /* When doing block smoothing, we latch coefficient Al values here */
  int * coef_bits_latch;
#define SAVED_COEFS  6		/* we save coef_bits[0..5] */
#endif
} my_coef_controller;
typedef my_coef_controller * my_coef_ptr;

/* Forward declarations */
METHODDEF(int) decompress_onepass
	JPP((j_decompress_ptr cinfo, JSAMPIMAGE output_buf));
#ifdef D_MULTISCAN_FILES_SUPPORTED
METHODDEF(int) decompress_data
	JPP((j_decompress_ptr cinfo, JSAMPIMAGE output_buf));
#endif
#ifdef BLOCK_SMOOTHING_SUPPORTED
LOCAL(boolean) smoothing_ok JPP((j_decompress_ptr cinfo));
METHODDEF(int) decompress_smooth_data
	JPP((j_decompress_ptr cinfo, JSAMPIMAGE output_buf));
#endif


LOCAL(void)
start_iMCU_row (j_decompress_ptr cinfo)
/* Reset within-iMCU-row counters for a new row (input side) */
{
  my_coef_ptr coef = (my_coef_ptr) cinfo->coef;

  /* In an interleaved scan, an MCU row is the same as an iMCU row.
   * In a noninterleaved scan, an iMCU row has v_samp_factor MCU rows.
   * But at the bottom of the image, process only what's left.
   */
  if (cinfo->comps_in_scan > 1) {
    coef->MCU_rows_per_iMCU_row = 1;
  } else {
#ifdef BLOCK_SMOOTHING_SUPPORTED
#endif
#ifdef D_MULTISCAN_FILES_SUPPORTED
#endif /* D_MULTISCAN_FILES_SUPPORTED */
#ifdef BLOCK_SMOOTHING_SUPPORTED
#define Q01_POS  1
#define Q10_POS  8
#define Q20_POS  16
#define Q11_POS  9
#define Q02_POS  2
#endif /* BLOCK_SMOOTHING_SUPPORTED */
#ifdef BLOCK_SMOOTHING_SUPPORTED
#endif
#ifdef D_MULTISCAN_FILES_SUPPORTED
#ifdef BLOCK_SMOOTHING_SUPPORTED
#endif
#else
#endif
