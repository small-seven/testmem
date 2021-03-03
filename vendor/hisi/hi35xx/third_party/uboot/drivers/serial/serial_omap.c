#include <common.h>
#include <dm.h>
#include <dt-structs.h>
#include <ns16550.h>
#include <serial.h>
#include <clk.h>
#ifndef CONFIG_SYS_NS16550_CLK
#define CONFIG_SYS_NS16550_CLK  0
#endif
#ifdef CONFIG_DEBUG_UART_OMAP
#ifndef CONFIG_SYS_NS16550_IER
#define CONFIG_SYS_NS16550_IER  0x00
#endif
#define UART_MCRVAL 0x00
#define UART_LCRVAL UART_LCR_8N1
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
#include <debug_uart.h>
#endif
#if CONFIG_IS_ENABLED(DM_SERIAL)
#if CONFIG_IS_ENABLED(OF_CONTROL) && !CONFIG_IS_ENABLED(OF_PLATDATA)
#endif /* OF_CONTROL && !OF_PLATDATA */
#if CONFIG_IS_ENABLED(SERIAL_PRESENT)
#if CONFIG_IS_ENABLED(OF_CONTROL) && !CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
#if !CONFIG_IS_ENABLED(OF_CONTROL)
#endif
#endif
#endif /* DM_SERIAL */
