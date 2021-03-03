#include <common.h>
#include <dm.h>
#include <errno.h>
#include <watchdog.h>
#include <asm/io.h>
#include <serial.h>
#include <dm/platform_data/serial_pl01x.h>
#include <linux/compiler.h>
#include "serial_pl01x_internal.h"
#include <usb.h>
#ifndef CONFIG_DM_SERIAL
#define NUM_PORTS (sizeof(port)/sizeof(port[0]))
#endif
#ifndef CONFIG_DM_SERIAL
#if defined(CONFIG_PL010_SERIAL)
#elif defined(CONFIG_PL011_SERIAL)
#endif
#endif /* nCONFIG_DM_SERIAL */
#ifndef CONFIG_MINI_BOOT
#endif
#ifdef CONFIG_DM_SERIAL
#if CONFIG_IS_ENABLED(OF_CONTROL)
#endif
#endif
#if defined(CONFIG_DEBUG_UART_PL010) || defined(CONFIG_DEBUG_UART_PL011)
#include <debug_uart.h>
#ifndef CONFIG_DEBUG_UART_SKIP_INIT
#endif
#endif
