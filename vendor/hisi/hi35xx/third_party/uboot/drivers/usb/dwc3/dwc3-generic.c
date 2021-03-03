#include <common.h>
#include <cpu_func.h>
#include <asm-generic/io.h>
#include <dm.h>
#include <dm/device-internal.h>
#include <dm/lists.h>
#include <dwc3-uboot.h>
#include <linux/usb/ch9.h>
#include <linux/usb/gadget.h>
#include <malloc.h>
#include <usb.h>
#include "core.h"
#include "gadget.h"
#include <reset.h>
#include <clk.h>
#include <usb/xhci.h>
#if CONFIG_IS_ENABLED(OF_CONTROL)
#endif
static int dwc3_generic_remove(struct udevice *dev,
			       struct dwc3_generic_priv *priv)
{
	struct dwc3 *dwc3 = &priv->dwc3;

	dwc3_remove(dwc3);
	dwc3_shutdown_phy(dev, priv->phys, priv->num_phys);
	unmap_physmem(dwc3->regs, MAP_NOCACHE);

	return 0;
}
#if CONFIG_IS_ENABLED(DM_USB_GADGET)
static int dwc3_generic_peripheral_remove(struct udevice *dev)
{
	struct dwc3_generic_priv *priv = dev_get_priv(dev);

	return dwc3_generic_remove(dev, priv);
}
#endif
#if defined(CONFIG_SPL_USB_HOST_SUPPORT) || !defined(CONFIG_SPL_BUILD)
static int dwc3_generic_host_remove(struct udevice *dev)
{
	struct dwc3_generic_host_priv *priv = dev_get_priv(dev);
	int rc;

	rc = xhci_deregister(dev);
	if (rc)
		return rc;

	return dwc3_generic_remove(dev, &priv->gen_priv);
}
#endif
#define USBOTGSS_UTMI_OTG_STATUS		0x0084
#define USBOTGSS_UTMI_OTG_OFFSET		0x0480
#define USBOTGSS_UTMI_OTG_STATUS_SW_MODE	BIT(31)
#define USBOTGSS_UTMI_OTG_STATUS_POWERPRESENT	BIT(9)
#define USBOTGSS_UTMI_OTG_STATUS_TXBITSTUFFENABLE BIT(8)
#define USBOTGSS_UTMI_OTG_STATUS_IDDIG		BIT(4)
#define USBOTGSS_UTMI_OTG_STATUS_SESSEND	BIT(3)
#define USBOTGSS_UTMI_OTG_STATUS_SESSVALID	BIT(2)
#define USBOTGSS_UTMI_OTG_STATUS_VBUSVALID	BIT(1)
#if CONFIG_IS_ENABLED(DM_USB_GADGET)
#endif
#if defined(CONFIG_SPL_USB_HOST_SUPPORT) || !defined(CONFIG_SPL_BUILD)
#endif
#if CONFIG_IS_ENABLED(CLK)
#endif
static int dwc3_glue_remove(struct udevice *dev)
{
	struct dwc3_glue_data *glue = dev_get_platdata(dev);

	reset_release_bulk(&glue->resets);

	clk_release_bulk(&glue->clks);

	return 0;
}
