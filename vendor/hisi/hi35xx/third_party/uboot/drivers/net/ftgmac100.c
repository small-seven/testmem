#include <clk.h>
#include <cpu_func.h>
#include <dm.h>
#include <miiphy.h>
#include <net.h>
#include <wait_bit.h>
#include <linux/io.h>
#include <linux/iopoll.h>
#include "ftgmac100.h"
#define ETH_ZLEN			60
#define FTGMAC100_RBSR_DEFAULT		0x640
#define PKTBUFSTX	4	/* must be power of 2 */
#define FTGMAC100_TX_TIMEOUT_MS		1000
#define FTGMAC100_MDIO_TIMEOUT_USEC	10000
#define MDC_CYCTHR			0x34
static int ftgmac100_remove(struct udevice *dev)
{
	struct ftgmac100_data *priv = dev_get_priv(dev);

	free(priv->phydev);
	mdio_unregister(priv->bus);
	mdio_free(priv->bus);
	clk_release_bulk(&priv->clks);

	return 0;
}
