#include "power_state_manager.h"
#include "hdf_object_manager.h"
#include "power_state_token_clnt.h"
static void PowerStateManagerReleaseWakeLock(
    struct PowerStateManager *inst, struct IPowerStateToken *tokenIf)
{
    struct HdfSRef *sref = NULL;
    struct PowerStateTokenClnt *stateTokeClnt = PowerStateManagerGetStateTokenClnt(inst, tokenIf);
    if (inst == NULL || stateTokeClnt == NULL) {
        return;
    }
    stateTokeClnt->powerState = POWER_STATE_INACTIVE;
    sref = &inst->wakeRef;
    if (sref->Release != NULL) {
        sref->Release(sref);
    }
}
