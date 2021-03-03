#include <common.h>
#include <clk.h>
#include <dm.h>
#include <reset.h>
#include <serial.h>
#include <watchdog.h>
#include <asm/io.h>
#include <asm/arch/stm32.h>
#include "serial_stm32.h"
#if !CONFIG_IS_ENABLED(OF_CONTROL)
#endif
#ifdef CONFIG_DEBUG_UART_STM32
#include <debug_uart.h>
#if defined(CONFIG_STM32F4)
#elif defined(CONFIG_STM32F7)
#else
#endif
#endif
