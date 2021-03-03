#include "bundle_ms_feature.h"
#include "ability_info_utils.h"
#include "appexecfwk_errors.h"
#include "bundle_info_utils.h"
#include "bundle_inner_interface.h"
#include "bundle_manager_service.h"
#include "bundle_message_id.h"
#include "convert_utils.h"
#include "hos_init.h"
#include "log.h"
#include "message.h"
#include "samgr_lite.h"
#include "securec.h"
#include "serializer.h"
#include "utils.h"
#include "want_utils.h"
void static InnerFreeDataBuff(void *ptr)
{
    if (ptr != nullptr) {
        free(ptr);
    }
}
