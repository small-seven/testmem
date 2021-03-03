#include "cmsis_os.h"
#include "los_typedef.h"
#include "los_typedef.h"
#include "los_printf.h"

#include "los_event.h"
#include "los_membox.h"
#include "los_memory.h"
#include "los_hwi.h"

#include "los_mux_pri.h"
#include "los_queue_pri.h"
#include "los_sem_pri.h"
#include "los_swtmr_pri.h"
#include "los_sys_pri.h"
#include "los_task_pri.h"
#include "los_tick_pri.h"
#include "string.h"
#include "securec.h"
#include "system_config.h"
#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */
#if (CMSIS_OS_VER == 2)

/* Kernel initialization state */
static osKernelState_t g_kernelState;

extern BOOL g_taskScheduled;

#define LOS_PRIORITY_WIN 8

const osVersion_t g_stLosVersion = { 001, 001 };
#define LITEOS_VERSION_MAJOR 1
#define LITEOS_VERSION_MINOR 0
#define LITEOS_VERSION_BUILD 0
#define KERNEL_VERSION            (((UINT32)LITEOS_VERSION_MAJOR * 10000000UL) | \
#define KERNEL_ID "HUAWEI-LiteOS"
#define UNUSED(var) do { (void)var; } while(0)
#ifndef LITEOS_WIFI_IOT_VERSION
#else
#endif
#ifndef LITEOS_WIFI_IOT_VERSION
#else
#endif
#ifndef LITEOS_WIFI_IOT_VERSION
#else
#endif
#ifndef LITEOS_WIFI_IOT_VERSION
#else
#endif
#if (LOSCFG_BASE_CORE_SWTMR == YES)
#if (LOSCFG_BASE_CORE_SWTMR_ALIGN == YES)
#endif
#if (LOSCFG_BASE_CORE_SWTMR_ALIGN == YES)
#else
#endif
#endif
#if (LOSCFG_BASE_IPC_MUX == YES)
osStatus_t osMutexRelease(osMutexId_t mutex_id)
{
    UINT32 uwRet;

    if (mutex_id == NULL) {
        return osErrorParameter;
    }

    uwRet = LOS_MuxPost(((LosMuxCB *)mutex_id)->muxID);
    if (uwRet == LOS_OK) {
        return osOK;
    } else {
        return osErrorResource;
    }
}
#endif
#if (LOSCFG_BASE_IPC_SEM == YES)
osStatus_t osSemaphoreRelease(osSemaphoreId_t semaphore_id)
{
    UINT32 uwRet;

    if (semaphore_id == NULL) {
        return osErrorParameter;
    }

    uwRet = LOS_SemPost(((LosSemCB *)semaphore_id)->semID);
    if (uwRet == LOS_OK) {
        return osOK;
    } else if (uwRet == LOS_ERRNO_SEM_INVALID) {
        return osErrorParameter;
    } else {
        return osErrorResource;
    }
}
#endif
#if (LOSCFG_BASE_IPC_QUEUE == YES)
#endif
#endif // (CMSIS_OS_VER == 2)
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
