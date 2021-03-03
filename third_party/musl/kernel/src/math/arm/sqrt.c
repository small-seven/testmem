#include <math.h>
#if __ARM_PCS_VFP || (__VFP_FP__ && !__SOFTFP__)
#else
#include "../sqrt.c"
#endif
