#include <common.h>
#include <serial.h>
#include <watchdog.h>
#include <command.h>
#include <asm/m5329.h>
#include <asm/immap_5329.h>
#include <asm/io.h>
#include <asm/uart.h>
#include "astro.h"
#if !defined(CONFIG_MONITOR_IS_IN_RAM)
#endif
#define UART_BASE MMAP_UART0
