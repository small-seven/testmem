#include "spi_core.h"
#include <string.h>
#include "hdf_log.h"
#include "osal_mem.h"
#include "spi_if.h"
#define HDF_LOG_TAG spi_core
void SpiCntlrDestroy(struct SpiCntlr *cntlr)
{
    if (cntlr == NULL) {
        return;
    }
    (void)OsalMutexDestroy(&(cntlr->lock));
    OsalMemFree(cntlr);
}
struct SpiCntlr *SpiCntlrCreate(struct HdfDeviceObject *device)
{
    struct SpiCntlr *cntlr = NULL;

    if (device == NULL) {
        HDF_LOGE("%s: invalid parameter\n", __func__);
        return NULL;
    }

    cntlr = (struct SpiCntlr *)OsalMemCalloc(sizeof(*cntlr));
    if (cntlr == NULL) {
        HDF_LOGE("%s: OsalMemCalloc error\n", __func__);
        return NULL;
    }
    cntlr->device = device;
    device->service = &(cntlr->service);
    (void)OsalMutexInit(&cntlr->lock);
    cntlr->priv = NULL;
    return cntlr;
}
