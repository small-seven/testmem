#include <common.h>
#include <dm.h>
#include <fdtdec.h>
#include <generic-phy.h>
#include <usb.h>
#include <dwc3-uboot.h>
#include <usb/xhci.h>
#include <asm/io.h>
#include <linux/usb/dwc3.h>
#include <linux/usb/otg.h>
#if CONFIG_IS_ENABLED(DM_USB)
static int xhci_dwc3_remove(struct udevice *dev)
{
	struct xhci_dwc3_platdata *plat = dev_get_platdata(dev);

	dwc3_shutdown_phy(dev, plat->usb_phys, plat->num_phys);

	return xhci_deregister(dev);
}
#endif
