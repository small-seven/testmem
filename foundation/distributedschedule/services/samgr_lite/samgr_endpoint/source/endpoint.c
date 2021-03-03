#include "endpoint.h"
#include <stdlib.h>
#include <securec.h>
#include <ohos_errno.h>
#include <service.h>
#include <log.h>
#include "iproxy_server.h"
#include "memory_adapter.h"
#include "thread_adapter.h"
#include "default_client.h"
#undef LOG_TAG
#undef LOG_DOMAIN
#define LOG_TAG "Samgr"
#define LOG_DOMAIN 0xD001800
#define MAX_STACK_SIZE 0x1000
#define MAX_OBJECT_NUM 5
#define MAX_RETRY_TIMES 3
#define RETRY_INTERVAL 5
#define MAX_REGISTER_RETRY_TIMES 10
#define REGISTER_RETRY_INTERVAL 2
#ifndef MAX_BUCKET_RATE
#define MAX_BUCKET_RATE 1000
#endif
#ifndef MAX_BURST_RATE
#define MAX_BURST_RATE (MAX_BUCKET_RATE + (MAX_BUCKET_RATE >> 1))
#endif
#define SAMGR_SERVICE "samgr"
typedef struct Router {
    SaName saName;
    Identity identity;
    IServerProxy *proxy;
    PolicyTrans *policy;
    uint32 policyNum;
} Router;
Endpoint *SAMGR_CreateEndpoint(const char *name, RegisterEndpoint registry)
{
    Endpoint *endpoint = SAMGR_Malloc(sizeof(Endpoint));
    if (endpoint == NULL) {
        return NULL;
    }
    endpoint->deadId = INVALID_INDEX;
    endpoint->context = OpenLiteIpc(LITEIPC_DEFAULT_MAP_SIZE);
    endpoint->boss = NULL;
    endpoint->routers = VECTOR_Make((VECTOR_Key)GetIServerProxy, (VECTOR_Compare)CompareIServerProxy);
    endpoint->name = name;
    endpoint->running = FALSE;
    endpoint->identity.handle = (uint32_t)INVALID_INDEX;
    endpoint->identity.token = (uint32_t)INVALID_INDEX;
    endpoint->identity.cookie = (uint32_t)INVALID_INDEX;
    endpoint->registerEP = (registry == NULL) ? RegisterRemoteEndpoint : registry;
    TB_InitBucket(&endpoint->bucket, MAX_BUCKET_RATE, MAX_BURST_RATE);
    return endpoint;
}
#ifdef LITE_LINUX_BINDER_IPC
#else
#endif
