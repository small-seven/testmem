#include "libavutil/common.h"
#include "dct.h"
#include "bit_depth_template.c"
#define DCTSIZE 8
#define BITS_IN_JSAMPLE BIT_DEPTH
#define GLOBAL(x) x
#define RIGHT_SHIFT(x, n) ((x) >> (n))
#define MULTIPLY16C16(var,const) ((var)*(const))
#define DESCALE(x,n)  RIGHT_SHIFT((x) + (1 << ((n) - 1)), n)
#if DCTSIZE != 8
#error  "Sorry, this code only copes with 8x8 DCTs."
#endif
#undef CONST_BITS
#undef PASS1_BITS
#undef OUT_SHIFT
#if BITS_IN_JSAMPLE == 8
#define CONST_BITS  13
#define PASS1_BITS  4   /* set this to 2 if 16x16 multiplies are faster */
#define OUT_SHIFT   PASS1_BITS
#else
#define CONST_BITS  13
#define PASS1_BITS  1   /* lose a little precision to avoid overflow */
#define OUT_SHIFT   (PASS1_BITS + 1)
#endif
#if CONST_BITS == 13
#define FIX_0_298631336  ((int32_t)  2446)      /* FIX(0.298631336) */
#define FIX_0_390180644  ((int32_t)  3196)      /* FIX(0.390180644) */
#define FIX_0_541196100  ((int32_t)  4433)      /* FIX(0.541196100) */
#define FIX_0_765366865  ((int32_t)  6270)      /* FIX(0.765366865) */
#define FIX_0_899976223  ((int32_t)  7373)      /* FIX(0.899976223) */
#define FIX_1_175875602  ((int32_t)  9633)      /* FIX(1.175875602) */
#define FIX_1_501321110  ((int32_t)  12299)     /* FIX(1.501321110) */
#define FIX_1_847759065  ((int32_t)  15137)     /* FIX(1.847759065) */
#define FIX_1_961570560  ((int32_t)  16069)     /* FIX(1.961570560) */
#define FIX_2_053119869  ((int32_t)  16819)     /* FIX(2.053119869) */
#define FIX_2_562915447  ((int32_t)  20995)     /* FIX(2.562915447) */
#define FIX_3_072711026  ((int32_t)  25172)     /* FIX(3.072711026) */
#else
#define FIX_0_298631336  FIX(0.298631336)
#define FIX_0_390180644  FIX(0.390180644)
#define FIX_0_541196100  FIX(0.541196100)
#define FIX_0_765366865  FIX(0.765366865)
#define FIX_0_899976223  FIX(0.899976223)
#define FIX_1_175875602  FIX(1.175875602)
#define FIX_1_501321110  FIX(1.501321110)
#define FIX_1_847759065  FIX(1.847759065)
#define FIX_1_961570560  FIX(1.961570560)
#define FIX_2_053119869  FIX(2.053119869)
#define FIX_2_562915447  FIX(2.562915447)
#define FIX_3_072711026  FIX(3.072711026)
#endif
#if BITS_IN_JSAMPLE == 8 && CONST_BITS<=13 && PASS1_BITS<=2
#define MULTIPLY(var,const)  MULTIPLY16C16(var,const)
#else
#define MULTIPLY(var,const)  ((var) * (const))
#endif
