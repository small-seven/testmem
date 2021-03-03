#include <common.h>
#include <asm/io.h>
#define PCI_DEV_CONFIG(segbus, dev, fn) ( \
#define LPC_DEV			0x1f
#define LPC_FUNC		0
#define UART_CONT		0x80
#define UART_RXD_COMMUITY	1
#define UART_TXD_COMMUITY	1
#define UART_RXD_FAMILY		4
#define UART_TXD_FAMILY		4
#define UART_RXD_PAD		2
#define UART_TXD_PAD		7
#define UART_RXD_FUNC		3
#define UART_TXD_FUNC		3
#define IO_BASE_ADDRESS		0xfed80000
