#include <cpu_func.h>
#include <asm/io.h>
#include <common.h>
#include <console.h>
#include <linux/bug.h>
#include <linux/mii.h>
#include <miiphy.h>
#include <net.h>
#include <reset.h>
#include <wait_bit.h>
#define STATION_ADDR_LOW		0x0000
#define STATION_ADDR_HIGH		0x0004
#define MAC_DUPLEX_HALF_CTRL		0x0008
#define PORT_MODE			0x0040
#define PORT_EN				0x0044
#define BIT_TX_EN			BIT(2)
#define BIT_RX_EN			BIT(1)
#define MODE_CHANGE_EN			0x01b4
#define BIT_MODE_CHANGE_EN		BIT(0)
#define MDIO_SINGLE_CMD			0x03c0
#define BIT_MDIO_BUSY			BIT(20)
#define MDIO_READ			(BIT(17) | BIT_MDIO_BUSY)
#define MDIO_WRITE			(BIT(16) | BIT_MDIO_BUSY)
#define MDIO_SINGLE_DATA		0x03c4
#define MDIO_RDATA_STATUS		0x03d0
#define BIT_MDIO_RDATA_INVALID		BIT(0)
#define RX_FQ_START_ADDR		0x0500
#define RX_FQ_DEPTH			0x0504
#define RX_FQ_WR_ADDR			0x0508
#define RX_FQ_RD_ADDR			0x050c
#define RX_FQ_REG_EN			0x0518
#define RX_BQ_START_ADDR		0x0520
#define RX_BQ_DEPTH			0x0524
#define RX_BQ_WR_ADDR			0x0528
#define RX_BQ_RD_ADDR			0x052c
#define RX_BQ_REG_EN			0x0538
#define TX_BQ_START_ADDR		0x0580
#define TX_BQ_DEPTH			0x0584
#define TX_BQ_WR_ADDR			0x0588
#define TX_BQ_RD_ADDR			0x058c
#define TX_BQ_REG_EN			0x0598
#define TX_RQ_START_ADDR		0x05a0
#define TX_RQ_DEPTH			0x05a4
#define TX_RQ_WR_ADDR			0x05a8
#define TX_RQ_RD_ADDR			0x05ac
#define TX_RQ_REG_EN			0x05b8
#define BIT_START_ADDR_EN		BIT(2)
#define BIT_DEPTH_EN			BIT(1)
#define DESC_WR_RD_ENA			0x05cc
#define BIT_RX_OUTCFF_WR		BIT(3)
#define BIT_RX_CFF_RD			BIT(2)
#define BIT_TX_OUTCFF_WR		BIT(1)
#define BIT_TX_CFF_RD			BIT(0)
#define BITS_DESC_ENA			(BIT_RX_OUTCFF_WR | BIT_RX_CFF_RD | \
#define RGMII_SPEED_1000		0x2c
#define RGMII_SPEED_100			0x2f
#define RGMII_SPEED_10			0x2d
#define MII_SPEED_100			0x0f
#define MII_SPEED_10			0x0d
#define GMAC_SPEED_1000			0x05
#define GMAC_SPEED_100			0x01
#define GMAC_SPEED_10			0x00
#define GMAC_FULL_DUPLEX		BIT(4)
#define RX_DESC_NUM			64
#define TX_DESC_NUM			2
#define DESC_SIZE			32
#define DESC_WORD_SHIFT			3
#define DESC_BYTE_SHIFT			5
#define DESC_CNT(n)			((n) >> DESC_BYTE_SHIFT)
#define DESC_BYTE(n)			((n) << DESC_BYTE_SHIFT)
#define DESC_VLD_FREE			0
#define DESC_VLD_BUSY			1
#define MAC_MAX_FRAME_SIZE		1600
#define flush_desc(d) flush_cache((unsigned long)(d), sizeof(*(d)))
#define invalidate_desc(d) \
static int higmac_remove(struct udevice *dev)
{
	struct higmac_priv *priv = dev_get_priv(dev);
	int i;

	mdio_unregister(priv->bus);
	mdio_free(priv->bus);

	/* Free RX packet buffers */
	for (i = 0; i < RX_DESC_NUM; i++)
		free((void *)(unsigned long)priv->rxfq[i].buf_addr);

	return 0;
}
