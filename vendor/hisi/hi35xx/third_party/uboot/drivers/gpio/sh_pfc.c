#include <common.h>
#include <asm/bitops.h>
#include <asm/io.h>
#include <sh_pfc.h>
#define pfc_phys_to_virt(p, a) ((void *)a)
#if 0
#else
#endif
#if 0
#endif
static void sh_gpio_free(unsigned offset)
{
	int pinmux_type;

	if (!gpioc)
		return;

	pinmux_type = gpioc->gpios[offset].flags & PINMUX_FLAG_TYPE;
	pinmux_config_gpio(gpioc, offset, pinmux_type, GPIO_CFG_FREE);
	gpioc->gpios[offset].flags &= ~PINMUX_FLAG_TYPE;
	gpioc->gpios[offset].flags |= PINMUX_TYPE_NONE;
}
#if defined(CONFIG_RCAR_GEN3)
#endif
int gpio_free(unsigned gpio)
{
	sh_gpio_free(gpio);
	return 0;
}
