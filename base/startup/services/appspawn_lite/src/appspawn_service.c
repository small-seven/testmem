#include "appspawn_service.h"
#include <stdlib.h>
#include "appspawn_message.h"
#include "appspawn_process.h"
#include "iproxy_server.h"
#include "iunknown.h"
#include "liteipc_adapter.h"
#include "log.h"
#include "message.h"
#include "ohos_errno.h"
#include "ohos_init.h"
#include "samgr_lite.h"
#include "service.h"
#ifdef __cplusplus
#if __cplusplus
#endif /* __cpluscplus */
#endif /* __cpluscplus */
typedef struct AppSpawnFeatureApi {
    INHERIT_SERVER_IPROXY;
} AppSpawnFeatureApi;
typedef struct AppSpawnService {
    INHERIT_SERVICE;
    INHERIT_IUNKNOWNENTRY(AppSpawnFeatureApi);
    Identity identity;
} AppSpawnService;
#ifdef __cplusplus
#if __cplusplus
#endif /* __cpluscplus */
#endif /* __cpluscplus */
