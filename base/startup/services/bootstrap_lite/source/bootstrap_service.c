#include "bootstrap_service.h"
#include <ohos_init.h>
#include "samgr_lite.h"
#define LOAD_FLAG 0x01
typedef struct Bootstrap {
    INHERIT_SERVICE;
    Identity identity;
    uint8 flag;
} Bootstrap;
