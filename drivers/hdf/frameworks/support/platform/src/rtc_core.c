#include "hdf_log.h"
#include "osal_mem.h"
#include "rtc_core.h"
#define HDF_LOG_TAG rtc_core
struct RtcHost *RtcHostCreate(struct HdfDeviceObject *device)
{
    struct RtcHost *host = NULL;

    if (device == NULL) {
        HDF_LOGE("RtcHostCreate: device NULL!");
        return NULL;
    }

    host = (struct RtcHost *)OsalMemCalloc(sizeof(*host));
    if (host == NULL) {
        HDF_LOGE("RtcHostCreate: malloc host fail!");
        return NULL;
    }
    host->device = device;
    return host;
}
void RtcHostDestroy(struct RtcHost *host)
{
    if (host != NULL) {
        host->device = NULL;
        host->method = NULL;
        host->data = NULL;
        OsalMemFree(host);
    }
}
