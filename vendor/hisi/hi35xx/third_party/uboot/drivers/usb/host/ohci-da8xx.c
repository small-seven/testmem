#include <common.h>
#include <asm/io.h>
#include <clk.h>
#include <dm.h>
#include <dm/ofnode.h>
#include <generic-phy.h>
#include <reset.h>
#include "ohci.h"
#include <asm/arch/da8xx-usb.h>
#if CONFIG_IS_ENABLED(DM_USB)
static int ohci_da8xx_remove(struct udevice *dev)
{
	struct da8xx_ohci *priv = dev_get_priv(dev);
	int ret;

	ret = ohci_deregister(dev);
	if (ret)
		return ret;

	ret = usb_cpu_stop();
	if (ret)
		return ret;

	return clk_release_all(priv->clocks, priv->clock_count);
}
#endif
