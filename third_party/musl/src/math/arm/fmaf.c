#include <math.h>
#if __ARM_FEATURE_FMA && __ARM_FP&4 && !__SOFTFP__ && !BROKEN_VFP_ASM
#else
#include "../fmaf.c"
#endif
