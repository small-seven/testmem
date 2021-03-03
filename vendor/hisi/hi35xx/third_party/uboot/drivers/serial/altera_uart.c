#include <common.h>
#include <dm.h>
#include <errno.h>
#include <serial.h>
#include <asm/io.h>
#define ALTERA_UART_TMT		BIT(5)	/* tx empty */
#define ALTERA_UART_TRDY	BIT(6)	/* tx ready */
#define ALTERA_UART_RRDY	BIT(7)	/* rx ready */
#ifdef CONFIG_DEBUG_UART_ALTERA_UART
#include <debug_uart.h>
#endif
