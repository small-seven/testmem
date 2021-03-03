#include <stdlib.h>
#include <string.h>
#include <los_base.h>
#include "securec.h"
#include "hctest.h"
#include "samgr_lite.h"
#define OPER_INTERVAL 200 // 200 ms
#define SERVICE_NUM 4
#define INDEX0 0
#define INDEX1 1
#define INDEX2 2
#define INDEX3 3
typedef struct Node {
    int id;
    const char *name;
} Node;
typedef struct DemoApi {
    INHERIT_IUNKNOWN;
    BOOL (*FeatureApi001)(IUnknown *iUnknown, char *para1);
    int32 (*SendRequestProxyF)(const Identity *identity, const Request *request, Handler handler);
} DemoApi;
typedef struct DemoFeature {
    INHERIT_FEATURE;
    INHERIT_IUNKNOWNENTRY(DemoApi);
    Identity identity;
    int featureCalledCount;
} DemoFeature;
typedef struct DefaultFeatureApi {
    INHERIT_IUNKNOWN;
    BOOL (*DefaultApi001)(IUnknown *iUnknown, char *para1);
    int32 (*SendRequestProxyDF)(const Identity *identity, const Request *request, Handler handler);
} DefaultFeatureApi;
typedef struct DemoService {
    INHERIT_SERVICE;
    INHERIT_IUNKNOWNENTRY(DefaultFeatureApi);
    Identity identity;
    int serviceCalledCount;
} DemoService;
