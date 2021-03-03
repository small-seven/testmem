#include <common.h>
#include <cpu_func.h>
#include <dm.h>
#include <errno.h>
#include <asm/io.h>
#include <pci.h>
#include <miiphy.h>
#include "pch_gbe.h"
#if !defined(CONFIG_PHYLIB)
# error "PCH Gigabit Ethernet driver requires PHYLIB - missing CONFIG_PHYLIB"
#endif
static int pch_gbe_remove(struct udevice *dev)
{
	struct pch_gbe_priv *priv = dev_get_priv(dev);

	free(priv->phydev);
	mdio_unregister(priv->bus);
	mdio_free(priv->bus);

	return 0;
}
