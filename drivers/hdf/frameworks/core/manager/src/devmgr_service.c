#include "devmgr_service.h"
#include <string.h>
#include "devhost_service_clnt.h"
#include "device_token_clnt.h"
#include "hdf_attribute_manager.h"
#include "hdf_base.h"
#include "hdf_driver_installer.h"
#include "hdf_host_info.h"
#include "hdf_log.h"
#include "hdf_object_manager.h"
#include "power_state_manager.h"
#define HDF_LOG_TAG devmgr_service
struct HdfObject *DevmgrServiceCreate()
{
    static bool isDevMgrServiceInit = false;
    static struct DevmgrService devmgrServiceInstance;
    if (!isDevMgrServiceInit) {
        if (!DevmgrServiceConstruct(&devmgrServiceInstance)) {
            return NULL;
        }
        isDevMgrServiceInit = true;
    }
    return (struct HdfObject *)&devmgrServiceInstance;
}
void DevmgrServiceRelease(struct HdfObject *object)
{
    struct DevmgrService *devmgrService = (struct DevmgrService *)object;
    if (devmgrService == NULL) {
        return;
    }
    HdfSListFlush(&devmgrService->hosts, DevHostServiceClntDelete);
    OsalMutexDestroy(&devmgrService->devMgrMutex);
}
void DevmgrServiceReleaseWakeLock(struct IDevmgrService *inst, struct IPowerStateToken *tokenIf)
{
    struct PowerStateManager *stateManager = PowerStateManagerGetInstance();
    if ((stateManager != NULL) && (stateManager->ReleaseWakeLock != NULL)) {
        stateManager->ReleaseWakeLock(stateManager, tokenIf);
    }
}
