#include <common.h>
#include <dm.h>
#include <dm/device-internal.h>
#include <dm/lists.h>
#include <linux/kernel.h>
#include <linux/io.h>
#include <usb.h>
#include <usb/xhci.h>
#include "core.h"
#include "host-export.h"
#include "gadget-export.h"
#include "drd.h"
#if defined(CONFIG_SPL_USB_HOST_SUPPORT) || !defined(CONFIG_SPL_BUILD)
#endif
#if CONFIG_IS_ENABLED(DM_USB_GADGET)
#endif
static int cdns3_remove(struct cdns3 *cdns)
{
	cdns3_exit_roles(cdns);
	generic_phy_power_off(&cdns->usb2_phy);
	generic_phy_power_off(&cdns->usb3_phy);
	generic_phy_exit(&cdns->usb2_phy);
	generic_phy_exit(&cdns->usb3_phy);
	return 0;
}
#if defined(CONFIG_SPL_USB_HOST_SUPPORT) || \
#endif
#if CONFIG_IS_ENABLED(DM_USB_GADGET)
#endif
#if CONFIG_IS_ENABLED(DM_USB_GADGET)
static int cdns3_gadget_remove(struct udevice *dev)
{
	struct cdns3_gadget_priv *priv = dev_get_priv(dev);
	struct cdns3 *cdns = &priv->cdns;

	return cdns3_remove(cdns);
}
#endif
#if defined(CONFIG_SPL_USB_HOST_SUPPORT) || \
static int cdns3_host_remove(struct udevice *dev)
{
	struct cdns3_host_priv *priv = dev_get_priv(dev);
	struct cdns3 *cdns = &priv->cdns;

	return cdns3_remove(cdns);
}
#endif
