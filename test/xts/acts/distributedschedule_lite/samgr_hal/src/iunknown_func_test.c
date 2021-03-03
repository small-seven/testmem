#include <los_base.h>
#include <hos_errno.h>
#include "hctest.h"
#include "samgr_lite.h"
#define SERVICE_NAME "S_iunknown"
#define FEATURE_NAME "F_iunknown"
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
