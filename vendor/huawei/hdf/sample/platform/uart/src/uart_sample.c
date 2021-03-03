#include "device_resource_if.h"
#include "buf_fifo.h"
#include "hdf_device_desc.h"
#include "hdf_log.h"
#include "hisoc/uart.h"
#include "osal_io.h"
#include "osal_mem.h"
#include "uart_core.h"
#include "uart_dev_sample.h"
#include "uart_dispatch_sample.h"
#include "uart_pl011_sample.h"
#define HDF_LOG_TAG uart_sample
#define UART_RX_FIFO_SIZE 128
static void HdfUartSampleRelease(struct HdfDeviceObject *device)
{
    struct UartHost *host = NULL;
    HDF_LOGI("Enter %s:", __func__);

    if (device == NULL) {
        HDF_LOGE("%s: device is NULL", __func__);
        return;
    }
    host = UartHostFromDevice(device);
    if (host == NULL) {
        HDF_LOGE("%s: host is NULL", __func__);
        return;
    }
    if (host->priv != NULL) {
        SampleDetach(host);
    }
    UartHostDestroy(host);
}
