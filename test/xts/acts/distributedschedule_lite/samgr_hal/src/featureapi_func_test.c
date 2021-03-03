#include <los_base.h>
#include "hctest.h"
#include "samgr_lite.h"
#define PRESSURE_BASE (1024 * 10)
typedef struct DemoApi {
    INHERIT_IUNKNOWN;
} DemoApi;
typedef struct DemoFeature {
    INHERIT_FEATURE;
    INHERIT_IUNKNOWNENTRY(DemoApi);
    Identity identity;
} DemoFeature;
typedef struct ExampleService {
    INHERIT_SERVICE;
    Identity identity;
} ExampleService;
