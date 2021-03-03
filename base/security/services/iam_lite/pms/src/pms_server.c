#include <ohos_init.h>
#include <ohos_errno.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include "log.h"
#include "feature.h"
#include "iproxy_client.h"
#include "iproxy_server.h"
#include "iunknown.h"
#include "liteipc_adapter.h"
#include "samgr_lite.h"
#include "service.h"
#include "pms.h"
#include "pms_common.h"
#include "pms_types.h"
#define SYS_APP_UID_MIN 100
#define SYS_APP_UID_MAX 999
typedef struct PermLiteApi {
    INHERIT_SERVER_IPROXY;
    int (*CheckPermission)(int taskID, const char *permissionName);
    int (*QueryPermission)(const char *identifier, PermissionSaved **permissions, int *permNum);
    int (*GrantPermission)(const char *identifier, const char *permName);
    int (*RevokePermission)(const char *identifier, const char *permName);
    int (*GrantRuntimePermission)(int taskID, const char *permissionName);
    int (*RequestPermission)(int taskID, const char *permissionName);
} PermLiteApi;
typedef struct PermLite {
    INHERIT_FEATURE;
    INHERIT_IUNKNOWNENTRY(PermLiteApi);
    Identity identity;
} PermLite;
void static InnerFreeDataBuff(void *ptr)
{
    if (ptr != NULL) {
        free(ptr);
    }
}
