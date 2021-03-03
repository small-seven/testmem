#include <common.h>
#include <clk.h>
#include <dm.h>
#include <errno.h>
#include <watchdog.h>
#include <serial.h>
#include <debug_uart.h>
#include <linux/compiler.h>
#include <asm/io.h>
#ifdef CONFIG_DM_SERIAL
#include <asm/arch/atmel_serial.h>
#endif
#include <asm/arch/clk.h>
#include <asm/arch/hardware.h>
#include "atmel_usart.h"
#ifndef CONFIG_DM_SERIAL
#endif
#ifdef CONFIG_DM_SERIAL
#if defined(CONFIG_SPL_BUILD) && !defined(CONFIG_SPL_CLK)
#else
#endif
#if CONFIG_IS_ENABLED(OF_CONTROL)
#endif
#if CONFIG_IS_ENABLED(OF_CONTROL)
#endif
#if CONFIG_IS_ENABLED(OF_CONTROL)
#endif
#if !CONFIG_IS_ENABLED(OF_CONTROL)
#endif
#endif
#ifdef CONFIG_DEBUG_UART_ATMEL
#endif
