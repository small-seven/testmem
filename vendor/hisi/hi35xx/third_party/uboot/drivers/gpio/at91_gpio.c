#include <config.h>
#include <common.h>
#include <clk.h>
#include <dm.h>
#include <asm/io.h>
#include <linux/sizes.h>
#include <asm/gpio.h>
#include <asm/arch/hardware.h>
#include <asm/arch/at91_pio.h>
#define GPIO_PER_BANK	32
#if (ATMEL_PIO_PORTS > 3)
#if (ATMEL_PIO_PORTS > 4)
#endif
#endif
#ifdef CONFIG_DM_GPIO
#endif
#ifndef CONFIG_DM_GPIO
int gpio_free(unsigned gpio)
{
	return 0;
}
#endif
#ifdef CONFIG_DM_GPIO
#if (ATMEL_PIO_PORTS > 3)
#if (ATMEL_PIO_PORTS > 4)
#endif
#endif
#if CONFIG_IS_ENABLED(OF_CONTROL)
#endif
#if CONFIG_IS_ENABLED(OF_CONTROL)
#endif
#if CONFIG_IS_ENABLED(OF_CONTROL)
#endif
#endif
