#include <math.h>
#if __ARM_PCS_VFP && !BROKEN_VFP_ASM
#else
#include "../fabsf.c"
#endif
