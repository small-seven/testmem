#include <common.h>
#include <dm.h>
#include <errno.h>
#include <fdtdec.h>
#include <linux/compiler.h>
#include <asm/io.h>
#include <asm/arch/clk.h>
#include <asm/arch/uart.h>
#include <serial.h>
#include <clk.h>
#define RX_FIFO_COUNT_SHIFT	0
#define RX_FIFO_COUNT_MASK	(0xff << RX_FIFO_COUNT_SHIFT)
#define RX_FIFO_FULL		(1 << 8)
#define TX_FIFO_COUNT_SHIFT	16
#define TX_FIFO_COUNT_MASK	(0xff << TX_FIFO_COUNT_SHIFT)
#define TX_FIFO_FULL		(1 << 24)
#ifndef CONFIG_SPL_BUILD
#ifdef CONFIG_CLK_EXYNOS
#else
#endif
#endif
#ifdef CONFIG_DEBUG_UART_S5P
#include <debug_uart.h>
#endif
