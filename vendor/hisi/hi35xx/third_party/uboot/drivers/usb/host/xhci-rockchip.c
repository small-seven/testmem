#include <common.h>
#include <dm.h>
#include <malloc.h>
#include <usb.h>
#include <watchdog.h>
#include <linux/errno.h>
#include <linux/compat.h>
#include <linux/usb/dwc3.h>
#include <power/regulator.h>
#include <usb/xhci.h>
static int xhci_usb_remove(struct udevice *dev)
{
	struct rockchip_xhci_platdata *plat = dev_get_platdata(dev);
	struct rockchip_xhci *ctx = dev_get_priv(dev);
	int ret;

	ret = xhci_deregister(dev);
	if (ret)
		return ret;
	ret = rockchip_xhci_core_exit(ctx);
	if (ret)
		return ret;

	if (plat->vbus_supply) {
		ret = regulator_set_enable(plat->vbus_supply, false);
		if (ret)
			pr_err("XHCI: failed to set VBus supply\n");
	}

	return ret;
}
