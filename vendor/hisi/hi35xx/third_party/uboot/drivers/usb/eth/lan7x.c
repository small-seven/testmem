#include <dm.h>
#include <malloc.h>
#include <miiphy.h>
#include <memalign.h>
#include <usb.h>
#include <linux/ethtool.h>
#include <linux/mii.h>
#include "usb_ether.h"
#include "lan7x.h"
int lan7x_eth_remove(struct udevice *dev)
{
	struct lan7x_private *priv = dev_get_priv(dev);

	debug("** %s()\n", __func__);
	free(priv->phydev);
	mdio_unregister(priv->mdiobus);
	mdio_free(priv->mdiobus);

	return 0;
}
