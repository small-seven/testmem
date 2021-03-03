#include "libavutil/common.h"
#include "libavutil/intreadwrite.h"
#include "dct.h"
#include "idctdsp.h"
#define EIGHT_BIT_SAMPLES
#define DCTSIZE 8
#define DCTSIZE2 64
#define GLOBAL
#define RIGHT_SHIFT(x, n) ((x) >> (n))
typedef int16_t DCTBLOCK[DCTSIZE2];

#define CONST_BITS 13

/*
 * This routine is specialized to the case DCTSIZE = 8.
 */

#if DCTSIZE != 8
  Sorry, this code only copes with 8x8 DCTs. /* deliberate syntax err */
#endif


/*
 * A 2-D IDCT can be done by 1-D IDCT on each row followed by 1-D IDCT
 * on each column.  Direct algorithms are also available, but they are
 * much more complex and seem not to be any faster when reduced to code.
 *
 * The poop on this scaling stuff is as follows:
 *
 * Each 1-D IDCT step produces outputs which are a factor of sqrt(N)
 * larger than the true IDCT outputs.  The final outputs are therefore
 * a factor of N larger than desired; since N=8 this can be cured by
 * a simple right shift at the end of the algorithm.  The advantage of
 * this arrangement is that we save two multiplications per 1-D IDCT,
 * because the y0 and y4 inputs need not be divided by sqrt(N).
 *
 * We have to do addition and subtraction of the integer inputs, which
 * is no problem, and multiplication by fractional constants, which is
 * a problem to do in integer arithmetic.  We multiply all the constants
 * by CONST_SCALE and convert them to integer constants (thus retaining
 * CONST_BITS bits of precision in the constants).  After doing a
 * multiplication we have to divide the product by CONST_SCALE, with proper
 * rounding, to produce the correct output.  This division can be done
 * cheaply as a right shift of CONST_BITS bits.  We postpone shifting
 * as long as possible so that partial sums can be added together with
 * full fractional precision.
 *
 * The outputs of the first pass are scaled up by PASS1_BITS bits so that
 * they are represented to better-than-integral precision.  These outputs
 * require BITS_IN_JSAMPLE + PASS1_BITS + 3 bits; this fits in a 16-bit word
 * with the recommended scaling.  (To scale up 12-bit sample data further, an
 * intermediate int32 array would be needed.)
 *
 * To avoid overflow of the 32-bit intermediate results in pass 2, we must
 * have BITS_IN_JSAMPLE + CONST_BITS + PASS1_BITS <= 26.  Error analysis
 * shows that the values given below are the most effective.
 */

#ifdef EIGHT_BIT_SAMPLES
#define PASS1_BITS  2
#else
#define PASS1_BITS  1   /* lose a little precision to avoid overflow */
#endif

#define ONE         ((int32_t) 1)

#define CONST_SCALE (ONE << CONST_BITS)

/* Convert a positive real constant to an integer scaled by CONST_SCALE.
 * IMPORTANT: if your compiler doesn't do this arithmetic at compile time,
 * you will pay a significant penalty in run time.  In that case, figure
 * the correct integer constant values and insert them by hand.
 */

/* Actually FIX is no longer used, we precomputed them all */
#define FIX(x)  ((int32_t) ((x) * CONST_SCALE + 0.5))

/* Descale and correctly round an int32_t value that's scaled by N bits.
 * We assume RIGHT_SHIFT rounds towards minus infinity, so adding
 * the fudge factor is correct for either sign of X.
 */

#define DESCALE(x,n)  RIGHT_SHIFT((x) + (ONE << ((n)-1)), n)

/* Multiply an int32_t variable by an int32_t constant to yield an int32_t result.
 * For 8-bit samples with the recommended scaling, all the variable
 * and constant values involved are no more than 16 bits wide, so a
 * 16x16->32 bit multiply can be used instead of a full 32x32 multiply;
 * this provides a useful speedup on many machines.
 * There is no way to specify a 16x16->32 multiply in portable C, but
 * some C compilers will do the right thing if you provide the correct
 * combination of casts.
 * NB: for 12-bit samples, a full 32-bit multiplication will be needed.
 */

#ifdef EIGHT_BIT_SAMPLES
#ifdef SHORTxSHORT_32           /* may work if 'int' is 32 bits */
#define MULTIPLY(var,const)  (((int16_t) (var)) * ((int16_t) (const)))
#endif
#ifdef SHORTxLCONST_32          /* known to work with Microsoft C 6.0 */
#define MULTIPLY(var,const)  (((int16_t) (var)) * ((int32_t) (const)))
#endif
#endif

#ifndef MULTIPLY                /* default definition */
#define MULTIPLY(var,const)  ((var) * (const))
#endif


/*
  Unlike our decoder where we approximate the FIXes, we need to use exact
ones here or successive P-frames will drift too much with Reference frame coding
*/
#define FIX_0_211164243 1730
#define FIX_0_275899380 2260
#define FIX_0_298631336 2446
#define FIX_0_390180644 3196
#define FIX_0_509795579 4176
#define FIX_0_541196100 4433
#define FIX_0_601344887 4926
#define FIX_0_765366865 6270
#define FIX_0_785694958 6436
#define FIX_0_899976223 7373
#define FIX_1_061594337 8697
#define FIX_1_111140466 9102
#define FIX_1_175875602 9633
#define FIX_1_306562965 10703
#define FIX_1_387039845 11363
#define FIX_1_451774981 11893
#define FIX_1_501321110 12299
#define FIX_1_662939225 13623
#define FIX_1_847759065 15137
#define FIX_1_961570560 16069
#define FIX_2_053119869 16819
#define FIX_2_172734803 17799
#define FIX_2_562915447 20995
#define FIX_3_072711026 25172

/*
 * Perform the inverse DCT on one block of coefficients.
 */

void ff_j_rev_dct(DCTBLOCK data)
{
  int32_t tmp0, tmp1, tmp2, tmp3;
  int32_t tmp10, tmp11, tmp12, tmp13;
  int32_t z1, z2, z3, z4, z5;
  int32_t d0, d1, d2, d3, d4, d5, d6, d7;
  register int16_t *dataptr;
  int rowctr;

  /* Pass 1: process rows. */
  /* Note results are scaled up by sqrt(8) compared to a true IDCT; */
  /* furthermore, we scale the results by 2**PASS1_BITS. */

  dataptr = data;

  for (rowctr = DCTSIZE-1; rowctr >= 0; rowctr--) {
    /* Due to quantization, we will usually find that many of the input
     * coefficients are zero, especially the AC terms.  We can exploit this
     * by short-circuiting the IDCT calculation for any row in which all
     * the AC terms are zero.  In that case each output is equal to the
     * DC coefficient (with scale factor as needed).
     * With typical images and quantization tables, half or more of the
     * row DCT calculations can be simplified this way.
     */

    register uint8_t *idataptr = (uint8_t*)dataptr;

    /* WARNING: we do the same permutation as MMX idct to simplify the
       video core */
    d0 = dataptr[0];
    d2 = dataptr[1];
    d4 = dataptr[2];
    d6 = dataptr[3];
    d1 = dataptr[4];
    d3 = dataptr[5];
    d5 = dataptr[6];
    d7 = dataptr[7];

    if ((d1 | d2 | d3 | d4 | d5 | d6 | d7) == 0) {
      /* AC terms all zero */
      if (d0) {
          /* Compute a 32 bit value to assign. */
          int16_t dcval = (int16_t) (d0 * (1 << PASS1_BITS));
          register int v = (dcval & 0xffff) | ((dcval * (1 << 16)) & 0xffff0000);

          AV_WN32A(&idataptr[ 0], v);
          AV_WN32A(&idataptr[ 4], v);
          AV_WN32A(&idataptr[ 8], v);
          AV_WN32A(&idataptr[12], v);
      }
#undef DCTSIZE
#define DCTSIZE 4
#define DCTSTRIDE 8
#undef FIX
#undef CONST_BITS
