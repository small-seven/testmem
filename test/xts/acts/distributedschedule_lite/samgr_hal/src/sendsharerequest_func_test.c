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
    uint32 *(*SAMGR_SendSharedRequestProxy)(const Identity *identity, const Request *request, uint32 *token, 
                                            Handler handler);
    int32 (*SAMGR_SendSharedDirectRequestProxy)(const Identity *id, const Request *req, const Response *resp, 
                                                uint32 **ref, Handler handler);
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
