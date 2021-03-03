#include <config.h>
#include <linux/kconfig.h>
#include <asm/io.h>
#include <compiler.h>
#include <hicpu_common.h>
#define error(_s)               uart_early_puts(_s)
#define putstr(_s)              uart_early_puts(_s)
#define EXCEPTION_LEVEL1   	1
#define EXCEPTION_LEVEL2   	2
#include "hw_decompress.c"
#define GZIP_SIZE_OFFSET 0x4
#define CR_I    (1 << 12)   /* Icache enable            */
