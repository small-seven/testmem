#include <ohos_errno.h>
#include <pthread.h>
#include <securec.h>
#include <stdio.h>
#include "cJSON.h"
#include "iproxy_client.h"
#include "liteipc_adapter.h"
#include "log.h"
#include "pms_interface.h"
#include "pms_types.h"
#include "registry.h"
#include "samgr_lite.h"
#define PERMISSION_SERVICE "permissionms"
#define PERM_FEATURE "PmsFeature"
#define MAX_DATA_LEN 0x100
#define FIELD_PERMISSION "permissions"
#define FIELD_NAME "name"
#define FIELD_DESC "desc"
#define FIELD_IS_GRANTED "isGranted"
#define SYS_SVC_UID_MAX 99
typedef struct ClientApi {
    INHERIT_CLIENT_IPROXY;
    int (*CheckPermission)(int taskID, const char *permissionName);
    int (*QueryPermission)(const char *identifier, PermissionSaved **permissions, int *permNum);
    int (*GrantPermission)(const char *identifier, const char *permName);
    int (*RevokePermission)(const char *identifier, const char *permName);
    int (*GrantRuntimePermission)(int taskID, const char *permissionName);
    int (*RequestPermission)(int taskID, const char *permissionName);
} ClientApi;
typedef struct ClientEntry {
    INHERIT_IUNKNOWNENTRY(ClientApi);
} ClientEntry;
typedef struct RetOfQueryPerms {
    int resultCode;
    int length;
    PermissionSaved *permission;
} RetOfQueryPerms;
void DestroyClient(const char *service, const char *feature, void *iproxy)
{
    free(iproxy);
}
static void ReleaseClientApi(ClientApi *clientApi)
{
    if (clientApi == NULL) {
        return;
    }
    int32 ref = clientApi->Release((IUnknown *)clientApi);
    HILOG_INFO(HILOG_MODULE_APP, "[Release api S:%s, F:%s]: is %p ref:%d\n",
               PERMISSION_SERVICE, PERM_FEATURE, clientApi, ref);
}
