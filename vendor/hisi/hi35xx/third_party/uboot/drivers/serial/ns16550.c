#include <common.h>
#include <clk.h>
#include <dm.h>
#include <errno.h>
#include <ns16550.h>
#include <reset.h>
#include <serial.h>
#include <watchdog.h>
#include <linux/types.h>
#include <asm/io.h>
#define UART_LCRVAL UART_LCR_8N1		/* 8 data, 1 stop, no parity */
#define UART_MCRVAL (UART_MCR_DTR | \
#if !CONFIG_IS_ENABLED(DM_SERIAL)
#ifdef CONFIG_SYS_NS16550_PORT_MAPPED
#define serial_out(x, y)	outb(x, (ulong)y)
#define serial_in(y)		inb((ulong)y)
#elif defined(CONFIG_SYS_NS16550_MEM32) && (CONFIG_SYS_NS16550_REG_SIZE > 0)
#define serial_out(x, y)	out_be32(y, x)
#define serial_in(y)		in_be32(y)
#elif defined(CONFIG_SYS_NS16550_MEM32) && (CONFIG_SYS_NS16550_REG_SIZE < 0)
#define serial_out(x, y)	out_le32(y, x)
#define serial_in(y)		in_le32(y)
#else
#define serial_out(x, y)	writeb(x, y)
#define serial_in(y)		readb(y)
#endif
#endif /* !CONFIG_DM_SERIAL */
#if defined(CONFIG_SOC_KEYSTONE)
#define UART_REG_VAL_PWREMU_MGMT_UART_DISABLE   0
#define UART_REG_VAL_PWREMU_MGMT_UART_ENABLE ((1 << 14) | (1 << 13) | (1 << 0))
#undef UART_MCRVAL
#ifdef CONFIG_SERIAL_HW_FLOW_CONTROL
#define UART_MCRVAL             (UART_MCR_RTS | UART_MCR_AFE)
#else
#define UART_MCRVAL             (UART_MCR_RTS)
#endif
#endif
#ifndef CONFIG_SYS_NS16550_IER
#define CONFIG_SYS_NS16550_IER  0x00
#endif /* CONFIG_SYS_NS16550_IER */
#ifdef CONFIG_SYS_NS16550_PORT_MAPPED
#elif defined(CONFIG_SYS_NS16550_MEM32) && defined(CONFIG_SYS_LITTLE_ENDIAN)
#elif defined(CONFIG_SYS_NS16550_MEM32) && defined(CONFIG_SYS_BIG_ENDIAN)
#elif defined(CONFIG_SYS_NS16550_MEM32)
#elif defined(CONFIG_SYS_BIG_ENDIAN)
#else
#endif
#ifdef CONFIG_SYS_NS16550_PORT_MAPPED
#elif defined(CONFIG_SYS_NS16550_MEM32) && defined(CONFIG_SYS_LITTLE_ENDIAN)
#elif defined(CONFIG_SYS_NS16550_MEM32) && defined(CONFIG_SYS_BIG_ENDIAN)
#elif defined(CONFIG_SYS_NS16550_MEM32)
#elif defined(CONFIG_SYS_BIG_ENDIAN)
#else
#endif
#if CONFIG_IS_ENABLED(DM_SERIAL)
#ifndef CONFIG_SYS_NS16550_CLK
#define CONFIG_SYS_NS16550_CLK  0
#endif
#define serial_out(value, addr)	\
#define serial_in(addr) \
#else
#endif
#if (defined(CONFIG_SPL_BUILD) && \
#endif
#if defined(CONFIG_ARCH_OMAP2PLUS) || defined(CONFIG_OMAP_SERIAL)
#endif
#if defined(CONFIG_ARCH_OMAP2PLUS) || defined(CONFIG_SOC_DA8XX) || \
#endif
#if defined(CONFIG_SOC_KEYSTONE)
#endif
#ifndef CONFIG_NS16550_MIN_FUNCTIONS
#endif /* CONFIG_NS16550_MIN_FUNCTIONS */
#ifndef CONFIG_NS16550_MIN_FUNCTIONS
#if !defined(CONFIG_SPL_BUILD) && defined(CONFIG_USB_TTY)
#endif
#endif /* CONFIG_NS16550_MIN_FUNCTIONS */
#ifdef CONFIG_DEBUG_UART_NS16550
#include <debug_uart.h>
#ifdef CONFIG_DEBUG_UART_NS16550_CHECK_ENABLED
#endif
#endif
#if CONFIG_IS_ENABLED(DM_SERIAL)
#ifdef CONFIG_SYS_NS16550_PORT_MAPPED
#else
#endif
#if CONFIG_IS_ENABLED(OF_CONTROL)
#endif
#if CONFIG_IS_ENABLED(OF_CONTROL) && !CONFIG_IS_ENABLED(OF_PLATDATA)
#ifdef CONFIG_SYS_NS16550_PORT_MAPPED
#else
#endif
#endif
#if CONFIG_IS_ENABLED(OF_CONTROL) && !CONFIG_IS_ENABLED(OF_PLATDATA)
#endif /* OF_CONTROL && !OF_PLATDATA */
#if CONFIG_IS_ENABLED(SERIAL_PRESENT)
#if !defined(CONFIG_TPL_BUILD) || defined(CONFIG_TPL_DM_SERIAL)
#if CONFIG_IS_ENABLED(OF_CONTROL) && !CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
#if !CONFIG_IS_ENABLED(OF_CONTROL)
#endif
#endif
#endif /* SERIAL_PRESENT */
#endif /* CONFIG_DM_SERIAL */
