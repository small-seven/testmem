#include <limits.h>
#include <fenv.h>
#include "libm.h"
#if LDBL_MANT_DIG == 53 && LDBL_MAX_EXP == 1024
#elif defined(FE_INEXACT)
#else
#endif
