#include <linux/kconfig.h>
#include <common.h>
#include <asm/system.h>
#include <asm/armv8/mmu.h>
#include <cpu_func.h>
void * memset(void * s,int c,size_t count)
{
	unsigned long *sl = (unsigned long *) s;
	unsigned long cl = 0;
	char *s8 = NULL;
	int i;

	/* do it one word at a time (32 bits or 64 bits) while possible */
	if ( ((ulong)s & (sizeof(*sl) - 1)) == 0) {
		for (i = 0; i < sizeof(*sl); i++) {
			cl <<= 8;
			cl |= c & 0xff;
		}
		while (count >= sizeof(*sl)) {
			*sl++ = cl;
			count -= sizeof(*sl);
		}
	}
	/* fill 8 bits at a time */
	s8 = (char *)sl;
	while (count--)
		*s8++ = c;

	return s;
}
#ifndef CONFIG_SYS_DCACHE_OFF
#define MAX_PTE_ENTRIES 512
#define EARLY_GD_ADDR (0x40000000)
#define EARLY_PAGE_TBL_SIZE (128 * 1024)
#define EARLY_PAGE_TBL_ADDR (EARLY_GD_ADDR + EARLY_PAGE_TBL_SIZE)
#else	/* CONFIG_SYS_DCACHE_OFF */
#ifndef CONFIG_SPL_BUILD
#error Please describe your MMU layout in CONFIG_SYS_MEM_MAP and enable dcache.
#endif
#endif	/* CONFIG_SYS_DCACHE_OFF */
#ifndef CONFIG_SYS_ICACHE_OFF
#else	/* CONFIG_SYS_ICACHE_OFF */
#endif	/* CONFIG_SYS_ICACHE_OFF */
