#if !defined(__mips_soft_float) && __mips >= 2
#include <math.h>
#else
#include "../sqrtf.c"
#endif
