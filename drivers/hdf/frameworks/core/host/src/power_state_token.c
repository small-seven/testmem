#include "power_state_token.h"
#include "devmgr_service_clnt.h"
#include "hdf_device_desc.h"
#include "hdf_slist.h"
#include "osal_mem.h"
static void PowerStateTokenReleaseWakeLock(struct IPowerStateToken *token)
{
    struct HdfSRef *sref = NULL;
    struct PowerStateToken *stateToken = (struct PowerStateToken *)token;
    if (stateToken == NULL) {
        return;
    }
    sref = (struct HdfSRef *)&stateToken->wakeRef;
    if ((sref != NULL) && (sref->Release != NULL)) {
        sref->Release(sref);
    }
}
static void PowerStateTokenOnLastRelease(struct HdfSRef *sref)
{
    if (sref == NULL) {
        return;
    }
    struct PowerStateToken *stateToken = (struct PowerStateToken *)HDF_SLIST_CONTAINER_OF(
        struct HdfSRef, sref, struct PowerStateToken, wakeRef);
    if (stateToken->state == POWER_STATE_ACTIVE) {
        struct IDevmgrService *devMgrSvcIf = NULL;
        struct IPowerEventListener *listener = stateToken->listener;
        struct DevmgrServiceClnt *inst = DevmgrServiceClntGetInstance();
        if (inst == NULL) {
            return;
        }
        devMgrSvcIf = (struct IDevmgrService *)inst->devMgrSvcIf;
        if ((devMgrSvcIf == NULL) || (devMgrSvcIf->AcquireWakeLock == NULL)) {
            return;
        }
        devMgrSvcIf->ReleaseWakeLock(devMgrSvcIf, &stateToken->super);
        if ((listener != NULL) && (listener->Suspend != NULL)) {
            listener->Suspend(stateToken->deviceObject);
        }
        stateToken->state = POWER_STATE_INACTIVE;
    }
}
void PowerStateTokenFreeInstance(struct PowerStateToken *stateToken)
{
    if (stateToken != NULL) {
        if (stateToken->wakeRef.listener != NULL) {
            OsalMemFree(stateToken->wakeRef.listener);
            stateToken->wakeRef.listener = NULL;
        }
        OsalMemFree(stateToken);
    }
}
