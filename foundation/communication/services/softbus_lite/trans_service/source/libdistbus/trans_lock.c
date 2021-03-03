#include "trans_lock.h"
#if defined(__LITEOS_M__) || defined(__LITEOS_RISCV__)
#include <cmsis_os.h>
#else
#include <pthread.h>
#endif
#include "data_bus_error.h"
#define BUS_WAIT_FOREVER 0xFFFFFFFF
#if defined(__LITEOS_M__) || defined(__LITEOS_RISCV__)
#else
#endif
#if defined(__LITEOS_M__) || defined(__LITEOS_RISCV__)
#else
#endif
#if defined(__LITEOS_M__) || defined(__LITEOS_RISCV__)
#else
#endif
int ReleaseTcpMgrLock(void)
{
#if defined(__LITEOS_M__) || defined(__LITEOS_RISCV__)
    if (g_sessionManagerLock == NULL) {
        return -DBE_INNER_ERROR;
    }
    osStatus_t ret = osMutexRelease(g_sessionManagerLock);
    if (ret != osOK) {
        return -DBE_INNER_ERROR;
    }
#else
    pthread_mutex_unlock(&g_sessionManagerLock);
#endif
    return DBE_SUCCESS;
}
