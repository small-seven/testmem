#include <common.h>
#include <dm.h>
#include <miiphy.h>
#include <dm/device-internal.h>
#include <dm/uclass-internal.h>
#define PHY_MODE_STR_CNT	2
#define PHY_HANDLE_STR_CNT	3
static int dm_mdio_pre_remove(struct udevice *dev)
{
	struct mdio_perdev_priv *pdata = dev_get_uclass_priv(dev);
	struct mdio_ops *ops = mdio_get_ops(dev);

	if (ops->reset)
		ops->reset(dev);
	mdio_unregister(pdata->mii_bus);
	mdio_free(pdata->mii_bus);

	return 0;
}
