#include <math.h>
#if __ARM_FEATURE_FMA && __ARM_FP&8 && !__SOFTFP__
#else
#include "../fma.c"
#endif
