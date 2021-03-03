#include "securecutil.h"
#define SECUREC_MEMSET_PARAM_OK(dest, destMax, count) (SECUREC_LIKELY((destMax) <= SECUREC_MEM_MAX_LEN && \
#if SECUREC_WITH_PERFORMANCE_ADDONS
typedef union {
    SecStrBuf32 buf32;
    SecStrBuf31 buf31;
    SecStrBuf30 buf30;
    SecStrBuf29 buf29;
    SecStrBuf28 buf28;
    SecStrBuf27 buf27;
    SecStrBuf26 buf26;
    SecStrBuf25 buf25;
    SecStrBuf24 buf24;
    SecStrBuf23 buf23;
    SecStrBuf22 buf22;
    SecStrBuf21 buf21;
    SecStrBuf20 buf20;
    SecStrBuf19 buf19;
    SecStrBuf18 buf18;
    SecStrBuf17 buf17;
    SecStrBuf16 buf16;
    SecStrBuf15 buf15;
    SecStrBuf14 buf14;
    SecStrBuf13 buf13;
    SecStrBuf12 buf12;
    SecStrBuf11 buf11;
    SecStrBuf10 buf10;
    SecStrBuf9 buf9;
    SecStrBuf8 buf8;
    SecStrBuf7 buf7;
    SecStrBuf6 buf6;
    SecStrBuf5 buf5;
    SecStrBuf4 buf4;
    SecStrBuf3 buf3;
    SecStrBuf2 buf2;
} SecStrBuf32Union;
#ifndef SECUREC_MEMSET_THRESHOLD_SIZE
#define SECUREC_MEMSET_THRESHOLD_SIZE 32UL
#endif
#define SECUREC_UNALIGNED_SET(dest, c, count) do { \
#define SECUREC_SET_VALUE_BY_STRUCT(dest, dataName, n) do { \
#define SECUREC_ALIGNED_SET_OPT_ZERO_FF(dest, c, count) do { \
#define SECUREC_SMALL_MEM_SET(dest, c, count) do { \
#define SECUREC_MEMSET_OPT(dest, c, count) do { \
#endif
SECUREC_INLINE errno_t SecMemsetError(void *dest, size_t destMax, int c, size_t count)
{
    /* Check destMax is 0 compatible with _sp macro */
    if (destMax == 0 || destMax > SECUREC_MEM_MAX_LEN) {
        SECUREC_ERROR_INVALID_RANGE("memset_s");
        return ERANGE;
    }
    if (dest == NULL) {
        SECUREC_ERROR_INVALID_PARAMTER("memset_s");
        return EINVAL;
    }
    if (count > destMax) {
        (void)memset(dest, c, destMax); /* Set entire buffer to value c */
        SECUREC_ERROR_INVALID_RANGE("memset_s");
        return ERANGE_AND_RESET;
    }
    return EOK;
}
errno_t memset_s(void *dest, size_t destMax, int c, size_t count)
{
    if (SECUREC_MEMSET_PARAM_OK(dest, destMax, count)) {
        SECUREC_MEMSET_WARP_OPT(dest, c, count);
        return EOK;
    }
    /* Meet some runtime violation, return error code */
    return SecMemsetError(dest, destMax, c, count);
}
#if SECUREC_IN_KERNEL
#endif
#if SECUREC_WITH_PERFORMANCE_ADDONS
errno_t memset_sOptAsm(void *dest, size_t destMax, int c, size_t count)
{
    if (SECUREC_MEMSET_PARAM_OK(dest, destMax, count)) {
        SECUREC_MEMSET_OPT(dest, c, count);
        return EOK;
    }
    /* Meet some runtime violation, return error code */
    return SecMemsetError(dest, destMax, c, count);
}
errno_t memset_sOptTc(void *dest, size_t destMax, int c, size_t count)
{
    if (SECUREC_LIKELY(count <= destMax && dest != NULL)) {
        SECUREC_MEMSET_OPT(dest, c, count);
        return EOK;
    }
    /* Meet some runtime violation, return error code */
    return SecMemsetError(dest, destMax, c, count);
}
#endif
