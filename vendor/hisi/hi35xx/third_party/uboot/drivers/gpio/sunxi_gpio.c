#include <common.h>
#include <dm.h>
#include <errno.h>
#include <fdtdec.h>
#include <malloc.h>
#include <asm/arch/gpio.h>
#include <asm/io.h>
#include <asm/gpio.h>
#include <dm/device-internal.h>
#include <dt-bindings/gpio/gpio.h>
#define SUNXI_GPIOS_PER_BANK	SUNXI_GPIO_A_NR
#ifndef CONFIG_DM_GPIO
int gpio_free(unsigned gpio)
{
	return 0;
}
#endif
#ifdef CONFIG_DM_GPIO
#if !defined CONFIG_SPL_BUILD && defined CONFIG_AXP_GPIO
#endif
#define ID(_compat_, _soc_data_) \
#endif
