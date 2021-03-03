#include "example.h"
#include <feature.h>
#include <securec.h>
#include <ohos_init.h>
#include <samgr_lite.h>
#include <cmsis_os.h>
typedef struct BootTestExample {
    Service service;
    Feature feature;
} BootTestExample;
