#include <stdlib.h>
#include <string.h>
#include <los_base.h>
#include "securec.h"
#include "hctest.h"
#include "samgr_lite.h"
#define OPER_INTERVAL 200    // 200 ms
#define PRESSURE_BASE (1024 * 10)
typedef struct DemoApi {
    INHERIT_IUNKNOWN;
    BOOL(*SyncCall)
    (IUnknown *iUnknown, struct Payload *payload);
    int32 (*SAMGR_SendRequestProxy)(const Identity *identity, const Request *request, Handler handler);
} DemoApi;
typedef struct DemoFeature {
    INHERIT_FEATURE;
    INHERIT_IUNKNOWNENTRY(DemoApi);
    Identity identity;
    int featureCalledCount;
    BOOL featureStatus;
    char *latestRequest;
} DemoFeature;
typedef struct DefaultFeatureApi {
    INHERIT_IUNKNOWN;
} DefaultFeatureApi;
typedef struct ExampleService {
    INHERIT_SERVICE;
    INHERIT_IUNKNOWNENTRY(DefaultFeatureApi);
    Identity identity;
} ExampleService;
