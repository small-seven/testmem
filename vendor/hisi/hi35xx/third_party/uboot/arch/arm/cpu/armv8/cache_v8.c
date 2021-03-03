#include <common.h>
#include <cpu_func.h>
#include <asm/system.h>
#include <asm/armv8/mmu.h>
#if !CONFIG_IS_ENABLED(SYS_DCACHE_OFF)
#define MAX_PTE_ENTRIES 512
#ifndef CONFIG_SYS_DISABLE_DCACHE_OPS
#else
#endif /* CONFIG_SYS_DISABLE_DCACHE_OPS */
#else	/* !CONFIG_IS_ENABLED(SYS_DCACHE_OFF) */
#ifndef CONFIG_SPL_BUILD
#error Please describe your MMU layout in CONFIG_SYS_MEM_MAP and enable dcache.
#endif
#endif	/* !CONFIG_IS_ENABLED(SYS_DCACHE_OFF) */
#if !CONFIG_IS_ENABLED(SYS_ICACHE_OFF)
#else	/* !CONFIG_IS_ENABLED(SYS_ICACHE_OFF) */
#endif	/* !CONFIG_IS_ENABLED(SYS_ICACHE_OFF) */
