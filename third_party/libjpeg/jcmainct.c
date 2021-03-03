#define JPEG_INTERNALS
#include "jinclude.h"
#include "jpeglib.h"
#undef FULL_MAIN_BUFFER_SUPPORTED
typedef struct {
  struct jpeg_c_main_controller pub; /* public fields */

  JDIMENSION cur_iMCU_row;	/* number of current iMCU row */
  JDIMENSION rowgroup_ctr;	/* counts row groups received in iMCU row */
  boolean suspended;		/* remember if we suspended output */
  J_BUF_MODE pass_mode;		/* current operating mode */

  /* If using just a strip buffer, this points to the entire set of buffers
   * (we allocate one for each component).  In the full-image case, this
   * points to the currently accessible strips of the virtual arrays.
   */
  JSAMPARRAY buffer[MAX_COMPONENTS];

#ifdef FULL_MAIN_BUFFER_SUPPORTED
  /* If using full-image storage, this array holds pointers to virtual-array
   * control blocks for each component.  Unused if not full-image storage.
   */
  jvirt_sarray_ptr whole_image[MAX_COMPONENTS];
#endif
} my_main_controller;
typedef my_main_controller * my_main_ptr;


/* Forward declarations */
METHODDEF(void) process_data_simple_main
	JPP((j_compress_ptr cinfo, JSAMPARRAY input_buf,
	     JDIMENSION *in_row_ctr, JDIMENSION in_rows_avail));
#ifdef FULL_MAIN_BUFFER_SUPPORTED
METHODDEF(void) process_data_buffer_main
	JPP((j_compress_ptr cinfo, JSAMPARRAY input_buf,
	     JDIMENSION *in_row_ctr, JDIMENSION in_rows_avail));
#endif


/*
 * Initialize for a processing pass.
 */

METHODDEF(void)
start_pass_main (j_compress_ptr cinfo, J_BUF_MODE pass_mode)
{
  my_main_ptr mainp = (my_main_ptr) cinfo->main;

  /* Do nothing in raw-data mode. */
  if (cinfo->raw_data_in)
    return;

  mainp->cur_iMCU_row = 0;	/* initialize counters */
  mainp->rowgroup_ctr = 0;
  mainp->suspended = FALSE;
  mainp->pass_mode = pass_mode;	/* save mode for use by process_data */

  switch (pass_mode) {
  case JBUF_PASS_THRU:
#ifdef FULL_MAIN_BUFFER_SUPPORTED
    if (mainp->whole_image[0] != NULL)
      ERREXIT(cinfo, JERR_BAD_BUFFER_MODE);
#endif
    mainp->pub.process_data = process_data_simple_main;
    break;
#ifdef FULL_MAIN_BUFFER_SUPPORTED
  case JBUF_SAVE_SOURCE:
  case JBUF_CRANK_DEST:
  case JBUF_SAVE_AND_PASS:
    if (mainp->whole_image[0] == NULL)
      ERREXIT(cinfo, JERR_BAD_BUFFER_MODE);
    mainp->pub.process_data = process_data_buffer_main;
    break;
#endif
  default:
    ERREXIT(cinfo, JERR_BAD_BUFFER_MODE);
    break;
  }
#ifdef FULL_MAIN_BUFFER_SUPPORTED
#endif /* FULL_MAIN_BUFFER_SUPPORTED */
#ifdef FULL_MAIN_BUFFER_SUPPORTED
#else
#endif
#ifdef FULL_MAIN_BUFFER_SUPPORTED
#endif
