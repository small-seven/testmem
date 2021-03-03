#include <config.h>
#include <linux/kconfig.h>
#include <asm/io.h>
#include <compiler.h>
#define error(_s)               uart_early_puts(_s)
#define putstr(_s)              uart_early_puts(_s)
#define large_malloc(_n)        malloc(_n)
#define large_free(_n)          free(_n)
static void *malloc(unsigned int size)
{
	void *ptr = (void *)malloc_start_lzma;
	malloc_start_lzma += size;

	if (malloc_start_lzma >= (unsigned long)&_start)
		return NULL;

	return ptr;
}
static void free(void *ptr)
{
}
#include "unlzma.c"
#ifndef CONFIG_SYS_ICACHE_OFF
#else
#endif
#ifdef CONFIG_EARLY_DCACHE_ENABLE
#endif
