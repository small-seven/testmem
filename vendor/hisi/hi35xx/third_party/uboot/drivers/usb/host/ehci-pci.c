#include <common.h>
#include <dm.h>
#include <errno.h>
#include <pci.h>
#include <usb.h>
#include <asm/io.h>
#include "ehci.h"
#if CONFIG_IS_ENABLED(DM_USB)
#else
#ifdef CONFIG_PCI_EHCI_DEVICE
#endif
#ifdef CONFIG_PCI_EHCI_DEVICE
#else
#endif
#endif /* !CONFIG_IS_ENABLED(DM_USB) */
#if CONFIG_IS_ENABLED(DM_USB)
static int ehci_pci_remove(struct udevice *dev)
{
	struct ehci_pci_priv *priv = dev_get_priv(dev);
	int ret;

	ret = ehci_deregister(dev);
	if (ret)
		return ret;

	return ehci_shutdown_phy(dev, &priv->phy);
}
#endif /* CONFIG_IS_ENABLED(DM_USB) */
