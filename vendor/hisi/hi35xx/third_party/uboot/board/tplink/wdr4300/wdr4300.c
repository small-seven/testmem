#include <common.h>
#include <asm/io.h>
#include <asm/addrspace.h>
#include <asm/types.h>
#include <mach/ath79.h>
#include <mach/ar71xx_regs.h>
#include <mach/ddr.h>
#include <debug_uart.h>
#ifdef CONFIG_USB
#else
#endif
#ifdef CONFIG_DEBUG_UART_BOARD_INIT
#endif
#ifdef CONFIG_BOARD_EARLY_INIT_F
#ifndef CONFIG_DEBUG_UART_BOARD_INIT
#endif
#ifndef CONFIG_SKIP_LOWLEVEL_INIT
#endif
#endif
