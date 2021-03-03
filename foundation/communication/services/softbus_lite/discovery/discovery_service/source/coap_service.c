#include "coap_service.h"
#include "coap_discover.h"
#include "coap_socket.h"
#include "common_info_manager.h"
#include "discovery_error.h"
#include "nstackx.h"
#include "os_adapter.h"
#include "securec.h"
#define DEV_HASH_ID 0
#define WLAN_NAME "wlan0"
#define DEV_DEFAULT_TYPE 14
typedef struct {
    char packageName[MAX_PACKAGE_NAME];
    unsigned int capabilityBitmap[MAX_CAPABILITY_NUM];
    char custData[MAX_SERVICE_DATA_LEN];
} PackageModule;
int CoapDeinit(void)
{
    int ret = NSTACKX_Deinit();
    if (ret != 0) {
        return ret;
    }
    return ERROR_SUCCESS;
}
