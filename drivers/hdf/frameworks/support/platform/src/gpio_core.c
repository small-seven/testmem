#include "gpio_core.h"
#include <string.h>
#include "hdf_log.h"
#include "osal_mem.h"
#define HDF_LOG_TAG gpio_core
void GpioCntlrRemove(struct GpioCntlr *cntlr)
{
    if (cntlr == NULL) {
        return;
    }

    if (cntlr->device == NULL) {
        HDF_LOGE("GpioCntlrRemove: no device associated!\n");
        return;
    }

    cntlr->device->service = NULL;
    g_cntlr = NULL;
}
