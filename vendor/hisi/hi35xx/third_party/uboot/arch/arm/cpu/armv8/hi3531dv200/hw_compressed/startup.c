#include <config.h>
#include <linux/kconfig.h>
#include <asm/io.h>
#include <compiler.h>
#define CR_M            (1 << 0)        /* MMU enable                   */
#define CR_A            (1 << 1)        /* Alignment abort enable       */
#define CR_C            (1 << 2)        /* Dcache enable                */
#define CR_SA           (1 << 3)        /* Stack Alignment Check Enable */
#define CR_I            (1 << 12)       /* Icache enable                */
#define CR_WXN          (1 << 19)       /* Write Permision Imply XN     */
#define CR_EE           (1 << 25)       /* Exception (Big) Endian       */
#define error(_s)               uart_early_puts(_s)
#define putstr(_s)              uart_early_puts(_s)
#define large_malloc(_n)        malloc(_n)
#define large_free(_n)          free(_n)
static void *malloc(unsigned int size)
{
	void *ptr = (void *)(uintptr_t)malloc_start_lzma;
	malloc_start_lzma += size;

	if (malloc_start_lzma >= (uintptr_t)&_start)
		return NULL;

	return ptr;
}
static void free(void *ptr)
{
}
#include "unlzma.c"
