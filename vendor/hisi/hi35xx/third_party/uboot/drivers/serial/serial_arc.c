#include <common.h>
#include <dm.h>
#include <serial.h>
#define UART_RXEMPTY		(1 << 5)
#define UART_OVERFLOW_ERR	(1 << 1)
#define UART_TXEMPTY		(1 << 7)
#ifdef CONFIG_DEBUG_ARC_SERIAL
#include <debug_uart.h>
#endif
