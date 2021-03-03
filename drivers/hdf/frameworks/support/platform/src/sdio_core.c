#include <string.h>
#include "device_resource_if.h"
#include "hdf_log.h"
#include "osal_mem.h"
#include "sdio_core.h"
#define HDF_LOG_TAG sdio_core
struct SdioCntlr *SdioCntlrCreateAndBind(struct HdfDeviceObject *device)
{
    struct SdioCntlr *cntlr = NULL;

    if (device == NULL) {
        HDF_LOGE("SdioCntlrCreateAndBind: device is NULL!");
        return NULL;
    }

    cntlr = (struct SdioCntlr *)OsalMemCalloc(sizeof(*cntlr));
    if (cntlr == NULL) {
        HDF_LOGE("SdioCntlrCreateAndBind: malloc host fail!");
        return NULL;
    }
    cntlr->device = device;
    device->service = &cntlr->service;
    return cntlr;
}
void SdioCntlrDestroy(struct SdioCntlr *cntlr)
{
    if (cntlr != NULL) {
        cntlr->device = NULL;
        cntlr->priv = NULL;
        cntlr->method = NULL;
        OsalMemFree(cntlr);
    }
}
