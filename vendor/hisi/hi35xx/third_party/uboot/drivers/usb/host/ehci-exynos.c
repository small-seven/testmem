#include <common.h>
#include <dm.h>
#include <fdtdec.h>
#include <linux/libfdt.h>
#include <malloc.h>
#include <usb.h>
#include <asm/arch/cpu.h>
#include <asm/arch/ehci.h>
#include <asm/arch/system.h>
#include <asm/arch/power.h>
#include <asm/gpio.h>
#include <linux/errno.h>
#include <linux/compat.h>
#include "ehci.h"
static int ehci_usb_remove(struct udevice *dev)
{
	struct exynos_ehci *ctx = dev_get_priv(dev);
	int ret;

	ret = ehci_deregister(dev);
	if (ret)
		return ret;
	reset_usb_phy(ctx->usb);

	return 0;
}
