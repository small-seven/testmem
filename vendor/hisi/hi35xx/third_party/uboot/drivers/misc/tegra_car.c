#include <common.h>
#include <dm.h>
#include <dm/lists.h>
#include <dm/root.h>
static int tegra_car_bpmp_remove(struct udevice *dev)
{
	debug("%s(dev=%p)\n", __func__, dev);

	return 0;
}
