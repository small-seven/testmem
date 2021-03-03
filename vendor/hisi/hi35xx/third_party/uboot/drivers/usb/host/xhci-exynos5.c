#include <common.h>
#include <dm.h>
#include <fdtdec.h>
#include <linux/libfdt.h>
#include <malloc.h>
#include <usb.h>
#include <watchdog.h>
#include <asm/arch/cpu.h>
#include <asm/arch/power.h>
#include <asm/arch/xhci-exynos.h>
#include <asm/gpio.h>
#include <linux/errno.h>
#include <linux/compat.h>
#include <linux/usb/dwc3.h>
#include <usb/xhci.h>
static int xhci_usb_remove(struct udevice *dev)
{
	struct exynos_xhci *ctx = dev_get_priv(dev);
	int ret;

	ret = xhci_deregister(dev);
	if (ret)
		return ret;
	exynos_xhci_core_exit(ctx);

	return 0;
}
