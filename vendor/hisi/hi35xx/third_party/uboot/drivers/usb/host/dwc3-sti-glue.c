#include <common.h>
#include <asm/io.h>
#include <dm.h>
#include <errno.h>
#include <fdtdec.h>
#include <linux/libfdt.h>
#include <dm/lists.h>
#include <regmap.h>
#include <reset-uclass.h>
#include <syscon.h>
#include <usb.h>
#include <linux/usb/dwc3.h>
#include <linux/usb/otg.h>
#include <dwc3-sti-glue.h>
static int sti_dwc3_glue_remove(struct udevice *dev)
{
	struct sti_dwc3_glue_platdata *plat = dev_get_platdata(dev);
	int ret;

	/* assert both powerdown and softreset */
	ret = reset_assert(&plat->powerdown_ctl);
	if (ret < 0) {
		pr_err("DWC3 powerdown reset deassert failed: %d", ret);
		return ret;
	}

	ret = reset_assert(&plat->softreset_ctl);
	if (ret < 0)
		pr_err("DWC3 soft reset deassert failed: %d", ret);

	return ret;
}
