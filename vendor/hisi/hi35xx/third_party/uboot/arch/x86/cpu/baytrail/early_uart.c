#include <common.h>
#include <errno.h>
#include <asm/io.h>
#define PCI_DEV_CONFIG(segbus, dev, fn) ( \
#define LPC_DEV			0x1f
#define LPC_FUNC		0
#define UART_CONT		0x80
#define UART_RXD_PAD			82
#define UART_TXD_PAD			83
#define GPSCORE_PAD_BASE	(IO_BASE_ADDRESS + IO_BASE_OFFSET_GPSCORE)
#define IO_BASE_ADDRESS			0xfed0c000
#define  IO_BASE_OFFSET_GPSCORE		0x0000
#define  IO_BASE_OFFSET_GPNCORE		0x1000
#define  IO_BASE_OFFSET_GPSSUS		0x2000
#define IO_BASE_SIZE			0x4000
