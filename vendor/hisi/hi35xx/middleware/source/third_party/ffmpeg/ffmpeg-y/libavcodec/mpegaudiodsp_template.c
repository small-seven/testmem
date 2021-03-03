#include <stdint.h>
#include "libavutil/attributes.h"
#include "libavutil/mem.h"
#include "dct32.h"
#include "mathops.h"
#include "mpegaudiodsp.h"
#include "mpegaudio.h"
#if USE_FLOATS
#define RENAME(n) n##_float
#define MACS(rt, ra, rb) rt+=(ra)*(rb)
#define MULS(ra, rb) ((ra)*(rb))
#define MULH3(x, y, s) ((s)*(y)*(x))
#define MLSS(rt, ra, rb) rt-=(ra)*(rb)
#define MULLx(x, y, s) ((y)*(x))
#define FIXHR(x)        ((float)(x))
#define FIXR(x)        ((float)(x))
#define SHR(a,b)       ((a)*(1.0f/(1<<(b))))
#else
#define RENAME(n) n##_fixed
#define OUT_SHIFT (WFRAC_BITS + FRAC_BITS - 15)
#   define MULS(ra, rb) MUL64(ra, rb)
#   define MACS(rt, ra, rb) MAC64(rt, ra, rb)
#   define MLSS(rt, ra, rb) MLS64(rt, ra, rb)
#   define MULH3(x, y, s) MULH((s)*(x), y)
#   define MULLx(x, y, s) MULL((int)(x),(y),s)
#   define SHR(a,b)       (((int)(a))>>(b))
#   define FIXR(a)        ((int)((a) * FRAC_ONE + 0.5))
#   define FIXHR(a)       ((int)((a) * (1LL<<32) + 0.5))
#endif
#define SUM8(op, sum, w, p)               \
#define SUM8P2(sum1, op1, sum2, op2, w1, w2, p) \
#if USE_FLOATS
#else
#endif
#if USE_FLOATS
#endif
#define C1 FIXHR(0.98480775301220805936/2)
#define C2 FIXHR(0.93969262078590838405/2)
#define C3 FIXHR(0.86602540378443864676/2)
#define C4 FIXHR(0.76604444311897803520/2)
#define C5 FIXHR(0.64278760968653932632/2)
#define C6 FIXHR(0.5/2)
#define C7 FIXHR(0.34202014332566873304/2)
#define C8 FIXHR(0.17364817766693034885/2)
