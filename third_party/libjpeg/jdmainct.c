#define JPEG_INTERNALS
#include "jinclude.h"
#include "jpeglib.h"
typedef struct {
  struct jpeg_d_main_controller pub; /* public fields */

  /* Pointer to allocated workspace (M or M+2 row groups). */
  JSAMPARRAY buffer[MAX_COMPONENTS];

  JDIMENSION rowgroup_ctr;	/* counts row groups output to postprocessor */
  JDIMENSION rowgroups_avail;	/* row groups available to postprocessor */

  /* Remaining fields are only used in the context case. */

  boolean buffer_full;		/* Have we gotten an iMCU row from decoder? */

  /* These are the master pointers to the funny-order pointer lists. */
  JSAMPIMAGE xbuffer[2];	/* pointers to weird pointer lists */

  int whichptr;			/* indicates which pointer set is now in use */
  int context_state;		/* process_data state machine status */
  JDIMENSION iMCU_row_ctr;	/* counts iMCU rows to detect image top/bot */
} my_main_controller;
typedef my_main_controller * my_main_ptr;

/* context_state values: */
#define CTX_PREPARE_FOR_IMCU	0	/* need to prepare for MCU row */
#define CTX_PROCESS_IMCU	1	/* feeding iMCU to postprocessor */
#define CTX_POSTPONED_ROW	2	/* feeding postponed row group */


/* Forward declarations */
METHODDEF(void) process_data_simple_main
	JPP((j_decompress_ptr cinfo, JSAMPARRAY output_buf,
	     JDIMENSION *out_row_ctr, JDIMENSION out_rows_avail));
METHODDEF(void) process_data_context_main
	JPP((j_decompress_ptr cinfo, JSAMPARRAY output_buf,
	     JDIMENSION *out_row_ctr, JDIMENSION out_rows_avail));
#ifdef QUANT_2PASS_SUPPORTED
METHODDEF(void) process_data_crank_post
	JPP((j_decompress_ptr cinfo, JSAMPARRAY output_buf,
	     JDIMENSION *out_row_ctr, JDIMENSION out_rows_avail));
#endif


LOCAL(void)
alloc_funny_pointers (j_decompress_ptr cinfo)
/* Allocate space for the funny pointer lists.
 * This is done only once, not once per pass.
 */
{
  my_main_ptr mainp = (my_main_ptr) cinfo->main;
  int ci, rgroup;
  int M = cinfo->min_DCT_v_scaled_size;
  jpeg_component_info *compptr;
  JSAMPARRAY xbuf;

  /* Get top-level space for component array pointers.
   * We alloc both arrays with one call to save a few cycles.
   */
  mainp->xbuffer[0] = (JSAMPIMAGE)
    (*cinfo->mem->alloc_small) ((j_common_ptr) cinfo, JPOOL_IMAGE,
				cinfo->num_components * 2 * SIZEOF(JSAMPARRAY));
  mainp->xbuffer[1] = mainp->xbuffer[0] + cinfo->num_components;

  for (ci = 0, compptr = cinfo->comp_info; ci < cinfo->num_components;
       ci++, compptr++) {
    rgroup = (compptr->v_samp_factor * compptr->DCT_v_scaled_size) /
      cinfo->min_DCT_v_scaled_size; /* height of a row group of component */
    /* Get space for pointer lists --- M+4 row groups in each list.
     * We alloc both pointer lists with one call to save a few cycles.
     */
    xbuf = (JSAMPARRAY)
      (*cinfo->mem->alloc_small) ((j_common_ptr) cinfo, JPOOL_IMAGE,
				  2 * (rgroup * (M + 4)) * SIZEOF(JSAMPROW));
    xbuf += rgroup;		/* want one row group at negative offsets */
    mainp->xbuffer[0][ci] = xbuf;
    xbuf += rgroup * (M + 4);
    mainp->xbuffer[1][ci] = xbuf;
  }
#ifdef QUANT_2PASS_SUPPORTED
#endif
#ifdef QUANT_2PASS_SUPPORTED
#endif /* QUANT_2PASS_SUPPORTED */
