#include "securecutil.h"
#ifndef SECUREC_MEMCOPY_WITH_PERFORMANCE
#define SECUREC_MEMCOPY_WITH_PERFORMANCE 0
#endif
#if SECUREC_WITH_PERFORMANCE_ADDONS || SECUREC_MEMCOPY_WITH_PERFORMANCE
#ifndef SECUREC_MEMCOPY_THRESHOLD_SIZE
#define SECUREC_MEMCOPY_THRESHOLD_SIZE 64UL
#endif
#define SECUREC_SMALL_MEM_COPY(dest, src, count) do { \
#define SECUREC_MEMCPY_OPT(dest, src, count) do { \
#endif
SECUREC_INLINE errno_t SecMemcpyError(void *dest, size_t destMax, const void *src, size_t count)
{
    if (destMax == 0 || destMax > SECUREC_MEM_MAX_LEN) {
        SECUREC_ERROR_INVALID_RANGE("memcpy_s");
        return ERANGE;
    }
    if (dest == NULL || src == NULL) {
        SECUREC_ERROR_INVALID_PARAMTER("memcpy_s");
        if (dest != NULL) {
            (void)memset(dest, 0, destMax);
            return EINVAL_AND_RESET;
        }
        return EINVAL;
    }
    if (count > destMax) {
        (void)memset(dest, 0, destMax);
        SECUREC_ERROR_INVALID_RANGE("memcpy_s");
        return ERANGE_AND_RESET;
    }
    if (SECUREC_MEMORY_IS_OVERLAP(dest, src, count)) {
        (void)memset(dest, 0, destMax);
        SECUREC_ERROR_BUFFER_OVERLAP("memcpy_s");
        return EOVERLAP_AND_RESET;
    }
    /* Count is 0 or dest equal src also ret EOK */
    return EOK;
}
#if defined(SECUREC_COMPATIBLE_WIN_FORMAT)
#define SECUREC_MEMCPY_PARAM_OK(dest, destMax, src, count) (SECUREC_LIKELY((count) <= (destMax) && \
#else
#define SECUREC_MEMCPY_PARAM_OK(dest, destMax, src, count) (SECUREC_LIKELY((count) <= (destMax) && \
#endif
errno_t memcpy_s(void *dest, size_t destMax, const void *src, size_t count)
{
    if (SECUREC_MEMCPY_PARAM_OK(dest, destMax, src, count)) {
#if SECUREC_MEMCOPY_WITH_PERFORMANCE
        SECUREC_MEMCPY_OPT(dest, src, count);
#else
        SECUREC_MEMCPY_WARP_OPT(dest, src, count);
#endif
        return EOK;
    }
    /* Meet some runtime violation, return error code */
    return SecMemcpyError(dest, destMax, src, count);
}
#if SECUREC_IN_KERNEL
#endif
#if SECUREC_WITH_PERFORMANCE_ADDONS
errno_t memcpy_sOptAsm(void *dest, size_t destMax, const void *src, size_t count)
{
    if (SECUREC_MEMCPY_PARAM_OK(dest, destMax, src, count)) {
        SECUREC_MEMCPY_OPT(dest, src, count);
        return EOK;
    }
    /* Meet some runtime violation, return error code */
    return SecMemcpyError(dest, destMax, src, count);
}
errno_t memcpy_sOptTc(void *dest, size_t destMax, const void *src, size_t count)
{
    if (SECUREC_LIKELY(count <= destMax && dest != NULL && src != NULL && \
                       count > 0 && SECUREC_MEMORY_NO_OVERLAP((dest), (src), (count)))) {
        SECUREC_MEMCPY_OPT(dest, src, count);
        return EOK;
    }
    /* Meet some runtime violation, return error code */
    return SecMemcpyError(dest, destMax, src, count);
}
#endif
