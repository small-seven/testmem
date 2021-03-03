#include <string.h>
#include "config.h"
#include "libavutil/attributes.h"
#include "libavutil/cpu.h"
#include "libavutil/ppc/cpu.h"
#include "libavutil/ppc/util_altivec.h"
#include "libavcodec/vp3dsp.h"
#if HAVE_ALTIVEC
#if HAVE_BIGENDIAN
#else
#endif
#define IDCT_START \
#define IDCT_1D(ADD, SHIFT)\
#define NOP(a) a
#define ADD8(a) vec_add(a, eight)
#define SHIFT4(a) vec_sra(a, four)
#define PUT(a)\
#if HAVE_BIGENDIAN
#define GET_VDST16\
#else
#define GET_VDST16\
#endif
#define ADD(a)\
#endif /* HAVE_ALTIVEC */
#if HAVE_ALTIVEC
#endif
