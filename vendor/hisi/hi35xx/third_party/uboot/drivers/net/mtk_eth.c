#include <common.h>
#include <cpu_func.h>
#include <dm.h>
#include <malloc.h>
#include <miiphy.h>
#include <regmap.h>
#include <reset.h>
#include <syscon.h>
#include <wait_bit.h>
#include <asm/gpio.h>
#include <asm/io.h>
#include <linux/err.h>
#include <linux/ioport.h>
#include <linux/mdio.h>
#include <linux/mii.h>
#include "mtk_eth.h"
#define NUM_TX_DESC		24
#define NUM_RX_DESC		24
#define TX_TOTAL_BUF_SIZE	(NUM_TX_DESC * PKTSIZE_ALIGN)
#define RX_TOTAL_BUF_SIZE	(NUM_RX_DESC * PKTSIZE_ALIGN)
#define TOTAL_PKT_BUF_SIZE	(TX_TOTAL_BUF_SIZE + RX_TOTAL_BUF_SIZE)
#define MT7530_NUM_PHYS		5
#define MT7530_DFL_SMI_ADDR	31
#define MT7530_PHY_ADDR(base, addr) \
#define GDMA_FWD_TO_CPU \
#define GDMA_FWD_DISCARD \
static int mtk_eth_remove(struct udevice *dev)
{
	struct mtk_eth_priv *priv = dev_get_priv(dev);

	/* MDIO unregister */
	mdio_unregister(priv->mdio_bus);
	mdio_free(priv->mdio_bus);

	/* Stop possibly started DMA */
	mtk_eth_stop(dev);

	return 0;
}
