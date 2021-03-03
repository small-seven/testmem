#include "example.h"
#include <ohos_init.h>
#include <securec.h>
#include <los_base.h>
#include <cmsis_os.h>
#include "iunknown.h"
#include "feature.h"
#include "service.h"
#include "samgr_lite.h"
typedef struct DefaultFeatureApi {
    INHERIT_IUNKNOWN;
    void (*SyncCall)(IUnknown *iUnknown);
} DefaultFeatureApi;
typedef struct ExampleService {
    INHERIT_SERVICE;
    INHERIT_IUNKNOWNENTRY(DefaultFeatureApi);
    Identity identity;
} ExampleService;
