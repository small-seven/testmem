#include <common.h>
#include <clk.h>
#include <dm.h>
#include <dm/ofnode.h>
#include <generic-phy.h>
#include <reset.h>
#include "ohci.h"
#if !defined(CONFIG_USB_OHCI_NEW)
# error "Generic OHCI driver requires CONFIG_USB_OHCI_NEW"
#endif
static int ohci_usb_remove(struct udevice *dev)
{
	struct generic_ohci *priv = dev_get_priv(dev);
	int ret;

	ret = ohci_deregister(dev);
	if (ret)
		return ret;

	ret = ohci_shutdown_phy(dev);
	if (ret)
		return ret;

	ret = reset_release_all(priv->resets, priv->reset_count);
	if (ret)
		return ret;

	return clk_release_all(priv->clocks, priv->clock_count);
}
