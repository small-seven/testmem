#if defined(_STD_LIB_SOUTH_) & defined(_HILINK_PRODUCT_)
#include "hks_mem.h"
#include "base/hilink_osadapter.h"
void *hks_south_calloc(size_t n, size_t size)
{
    if (n == 0 || size == 0)
        return NULL;
    if (n > (UINT32_MAX / size))
        return NULL;
    unsigned int len = (unsigned int)(n * size);

    void *data = HKS_MALLOC(len);

    if (data != NULL)
        (void)hilink_memset_s((char *)data, len, 0, len);
    return data;
}
#endif
