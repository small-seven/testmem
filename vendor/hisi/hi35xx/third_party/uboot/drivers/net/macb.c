#include <common.h>
#include <clk.h>
#include <cpu_func.h>
#include <dm.h>
#include <net.h>
#ifndef CONFIG_DM_ETH
#include <netdev.h>
#endif
#include <malloc.h>
#include <miiphy.h>
#include <linux/mii.h>
#include <asm/io.h>
#include <asm/dma-mapping.h>
#include <asm/arch/clk.h>
#include <linux/errno.h>
#include "macb.h"
#define MACB_RX_BUFFER_SIZE		128
#define GEM_RX_BUFFER_SIZE		2048
#define RX_BUFFER_MULTIPLE		64
#define MACB_RX_RING_SIZE		32
#define MACB_TX_RING_SIZE		16
#define MACB_TX_TIMEOUT		1000
#define MACB_AUTONEG_TIMEOUT	5000000
#ifdef CONFIG_MACB_ZYNQ
#define MACB_ZYNQ_GEM_DMACR_BLENGTH		0x00000004
#define MACB_ZYNQ_GEM_DMACR_RXSIZE		0x00000300
#define MACB_ZYNQ_GEM_DMACR_TXSIZE		0x00000400
#define MACB_ZYNQ_GEM_DMACR_RXBUF		0x00020000
#define MACB_ZYNQ_GEM_DMACR_INIT \
#endif
#define DMA_DESC_BYTES(n)	(n * sizeof(struct macb_dma_desc))
#define MACB_TX_DMA_DESC_SIZE	(DMA_DESC_BYTES(MACB_TX_RING_SIZE))
#define MACB_RX_DMA_DESC_SIZE	(DMA_DESC_BYTES(MACB_RX_RING_SIZE))
#define MACB_TX_DUMMY_DMA_DESC_SIZE	(DMA_DESC_BYTES(1))
#define RXBUF_FRMLEN_MASK	0x00000fff
#define TXBUF_FRMLEN_MASK	0x000007ff
#ifndef CONFIG_DM_ETH
#endif
#ifdef CONFIG_PHYLIB
#endif
#ifdef CONFIG_DM_ETH
#ifdef CONFIG_CLK
#endif
#endif
#ifndef CONFIG_DM_ETH
#define to_macb(_nd) container_of(_nd, struct macb_device, netdev)
#endif
#ifndef cpu_is_sama5d2
#define cpu_is_sama5d2() 0
#endif
#ifndef cpu_is_sama5d4
#define cpu_is_sama5d4() 0
#endif
#if defined(CONFIG_CMD_MII) || defined(CONFIG_PHYLIB)
#ifdef CONFIG_DM_ETH
#else
#endif
#ifdef CONFIG_DM_ETH
#else
#endif
#endif
#define RX	1
#define TX	0
#if defined(CONFIG_CMD_NET)
#ifdef CONFIG_DM_ETH
#ifdef CONFIG_CLK
#endif
#else
#endif
#ifdef CONFIG_DM_ETH
#else
#endif
#ifdef CONFIG_DM_ETH
#endif
#ifdef CONFIG_PHYLIB
#ifdef CONFIG_DM_ETH
#else
#endif
#endif
#ifdef CONFIG_DM_ETH
#else
#endif
#ifdef CONFIG_DM_ETH
#else
#endif
#ifdef CONFIG_DM_ETH
#else
#endif
#ifdef CONFIG_DM_ETH
#else
#endif
#ifdef CONFIG_DM_ETH
#endif
#ifdef CONFIG_MACB_ZYNQ
#endif
#ifdef CONFIG_DM_ETH
#else
#if defined(CONFIG_RGMII) || defined(CONFIG_RMII)
#else
#endif
#endif
#ifdef CONFIG_DM_ETH
#ifdef CONFIG_AT91FAMILY
#else
#endif
#else
#ifdef CONFIG_RMII
#ifdef CONFIG_AT91FAMILY
#else
#endif
#else
#ifdef CONFIG_AT91FAMILY
#else
#endif
#endif /* CONFIG_RMII */
#endif
#ifdef CONFIG_DM_ETH
#else
#endif
#if defined(CONFIG_DM_ETH) && defined(CONFIG_CLK)
#else
#endif
#if defined(CONFIG_DM_ETH) && defined(CONFIG_CLK)
#else
#endif
#ifndef CONFIG_DM_ETH
#if defined(CONFIG_CMD_MII) || defined(CONFIG_PHYLIB)
#endif
#endif /* !CONFIG_DM_ETH */
#ifdef CONFIG_DM_ETH
#ifdef CONFIG_CLK
#endif
#ifdef CONFIG_CLK
#endif
#if defined(CONFIG_CMD_MII) || defined(CONFIG_PHYLIB)
#endif
static int macb_eth_remove(struct udevice *dev)
{
	struct macb_device *macb = dev_get_priv(dev);

#ifdef CONFIG_PHYLIB
	free(macb->phydev);
#endif
	mdio_unregister(macb->bus);
	mdio_free(macb->bus);

	return 0;
}
#endif
#endif
