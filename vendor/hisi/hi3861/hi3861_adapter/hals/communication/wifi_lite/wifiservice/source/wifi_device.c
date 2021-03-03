#include "wifi_device.h"
#include <securec.h>
#include <stdio.h>
#include <stdlib.h>
#include "wifi_device_util.h"
#include "wifi_hotspot_config.h"
#define WIFI_RECONN_POLICY_ENABLE        1
#define WIFI_RECONN_POLICY_TIMEOUT       60
#define WIFI_RECONN_POLICY_PERIOD        600
#define WIFI_RECONN_POLICY_MAX_TRY_COUNT 3
#define WIFI_DISCONNECT_REASON_NO_AP     1
#define WIFI_DEFAULT_KEY_FOR_PSK    "wifipskmode"
