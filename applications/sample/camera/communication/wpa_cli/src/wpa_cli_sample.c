#include "utils/includes.h"
#include "pthread.h"
#include "common/wpa_ctrl.h"
#include "securec.h"
#define WPA_IFACE_NAME "wlan0"
#define WIFI_AUTH_FAILED_REASON_STR "WRONG_KEY"
#define WIFI_AUTH_FAILED_REASON_CODE "reason=2"
#define WPA_CTRL_REQUEST_OK "OK"
#define WPA_CTRL_REQUEST_FAIL "FAIL"
#define SAMPLE_INFO(format, args...) \
#define SAMPLE_ERROR(format, args...) \
