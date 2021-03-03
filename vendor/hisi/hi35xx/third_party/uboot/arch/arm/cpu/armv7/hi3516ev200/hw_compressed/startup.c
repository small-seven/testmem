#include <config.h>
#include <linux/kconfig.h>
#include <asm/io.h>
#include <compiler.h>
#include <hicpu_common.h>
#define error(_s)               uart_early_puts(_s)
#define putstr(_s)              uart_early_puts(_s)
#include "hw_decompress.c"
#define GZIP_SIZE_OFFSET 0x4
#ifndef CONFIG_SYS_ICACHE_OFF
#else
#endif
#ifdef CONFIG_MINI_BOOT
#ifndef bit
#define bit(x) (1 << (x))
#endif
#define TIME2_CLK_SEL  bit(18)
#define TIME_STAMP_CNT      0x12020138
#define TIME_STAMP_VALUE    0x04010050
#define CONFIG_TIME_STAMP_ENABLE
#ifdef CONFIG_TIME_STAMP_ENABLE
#endif
#endif
#ifndef CONFIG_MINI_BOOT
#endif
#ifndef CONFIG_MINI_BOOT
#endif
#ifndef CONFIG_MINI_BOOT
#endif
