#include <math.h>
#if __riscv_flen >= 32
#else
#include "../fabsf.c"
#endif
