#include <math.h>
#include <stdint.h>
#include "libm.h"
#include "exp2f_data.h"
#include "powf_data.h"
#define N (1 << POWF_LOG2_TABLE_BITS)
#define T __powf_log2_data.tab
#define A __powf_log2_data.poly
#define OFF 0x3f330000
#undef N
#undef T
#define N (1 << EXP2F_TABLE_BITS)
#define T __exp2f_data.tab
#define SIGN_BIAS (1 << (EXP2F_TABLE_BITS + 11))
#if TOINT_INTRINSICS
#define C __exp2f_data.poly_scaled
#else
#define C __exp2f_data.poly
#define SHIFT __exp2f_data.shift_scaled
#endif
