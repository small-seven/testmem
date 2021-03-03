#include <common.h>
#include <dm.h>
#include <asm/arch/at91_common.h>
#include <asm/arch/clk.h>
#include <asm/arch/gpio.h>
#include <asm/io.h>
#ifdef CONFIG_AT91_GPIO_PULLUP
# define PUP CONFIG_AT91_GPIO_PULLUP
#else
# define PUP 0
#endif
#ifdef CONFIG_ATMEL_SPI
#endif
#ifdef CONFIG_MACB
#ifndef CONFIG_RMII
#endif
#endif
#ifdef CONFIG_GENERIC_ATMEL_MCI
#endif
