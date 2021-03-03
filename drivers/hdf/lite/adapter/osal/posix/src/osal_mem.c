#include "osal_mem.h"
#include <stdlib.h>
#include <string.h>
#include "securec.h"
#include "hdf_log.h"
#define HDF_LOG_TAG osal_mem
void *OsalMemAlloc(size_t size)
{
    void *buf = NULL;

    if (size == 0) {
        HDF_LOGE("%s invalid param", __func__);
        return NULL;
    }

    buf = malloc(size);

    return buf;
}
void *OsalMemCalloc(size_t size)
{
    void *buf = NULL;

    if (size == 0) {
        HDF_LOGE("%s invalid param", __func__);
        return NULL;
    }

    buf = OsalMemAlloc(size);
    if (buf != NULL) {
        (void)memset_s(buf, size, 0, size);
    }

    return buf;
}
void OsalMemFree(void *mem)
{
    if (mem != NULL) {
        free(mem);
    }
}
