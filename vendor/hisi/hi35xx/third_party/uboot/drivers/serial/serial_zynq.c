#include <clk.h>
#include <common.h>
#include <debug_uart.h>
#include <dm.h>
#include <errno.h>
#include <fdtdec.h>
#include <watchdog.h>
#include <asm/io.h>
#include <linux/compiler.h>
#include <serial.h>
#define ZYNQ_UART_SR_TXACTIVE	BIT(11) /* TX active */
#define ZYNQ_UART_SR_TXFULL	BIT(4) /* TX FIFO full */
#define ZYNQ_UART_SR_RXEMPTY	BIT(1) /* RX FIFO empty */
#define ZYNQ_UART_CR_TX_EN	BIT(4) /* TX enabled */
#define ZYNQ_UART_CR_RX_EN	BIT(2) /* RX enabled */
#define ZYNQ_UART_CR_TXRST	BIT(1) /* TX logic reset */
#define ZYNQ_UART_CR_RXRST	BIT(0) /* RX logic reset */
#define ZYNQ_UART_MR_PARITY_NONE	0x00000020  /* No parity mode */
#ifdef CONFIG_DEBUG_UART_ZYNQ
#endif
