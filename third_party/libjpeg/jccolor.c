#define JPEG_INTERNALS
#include "jinclude.h"
#include "jpeglib.h"
typedef struct {
  struct jpeg_color_converter pub; /* public fields */

  /* Private state for RGB->YCC conversion */
  INT32 * rgb_ycc_tab;		/* => table for RGB to YCbCr conversion */
} my_color_converter;
typedef my_color_converter * my_cconvert_ptr;


/**************** RGB -> YCbCr conversion: most common case **************/

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
 *	Y  = Kr * R + (1 - Kr - Kb) * G + Kb * B
 *	Cb = 0.5 * (B - Y) / (1 - Kb)
 *	Cr = 0.5 * (R - Y) / (1 - Kr)
 * With Kr = 0.299 and Kb = 0.114 (derived according to SMPTE RP 177-1993
 * from the 1953 FCC NTSC primaries and CIE Illuminant C),
 * the conversion equations to be implemented are therefore
 *	Y  =  0.299 * R + 0.587 * G + 0.114 * B
 *	Cb = -0.168735892 * R - 0.331264108 * G + 0.5 * B + CENTERJSAMPLE
 *	Cr =  0.5 * R - 0.418687589 * G - 0.081312411 * B + CENTERJSAMPLE
 * Note: older versions of the IJG code used a zero offset of MAXJSAMPLE/2,
 * rather than CENTERJSAMPLE, for Cb and Cr.  This gave equal positive and
 * negative swings for Cb/Cr, but meant that grayscale values (Cb=Cr=0)
 * were not represented exactly.  Now we sacrifice exact representation of
 * maximum red and maximum blue in order to get exact grayscales.
 *
 * To avoid floating-point arithmetic, we represent the fractional constants
 * as integers scaled up by 2^16 (about 4 digits precision); we have to divide
 * the products by 2^16, with appropriate rounding, to get the correct answer.
 *
 * For even more speed, we avoid doing any multiplications in the inner loop
 * by precalculating the constants times R,G,B for all possible values.
 * For 8-bit JSAMPLEs this is very reasonable (only 256 entries per table);
 * for 9-bit to 12-bit samples it is still acceptable.  It's not very
 * reasonable for 16-bit samples, but if you want lossless storage you
 * shouldn't be changing colorspace anyway.
 * The CENTERJSAMPLE offsets and the rounding fudge-factor of 0.5 are included
 * in the tables to save adding them separately in the inner loop.
 */

#define SCALEBITS	16	/* speediest right-shift on some machines */
#define CBCR_OFFSET	((INT32) CENTERJSAMPLE << SCALEBITS)
#define ONE_HALF	((INT32) 1 << (SCALEBITS-1))
#define FIX(x)		((INT32) ((x) * (1L<<SCALEBITS) + 0.5))

/* We allocate one big table and divide it up into eight parts, instead of
 * doing eight alloc_small requests.  This lets us use a single table base
 * address, which can be held in a register in the inner loops on many
 * machines (more than can hold all eight addresses, anyway).
 */

#define R_Y_OFF		0			/* offset to R => Y section */
#define G_Y_OFF		(1*(MAXJSAMPLE+1))	/* offset to G => Y section */
#define B_Y_OFF		(2*(MAXJSAMPLE+1))	/* etc. */
#define R_CB_OFF	(3*(MAXJSAMPLE+1))
#define G_CB_OFF	(4*(MAXJSAMPLE+1))
#define B_CB_OFF	(5*(MAXJSAMPLE+1))
#define R_CR_OFF	B_CB_OFF		/* B=>Cb, R=>Cr are the same */
#define G_CR_OFF	(6*(MAXJSAMPLE+1))
#define B_CR_OFF	(7*(MAXJSAMPLE+1))
#define TABLE_SIZE	(8*(MAXJSAMPLE+1))


/*
 * Initialize for RGB->YCC colorspace conversion.
 */

METHODDEF(void)
rgb_ycc_start (j_compress_ptr cinfo)
{
  my_cconvert_ptr cconvert = (my_cconvert_ptr) cinfo->cconvert;
  INT32 * rgb_ycc_tab;
  INT32 i;

  /* Allocate and fill in the conversion tables. */
  cconvert->rgb_ycc_tab = rgb_ycc_tab = (INT32 *)
    (*cinfo->mem->alloc_small) ((j_common_ptr) cinfo, JPOOL_IMAGE,
				TABLE_SIZE * SIZEOF(INT32));

  for (i = 0; i <= MAXJSAMPLE; i++) {
    rgb_ycc_tab[i+R_Y_OFF] = FIX(0.299) * i;
    rgb_ycc_tab[i+G_Y_OFF] = FIX(0.587) * i;
    rgb_ycc_tab[i+B_Y_OFF] = FIX(0.114) * i   + ONE_HALF;
    rgb_ycc_tab[i+R_CB_OFF] = (- FIX(0.168735892)) * i;
    rgb_ycc_tab[i+G_CB_OFF] = (- FIX(0.331264108)) * i;
    /* We use a rounding fudge-factor of 0.5-epsilon for Cb and Cr.
     * This ensures that the maximum output will round to MAXJSAMPLE
     * not MAXJSAMPLE+1, and thus that we don't have to range-limit.
     */
    rgb_ycc_tab[i+B_CB_OFF] = FIX(0.5) * i    + CBCR_OFFSET + ONE_HALF-1;
/*  B=>Cb and R=>Cr tables are the same
    rgb_ycc_tab[i+R_CR_OFF] = FIX(0.5) * i    + CBCR_OFFSET + ONE_HALF-1;
*/
    rgb_ycc_tab[i+G_CR_OFF] = (- FIX(0.418687589)) * i;
    rgb_ycc_tab[i+B_CR_OFF] = (- FIX(0.081312411)) * i;
  }
#if RGB_PIXELSIZE != 3
#endif /* else share code with YCbCr */
