#include <clk.h>
#include <common.h>
#include <div64.h>
#include <dm.h>
#include <errno.h>
#include <serial.h>
#include <watchdog.h>
#include <asm/io.h>
#include <asm/types.h>
#define thr rbr
#define iir fcr
#define dll rbr
#define dlm ier
#define UART_LCR_WLS_8	0x03		/* 8 bit character length */
#define UART_LCR_DLAB	0x80		/* Divisor latch access bit */
#define UART_LSR_DR	0x01		/* Data ready */
#define UART_LSR_THRE	0x20		/* Xmit holding register empty */
#define UART_LSR_TEMT	0x40		/* Xmitter empty */
#define UART_MCR_DTR	0x01		/* DTR   */
#define UART_MCR_RTS	0x02		/* RTS   */
#define UART_FCR_FIFO_EN	0x01	/* Fifo enable */
#define UART_FCR_RXSR		0x02	/* Receiver soft reset */
#define UART_FCR_TXSR		0x04	/* Transmitter soft reset */
#define UART_MCRVAL (UART_MCR_DTR | \
#define UART_FCRVAL (UART_FCR_FIFO_EN | \
#define BAUD_ALLOW_MAX(baud)	((baud) + (baud) * 3 / 100)
#define BAUD_ALLOW_MIX(baud)	((baud) - (baud) * 3 / 100)
#if defined(CONFIG_DM_SERIAL) && \
#else
#define DECLARE_HSUART_PRIV(port) \
#define DECLARE_HSUART_FUNCTIONS(port) \
#define INIT_HSUART_STRUCTURE(port, __name) {	\
#define DECLARE_HSUART(port, __name) \
#if !defined(CONFIG_CONS_INDEX)
#elif (CONFIG_CONS_INDEX < 1) || (CONFIG_CONS_INDEX > 6)
#error	"Invalid console index value."
#endif
#if CONFIG_CONS_INDEX == 1 && !defined(CONFIG_SYS_NS16550_COM1)
#error	"Console port 1 defined but not configured."
#elif CONFIG_CONS_INDEX == 2 && !defined(CONFIG_SYS_NS16550_COM2)
#error	"Console port 2 defined but not configured."
#elif CONFIG_CONS_INDEX == 3 && !defined(CONFIG_SYS_NS16550_COM3)
#error	"Console port 3 defined but not configured."
#elif CONFIG_CONS_INDEX == 4 && !defined(CONFIG_SYS_NS16550_COM4)
#error	"Console port 4 defined but not configured."
#elif CONFIG_CONS_INDEX == 5 && !defined(CONFIG_SYS_NS16550_COM5)
#error	"Console port 5 defined but not configured."
#elif CONFIG_CONS_INDEX == 6 && !defined(CONFIG_SYS_NS16550_COM6)
#error	"Console port 6 defined but not configured."
#endif
#if defined(CONFIG_SYS_NS16550_COM1)
#endif
#if defined(CONFIG_SYS_NS16550_COM2)
#endif
#if defined(CONFIG_SYS_NS16550_COM3)
#endif
#if defined(CONFIG_SYS_NS16550_COM4)
#endif
#if defined(CONFIG_SYS_NS16550_COM5)
#endif
#if defined(CONFIG_SYS_NS16550_COM6)
#endif
#if CONFIG_CONS_INDEX == 1
#elif CONFIG_CONS_INDEX == 2
#elif CONFIG_CONS_INDEX == 3
#elif CONFIG_CONS_INDEX == 4
#elif CONFIG_CONS_INDEX == 5
#elif CONFIG_CONS_INDEX == 6
#else
#error "Bad CONFIG_CONS_INDEX."
#endif
#if defined(CONFIG_SYS_NS16550_COM1)
#endif
#if defined(CONFIG_SYS_NS16550_COM2)
#endif
#if defined(CONFIG_SYS_NS16550_COM3)
#endif
#if defined(CONFIG_SYS_NS16550_COM4)
#endif
#if defined(CONFIG_SYS_NS16550_COM5)
#endif
#if defined(CONFIG_SYS_NS16550_COM6)
#endif
#endif
#ifdef CONFIG_DEBUG_UART_MTK
#include <debug_uart.h>
#endif