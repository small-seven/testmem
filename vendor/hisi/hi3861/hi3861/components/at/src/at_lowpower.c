#include "at_lowpower.h"
#ifndef CONFIG_FACTORY_TEST_MODE
#include "lwip/ip_addr.h"
#endif
#include "hi_at.h"
#include "hi_gpio.h"
#include "hi_io.h"
#include "hi_lowpower.h"
#include "hi_stdlib.h"
#include "hi_time.h"
#include "hi_types_base.h"
#include "hi_watchdog.h"
#include "hi_wifi_api.h"
#include "at.h"
#include "at_io.h"
#define MILLISECOND_PER_TICK     10
#define GPIO3_WAKE_UP_SOURCE     3
#define GPIO5_WAKE_UP_SOURCE     5
#define GPIO7_WAKE_UP_SOURCE     7
#define GPIO14_WAKE_UP_SOURCE    14
#define ALL_GPIO_WAKE_UP_SOURCE  0
#define IO0_GPIO_MODE            0
#define IO1_GPIO_MODE            0
#define IO2_GPIO_MODE            0
#define IO3_GPIO_MODE            0
#define IO4_GPIO_MODE            0
#define IO5_GPIO_MODE            0
#define IO6_GPIO_MODE            0
#define IO7_GPIO_MODE            0
#define IO8_GPIO_MODE            0
#define IO9_GPIO_MODE            0
#define IO10_GPIO_MODE           0
#define IO11_GPIO_MODE           0
#define IO12_GPIO_MODE           0
#define IO13_GPIO_MODE           4
#define IO14_GPIO_MODE           4
#ifndef CONFIG_FACTORY_TEST_MODE
#endif
#ifndef CONFIG_FACTORY_TEST_MODE
#endif
#define AT_LOWPOWER_FUNC_NUM (sizeof(g_at_lowpower_func_tbl) / sizeof(g_at_lowpower_func_tbl[0]))
