#include "osal_time.h"
#include <sys/time.h>
#include <time.h>
#include "los_sys.h"
#include "los_task.h"
#include "hdf_log.h"
#define HDF_LOG_TAG osal_time
#define TM_SINCE_YEAR 1900
uint64_t OsalGetSysTimeMs(void)
{
    return LOS_TickCountGet() * (HDF_KILO_UNIT / LOSCFG_BASE_CORE_TICK_PER_SECOND);
}
