#include "config.h"
#include "libavutil/attributes.h"
#include "libavutil/cpu.h"
#include "libavutil/internal.h"
#include "libavutil/ppc/cpu.h"
#include "libavutil/ppc/util_altivec.h"
#include "libavcodec/mpegaudiodsp.h"
#if HAVE_ALTIVEC
#define MACS(rt, ra, rb) rt+=(ra)*(rb)
#define MLSS(rt, ra, rb) rt-=(ra)*(rb)
#define SUM8(op, sum, w, p)               \
#define MULT(a, b)                         \
#endif /* HAVE_ALTIVEC */
#if HAVE_ALTIVEC
#endif /* HAVE_ALTIVEC */
