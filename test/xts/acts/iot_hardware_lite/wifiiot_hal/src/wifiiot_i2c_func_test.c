#include "hos_types.h"
#include <hos_init.h>
#include <los_base.h>
#include <securec.h>
#include "hctest.h"
#include "hi_task.h"
#include "hi_time.h"
#include "samgr_lite.h"
#include "wifiiot_errno.h"
#ifdef CONFIG_I2C_SUPPORT
#include "wifiiot_i2c.h"
#include "wifiiot_i2c_ex.h"
#endif
#define SEND_RECV_LEN 3
#define AT24C02_1K 0xa0
#define INIT_BAUD_RATE 10000
#define SET_BAUD_RATE 19200
#ifdef CONFIG_I2C_SUPPORT
#endif
