#include <common.h>
#include <linux/libfdt.h>
#include <linux/err.h>
#include <linux/list.h>
#include <dm.h>
#include <dm/lists.h>
#include <dm/pinctrl.h>
#include <dm/util.h>
#include <dm/of_access.h>
#if CONFIG_IS_ENABLED(PINCTRL_FULL)
#if CONFIG_IS_ENABLED(PINCONF_RECURSIVE)
#endif
#else
#endif
int pinctrl_gpio_free(struct udevice *dev, unsigned offset)
{
	const struct pinctrl_ops *ops;
	struct udevice *pctldev;
	unsigned int pin_selector;
	int ret;

	ret = pinctrl_gpio_get_pinctrl_and_offset(dev, offset,
						  &pctldev, &pin_selector);
	if (ret)
		return ret;

	ops = pinctrl_get_ops(pctldev);
	if (!ops || !ops->gpio_disable_free)
		return -ENOTSUPP;

	return ops->gpio_disable_free(pctldev, pin_selector);
}
