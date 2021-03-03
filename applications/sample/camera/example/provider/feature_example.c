#include "example.h"
#include <ohos_init.h>
#include <securec.h>
#include <samgr_maintenance.h>
#include <log.h>
#include <unistd.h>
#include <pthread.h>
#include <ohos_errno.h>
#include "feature.h"
#include "service.h"
#include "samgr_lite.h"
#define WAIT_FEATURE_PROC 1000
typedef struct DemoFeatureApi {
    INHERIT_SERVER_IPROXY;
    BOOL (*AsyncCall)(IUnknown *iUnknown, const char *buff);
    BOOL (*AsyncTimeCall)(IUnknown *iUnknown);
    BOOL (*SyncCall)(IUnknown *iUnknown, struct Payload *payload);
    BOOL (*AsyncCallBack)(IUnknown *iUnknown, const char *buff, IOwner notify, INotifyFunc handler);
} DemoFeatureApi;
typedef struct DemoFeature {
    INHERIT_FEATURE;
    INHERIT_IUNKNOWNENTRY(DemoFeatureApi);
    Identity identity;
} DemoFeature;
typedef struct AsyncBody {
    IOwner owner;
    INotifyFunc handler;
    char body[0];
} AsyncBody;
