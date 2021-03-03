#include "wpa_hal_cmd.h"
#include "wpa_hal.h"
#include "hdf_sbuf.h"
#include "utils/hdf_base.h"
#include "wpa_hal_service.h"
#include "common.h"
#include "driver.h"
#include "securec.h"
#include <stdint.h>
#ifdef __cplusplus
#if __cplusplus
#endif
#endif
#define DEFAULT_EAPOL_PACKAGE_SIZE 800
int32_t WifiWpaCmdStaRemove(const char *ifname, const uint8_t *addr, uint32_t addrLen)
{
    if (ifname == NULL || addr == NULL) {
        return -EFAIL;
    }
    struct HdfSBuf *data = HdfSBufObtainDefaultSize();
    if (data == NULL) {
        return -EFAIL;
    }
    bool isSerializeFailed = false;
    isSerializeFailed = isSerializeFailed || !HdfSbufWriteString(data, ifname);
    isSerializeFailed = isSerializeFailed || !HdfSbufWriteBuffer(data, addr, addrLen);
    int32_t ret;
    if (isSerializeFailed) {
        wpa_printf(MSG_ERROR, "Serialize failed!");
        ret = -EFAIL;
    } else {
        ret = WifiWpaCmdBlockSyncSend(WIFI_WPA_CMD_STA_REMOVE, data, NULL);
    }
    HdfSBufRecycle(data);
    return ret;
}
#ifdef __cplusplus
#if __cplusplus
#endif
#endif
