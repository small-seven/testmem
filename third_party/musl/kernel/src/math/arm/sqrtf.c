#include <math.h>
#if (__ARM_PCS_VFP || (__VFP_FP__ && !__SOFTFP__)) && !BROKEN_VFP_ASM
#else
#include "../sqrtf.c"
#endif
