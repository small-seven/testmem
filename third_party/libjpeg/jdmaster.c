#define JPEG_INTERNALS
#include "jinclude.h"
#include "jpeglib.h"
typedef struct {
  struct jpeg_decomp_master pub; /* public fields */

  int pass_number;		/* # of passes completed */

  boolean using_merged_upsample; /* TRUE if using merged upsample/cconvert */

  /* Saved references to initialized quantizer modules,
   * in case we need to switch modes.
   */
  struct jpeg_color_quantizer * quantizer_1pass;
  struct jpeg_color_quantizer * quantizer_2pass;
} my_decomp_master;
typedef my_decomp_master * my_master_ptr;


/*
 * Determine whether merged upsample/color conversion should be used.
 * CRUCIAL: this must match the actual capabilities of jdmerge.c!
 */

LOCAL(boolean)
use_merged_upsample (j_decompress_ptr cinfo)
{
#ifdef UPSAMPLE_MERGING_SUPPORTED
  /* Merging is the equivalent of plain box-filter upsampling. */
  /* The following condition is only needed if fancy shall select
   * a different upsampling method.  In our current implementation
   * fancy only affects the DCT scaling, thus we can use fancy
   * upsampling and merged upsample simultaneously, in particular
   * with scaled DCT sizes larger than the default DCTSIZE.
   */
#if 0
  if (cinfo->do_fancy_upsampling)
    return FALSE;
#endif
  if (cinfo->CCIR601_sampling)
    return FALSE;
  /* jdmerge.c only supports YCC=>RGB color conversion */
  if ((cinfo->jpeg_color_space != JCS_YCbCr &&
       cinfo->jpeg_color_space != JCS_BG_YCC) ||
      cinfo->num_components != 3 ||
      cinfo->out_color_space != JCS_RGB ||
      cinfo->out_color_components != RGB_PIXELSIZE ||
      cinfo->color_transform)
    return FALSE;
  /* and it only handles 2h1v or 2h2v sampling ratios */
  if (cinfo->comp_info[0].h_samp_factor != 2 ||
      cinfo->comp_info[1].h_samp_factor != 1 ||
      cinfo->comp_info[2].h_samp_factor != 1 ||
      cinfo->comp_info[0].v_samp_factor >  2 ||
      cinfo->comp_info[1].v_samp_factor != 1 ||
      cinfo->comp_info[2].v_samp_factor != 1)
    return FALSE;
  /* furthermore, it doesn't work if we've scaled the IDCTs differently */
  if (cinfo->comp_info[0].DCT_h_scaled_size != cinfo->min_DCT_h_scaled_size ||
      cinfo->comp_info[1].DCT_h_scaled_size != cinfo->min_DCT_h_scaled_size ||
      cinfo->comp_info[2].DCT_h_scaled_size != cinfo->min_DCT_h_scaled_size ||
      cinfo->comp_info[0].DCT_v_scaled_size != cinfo->min_DCT_v_scaled_size ||
      cinfo->comp_info[1].DCT_v_scaled_size != cinfo->min_DCT_v_scaled_size ||
      cinfo->comp_info[2].DCT_v_scaled_size != cinfo->min_DCT_v_scaled_size)
    return FALSE;
  /* ??? also need to test for upsample-time rescaling, when & if supported */
  return TRUE;			/* by golly, it'll work... */
#else
  return FALSE;
#endif
}
#ifdef IDCT_SCALING_SUPPORTED
#endif
#ifdef IDCT_SCALING_SUPPORTED
#endif /* IDCT_SCALING_SUPPORTED */
#if RGB_PIXELSIZE != 3
#endif /* else share code with YCbCr */
#ifdef QUANT_1PASS_SUPPORTED
#else
#endif
#ifdef QUANT_2PASS_SUPPORTED
#else
#endif
#ifdef UPSAMPLE_MERGING_SUPPORTED
#else
#endif
#ifdef D_MULTISCAN_FILES_SUPPORTED
#endif /* D_MULTISCAN_FILES_SUPPORTED */
#ifdef QUANT_2PASS_SUPPORTED
#else
#endif /* QUANT_2PASS_SUPPORTED */
#ifdef D_MULTISCAN_FILES_SUPPORTED
#endif /* D_MULTISCAN_FILES_SUPPORTED */
