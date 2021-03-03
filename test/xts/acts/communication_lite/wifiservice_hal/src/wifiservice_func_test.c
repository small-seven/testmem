#include "hctest.h"
#include "hos_types.h"
#include "wifi_device.h"
#include "wifi_hotspot.h"
#include "lwip/netif.h"
#include "lwip/netifapi.h"
#include "lwip/ip4_addr.h"
#include "cmsis_os2.h"
#include <unistd.h>
#define DEF_TIMEOUT 15
#define ONE_SECOND 1
#define LEVEL_ERROR (-1)
#define LEVEL_ONE 1
#define LEVEL_TWO 2
#define LEVEL_THREE 3
#define LEVEL_FOUR 4
#define DEF_TASK_STACK 2000
#define DEF_TASK_PRIORITY 20
#define DEPE_AP_SSID "xts_execute"
#define DEF_NET_IF "wlan0"
