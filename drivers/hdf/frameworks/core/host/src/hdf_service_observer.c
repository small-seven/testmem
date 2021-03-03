#include "hdf_service_observer.h"
#include "hdf_base.h"
#include "hdf_cstring.h"
#include "hdf_log.h"
#include "hdf_observer_record.h"
#define HDF_LOG_TAG service_observer
void HdfServiceObserverRemoveRecord(struct HdfServiceObserver *observer, const char *svcName)
{
    struct HdfServiceObserverRecord *serviceRecord = NULL;
    uint32_t serviceKey = HdfStringMakeHashKey(svcName, 0);
    if ((observer == NULL) || (svcName == NULL)) {
        HDF_LOGW("observer or svcName is null");
        return;
    }
    serviceRecord = (struct HdfServiceObserverRecord *)HdfSListSearch(
        &observer->services, serviceKey, HdfServiceObserverRecordCompare);
    if (serviceRecord != NULL) {
        OsalMutexLock(&observer->observerMutex);
        HdfSListRemove(&observer->services, &serviceRecord->entry);
        OsalMutexUnlock(&observer->observerMutex);
        HdfServiceObserverRecordRecycle(serviceRecord);
    }
}
