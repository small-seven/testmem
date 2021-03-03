#include "hdf_netbuf.h"
#include "osal.h"
#include "los_memory.h"
#include "lwip/prot/ethernet.h"
#define HDF_LOG_TAG             NetBuf
struct NetBuf *NetBufAlloc(uint32_t size)
{
    struct NetBuf *nb = NULL;
    uint8_t *data = NULL;

    nb = (struct NetBuf *)LOS_MemAllocAlign(m_aucSysMem0, sizeof(*nb), CACHE_ALIGNED_SIZE);
    if (nb == NULL) {
        HDF_LOGE("%s alloc net buf fail", __func__);
        return NULL;
    }

    data = (uint8_t *)LOS_MemAllocAlign(m_aucSysMem0, size, CACHE_ALIGNED_SIZE);
    if (data == NULL) {
        HDF_LOGE("%s alloc data fail, size:%u", __func__, size);
        LOS_MemFree(m_aucSysMem0, nb);
        return NULL;
    }

    (void)memset_s(nb, sizeof(struct NetBuf), 0, sizeof(struct NetBuf));

    nb->mem = data;
    nb->len = size;
    nb->dataLen = 0;
    nb->bufs[E_HEAD_BUF].offset = 0;
    nb->bufs[E_HEAD_BUF].len    = 0;
    nb->bufs[E_DATA_BUF].offset = 0;
    nb->bufs[E_DATA_BUF].len    = 0;
    nb->bufs[E_TAIL_BUF].offset = 0;
    nb->bufs[E_TAIL_BUF].len    = size;

    return nb;
}
void NetBufFree(struct NetBuf *nb)
{
    if (nb == NULL) {
        return;
    }

    if (nb->mem != NULL) {
        LOS_MemFree(m_aucSysMem0, nb->mem);
        nb->mem = NULL;
    }

    LOS_MemFree(m_aucSysMem0, nb);
}
