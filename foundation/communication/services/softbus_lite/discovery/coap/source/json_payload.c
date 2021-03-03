#include "json_payload.h"
#include <securec.h>
#include "cJSON.h"
#include "nstackx_device.h"
#include "nstackx_error.h"
#include "os_adapter.h"
#if defined(__LITEOS_M__) || defined(__LITEOS_RISCV__)
#else
#include <arpa/inet.h>
#endif
#define TAG "nStackXCoAP"
#define JSON_COAP_URI "coapUri"
#define JSON_CAPABILITY_BITMAP "capabilityBitmap"
#define JSON_DEVICE_ID "deviceId"
#define JSON_DEVICE_NAME "devicename"
#define JSON_DEVICE_WLAN_IP "wlanIp"
#define JSON_DEVICE_TYPE "type"
#define JSON_HICOM_VERSION "hicomversion"
#define JSON_REQUEST_MODE "mode"
#define JSON_DEVICE_HASH "deviceHash"
#define JSON_SERVICE_DATA "serviceData"
#define NSTACKX_MAX_URI_BUFFER_LENGTH 64
