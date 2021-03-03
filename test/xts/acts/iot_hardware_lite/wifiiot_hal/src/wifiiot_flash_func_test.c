#include "hos_types.h"
#include <hos_init.h>
#include <los_base.h>
#include <securec.h>
#include "hctest.h"
#include "hi_task.h"
#include "hi_time.h"
#include "samgr_lite.h"
#include "wifiiot_errno.h"
#include "wifiiot_flash.h"
#include "wifiiot_flash_ex.h"
#define TEST_FLASH_SIZE 8
#define TEST_FLASH_SIZE_4K 4096
#define TEST_FLASH_OFFSET 0x1FF000
