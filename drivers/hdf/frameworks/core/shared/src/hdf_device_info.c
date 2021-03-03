#include "hdf_device_info.h"
#include "hdf_log.h"
#include "osal_mem.h"
#define HDF_LOG_TAG device_info
void HdfDeviceInfoFreeInstance(struct HdfDeviceInfo *deviceInfo)
{
    if (deviceInfo != NULL) {
        OsalMemFree(deviceInfo);
    }
}
