#include "los_exc_pri.h"
#include "los_memcheck_pri.h"
#ifdef LOSCFG_LIB_LIBC
#include "string.h"
#endif
#include "securec.h"
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
#define EXC_INT_STATUS_LEN              OS_NVIC_INT_ENABLE_SIZE + OS_NVIC_INT_PEND_SIZE + OS_NVIC_INT_ACT_SIZE + \
#define TASK_ARRAY_INIT_VALUE           0xff
#define FAULT_STATUS_REG_BIT            32
#define OS_NVIC_INT_CTRL_SIZE           4
#define OS_NVIC_SHCSR_SIZE              4
#define USGFAULT                        (1 << 18)
#define BUSFAULT                        (1 << 17)
#define MEMFAULT                        (1 << 16)
#define DIV0FAULT                       (1 << 4)
#define CORE_TYPE_CORTEX_M4             2
#define HARDFAULT_IRQN                  (-13)
#ifdef __cplusplus
#if __cplusplus
#endif /* __cplusplus */
#endif /* __cplusplus */
