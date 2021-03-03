#include "wifi_device_util.h"
#include <stdio.h>
#include "cmsis_os.h"
#include "common.h"
#include "hos_init.h"
#include "wifi_hotspot_config.h"
#define WIFI_WAIT_FOREVER 0xFFFFFFFF
#define CHANNEL_80211B_ONLY 14
#define FREQ_OF_CHANNEL_1 2412
#define FREQ_OF_CHANNEL_80211B_ONLY 2484
#define WIFI_MIN_CHANNEL 1
#define WIFI_FREQ_INTERVAL 5
