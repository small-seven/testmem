#include "client/app_spawn_client.h"
#include "appspawn_service.h"
#include "cJSON.h"
#include "hos_errno.h"
#include "liteipc_adapter.h"
#include "samgr_lite.h"
#include "securec.h"
#include "util/abilityms_log.h"
void static InnerFreeDataBuff(void *ptr)
{
    if (ptr != nullptr) {
        cJSON_free(ptr);
    }
}
