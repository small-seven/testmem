#include "hos_types.h"
#include <hos_init.h>
#include <los_base.h>
#include <securec.h>
#include "hctest.h"
#include "hi_task.h"
#include "hi_time.h"
#include "samgr_lite.h"
#include "wifiiot_errno.h"
#include "wifiiot_uart.h"
#include "wifiiot_uart_ex.h"
#define TEST_UART_SIZE 8
#define INIT_BAUD_RATE 115200
#define TEST_BUF_SIZE 10000
