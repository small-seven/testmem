#include <common.h>
#include <dm.h>
#include <errno.h>
#include <i2c.h>
#include <asm-generic/gpio.h>
static int pca954x_remove(struct udevice *dev)
{
	if (IS_ENABLED(CONFIG_DM_GPIO)) {
		struct pca954x_priv *priv = dev_get_priv(dev);

		if (dm_gpio_is_valid(&priv->gpio_mux_reset))
			dm_gpio_free(dev, &priv->gpio_mux_reset);
	}

	return 0;
}
