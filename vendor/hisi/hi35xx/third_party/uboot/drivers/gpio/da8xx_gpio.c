#include <common.h>
#include <dm.h>
#include <fdtdec.h>
#include <asm/io.h>
#include <asm/gpio.h>
#include <dt-bindings/gpio/gpio.h>
#include "da8xx_gpio.h"
#ifndef CONFIG_DM_GPIO
#include <asm/arch/hardware.h>
#include <asm/arch/davinci_misc.h>
#if defined(CONFIG_SOC_DA8XX)
#define pinmux(x)       (&davinci_syscfg_regs->pinmux[x])
#if defined(CONFIG_SOC_DA8XX) && !defined(CONFIG_SOC_DA850)
#else /* CONFIG_SOC_DA8XX && CONFIG_SOC_DA850 */
#endif /* CONFIG_SOC_DA8XX && !CONFIG_SOC_DA850 */
#else /* !CONFIG_SOC_DA8XX */
#define davinci_configure_pin_mux(a, b)
#endif /* CONFIG_SOC_DA8XX */
int gpio_free(unsigned int gpio)
{
	if (gpio >= MAX_NUM_GPIOS)
		return -1;

	if (!gpio_registry[gpio].is_registered)
		return -1;

	gpio_registry[gpio].is_registered = 0;
	gpio_registry[gpio].name[0] = '\0';
	/* Do not configure as input or change pin mux here */
	return 0;
}
#endif
#ifndef CONFIG_DM_GPIO
#else /* CONFIG_DM_GPIO */
#endif
