#include <common.h>
#include <vsprintf.h>
#include <asm/io.h>
#include <asm/arch/hardware.h>
#include <asm/arch/at91_pit.h>
#include <asm/arch/at91_gpbr.h>
#include <asm/arch/clk.h>
#ifndef CONFIG_SYS_AT91_MAIN_CLOCK
#define CONFIG_SYS_AT91_MAIN_CLOCK 0
#endif
#if defined(CONFIG_DISPLAY_CPUINFO)
#endif
