#include "uart_dev_sample.h"
#include "fs/fs.h"
#include "securec.h"
#include "user_copy.h"
#include "hdf_log.h"
#include "osal_mem.h"
#include "uart_pl011_sample.h"
#define HDF_LOG_TAG hdf_uart_dev
#define HDF_UART_FS_MODE 0660
static int32_t UartSampleRelease(FAR struct file *filep)
{
    struct inode *inode = NULL;
    struct UartHost *host = NULL;

    if (filep == NULL || filep->f_inode == NULL) {
        return HDF_ERR_INVALID_PARAM;
    }
    inode = (struct inode *)filep->f_inode;
    host = (struct UartHost *)inode->i_private;
    if (host == NULL) {
        HDF_LOGE("%s: host is NULL", __func__);
        return HDF_ERR_INVALID_PARAM;
    }
    HDF_LOGI("%s: close uart%d success", __func__, host->num);
    return HDF_SUCCESS;
}
#define MAX_DEV_NAME_SIZE 32
