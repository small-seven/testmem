#include <common.h>
#include <dm.h>
#include <asm/io.h>
#include <asm/arch/at91sam9260_matrix.h>
#include <asm/arch/at91_common.h>
#include <asm/arch/at91sam9_sdramc.h>
#include <asm/arch/clk.h>
#include <asm/arch/gpio.h>
#ifdef CONFIG_AT91_GPIO_PULLUP
# define PUP CONFIG_AT91_GPIO_PULLUP
#else
# define PUP 0
#endif
#ifdef CONFIG_ATMEL_SPI
#endif
#ifdef CONFIG_MACB
#ifndef CONFIG_RMII
#if defined(CONFIG_AT91SAM9260EK)
#else
#if defined(CONFIG_AT91SAM9G20)
#endif
#endif
#endif
#endif
#if defined(CONFIG_GENERIC_ATMEL_MCI)
#if defined(CONFIG_ATMEL_MCI_PORTB)
#else
#endif
#endif
