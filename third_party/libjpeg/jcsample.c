#define JPEG_INTERNALS
#include "jinclude.h"
#include "jpeglib.h"
typedef JMETHOD(void, downsample1_ptr,
		(j_compress_ptr cinfo, jpeg_component_info * compptr,
		 JSAMPARRAY input_data, JSAMPARRAY output_data));

/* Private subobject */

typedef struct {
  struct jpeg_downsampler pub;	/* public fields */

  /* Downsampling method pointers, one per component */
  downsample1_ptr methods[MAX_COMPONENTS];

  /* Height of an output row group for each component. */
  int rowgroup_height[MAX_COMPONENTS];

  /* These arrays save pixel expansion factors so that int_downsample need not
   * recompute them each time.  They are unused for other downsampling methods.
   */
  UINT8 h_expand[MAX_COMPONENTS];
  UINT8 v_expand[MAX_COMPONENTS];
} my_downsampler;
typedef my_downsampler * my_downsample_ptr;


/*
 * Initialize for a downsampling pass.
 */

METHODDEF(void)
start_pass_downsample (j_compress_ptr cinfo)
{
  /* no work for now */
}
#ifdef INPUT_SMOOTHING_SUPPORTED
#endif /* INPUT_SMOOTHING_SUPPORTED */
#ifdef INPUT_SMOOTHING_SUPPORTED
#endif
#ifdef INPUT_SMOOTHING_SUPPORTED
#endif
#ifdef INPUT_SMOOTHING_SUPPORTED
#endif
