#include <common.h>
#include <dm.h>
#include <errno.h>
#include <led.h>
#include <asm/gpio.h>
#include <dm/lists.h>
static int led_gpio_remove(struct udevice *dev)
{
	/*
	 * The GPIO driver may have already been removed. We will need to
	 * address this more generally.
	 */
#ifndef CONFIG_SANDBOX
	struct led_gpio_priv *priv = dev_get_priv(dev);

	if (dm_gpio_is_valid(&priv->gpio))
		dm_gpio_free(dev, &priv->gpio);
#endif

	return 0;
}
