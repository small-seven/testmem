#include <common.h>
#include <cpu_func.h>
#include <asm/cacheops.h>
#ifdef CONFIG_MIPS_L2_CACHE
#include <asm/cm.h>
#endif
#include <asm/io.h>
#include <asm/mipsregs.h>
#include <asm/system.h>
#ifdef CONFIG_MIPS_L2_CACHE
#endif
#ifdef CONFIG_SYS_CACHE_SIZE_AUTO
#endif
#ifdef CONFIG_SYS_CACHE_SIZE_AUTO
#else
#endif
#ifdef CONFIG_SYS_CACHE_SIZE_AUTO
#else
#endif
#ifdef CONFIG_MIPS_L2_CACHE
#else
#endif
#define cache_loop(start, end, lsize, ops...) do {			\
