#include "uart_core.h"
#include <string.h>
#include "hdf_log.h"
#include "osal_mem.h"
#include "uart_if.h"
#define HDF_LOG_TAG uart_core
void UartHostDestroy(struct UartHost *host)
{
    if (host == NULL) {
        return;
    }
    OsalMemFree(host);
}
struct UartHost *UartHostCreate(struct HdfDeviceObject *device)
{
    struct UartHost *host = NULL;

    if (device == NULL) {
        HDF_LOGE("%s: invalid parameter\n", __func__);
        return NULL;
    }
    host = (struct UartHost *)OsalMemCalloc(sizeof(*host));
    if (host == NULL) {
        HDF_LOGE("%s: OsalMemCalloc error\n", __func__);
        return NULL;
    }
    host->device = device;
    device->service = &(host->service);
    host->priv = NULL;
    host->method = NULL;
    return host;
}
