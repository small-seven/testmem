#include <common.h>
#include <usb.h>
#include <linux/errno.h>
#include <linux/compat.h>
#include <linux/usb/xhci-fsl.h>
#include <linux/usb/dwc3.h>
#include <usb/xhci.h>
#include <fsl_errata.h>
#include <fsl_usb.h>
#include <dm.h>
#if !CONFIG_IS_ENABLED(DM_USB)
#else
#endif
#if defined(CONFIG_TARGET_LS2080AQDS) || defined(CONFIG_TARGET_LS2080ARDB) ||\
#endif
#if CONFIG_IS_ENABLED(DM_USB)
static int xhci_fsl_remove(struct udevice *dev)
{
	struct xhci_fsl_priv *priv = dev_get_priv(dev);

	fsl_xhci_core_exit(&priv->ctx);

	return xhci_deregister(dev);
}
#else
#endif
