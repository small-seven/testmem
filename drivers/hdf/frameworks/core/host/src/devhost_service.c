#include "devhost_service.h"
#include "devmgr_service_clnt.h"
#include "devsvc_manager_clnt.h"
#include "hdf_base.h"
#include "hdf_driver_loader.h"
#include "hdf_log.h"
#include "hdf_object_manager.h"
#include "osal_mem.h"
#define HDF_LOG_TAG devhost_service
static void DevHostServiceFreeDevice(struct DevHostService *inst, uint16_t deviceId)
{
    struct HdfDevice *deviceNode = DevHostServiceFindDevice(inst, deviceId);
    if (deviceNode != NULL) {
        HdfSListRemove(&inst->devices, &deviceNode->node);
        HdfDeviceFreeInstance(deviceNode);
    }
}
struct HdfObject *DevHostServiceCreate()
{
    struct DevHostService *devHostService = (struct DevHostService *)OsalMemCalloc(sizeof(struct DevHostService));
    if (devHostService != NULL) {
        DevHostServiceConstruct(devHostService);
    }
    return (struct HdfObject *)devHostService;
}
void DevHostServiceRelease(struct HdfObject *object)
{
    struct DevHostService *devHostService = (struct DevHostService *)object;
    if (devHostService != NULL) {
        DevHostServiceDestruct(devHostService);
        OsalMemFree(devHostService);
    }
}
void DevHostServiceFreeInstance(struct IDevHostService *service)
{
    if (service != NULL) {
        HdfObjectManagerFreeObject(&service->object);
    }
}
