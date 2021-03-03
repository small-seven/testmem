#include "config.h"
#include <stdint.h>
#include "libavutil/attributes.h"
#include "libavutil/cpu.h"
#include "libavutil/ppc/cpu.h"
#include "libavutil/ppc/util_altivec.h"
#include "libavcodec/mpegvideoencdsp.h"
#if HAVE_ALTIVEC
#if HAVE_VSX
#else
#endif /* HAVE_VSX */
#if HAVE_VSX
#else
#endif /* HAVE_VSX */
#endif /* HAVE_ALTIVEC */
#if HAVE_ALTIVEC
#endif /* HAVE_ALTIVEC */
