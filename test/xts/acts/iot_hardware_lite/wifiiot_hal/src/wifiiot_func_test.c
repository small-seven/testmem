#include "hos_types.h"
#include <hos_init.h>
#include <los_base.h>
#include <securec.h>
#include "hctest.h"
#include "hi_task.h"
#include "hi_time.h"
#include "samgr_lite.h"
#include "wifiiot_errno.h"
#include "wifiiot_watchdog.h"
#include "wifiiot_partition.h"
#include "wifiiot_at.h"
#include "wifiiot_kal.h"
#ifdef CONFIG_I2S_SUPPORT
#include "wifiiot_i2s.h"
#endif
#ifdef CONFIG_PWM_SUPPORT
#include "wifiiot_pwm.h"
#endif
#define TEST_REGISTER_CMD 2
#define TEST_PWM_PORT 1200
#define TEST_PWM_DUTY 1500
#define TEST_I2S_SIZE 8
#define TEST_I2S_TIMEOUT 1000
#ifdef CONFIG_PWM_SUPPORT
#endif
#ifdef CONFIG_I2S_SUPPORT
#endif
