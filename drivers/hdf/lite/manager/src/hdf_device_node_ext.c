#include "hdf_device_node_ext.h"
#include "devsvc_manager_clnt.h"
#include "hdf_base.h"
#include "hdf_device_desc.h"
#include "hdf_log.h"
#include "hdf_sbuf.h"
#include "osal_mem.h"
#define HDF_LOG_TAG device_node_ext
struct HdfObject *DeviceNodeExtCreate()
{
    struct DeviceNodeExt *instance =
        (struct DeviceNodeExt *)OsalMemCalloc(sizeof(struct DeviceNodeExt));
    if (instance != NULL) {
        DeviceNodeExtConstruct(instance);
        instance->ioService = NULL;
    }
    return (struct HdfObject *)instance;
}
void DeviceNodeExtRelease(struct HdfObject *object)
{
    struct DeviceNodeExt *instance = (struct DeviceNodeExt *)object;
    if (instance != NULL) {
        if (instance->ioService != NULL) {
            HdfIoServiceRecycle(instance->ioService);
        }
        HdfDeviceNodeDestruct(&instance->super);
        OsalMemFree(instance);
    }
}
