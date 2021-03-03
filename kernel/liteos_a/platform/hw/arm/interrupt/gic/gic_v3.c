#include "gic_common.h"
#include "gic_v3.h"
#include "los_typedef.h"
#include "los_typedef.h"
#include "los_hwi_pri.h"
#include "los_mp.h"

#ifdef LOSCFG_PLATFORM_BSP_GIC_V3

STATIC UINT32 g_curIrqNum = 0;

STATIC INLINE UINT64 MpidrToAffinity(UINT64 mpidr)
{
    return ((MPIDR_AFF_LEVEL(mpidr, 3) << 32) |
            (MPIDR_AFF_LEVEL(mpidr, 2) << 16) |
            (MPIDR_AFF_LEVEL(mpidr, 1) << 8)  |
            (MPIDR_AFF_LEVEL(mpidr, 0)));
}
#if (LOSCFG_KERNEL_SMP == YES)
#endif
#ifdef LOSCFG_ARCH_SECURE_MONITOR_MODE
#else
#endif
#ifdef LOSCFG_ARCH_SECURE_MONITOR_MODE
#else
#endif
#ifdef LOSCFG_ARCH_SECURE_MONITOR_MODE
#else
#endif
#ifdef LOSCFG_KERNEL_SMP
#endif
#if (LOSCFG_KERNEL_SMP == YES)
#endif
#endif
