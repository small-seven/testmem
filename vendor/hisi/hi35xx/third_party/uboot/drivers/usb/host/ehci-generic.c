#include <common.h>
#include <clk.h>
#include <dm/ofnode.h>
#include <generic-phy.h>
#include <reset.h>
#include <asm/io.h>
#include <dm.h>
#include "ehci.h"
#include <power/regulator.h>
#ifdef CONFIG_DM_REGULATOR
#endif
#ifdef CONFIG_DM_REGULATOR
#else
#endif
static int ehci_usb_remove(struct udevice *dev)
{
	struct generic_ehci *priv = dev_get_priv(dev);
	int ret;

	ret = ehci_deregister(dev);
	if (ret)
		return ret;

	ret = ehci_shutdown_phy(dev, &priv->phy);
	if (ret)
		return ret;

	ret = ehci_disable_vbus_supply(priv);
	if (ret)
		return ret;

	ret =  reset_release_all(priv->resets, priv->reset_count);
	if (ret)
		return ret;

	return clk_release_all(priv->clocks, priv->clock_count);
}
