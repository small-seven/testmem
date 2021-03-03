#include <unistd.h>
#include "lwip/ip4_addr.h"
#include "lwip/netif.h"
#include "lwip/netifapi.h"
#include "cmsis_os2.h"
#include "hos_init.h"
#include "hos_types.h"
#include "netcfg_service.h"
#include "wifi_device_config.h"
#include "wifiiot_gpio.h"
#include "wifiiot_gpio_ex.h"
#define SAMPLE_SEND_BUF_SIZE 400
#define SAMPLE_LED_INTERVAL_TIME_US 300000
#define SAMPLE_BIZ_SLEEP_TIME_US    1000000
#define SAMPLE_TASK_STACK_SIZE 4048
#define SAMPLE_TASK_PRIO 25
#define TEST_NUM_2 2
#define TEST_NUM_3 3
#define TEST_NUM_4 4
#define TEST_NUM_5 5
#define TEST_CONNECT_RETRY_COUNT 5
#define SAMPLE_NETCFG_DEFAULT_DB (-61)
#define SAMPLE_NETCFG_DEFAULT_ACK_TIMEOUT 3
#define SAMPLE_NETCFG_DEFAULT_HEARTBEAT_TIMEOUT 60;
#define SAMPLE_TIME_COUNT 5
