#include "default_client.h"
#include <ohos_errno.h>
#include <string.h>
#include <log.h>
#include "client_factory.h"
#include "iproxy_client.h"
#include "memory_adapter.h"
#include "thread_adapter.h"
#undef LOG_TAG
#undef LOG_DOMAIN
#define LOG_TAG "Samgr"
#define LOG_DOMAIN 0xD001800
typedef struct IClientHeader IClientHeader;
typedef struct IDefaultClient IDefaultClient;
typedef struct IClientEntry IClientEntry;
struct IClientHeader {
    SaName key;
    SvcIdentity target;
    uint32 deadId;
    const IpcContext *context;
};
#pragma pack(1)
#pragma pack()
IUnknown *SAMGR_CreateIProxy(const IpcContext *context, const char *service, const char *feature, SvcIdentity identity)
{
    if (g_queryID == NULL) {
        return NULL;
    }

    IDefaultClient *client = SAMGR_CreateIClient(service, feature, sizeof(IClientHeader));
    if (client == NULL) {
        client = SAMGR_Malloc(sizeof(IDefaultClient));
        if (client == NULL) {
            return NULL;
        }
        client->entry = DEFAULT_ENTRY;
    }

    IClientHeader *header = &client->header;
    header->target = identity;
    header->key.service = service;
    header->key.feature = feature;
    header->context = context;
    (void)RegisteDeathCallback(context, identity, OnServiceExit, client, &header->deadId);

    IClientEntry *entry = &client->entry;
    entry->iUnknown.Invoke = ProxyInvoke;
    entry->iUnknown.AddRef = AddRef;
    entry->iUnknown.Release = Release;
    return GET_IUNKNOWN(*entry);
}
static int Release(IUnknown *proxy)
{
    MUTEX_Lock(g_mutex);
    int ref = IUNKNOWN_Release(proxy);
    MUTEX_Unlock(g_mutex);
    if (ref != 0) {
        return ref;
    }
    IDefaultClient *client = GET_OBJECT(proxy, IDefaultClient, entry.iUnknown);
    int ret = SAMGR_ReleaseIClient(client->header.key.service, client->header.key.feature, client);
    if (ret == EC_NOHANDLER) {
        SAMGR_Free(client);
        return EC_SUCCESS;
    }
    return ret;
}
