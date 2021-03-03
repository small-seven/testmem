#include "wpa_hal_service.h"
#include "wpa_hal_event.h"
#include "hdf_log.h"
#include "hdf_sbuf.h"
#include "utils/hdf_base.h"
#include "hdf_io_service.h"
#ifdef __cplusplus
#if __cplusplus
#endif
#endif
void WpaMsgServiceDeinit(void)
{
    if (HdfDeviceUnregisterEventListener(g_wifiService, &g_wifiEventListener)) {
        HDF_LOGE("fail to  unregister listener");
        return;
    }

    HdfIoServiceRecycle(g_wifiService);
}
#ifdef __cplusplus
#if __cplusplus
#endif
#endif