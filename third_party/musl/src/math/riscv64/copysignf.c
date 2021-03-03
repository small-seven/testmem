#include <math.h>
#if __riscv_flen >= 32
#else
#include "../copysignf.c"
#endif
