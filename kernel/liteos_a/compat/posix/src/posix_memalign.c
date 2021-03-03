#include "los_typedef.h"
#include "los_typedef.h"
#include "los_memory.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

int posix_memalign(void **memAddr, size_t alignment, size_t size)
{
    if ((alignment == 0) || ((alignment & (alignment - 1)) != 0) || ((alignment % sizeof(void *)) != 0)) {
        return EINVAL;
    }
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */