#include "dmslite_famgr.h"
#include "distributed_service_interface.h"
#include "dmslite_log.h"
#include "ability_manager.h"
#include "ability_service_interface.h"
#include "iproxy_client.h"
#include "iunknown.h"
#include "liteipc_adapter.h"
#include "ohos_errno.h"
#include "samgr_lite.h"
#include "securec.h"
#define INVALID_IPC_TOKEN 0
#define INVALID_IPC_HANDLE (-1)
