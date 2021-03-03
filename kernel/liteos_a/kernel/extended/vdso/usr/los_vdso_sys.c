#include "asm/page.h"
#include "time.h"
#include "sys/time.h"
#include "los_typedef.h"
#include "los_typedef.h"
#include "los_vdso_datapage.h"

STATIC INT32 VdsoGetRealtimeCoarse(struct timespec *ts, const VdsoDataPage *usrVdsoDataPage)
{
    do {
        if (!usrVdsoDataPage->lockCount) {
            ts->tv_sec = usrVdsoDataPage->realTimeSec;
            ts->tv_nsec = usrVdsoDataPage->realTimeNsec;
            return 0;
        }
