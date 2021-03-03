#include "discovery_service.h"
#include "bus_manager.h"
#include "coap_discover.h"
#include "coap_service.h"
#include "common_info_manager.h"
#include "discovery_error.h"
#include "os_adapter.h"
#include "securec.h"
#ifdef __cplusplus
#endif
typedef struct {
    char package[MAX_PACKAGE_NAME];
    int publishId;
    unsigned short medium;
    unsigned short capabilityBitmap;
    char *capabilityData;
    unsigned short dataLength;
    unsigned short used;
} PublishModule;
typedef struct {
    char deviceId[MAX_DEV_ID_LEN];
    char deviceName[MAX_DEV_NAME_LEN];
    int  deviceType;
} ConfigDeviceInfo;
#define MAX_MODULE_COUNT 3
#define INVALID_SEM_ID 0xffffffff
#define SOFTBUS_PERMISSION  "ohos.permission.DISTRIBUTED_DATASYNC"
int DeinitService(void)
{
    int ret = BusManager(0);
    if (ret != ERROR_SUCCESS) {
        SOFTBUS_PRINT("[DISCOVERY] DeinitService BusManager(0) fail\n");
    }

    if (g_publishModule) {
        free(g_publishModule);
        g_publishModule = NULL;
    }

    if (g_capabilityData) {
        free(g_capabilityData);
        g_capabilityData = NULL;
    }

    ret = CoapDeinit();
    if (ret != ERROR_SUCCESS) {
        SOFTBUS_PRINT("[DISCOVERY] DeinitService CoapDeinit fail\n");
    }

    RegisterWifiCallback(NULL);
    DeinitCommonManager();
    g_isServiceInit = 0;
    return ERROR_SUCCESS;
}
#if defined(__LITEOS_M__) || defined(__LITEOS_RISCV__)
#endif
#if defined(__LITEOS_A__) || defined(__LINUX__)
#endif
unsigned int IsAllModuleFree(void)
{
    if (g_publishModule == NULL) {
        return 1;
    }

    for (int i = 0; i < MAX_MODULE_COUNT; i++) {
        if (g_publishModule[i].used == 1) {
            return 0;
        }
    }

    return 1;
}
PublishModule *FindFreeModule(void)
{
    if (g_publishModule == NULL) {
        return NULL;
    }

    for (int i = 0; i < MAX_MODULE_COUNT; i++) {
        if (g_publishModule[i].used == 1) {
            continue;
        }
        return &g_publishModule[i];
    }

    return NULL;
}
#ifdef COAP_DEBUG
#endif
