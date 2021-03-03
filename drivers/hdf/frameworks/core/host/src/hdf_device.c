#include "hdf_device.h"
#include "hdf_base.h"
#include "hdf_cstring.h"
#include "hdf_device_node.h"
#include "hdf_device_token.h"
#include "hdf_log.h"
#include "hdf_object_manager.h"
#include "hdf_service_observer.h"
#include "osal_mem.h"
#define HDF_LOG_TAG hdf_device
struct HdfObject *HdfDeviceCreate()
{
    struct HdfDevice *device =
        (struct HdfDevice *)OsalMemCalloc(sizeof(struct HdfDevice));
    if (device != NULL) {
        HdfDeviceConstruct(device);
    }
    return (struct HdfObject *)device;
}
void HdfDeviceRelease(struct HdfObject *object)
{
    struct HdfDevice *device = (struct HdfDevice *)object;
    if (device != NULL) {
        HdfDeviceDestruct(device);
        OsalMemFree(device);
    }
}
void HdfDeviceFreeInstance(struct HdfDevice *device)
{
    if (device != NULL) {
        HdfObjectManagerFreeObject((struct HdfObject *)device);
    }
}
