#include "osal_firmware.h"
#include <limits.h>
#include <sys/stat.h>
#include <unistd.h>
#include "fs/file.h"
#include "hdf_log.h"
#include "osal_mem.h"
#define HDF_LOG_TAG osal_fw
#define HDF_FW_BLOCK_SIZE 64
int32_t OsalReleaseFirmware(struct OsalFirmware *fwPara)
{
    struct OsalFwDesc *fw = NULL;

    if (fwPara == NULL || fwPara->para == NULL) {
        HDF_LOGE("%s invalid param", __func__);
        return HDF_ERR_INVALID_PARAM;
    }

    fw = (struct OsalFwDesc *)fwPara->para;
    if (fw->fd == -1) {
        HDF_LOGE("%s invalid file id",  __func__);
        return HDF_ERR_INVALID_PARAM;
    }

    if (close(fw->fd) != 0) {
        HDF_LOGE("%s close fail %d",  __func__, errno);
        return HDF_FAILURE;
    }
    OsalMemFree(fwPara->para);
    fwPara->para = NULL;

    return HDF_SUCCESS;
}
