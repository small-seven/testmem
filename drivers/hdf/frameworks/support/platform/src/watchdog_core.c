#include "watchdog_core.h"
#include <string.h>
#include "hdf_log.h"
#include "osal_mem.h"
#define HDF_LOG_TAG watchdog_core
void WatchdogCntlrRemove(struct WatchdogCntlr *cntlr)
{
    if (cntlr == NULL) {
        return;
    }

    if (cntlr->device == NULL) {
        HDF_LOGE("WatchdogCntlrRemove: no device associated!");
        return;
    }

    cntlr->device->service = NULL;
    (void)OsalSpinDestroy(&cntlr->lock);
}
