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
#if defined(CONFIG_AT91SAM9G20)
#endif
#if defined(CONFIG_AT91SAM9G20)
#endif
#endif
#ifndef CONFIG_SYS_AT91_MAIN_CLOCK
#endif
#ifdef CONFIG_USB_ATMEL
#endif
#if defined(CONFIG_AT91SAM9G45) || defined(CONFIG_AT91SAM9M10G45) \
#endif
#if defined(CONFIG_AT91SAM9X5)
#else
#endif
#if defined(CONFIG_AT91SAM9G20)
#elif defined(CONFIG_AT91SAM9G45) || defined(CONFIG_AT91SAM9M10G45) \
#else
#endif
#if !defined(AT91_PLL_LOCK_TIMEOUT)
#define AT91_PLL_LOCK_TIMEOUT	1000000
#endif
