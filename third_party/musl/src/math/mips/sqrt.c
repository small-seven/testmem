#if !defined(__mips_soft_float) && __mips >= 3
#include <math.h>
#else
#include "../sqrt.c"
#endif
