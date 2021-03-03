#include "device_token_clnt.h"
#include "devhost_service_clnt.h"
#include "hdf_base.h"
#include "hdf_driver_installer.h"
#include "hdf_log.h"
#include "osal_mem.h"
#define HDF_LOG_TAG devhost_service_clnt
void DevHostServiceClntFreeInstance(struct DevHostServiceClnt *hostClnt)
{
    if (hostClnt != NULL) {
        HdfSListFlush(&hostClnt->devices, DeviceTokenClntDelete);
        HdfSListFlush(hostClnt->deviceInfos, HdfDeviceInfoDelete);
        OsalMemFree(hostClnt);
    }
}
