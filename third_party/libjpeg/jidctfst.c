#define JPEG_INTERNALS
#include "jinclude.h"
#include "jpeglib.h"
#include "jdct.h"		/* Private declarations for DCT subsystem */
#ifdef DCT_IFAST_SUPPORTED
#if DCTSIZE != 8
#endif
#if BITS_IN_JSAMPLE == 8
#define CONST_BITS  8
#define PASS1_BITS  2
#else
#define CONST_BITS  8
#define PASS1_BITS  1		/* lose a little precision to avoid overflow */
#endif
#if CONST_BITS == 8
#define FIX_1_082392200  ((INT32)  277)		/* FIX(1.082392200) */
#define FIX_1_414213562  ((INT32)  362)		/* FIX(1.414213562) */
#define FIX_1_847759065  ((INT32)  473)		/* FIX(1.847759065) */
#define FIX_2_613125930  ((INT32)  669)		/* FIX(2.613125930) */
#else
#define FIX_1_082392200  FIX(1.082392200)
#define FIX_1_414213562  FIX(1.414213562)
#define FIX_1_847759065  FIX(1.847759065)
#define FIX_2_613125930  FIX(2.613125930)
#endif
#ifndef USE_ACCURATE_ROUNDING
#undef DESCALE
#define DESCALE(x,n)  RIGHT_SHIFT(x, n)
#endif
#define MULTIPLY(var,const)  ((DCTELEM) DESCALE((var) * (const), CONST_BITS))
#if BITS_IN_JSAMPLE == 8
#define DEQUANTIZE(coef,quantval)  (((IFAST_MULT_TYPE) (coef)) * (quantval))
#else
#define DEQUANTIZE(coef,quantval)  \
#endif
#ifndef NO_ZERO_ROW_TEST
#endif
#endif /* DCT_IFAST_SUPPORTED */
