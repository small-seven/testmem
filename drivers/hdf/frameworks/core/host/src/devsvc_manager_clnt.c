#include "devsvc_manager_clnt.h"
#include "devsvc_manager.h"
#include "hdf_base.h"
#include "hdf_log.h"
#include "hdf_object_manager.h"
#define HDF_LOG_TAG devsvc_manager_clnt
void DevSvcManagerClntRemoveService(const char *svcName)
{
    struct DevSvcManagerClnt *devSvcMgrClnt = DevSvcManagerClntGetInstance();
    if (devSvcMgrClnt == NULL) {
        HDF_LOGE("Get device manager client is null");
        return;
    }

    struct IDevSvcManager *serviceManager = devSvcMgrClnt->devSvcMgrIf;
    if (serviceManager->RemoveService == NULL) {
        HDF_LOGE("Remove service function is not assigned");
        return;
    }
    serviceManager->RemoveService(serviceManager, svcName);
}
void DevSvcManagerClntFreeInstance(struct DevSvcManagerClnt *instance)
{
    if (instance != NULL) {
        if (instance->devSvcMgrIf != NULL) {
            HdfObjectManagerFreeObject((struct HdfObject *)instance->devSvcMgrIf);
        }
    }
}
