#define JPEG_INTERNALS
#include "jinclude.h"
#include "jpeglib.h"
#if RANGE_BITS < 2
#endif
typedef struct {
  struct jpeg_color_deconverter pub; /* public fields */

  /* Private state for YCbCr->RGB and BG_YCC->RGB conversion */
  int * Cr_r_tab;		/* => table for Cr to R conversion */
  int * Cb_b_tab;		/* => table for Cb to B conversion */
  INT32 * Cr_g_tab;		/* => table for Cr to G conversion */
  INT32 * Cb_g_tab;		/* => table for Cb to G conversion */

  /* Private state for RGB->Y conversion */
  INT32 * rgb_y_tab;		/* => table for RGB to Y conversion */
} my_color_deconverter;
typedef my_color_deconverter * my_cconvert_ptr;


/***************  YCbCr -> RGB conversion: most common case **************/
/*************** BG_YCC -> RGB conversion: less common case **************/
/***************    RGB -> Y   conversion: less common case **************/

/*
 * YCbCr is defined per Recommendation ITU-R BT.601-7 (03/2011),
 * previously known as Recommendation CCIR 601-1, except that Cb and Cr
 * are normalized to the range 0..MAXJSAMPLE rather than -0.5 .. 0.5.
 * sRGB (standard RGB color space) is defined per IEC 61966-2-1:1999.
 * sYCC (standard luma-chroma-chroma color space with extended gamut)
 * is defined per IEC 61966-2-1:1999 Amendment A1:2003 Annex F.
 * bg-sRGB and bg-sYCC (big gamut standard color spaces)
 * are defined per IEC 61966-2-1:1999 Amendment A1:2003 Annex G.
 * Note that the derived conversion coefficients given in some of these
 * documents are imprecise.  The general conversion equations are
 *
 *	R = Y + K * (1 - Kr) * Cr
 *	G = Y - K * (Kb * (1 - Kb) * Cb + Kr * (1 - Kr) * Cr) / (1 - Kr - Kb)
 *	B = Y + K * (1 - Kb) * Cb
 *
 *	Y = Kr * R + (1 - Kr - Kb) * G + Kb * B
 *
 * With Kr = 0.299 and Kb = 0.114 (derived according to SMPTE RP 177-1993
 * from the 1953 FCC NTSC primaries and CIE Illuminant C), K = 2 for sYCC,
 * the conversion equations to be implemented are therefore
 *
 *	R = Y + 1.402 * Cr
 *	G = Y - 0.344136286 * Cb - 0.714136286 * Cr
 *	B = Y + 1.772 * Cb
 *
 *	Y = 0.299 * R + 0.587 * G + 0.114 * B
 *
 * where Cb and Cr represent the incoming values less CENTERJSAMPLE.
 * For bg-sYCC, with K = 4, the equations are
 *
 *	R = Y + 2.804 * Cr
 *	G = Y - 0.688272572 * Cb - 1.428272572 * Cr
 *	B = Y + 3.544 * Cb
 *
 * To avoid floating-point arithmetic, we represent the fractional constants
 * as integers scaled up by 2^16 (about 4 digits precision); we have to divide
 * the products by 2^16, with appropriate rounding, to get the correct answer.
 * Notice that Y, being an integral input, does not contribute any fraction
 * so it need not participate in the rounding.
 *
 * For even more speed, we avoid doing any multiplications in the inner loop
 * by precalculating the constants times Cb and Cr for all possible values.
 * For 8-bit JSAMPLEs this is very reasonable (only 256 entries per table);
 * for 9-bit to 12-bit samples it is still acceptable.  It's not very
 * reasonable for 16-bit samples, but if you want lossless storage you
 * shouldn't be changing colorspace anyway.
 * The Cr=>R and Cb=>B values can be rounded to integers in advance; the
 * values for the G calculation are left scaled up, since we must add them
 * together before rounding.
 */

#define SCALEBITS	16	/* speediest right-shift on some machines */
#define ONE_HALF	((INT32) 1 << (SCALEBITS-1))
#define FIX(x)		((INT32) ((x) * (1L<<SCALEBITS) + 0.5))

/* We allocate one big table for RGB->Y conversion and divide it up into
 * three parts, instead of doing three alloc_small requests.  This lets us
 * use a single table base address, which can be held in a register in the
 * inner loops on many machines (more than can hold all three addresses,
 * anyway).
 */

#define R_Y_OFF		0			/* offset to R => Y section */
#define G_Y_OFF		(1*(MAXJSAMPLE+1))	/* offset to G => Y section */
#define B_Y_OFF		(2*(MAXJSAMPLE+1))	/* etc. */
#define TABLE_SIZE	(3*(MAXJSAMPLE+1))


/*
 * Initialize tables for YCbCr->RGB and BG_YCC->RGB colorspace conversion.
 */

LOCAL(void)
build_ycc_rgb_table (j_decompress_ptr cinfo)
/* Normal case, sYCC */
{
  my_cconvert_ptr cconvert = (my_cconvert_ptr) cinfo->cconvert;
  int i;
  INT32 x;
  SHIFT_TEMPS

  cconvert->Cr_r_tab = (int *) (*cinfo->mem->alloc_small)
    ((j_common_ptr) cinfo, JPOOL_IMAGE, (MAXJSAMPLE+1) * SIZEOF(int));
  cconvert->Cb_b_tab = (int *) (*cinfo->mem->alloc_small)
    ((j_common_ptr) cinfo, JPOOL_IMAGE, (MAXJSAMPLE+1) * SIZEOF(int));
  cconvert->Cr_g_tab = (INT32 *) (*cinfo->mem->alloc_small)
    ((j_common_ptr) cinfo, JPOOL_IMAGE, (MAXJSAMPLE+1) * SIZEOF(INT32));
  cconvert->Cb_g_tab = (INT32 *) (*cinfo->mem->alloc_small)
    ((j_common_ptr) cinfo, JPOOL_IMAGE, (MAXJSAMPLE+1) * SIZEOF(INT32));

  for (i = 0, x = -CENTERJSAMPLE; i <= MAXJSAMPLE; i++, x++) {
    /* i is the actual input pixel value, in the range 0..MAXJSAMPLE */
    /* The Cb or Cr value we are thinking of is x = i - CENTERJSAMPLE */
    /* Cr=>R value is nearest int to 1.402 * x */
    cconvert->Cr_r_tab[i] = (int) DESCALE(FIX(1.402) * x, SCALEBITS);
    /* Cb=>B value is nearest int to 1.772 * x */
    cconvert->Cb_b_tab[i] = (int) DESCALE(FIX(1.772) * x, SCALEBITS);
    /* Cr=>G value is scaled-up -0.714136286 * x */
    cconvert->Cr_g_tab[i] = (- FIX(0.714136286)) * x;
    /* Cb=>G value is scaled-up -0.344136286 * x */
    /* We also add in ONE_HALF so that need not do it in inner loop */
    cconvert->Cb_g_tab[i] = (- FIX(0.344136286)) * x + ONE_HALF;
  }
