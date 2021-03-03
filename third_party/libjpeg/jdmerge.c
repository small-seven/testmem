#define JPEG_INTERNALS
#include "jinclude.h"
#include "jpeglib.h"
#ifdef UPSAMPLE_MERGING_SUPPORTED
#if RANGE_BITS < 2
#endif
typedef struct {
  struct jpeg_upsampler pub;	/* public fields */

  /* Pointer to routine to do actual upsampling/conversion of one row group */
  JMETHOD(void, upmethod, (j_decompress_ptr cinfo,
			   JSAMPIMAGE input_buf, JDIMENSION in_row_group_ctr,
			   JSAMPARRAY output_buf));

  /* Private state for YCC->RGB conversion */
  int * Cr_r_tab;		/* => table for Cr to R conversion */
  int * Cb_b_tab;		/* => table for Cb to B conversion */
  INT32 * Cr_g_tab;		/* => table for Cr to G conversion */
  INT32 * Cb_g_tab;		/* => table for Cb to G conversion */

  /* For 2:1 vertical sampling, we produce two output rows at a time.
   * We need a "spare" row buffer to hold the second output row if the
   * application provides just a one-row buffer; we also use the spare
   * to discard the dummy last row if the image height is odd.
   */
  JSAMPROW spare_row;
  boolean spare_full;		/* T if spare buffer is occupied */

  JDIMENSION out_row_width;	/* samples per output row */
  JDIMENSION rows_to_go;	/* counts rows remaining in image */
} my_upsampler;
typedef my_upsampler * my_upsample_ptr;

#define SCALEBITS	16	/* speediest right-shift on some machines */
#define ONE_HALF	((INT32) 1 << (SCALEBITS-1))
#define FIX(x)		((INT32) ((x) * (1L<<SCALEBITS) + 0.5))


/*
 * Initialize tables for YCbCr->RGB and BG_YCC->RGB colorspace conversion.
 * This is taken directly from jdcolor.c; see that file for more info.
 */

LOCAL(void)
build_ycc_rgb_table (j_decompress_ptr cinfo)
/* Normal case, sYCC */
{
  my_upsample_ptr upsample = (my_upsample_ptr) cinfo->upsample;
  int i;
  INT32 x;
  SHIFT_TEMPS

  upsample->Cr_r_tab = (int *) (*cinfo->mem->alloc_small)
    ((j_common_ptr) cinfo, JPOOL_IMAGE, (MAXJSAMPLE+1) * SIZEOF(int));
  upsample->Cb_b_tab = (int *) (*cinfo->mem->alloc_small)
    ((j_common_ptr) cinfo, JPOOL_IMAGE, (MAXJSAMPLE+1) * SIZEOF(int));
  upsample->Cr_g_tab = (INT32 *) (*cinfo->mem->alloc_small)
    ((j_common_ptr) cinfo, JPOOL_IMAGE, (MAXJSAMPLE+1) * SIZEOF(INT32));
  upsample->Cb_g_tab = (INT32 *) (*cinfo->mem->alloc_small)
    ((j_common_ptr) cinfo, JPOOL_IMAGE, (MAXJSAMPLE+1) * SIZEOF(INT32));

  for (i = 0, x = -CENTERJSAMPLE; i <= MAXJSAMPLE; i++, x++) {
    /* i is the actual input pixel value, in the range 0..MAXJSAMPLE */
    /* The Cb or Cr value we are thinking of is x = i - CENTERJSAMPLE */
    /* Cr=>R value is nearest int to 1.402 * x */
    upsample->Cr_r_tab[i] = (int) DESCALE(FIX(1.402) * x, SCALEBITS);
    /* Cb=>B value is nearest int to 1.772 * x */
    upsample->Cb_b_tab[i] = (int) DESCALE(FIX(1.772) * x, SCALEBITS);
    /* Cr=>G value is scaled-up -0.714136286 * x */
    upsample->Cr_g_tab[i] = (- FIX(0.714136286)) * x;
    /* Cb=>G value is scaled-up -0.344136286 * x */
    /* We also add in ONE_HALF so that need not do it in inner loop */
    upsample->Cb_g_tab[i] = (- FIX(0.344136286)) * x + ONE_HALF;
  }
#endif /* UPSAMPLE_MERGING_SUPPORTED */
