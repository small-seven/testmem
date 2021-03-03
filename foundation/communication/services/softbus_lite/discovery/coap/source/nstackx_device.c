#include "nstackx_device.h"
#include <securec.h>
#include "nstackx_error.h"
#include "os_adapter.h"
#define NSTACKX_DEFAULT_DEVICE_NAME "nStack Device"
#define NSTACKX_RESERVED_INFO_WIFI_IP "wifiIpAddr"
#define NSTACKX_WLAN_INDEX 0
#define NSTACKX_ETH_INDEX 1
#define NSTACKX_MAX_INTERFACE_NUM 4
#define NETWORKTYPE_LENGTH 20
