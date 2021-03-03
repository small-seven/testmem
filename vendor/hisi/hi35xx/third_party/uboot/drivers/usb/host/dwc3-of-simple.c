#include <common.h>
#include <dm.h>
#include <fdtdec.h>
#include <reset.h>
#include <clk.h>
#if CONFIG_IS_ENABLED(CLK)
#endif
static int dwc3_of_simple_remove(struct udevice *dev)
{
	struct dwc3_of_simple *simple = dev_get_platdata(dev);

	reset_release_bulk(&simple->resets);

	clk_release_bulk(&simple->clks);

	return dm_scan_fdt_dev(dev);
}
