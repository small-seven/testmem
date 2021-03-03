#include "nstackx_common.h"
#include <securec.h>
#include "cJSON.h"
#include "coap_discover.h"
#include "nstackx.h"
#include "nstackx_device.h"
#include "nstackx_error.h"
#include "os_adapter.h"
int NSTACKX_Deinit(void)
{
    if (g_nstackInitState == NSTACKX_INIT_STATE_START) {
        return NSTACKX_EOK;
    }

    int ret = CoapDeinitDiscovery();
    if (ret != NSTACKX_EOK) {
        return ret;
    }

    ClearLocalData();
    g_nstackInitState = NSTACKX_INIT_STATE_START;
    return NSTACKX_EOK;
}
typedef struct {
    uint32_t capabilityBitmapNum;
    uint32_t capabilityBitmap[NSTACKX_MAX_CAPABILITY_NUM];
} CapabilityProcessData;
