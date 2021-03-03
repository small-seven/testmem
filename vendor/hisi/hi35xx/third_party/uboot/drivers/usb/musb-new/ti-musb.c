#include <common.h>
#include <command.h>
#include <console.h>
#include <dm.h>
#include <linux/usb/otg.h>
#include <dm/device-internal.h>
#include <dm/lists.h>
#include <asm/io.h>
#include <asm/omap_musb.h>
#include "musb_uboot.h"
#if CONFIG_IS_ENABLED(DM_USB)
#define CM_PHY_PWRDN			(1 << 0)
#define CM_PHY_OTG_PWRDN		(1 << 1)
#define OTGVDET_EN			(1 << 19)
#define OTGSESSENDEN			(1 << 20)
#define AM335X_USB0_CTRL	0x0
#define AM335X_USB1_CTRL	0x8
#if CONFIG_IS_ENABLED(OF_CONTROL)
#endif
static int ti_musb_host_remove(struct udevice *dev)
{
	struct musb_host_data *host = dev_get_priv(dev);

	musb_stop(host->host);
	ti_musb_set_phy_power(dev, 0);

	return 0;
}
#if CONFIG_IS_ENABLED(OF_CONTROL)
#endif
#if CONFIG_IS_ENABLED(OF_CONTROL)
#endif
#if CONFIG_IS_ENABLED(DM_USB_GADGET)
#if CONFIG_IS_ENABLED(OF_CONTROL)
#endif
static int ti_musb_peripheral_remove(struct udevice *dev)
{
	struct ti_musb_peripheral *priv = dev_get_priv(dev);

	usb_del_gadget_udc(&priv->periph->g);
	ti_musb_set_phy_power(dev, 0);

	return 0;
}
#if CONFIG_IS_ENABLED(OF_CONTROL)
#endif
#endif
#if CONFIG_IS_ENABLED(OF_CONTROL)
#endif /* CONFIG_IS_ENABLED(OF_CONTROL) */
#endif /* CONFIG_IS_ENABLED(DM_USB) */
