#include <math.h>
#if __riscv_flen >= 64
#else
#include "../fmin.c"
#endif
