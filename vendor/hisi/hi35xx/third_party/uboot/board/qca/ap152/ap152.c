#include <common.h>
#include <asm/io.h>
#include <asm/addrspace.h>
#include <asm/types.h>
#include <mach/ar71xx_regs.h>
#include <mach/ddr.h>
#include <mach/ath79.h>
#include <debug_uart.h>
#define RST_RESET_RTC_RESET_LSB 27
#define RST_RESET_RTC_RESET_MASK 0x08000000
#define RST_RESET_RTC_RESET_SET(x) \
#ifdef CONFIG_DEBUG_UART_BOARD_INIT
#endif
#ifndef CONFIG_SKIP_LOWLEVEL_INIT
#endif
