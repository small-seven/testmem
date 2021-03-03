#include <common.h>
#include <dm.h>
#include <errno.h>
#include <i2c.h>
#include <asm/gpio.h>
static int i2c_arbitrator_remove(struct udevice *dev)
{
	struct i2c_arbitrator_priv *priv = dev_get_priv(dev);

	dm_gpio_free(dev, &priv->ap_claim);
	dm_gpio_free(dev, &priv->ec_claim);

	return 0;
}
