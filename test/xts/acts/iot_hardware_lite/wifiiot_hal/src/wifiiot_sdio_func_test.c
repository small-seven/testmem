#include "hos_types.h"
#include <hos_init.h>
#include <los_base.h>
#include <securec.h>
#include "hctest.h"
#include "hi_task.h"
#include "hi_time.h"
#include "samgr_lite.h"
#include "wifiiot_errno.h"
#include "wifiiot_sdio.h"
#define TEST_SDIO_LENGTH 8
#define TEST_REG_NUM 10
#define TEST_BYTE_NUM 100
#define MAX_ADMA_INDEX 130
#define MAX_MSG_VALUE 31
#define ADMA_TABLE_PARAM 666
