#include "watchdog_if.h"
#include "devsvc_manager_clnt.h"
#include "hdf_base.h"
#include "hdf_log.h"
#include "osal_mem.h"
#include "securec.h"
#include "watchdog_core.h"
#define HDF_LOG_TAG watchdog_if
#define WATCHDOG_ID_MAX   8
#define WATCHDOG_NAME_LEN 32
