#include "osal_mem.h"
#include "los_memory.h"
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

    buf = LOS_MemAlloc(m_aucSysMem0, size);

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
void *OsalMemAllocAlign(size_t alignment, size_t size)
{
    void *buf = NULL;

    if (size == 0) {
        HDF_LOGE("%s invalid param", __func__);
        return NULL;
    }

    buf = LOS_MemAllocAlign(m_aucSysMem0, size, alignment);

    return buf;
}
void OsalMemFree(void *mem)
{
    if (mem != NULL) {
        LOS_MemFree(m_aucSysMem0, mem);
    }
}
