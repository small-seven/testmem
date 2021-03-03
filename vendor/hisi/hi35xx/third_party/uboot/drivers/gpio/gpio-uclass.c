#include <common.h>
#include <dm.h>
#include <dm/device-internal.h>
#include <dm/lists.h>
#include <dm/uclass-internal.h>
#include <dt-bindings/gpio/gpio.h>
#include <errno.h>
#include <fdtdec.h>
#include <malloc.h>
#include <asm/gpio.h>
#include <linux/bug.h>
#include <linux/ctype.h>
#if defined(CONFIG_GPIO_HOG)
#else
#endif
#if !defined(CONFIG_SPL_BUILD) || !CONFIG_IS_ENABLED(USE_TINY_PRINTF)
#else
#endif
#if !defined(CONFIG_SPL_BUILD) || !CONFIG_IS_ENABLED(USE_TINY_PRINTF)
#else
#endif
int _dm_gpio_free(struct udevice *dev, uint offset)
{
	struct gpio_dev_priv *uc_priv;
	int ret;

	uc_priv = dev_get_uclass_priv(dev);
	if (!uc_priv->name[offset])
		return -ENXIO;
	if (gpio_get_ops(dev)->free) {
		ret = gpio_get_ops(dev)->free(dev, offset);
		if (ret)
			return ret;
	}

	free(uc_priv->name[offset]);
	uc_priv->name[offset] = NULL;

	return 0;
}
int gpio_free(unsigned gpio)
{
	struct gpio_desc desc;
	int ret;

	ret = gpio_to_device(gpio, &desc);
	if (ret)
		return ret;

	return _dm_gpio_free(desc.dev, desc.offset);
}
int dm_gpio_free(struct udevice *dev, struct gpio_desc *desc)
{
	/* For now, we don't do any checking of dev */
	return _dm_gpio_free(desc->dev, desc->offset);
}
static int gpio_pre_remove(struct udevice *dev)
{
	struct gpio_dev_priv *uc_priv = dev_get_uclass_priv(dev);
	int i;

	for (i = 0; i < uc_priv->gpio_count; i++) {
		if (uc_priv->name[i])
			free(uc_priv->name[i]);
	}
	free(uc_priv->name);

	return gpio_renumber(dev);
}
#if defined(CONFIG_NEEDS_MANUAL_RELOC)
#endif
