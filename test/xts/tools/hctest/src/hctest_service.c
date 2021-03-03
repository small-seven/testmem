#include "bootstrap_service.h"
#include "samgr_lite.h"
#include <hos_init.h>
#include <securec.h>
#include <los_base.h>
#include "service.h"
#include "common.h"
#include "hctest_internal.h"
typedef struct TestService {
    INHERIT_SERVICE;
    Identity identity;
    uint8 flag;
} TestService;
