#include "securecutil.h"
#ifndef SECUREC_STRCPY_WITH_PERFORMANCE
#define SECUREC_STRCPY_WITH_PERFORMANCE 1
#endif
#define SECUREC_STRCPY_PARAM_OK(strDest, destMax, strSrc) ((destMax) > 0 && \
#if (!SECUREC_IN_KERNEL) && SECUREC_STRCPY_WITH_PERFORMANCE
#ifndef SECUREC_STRCOPY_THRESHOLD_SIZE
#define SECUREC_STRCOPY_THRESHOLD_SIZE   32UL
#endif
#define SECUREC_SMALL_STR_COPY(strDest, strSrc, lenWithTerm) do { \
#endif
#if SECUREC_IN_KERNEL || (!SECUREC_STRCPY_WITH_PERFORMANCE)
#define SECUREC_STRCPY_OPT(dest, src, lenWithTerm) SECUREC_MEMCPY_WARP_OPT((dest), (src), (lenWithTerm))
#else
#define SECUREC_STRCPY_OPT(dest, src, lenWithTerm) do { \
#endif
#if SECUREC_IN_KERNEL
#endif
