#include <common.h>
#include <dm.h>
#include <errno.h>
#include <serial.h>
#include <asm/io.h>
#define ALTERA_JTAG_RVALID	BIT(15)	/* Read valid */
#define ALTERA_JTAG_AC		BIT(10)	/* activity indicator */
#define ALTERA_JTAG_RRDY	BIT(12)	/* read available */
#define ALTERA_JTAG_WSPACE(d)	((d) >> 16)	/* Write space avail */
#define ALTERA_JTAG_WRITE_DEPTH	64
#ifdef CONFIG_ALTERA_JTAG_UART_BYPASS
#endif
#ifdef CONFIG_ALTERA_JTAG_UART_BYPASS
#endif
#ifdef CONFIG_DEBUG_UART_ALTERA_JTAGUART
#include <debug_uart.h>
#endif
