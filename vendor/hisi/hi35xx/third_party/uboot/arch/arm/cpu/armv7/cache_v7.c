#include <cpu_func.h>
#include <linux/types.h>
#include <common.h>
#include <asm/armv7.h>
#include <asm/utils.h>
#define ARMV7_DCACHE_INVAL_RANGE	1
#define ARMV7_DCACHE_CLEAN_INVAL_RANGE	2
#if !CONFIG_IS_ENABLED(SYS_DCACHE_OFF)
#else /* #if !CONFIG_IS_ENABLED(SYS_DCACHE_OFF) */
#endif /* #if !CONFIG_IS_ENABLED(SYS_DCACHE_OFF) */
#if !CONFIG_IS_ENABLED(SYS_ICACHE_OFF)
#else
#endif
