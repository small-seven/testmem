#define JPEG_INTERNALS
#include "jinclude.h"
#include "jpeglib.h"
typedef enum {
	main_pass,		/* input data, also do first output step */
	huff_opt_pass,		/* Huffman code optimization pass */
	output_pass		/* data output pass */
} c_pass_type;
typedef struct {
  struct jpeg_comp_master pub;	/* public fields */

  c_pass_type pass_type;	/* the type of the current pass */

  int pass_number;		/* # of passes completed */
  int total_passes;		/* total # of passes needed */

  int scan_number;		/* current index in scan_info[] */
} my_comp_master;
typedef my_comp_master * my_master_ptr;


/*
 * Support routines that do various essential calculations.
 */

LOCAL(void)
initial_setup (j_compress_ptr cinfo)
/* Do computations that are needed before master selection phase */
{
  int ci, ssize;
  jpeg_component_info *compptr;

  /* Sanity check on block_size */
  if (cinfo->block_size < 1 || cinfo->block_size > 16)
    ERREXIT2(cinfo, JERR_BAD_DCTSIZE, cinfo->block_size, cinfo->block_size);

  /* Derive natural_order from block_size */
  switch (cinfo->block_size) {
  case 2: cinfo->natural_order = jpeg_natural_order2; break;
  case 3: cinfo->natural_order = jpeg_natural_order3; break;
  case 4: cinfo->natural_order = jpeg_natural_order4; break;
  case 5: cinfo->natural_order = jpeg_natural_order5; break;
  case 6: cinfo->natural_order = jpeg_natural_order6; break;
  case 7: cinfo->natural_order = jpeg_natural_order7; break;
  default: cinfo->natural_order = jpeg_natural_order;
  }
#ifdef DCT_SCALING_SUPPORTED
#endif
#ifdef DCT_SCALING_SUPPORTED
#endif
#ifdef C_MULTISCAN_FILES_SUPPORTED
#ifdef C_PROGRESSIVE_SUPPORTED
#endif
#ifdef C_PROGRESSIVE_SUPPORTED
#else
#endif
#ifdef C_PROGRESSIVE_SUPPORTED
#endif
#ifdef C_PROGRESSIVE_SUPPORTED
#endif
#endif /* C_MULTISCAN_FILES_SUPPORTED */
#ifdef C_MULTISCAN_FILES_SUPPORTED
#endif
#ifdef ENTROPY_OPT_SUPPORTED
#endif
#ifdef C_MULTISCAN_FILES_SUPPORTED
#else
#endif
