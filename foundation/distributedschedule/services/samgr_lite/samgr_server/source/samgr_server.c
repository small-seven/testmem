#include "samgr_server.h"
#include <stdlib.h>
#include <ohos_init.h>
#include <ohos_types.h>
#include <ohos_errno.h>
#include <liteipc_adapter.h>
#include <log.h>
#include "policy_define.h"
#include "samgr_lite.h"
#include "memory_adapter.h"
#include "thread_adapter.h"
#include "default_client.h"
#undef LOG_TAG
#undef LOG_DOMAIN
#define LOG_TAG "Samgr"
#define LOG_DOMAIN 0xD001800
typedef int(*ProcFunc)(SamgrServer *server, int32 option, void *origin, IpcIo *req, IpcIo *reply);
#define MAX_SA_SIZE 0x100
#define RETRY_TIMES 3
#define RETRY_INTERVAL 1

static const char *GetName(Service *service);
static BOOL Initialize(Service *service, Identity identity);
static TaskConfig GetTaskConfig(Service *service);
static BOOL MessageHandle(Service *service, Request *request);
static int32 Invoke(IServerProxy *iProxy, int funcId, void *origin, IpcIo *req, IpcIo *reply);
static int OnEndpointExit(const IpcContext *context, void* ipcMsg, IpcIo* data, void* argv);
static int ProcEndpoint(SamgrServer *server, int32 option, void *origin, IpcIo *req, IpcIo *reply);
static int32 ProcPutFeature(SamgrServer *server, const void *origin, IpcIo *req, IpcIo *reply, SvcIdentity *identity);
static int32 ProcGetFeature(SamgrServer *server, const void *origin, IpcIo *req, IpcIo *reply, SvcIdentity *identity);
static int ProcFeature(SamgrServer *server, int32 option, void *origin, IpcIo *req, IpcIo *reply);
static SvcIdentity QueryLocalIdentity(const char *service, const char *feature);
static int RegisterLocalIdentity(const char *service, const char *feature, SvcIdentity *identity,
                                 PolicyTrans **policy, uint32 *policyNum);
static int RegisterSamgrEndpoint(const IpcContext* context, SvcIdentity* identity);
static void TransmitPolicy(int ret, const SvcIdentity* identity, IpcIo *reply,
                           const PolicyTrans *policy, uint32 policyNum);
static void TransmitFixedPolicy(IpcIo *reply, PolicyTrans policy);
static IpcAuthInterface *GetIpcAuthInterface(void);

static SamgrServer g_server = {
    .GetName = GetName,
    .Initialize = Initialize,
    .GetTaskConfig = GetTaskConfig,
    .MessageHandle = MessageHandle,
    SERVER_IPROXY_IMPL_BEGIN,
    .Invoke = Invoke,
    IPROXY_END,
};
