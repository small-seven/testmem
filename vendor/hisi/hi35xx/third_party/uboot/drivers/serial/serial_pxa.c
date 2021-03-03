#include <common.h>
#include <asm/arch/pxa-regs.h>
#include <asm/arch/regs-uart.h>
#include <asm/io.h>
#include <dm.h>
#include <dm/platform_data/serial_pxa.h>
#include <linux/compiler.h>
#include <serial.h>
#include <watchdog.h>
#ifndef CONFIG_DM_SERIAL
#define	pxa_uart(uart, UART)						\
#define	pxa_uart_desc(uart)						\
#define	pxa_uart_multi(uart, UART)					\
#if defined(CONFIG_HWUART)
#endif
#if defined(CONFIG_STUART)
#endif
#if defined(CONFIG_FFUART)
#endif
#if defined(CONFIG_BTUART)
#endif
#if CONFIG_CONS_INDEX == 1
#elif CONFIG_CONS_INDEX == 2
#elif CONFIG_CONS_INDEX == 3
#elif CONFIG_CONS_INDEX == 4
#else
#error "Bad CONFIG_CONS_INDEX."
#endif
#if defined(CONFIG_FFUART)
#endif
#if defined(CONFIG_BTUART)
#endif
#if defined(CONFIG_STUART)
#endif
#endif /* CONFIG_DM_SERIAL */
#ifdef CONFIG_DM_SERIAL
#endif /* CONFIG_DM_SERIAL */
