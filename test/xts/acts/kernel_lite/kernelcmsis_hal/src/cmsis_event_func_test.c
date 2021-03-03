#include "hos_types.h"
#include <securec.h>
#include "hctest.h"
#include "los_config.h"
#include "cmsis_os2.h"
#include "kernel_test.h"
#define EVENT_MASK_HEX_1 0x01
#define EVENT_MASK_HEX_2 0x02
#define EVENT_MASK_HEX_4 0x04
#define EVENT_MASK_HEX_10 0x10
#define EVENT_MASK_HEX_11 0x11
#define TIMEOUT_NUM_3 3
#define TIMEOUT_NUM_10 10
#define INVALID_FLAG_OPTION 0x00000004U
