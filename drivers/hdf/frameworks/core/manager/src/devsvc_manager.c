#include "devsvc_manager.h"
#include "devmgr_service.h"
#include "hdf_base.h"
#include "hdf_cstring.h"
#include "hdf_log.h"
#include "hdf_object_manager.h"
#include "hdf_service_record.h"
#define HDF_LOG_TAG devsvc_manager
void DevSvcManagerRemoveService(struct IDevSvcManager *inst, const char *svcName)
{
    struct DevSvcManager *devSvcManager = (struct DevSvcManager *)inst;
    uint32_t serviceKey = HdfStringMakeHashKey(svcName, 0);
    if (svcName == NULL || devSvcManager == NULL) {
        return;
    }
    struct DevSvcRecord *serviceRecord = DevSvcManagerSearchService(inst, serviceKey);
    if (serviceRecord != NULL) {
        OsalMutexLock(&devSvcManager->mutex);
        HdfSListRemove(&devSvcManager->services, &serviceRecord->entry);
        OsalMutexUnlock(&devSvcManager->mutex);
    }
}
struct HdfObject *DevSvcManagerCreate()
{
    static bool isDevSvcManagerInit = false;
    static struct DevSvcManager devSvcManagerInstance;
    if (!isDevSvcManagerInit) {
        if (!DevSvcManagerConstruct(&devSvcManagerInstance)) {
            return NULL;
        }
        isDevSvcManagerInit = true;
    }
    return (struct HdfObject *)&devSvcManagerInstance;
}
void DevSvcManagerRelease(struct HdfObject *object)
{
    struct DevSvcManager *devSvcManager = (struct DevSvcManager *)object;
    if (object == NULL) {
        return;
    }
    HdfSListFlush(&devSvcManager->services, DevSvcRecordDelete);
    OsalMutexDestroy(&devSvcManager->mutex);
}
