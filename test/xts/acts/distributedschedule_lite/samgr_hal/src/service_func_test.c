#include <string.h>
#include <los_base.h>
#include "hctest.h"
#include "samgr_lite.h"
#define OPER_INTERVAL 200    // 200 ms
#define PRESSURE_BASE (1024 * 10)
typedef struct DefaultFeatureApi {
    INHERIT_IUNKNOWN;
} DefaultFeatureApi;
typedef struct ExampleService {
    INHERIT_SERVICE;
    INHERIT_IUNKNOWNENTRY(DefaultFeatureApi);
    Identity identity;
} ExampleService;
typedef struct DemoApi {
    INHERIT_IUNKNOWN;
} DemoApi;
typedef struct DemoFeature {
    INHERIT_FEATURE;
    INHERIT_IUNKNOWNENTRY(DemoApi);
    Identity identity;
} DemoFeature;
