#include "config.h"
#include <stdlib.h>
#include <string.h>
#include "libavutil/attributes.h"
#include "libavutil/cpu.h"
#include "libavutil/ppc/cpu.h"
#include "libavutil/ppc/util_altivec.h"
#include "libavcodec/idctdsp.h"
#if HAVE_ALTIVEC
#define IDCT_HALF                                       \
#define IDCT                                                                \
#define COPY(dest, src)                                     \
#if HAVE_BIGENDIAN
#endif
#if HAVE_BIGENDIAN
#define GET_TMP2(dest, prm)                                 \
#else
#define GET_TMP2(dest, prm)                                 \
#endif
#define ADD(dest, src, perm)                                \
#endif /* HAVE_ALTIVEC */
#if HAVE_ALTIVEC
#endif /* HAVE_ALTIVEC */
