#include <stdlib.h>
#include <stdio.h>
#include "libavutil/common.h"
#include "dct.h"
#define DCTSIZE 8
#define GLOBAL(x) x
#define RIGHT_SHIFT(x, n) ((x) >> (n))
#if DCTSIZE != 8
#endif
#define CONST_BITS  8
#if CONST_BITS == 8
#define FIX_0_382683433  ((int32_t)   98)       /* FIX(0.382683433) */
#define FIX_0_541196100  ((int32_t)  139)       /* FIX(0.541196100) */
#define FIX_0_707106781  ((int32_t)  181)       /* FIX(0.707106781) */
#define FIX_1_306562965  ((int32_t)  334)       /* FIX(1.306562965) */
#else
#define FIX_0_382683433  FIX(0.382683433)
#define FIX_0_541196100  FIX(0.541196100)
#define FIX_0_707106781  FIX(0.707106781)
#define FIX_1_306562965  FIX(1.306562965)
#endif
#ifndef USE_ACCURATE_ROUNDING
#undef DESCALE
#define DESCALE(x,n)  RIGHT_SHIFT(x, n)
#endif
#define MULTIPLY(var,const)  ((int16_t) DESCALE((var) * (const), CONST_BITS))
#undef GLOBAL
#undef CONST_BITS
#undef DESCALE
#undef FIX_0_541196100
#undef FIX_1_306562965
