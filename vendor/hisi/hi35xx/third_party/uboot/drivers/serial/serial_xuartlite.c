#include <config.h>
#include <common.h>
#include <dm.h>
#include <asm/io.h>
#include <linux/compiler.h>
#include <serial.h>
#define SR_TX_FIFO_FULL		BIT(3) /* transmit FIFO full */
#define SR_TX_FIFO_EMPTY	BIT(2) /* transmit FIFO empty */
#define SR_RX_FIFO_VALID_DATA	BIT(0) /* data in receive FIFO */
#define SR_RX_FIFO_FULL		BIT(1) /* receive FIFO full */
#define ULITE_CONTROL_RST_TX	0x01
#define ULITE_CONTROL_RST_RX	0x02
#ifdef CONFIG_DEBUG_UART_UARTLITE
#include <debug_uart.h>
#endif
