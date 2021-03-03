#include <unistd.h>
#include "lwip/netif.h"
#include "lwip/netifapi.h"
#include "lwip/ip4_addr.h"
#include "base64.h"
#include "cmsis_os2.h"
#include "hos_types.h"
#include "network_config_service.h"
#include "wifi_device_config.h"
#include "wifiiot_gpio.h"
#include "wifiiot_gpio_ex.h"
#define SAMPLE_LED_INTERVAL_TIME_US 300000
#define SAMPLE_BIZ_SLEEP_TIME_US    1000000
#define SAMPLE_TIME_COUNT 5
#define DEVICE_INFO_NUM 2
#define POWER_NUM (-52)
#define MAX_DATA_LEN 4096
#define CHANNEL_80211B_ONLY 14
#define FREQ_OF_CHANNEL_1 2412
#define FREQ_OF_CHANNEL_80211B_ONLY 2484
#define WIFI_MIN_CHANNEL 1
#define WIFI_FREQ_INTERVAL 5
#define SAMPLE_TASK_STACK_SIZE 4048
#define SAMPLE_TASK_PRIO 25
#define TEST_NUM_2 2
#define TEST_NUM_3 3
#define TEST_NUM_4 4
#define TEST_NUM_5 5
#define TEST_CONNECT_RETRY_COUNT 5
