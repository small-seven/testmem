#include <common.h>
#include <cpu_func.h>
#include <asm/cache.h>
#ifdef CONFIG_ARMV7_LPAE
#define ARMV7_DCACHE_POLICY	DCACHE_WRITEALLOC
#else
#define ARMV7_DCACHE_POLICY	DCACHE_WRITEBACK & ~TTB_SECT_XN_MASK
#endif
#define ARMV7_DOMAIN_CLIENT	1
#define ARMV7_DOMAIN_MASK	(0x3 << 0)
