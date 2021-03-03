#include "i2c_core.h"
#include <string.h>
#include "hdf_log.h"
#include "osal_mem.h"
#define HDF_LOG_TAG i2c_core
void I2cCntlrRemove(struct I2cCntlr *cntlr)
{
    if (cntlr == NULL) {
        return;
    }

    if (cntlr->device == NULL) {
        HDF_LOGE("I2cCntlrBind: no device associated!\n");
        return;
    }

    cntlr->device->service = NULL;
    (void)OsalMutexDestroy(&cntlr->lock);
}
