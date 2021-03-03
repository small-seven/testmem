#include <common.h>
#include <cpu_func.h>
#include <errno.h>
#include <dm.h>
#include <net.h>
#include <miiphy.h>
#include <console.h>
#include <time.h>
#include <wait_bit.h>
#include <asm/gpio.h>
#include <linux/mii.h>
#include "pic32_eth.h"
#define MAX_RX_BUF_SIZE		1536
#define MAX_RX_DESCR		PKTBUFSRX
#define MAX_TX_DESCR		2
static int pic32_eth_remove(struct udevice *dev)
{
	struct pic32eth_dev *priv = dev_get_priv(dev);
	struct mii_dev *bus;

	dm_gpio_free(dev, &priv->rst_gpio);
	phy_shutdown(priv->phydev);
	free(priv->phydev);
	bus = miiphy_get_dev_by_name(PIC32_MDIO_NAME);
	mdio_unregister(bus);
	mdio_free(bus);
	iounmap(priv->ectl_regs);
	return 0;
}
