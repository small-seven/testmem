#include "libavutil/intreadwrite.h"
#include "avcodec.h"
#include "mathops.h"
#include "simple_idct.h"
#define IN_IDCT_DEPTH 16
#define BIT_DEPTH 8
#include "simple_idct_template.c"
#undef BIT_DEPTH
#define BIT_DEPTH 10
#include "simple_idct_template.c"
#define EXTRA_SHIFT  2
#include "simple_idct_template.c"
#undef EXTRA_SHIFT
#undef BIT_DEPTH
#define BIT_DEPTH 12
#include "simple_idct_template.c"
#undef BIT_DEPTH
#undef IN_IDCT_DEPTH
#define IN_IDCT_DEPTH 32
#define BIT_DEPTH 10
#include "simple_idct_template.c"
#undef BIT_DEPTH
#undef IN_IDCT_DEPTH
#define CN_SHIFT 12
#define C_FIX(x) ((int)((x) * (1 << CN_SHIFT) + 0.5))
#define C1 C_FIX(0.6532814824)
#define C2 C_FIX(0.2705980501)
#define C_SHIFT (4+1+12)
#define BF(k) \
#undef CN_SHIFT
#undef C_SHIFT
#undef C_FIX
#undef C1
#undef C2
#define CN_SHIFT 12
#define C_FIX(x) ((int)((x) * M_SQRT2 * (1 << CN_SHIFT) + 0.5))
#define C1 C_FIX(0.6532814824)
#define C2 C_FIX(0.2705980501)
#define C3 C_FIX(0.5)
#define C_SHIFT (4+1+12)
#define RN_SHIFT 15
#define R_FIX(x) ((int)((x) * M_SQRT2 * (1 << RN_SHIFT) + 0.5))
#define R1 R_FIX(0.6532814824)
#define R2 R_FIX(0.2705980501)
#define R3 R_FIX(0.5)
#define R_SHIFT 11
