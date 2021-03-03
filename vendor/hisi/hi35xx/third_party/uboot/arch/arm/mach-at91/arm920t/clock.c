#include <common.h>
#include <asm/io.h>
#include <asm/arch/hardware.h>
#include <asm/arch/at91_pmc.h>
#include <asm/arch/clk.h>
#if !defined(CONFIG_AT91FAMILY)
# error You need to define CONFIG_AT91FAMILY in your board config!
#endif
#define EN_PLLB_TIMEOUT	500
#ifdef CONFIG_USB_ATMEL
#endif
#ifndef CONFIG_SYS_AT91_MAIN_CLOCK
#endif
#ifdef CONFIG_USB_ATMEL
#endif
