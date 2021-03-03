#include <math.h>
#include <stdint.h>
#include "libm.h"
#include "log2_data.h"
#define T __log2_data.tab
#define T2 __log2_data.tab2
#define B __log2_data.poly1
#define A __log2_data.poly
#define InvLn2hi __log2_data.invln2hi
#define InvLn2lo __log2_data.invln2lo
#define N (1 << LOG2_TABLE_BITS)
#define OFF 0x3fe6000000000000
#define LO asuint64(1.0 - 0x1.5b51p-5)
#define HI asuint64(1.0 + 0x1.6ab2p-5)
#if __FP_FAST_FMA
#else
#endif
#if __FP_FAST_FMA
#else
#endif
