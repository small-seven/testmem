#include <math.h>
#if __FMA__
#elif __FMA4__
#else
#include "../fmaf.c"
#endif
