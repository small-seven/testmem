#include <common.h>
#include <dm.h>
#include <serial.h>
#include <asm/io.h>
#define UART_RX_REG		0x00
#define UART_TX_REG		0x04
#define UART_CTRL_REG		0x08
#define UART_STATUS_REG		0x0c
#define UART_BAUD_REG		0x10
#define UART_POSSR_REG		0x14
#define UART_STATUS_RX_RDY	0x10
#define UART_STATUS_TXFIFO_FULL	0x800
#define UART_CTRL_RXFIFO_RESET	0x4000
#define UART_CTRL_TXFIFO_RESET	0x8000
#define CONFIG_UART_BASE_CLOCK	25804800
#ifdef CONFIG_DEBUG_MVEBU_A3700_UART
#include <debug_uart.h>
#endif
