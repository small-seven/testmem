#include "devsvc_manager_clnt.h"
#include "hdf_base.h"
#include "hdf_log.h"
#include "osal_mem.h"
#include "securec.h"
#include "sdio_core.h"
#define HDF_LOG_TAG sdio_if_c
#define SDIO_NAME_LEN 32
#define SDIO_BUS_MAX 2
void SdioReleaseHost(struct DevHandle *handle)
{
    struct SdioCntlr *cntlr = NULL;

    if (handle == NULL || handle->object == NULL) {
        HDF_LOGE("SdioReleaseHost: handle or object is null!");
        return;
    }

    cntlr = (struct SdioCntlr *)handle->object;
    if (cntlr->method == NULL || cntlr->method->releaseHost == NULL) {
        HDF_LOGE("SdioReleaseHost: method or releaseHost is null!");
        return;
    }
    HDF_LOGD("SdioReleaseHost: Success!");
    cntlr->method->releaseHost(cntlr);
}
int32_t SdioReleaseIrq(struct DevHandle *handle)
{
    struct SdioCntlr *cntlr = NULL;

    if (handle == NULL || handle->object == NULL) {
        HDF_LOGE("SdioReleaseIrq: handle or object is null!");
        return HDF_ERR_INVALID_OBJECT;
    }

    cntlr = (struct SdioCntlr *)handle->object;
    if (cntlr->method == NULL || cntlr->method->releaseIrq == NULL) {
        HDF_LOGE("SdioReleaseIrq: method or releaseIrq is null!");
        return HDF_ERR_NOT_SUPPORT;
    }
    HDF_LOGD("SdioReleaseIrq: Success!");
    return cntlr->method->releaseIrq(cntlr);
}
