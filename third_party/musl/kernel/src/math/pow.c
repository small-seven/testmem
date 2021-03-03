#include <math.h>
#include <stdint.h>
#include "libm.h"
#include "exp_data.h"
#include "pow_data.h"
#define T __pow_log_data.tab
#define A __pow_log_data.poly
#define Ln2hi __pow_log_data.ln2hi
#define Ln2lo __pow_log_data.ln2lo
#define N (1 << POW_LOG_TABLE_BITS)
#define OFF 0x3fe6955500000000
#if __FP_FAST_FMA
#else
#endif
#if __FP_FAST_FMA
#else
#endif
#undef N
#undef T
#define N (1 << EXP_TABLE_BITS)
#define InvLn2N __exp_data.invln2N
#define NegLn2hiN __exp_data.negln2hiN
#define NegLn2loN __exp_data.negln2loN
#define Shift __exp_data.shift
#define T __exp_data.tab
#define C2 __exp_data.poly[5 - EXP_POLY_ORDER]
#define C3 __exp_data.poly[6 - EXP_POLY_ORDER]
#define C4 __exp_data.poly[7 - EXP_POLY_ORDER]
#define C5 __exp_data.poly[8 - EXP_POLY_ORDER]
#define C6 __exp_data.poly[9 - EXP_POLY_ORDER]
#define SIGN_BIAS (0x800 << EXP_TABLE_BITS)
#if TOINT_INTRINSICS
#elif EXP_USE_TOINT_NARROW
#else
#endif
#if __FP_FAST_FMA
#else
#endif
