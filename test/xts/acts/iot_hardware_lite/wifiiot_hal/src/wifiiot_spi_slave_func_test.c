#include "hos_types.h"
#include <hos_init.h>
#include <los_base.h>
#include <securec.h>
#include "hctest.h"
#include "hi_task.h"
#include "hi_time.h"
#include "samgr_lite.h"
#include "wifiiot_errno.h"
#ifdef CONFIG_SPI_SUPPORT
#include "wifiiot_spi.h"
#endif
#define TEST_SPI_SIZE 20
#define TEST_FREQ_SIZE 2000000
#define TEST_SPI_TIMEOUT 1000
#ifdef CONFIG_SPI_SUPPORT
#endif
