#include "config.h"
#include "libavutil/cpu.h"
#include "libavutil/ppc/cpu.h"
#include "libavutil/ppc/util_altivec.h"
#include "libavcodec/fft.h"
#if HAVE_VSX
#include "fft_vsx.h"
#else
#endif
#if HAVE_GNU_AS && HAVE_ALTIVEC && (HAVE_BIGENDIAN || HAVE_VSX)
#define CMULA(p,o0,o1,o2,o3)\
#define STORE2(v,dst)\
#define STORE8(p)\
#if HAVE_VSX
#else
#endif
#define CMULB(d0,d1,o)\
#endif /* HAVE_GNU_AS && HAVE_ALTIVEC && (HAVE_BIGENDIAN || HAVE_VSX) */
#if HAVE_GNU_AS && HAVE_ALTIVEC && (HAVE_BIGENDIAN || HAVE_VSX)
#if HAVE_VSX
#else
#endif
#endif /* HAVE_GNU_AS && HAVE_ALTIVEC && HAVE_BIGENDIAN */
