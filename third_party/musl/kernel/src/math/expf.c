#include <math.h>
#include <stdint.h>
#include "libm.h"
#include "exp2f_data.h"
#define N (1 << EXP2F_TABLE_BITS)
#define InvLn2N __exp2f_data.invln2_scaled
#define T __exp2f_data.tab
#define C __exp2f_data.poly_scaled
#if TOINT_INTRINSICS
#else
# define SHIFT __exp2f_data.shift
#endif
