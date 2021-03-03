#include <config.h>
#include <linux/kconfig.h>
#include <asm/io.h>
#include <compiler.h>
#include <hicpu_common.h>
#define error(_s)	uart_early_puts(_s)
#define putstr(_s)	uart_early_puts(_s)
#include "hw_decompress.c"
#define GZIP_SIZE_OFFSET 0x4
#ifndef CONFIG_SYS_ICACHE_OFF
#else
#endif
