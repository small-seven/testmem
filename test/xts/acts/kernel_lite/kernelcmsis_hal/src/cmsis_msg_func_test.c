#include "hos_types.h"
#include <securec.h>
#include "hctest.h"
#include "los_config.h"
#include "cmsis_os2.h"
#include "kernel_test.h"
#define MSGQUEUE_COUNT    16
#define MSGQUEUE_SPACE_COUNT    13
#define MSGQUEUE_PUT_COUNT    3
#define MSG_SIZE    4
#define MSGINFO_LEN    4
#define TIMEOUT_COUNT    1000
#define BUF_LEN    32
#define MSGQUEUE_COUNT_INDEX_0    0
#define MSGQUEUE_COUNT_INDEX_1    1
#define MSGQUEUE_COUNT_INDEX_2    2
