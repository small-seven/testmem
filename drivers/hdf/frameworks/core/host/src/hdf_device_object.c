#include "hdf_device_object.h"
#include "hdf_base.h"
#include "hdf_device_node.h"
#include "hdf_log.h"
#include "hdf_observer_record.h"
#include "hdf_service_observer.h"
#include "power_state_token.h"
#define HDF_LOG_TAG device_object
void HdfDeviceReleaseWakeLock(struct HdfDeviceObject *deviceObject)
{
    if (deviceObject == NULL) {
        HDF_LOGE("%s input param is invalid", __func__);
        return;
    }
    struct HdfDeviceNode *devNode = (struct HdfDeviceNode *)HDF_SLIST_CONTAINER_OF(
        struct HdfDeviceObject, deviceObject, struct HdfDeviceNode, deviceObject);
    struct IPowerStateToken *tokenIf = (struct IPowerStateToken *)devNode->powerToken;
    if ((tokenIf != NULL) && (tokenIf->ReleaseWakeLock != NULL)) {
        tokenIf->ReleaseWakeLock(tokenIf);
    }
}
