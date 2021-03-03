#include "los_config.h"
#include "los_task_pri.h"
#include "los_swtmr_pri.h"
#include "los_printf.h"
#include "los_atomic.h"
#include "gic_common.h"
#include "uart.h"
#include "los_process_pri.h"
#include "los_arch_mmu.h"
#if (LOSCFG_KERNEL_SMP == YES)
#endif
#ifdef LOSCFG_DEBUG_VERSION
#else
#endif /* LOSCFG_DEBUG_VERSION */
#if (LOSCFG_KERNEL_SMP == YES)
#else
#endif
#if (LOSCFG_KERNEL_SMP == YES)
#endif
#if (LOSCFG_KERNEL_SMP == YES)
#endif
#if (LOSCFG_KERNEL_SMP == YES)
#ifdef LOSCFG_TEE_ENABLE
#define TSP_CPU_ON  0xb2000011UL
#else
#define CLEAR_RESET_REG_STATUS(regval) (regval) &= ~(1U << 2)
#endif /* LOSCFG_TEE_ENABLE */
#endif /* LOSCFG_KERNEL_SMP */
#if (LOSCFG_KERNEL_SMP == YES)
#ifndef LOSCFG_TEE_ENABLE
#endif
#endif
#if (LOSCFG_KERNEL_SMP == YES)
#endif
