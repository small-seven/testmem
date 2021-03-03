#include "example.h"
#include <ohos_init.h>
#include <pthread.h>
#include <log.h>
#include <ohos_errno.h>
#include "iproxy_server.h"
#include "feature.h"
#include "service.h"
#include "samgr_lite.h"
typedef struct ExampleService {
    INHERIT_SERVICE;
    INHERIT_IUNKNOWNENTRY(DefaultFeatureApi);
    Identity identity;
} ExampleService;
