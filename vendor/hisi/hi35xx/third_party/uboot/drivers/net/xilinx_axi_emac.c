#include <config.h>
#include <common.h>
#include <cpu_func.h>
#include <dm.h>
#include <net.h>
#include <malloc.h>
#include <asm/io.h>
#include <phy.h>
#include <miiphy.h>
#include <wait_bit.h>
#define XAE_EMMC_LINKSPEED_MASK	0xC0000000 /* Link speed */
#define XAE_EMMC_LINKSPD_10	0x00000000 /* Link Speed mask for 10 Mbit */
#define XAE_EMMC_LINKSPD_100	0x40000000 /* Link Speed mask for 100 Mbit */
#define XAE_EMMC_LINKSPD_1000	0x80000000 /* Link Speed mask for 1000 Mbit */
#define XAE_INT_RXRJECT_MASK	0x00000008 /* Rx frame rejected */
#define XAE_INT_MGTRDY_MASK	0x00000080 /* MGT clock Lock */
#define XAE_RCW1_RX_MASK	0x10000000 /* Receiver enable */
#define XAE_TC_TX_MASK		0x10000000 /* Transmitter enable */
#define XAE_UAW1_UNICASTADDR_MASK	0x0000FFFF
#define XAE_MDIO_MC_MDIOEN_MASK		0x00000040 /* MII management enable*/
#define XAE_MDIO_MCR_PHYAD_MASK		0x1F000000 /* Phy Address Mask */
#define XAE_MDIO_MCR_PHYAD_SHIFT	24	   /* Phy Address Shift */
#define XAE_MDIO_MCR_REGAD_MASK		0x001F0000 /* Reg Address Mask */
#define XAE_MDIO_MCR_REGAD_SHIFT	16	   /* Reg Address Shift */
#define XAE_MDIO_MCR_OP_READ_MASK	0x00008000 /* Op Code Read Mask */
#define XAE_MDIO_MCR_OP_WRITE_MASK	0x00004000 /* Op Code Write Mask */
#define XAE_MDIO_MCR_INITIATE_MASK	0x00000800 /* Ready Mask */
#define XAE_MDIO_MCR_READY_MASK		0x00000080 /* Ready Mask */
#define XAE_MDIO_DIV_DFT	29	/* Default MDIO clock divisor */
#define XAXIDMA_BD_STS_ACTUAL_LEN_MASK	0x007FFFFF /* Actual len */
#define XAXIDMA_CR_RUNSTOP_MASK	0x00000001 /* Start/stop DMA channel */
#define XAXIDMA_CR_RESET_MASK	0x00000004 /* Reset DMA engine */
#define XAXIDMA_HALTED_MASK	0x00000001  /* DMA channel halted */
#define XAXIDMA_IRQ_IOC_MASK	0x00001000 /* Completion intr */
#define XAXIDMA_IRQ_DELAY_MASK	0x00002000 /* Delay interrupt */
#define XAXIDMA_IRQ_ALL_MASK	0x00007000 /* All interrupts */
#define XAXIDMA_BD_CTRL_TXSOF_MASK	0x08000000 /* First tx packet */
#define XAXIDMA_BD_CTRL_TXEOF_MASK	0x04000000 /* Last tx packet */
#define DMAALIGN	128
#define PHY_DETECT_REG  1
#define PHY_DETECT_MASK 0x1808
#if defined(CONFIG_PHYS_64BIT)
#else
#endif
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
static int axi_emac_remove(struct udevice *dev)
{
	struct axidma_priv *priv = dev_get_priv(dev);

	free(priv->phydev);
	mdio_unregister(priv->bus);
	mdio_free(priv->bus);

	return 0;
}
