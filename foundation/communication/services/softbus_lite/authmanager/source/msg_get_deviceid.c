#include "msg_get_deviceid.h"
#include "message.h"
#define CMD_TAG "TECmd"
#define DATA_TAG "TEData"
#define DEVICEID_TAG "TEDeviceId"
#define CMD_GET_AUTH_INFO "getAuthInfo"
#define CMD_RET_AUTH_INFO "retAuthInfo"
#define DEVICE_CONN_CAP_WIFI 0x1f
#if defined(__LITEOS_M__) || defined(__LITEOS_RISCV__)
#define DEVICE_TYPE_DEFAULT "DEV_L0"
#else
#define DEVICE_TYPE_DEFAULT "DEV_L1"
#endif
