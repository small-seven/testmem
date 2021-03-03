#include <limits.h>
#include <fenv.h>
#include <math.h>
#include "libm.h"
#if LONG_MAX < 1U<<53 && defined(FE_INEXACT)
#include <float.h>
#include <stdint.h>
#if FLT_EVAL_METHOD==0 || FLT_EVAL_METHOD==1
#define EPS DBL_EPSILON
#elif FLT_EVAL_METHOD==2
#define EPS LDBL_EPSILON
#endif
#ifdef __GNUC__
#endif
#else
#endif
