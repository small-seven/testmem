#include <common.h>
#include <clk.h>
#include <dm.h>
#include <errno.h>
#include <fdtdec.h>
#include <serial.h>
#include <asm/io.h>
#include <asm/types.h>
#define	OWL_UART_CTL			(0x0000)
#define	OWL_UART_RXDAT			(0x0004)
#define	OWL_UART_TXDAT			(0x0008)
#define	OWL_UART_STAT			(0x000C)
#define	OWL_UART_CTL_PRS_NONE		GENMASK(6, 4)
#define	OWL_UART_CTL_STPS		BIT(2)
#define	OWL_UART_CTL_DWLS		3
#define	OWL_UART_STAT_TFES		BIT(10)	/* TX FIFO Empty Status	*/
#define	OWL_UART_STAT_RFFS		BIT(9)	/* RX FIFO full	Status */
#define	OWL_UART_STAT_TFFU		BIT(6)	/* TX FIFO full	Status */
#define	OWL_UART_STAT_RFEM		BIT(5)	/* RX FIFO Empty Status	*/
