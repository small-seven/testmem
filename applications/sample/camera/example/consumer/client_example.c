#include "example.h"
#include <pthread.h>
#include <securec.h>
#include <ohos_errno.h>
#include <log.h>
#include <iproxy_client.h>
#define MAX_DATA_LEN 0x100
typedef struct DemoClientProxy {
    INHERIT_CLIENT_IPROXY;
    BOOL (*AsyncCall)(IUnknown *iUnknown, const char *buff);
    BOOL (*AsyncTimeCall)(IUnknown *iUnknown);
    BOOL (*SyncCall)(IUnknown *iUnknown, struct Payload *payload);
    BOOL (*AsyncCallBack)(IUnknown *iUnknown, const char *buff, IOwner notify, INotifyFunc handler);
} DemoClientProxy;
typedef struct DemoClientEntry {
    INHERIT_IUNKNOWNENTRY(DemoClientProxy);
} DemoClientEntry;
void DEMO_DestroyClient(const char *service, const char *feature, void *iproxy)
{
    free(iproxy);
}
