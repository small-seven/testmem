#include "example.h"
#include <ohos_init.h>
#include <securec.h>
#include <los_base.h>
#include <cmsis_os.h>
#include <samgr_maintenance.h>
#include "iunknown.h"
#include "feature.h"
#include "service.h"
#include "samgr_lite.h"
#define WAIT_FEATURE_PROC 1000
typedef struct DemoApi {
    INHERIT_IUNKNOWN;
    BOOL (*AsyncCall)(IUnknown *iUnknown, const char *buff);
    BOOL (*AsyncTimeCall)(IUnknown *iUnknown);
    BOOL (*SyncCall)(IUnknown *iUnknown, struct Payload *payload);
    BOOL (*AsyncCallBack)(IUnknown *iUnknown, const char *buff, Handler handler);
} DemoApi;
typedef struct DemoFeature {
    INHERIT_FEATURE;
    INHERIT_IUNKNOWNENTRY(DemoApi);
    Identity identity;
} DemoFeature;
