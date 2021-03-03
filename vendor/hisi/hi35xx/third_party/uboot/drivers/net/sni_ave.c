#include <clk.h>
#include <cpu_func.h>
#include <dm.h>
#include <fdt_support.h>
#include <linux/io.h>
#include <linux/iopoll.h>
#include <miiphy.h>
#include <net.h>
#include <regmap.h>
#include <reset.h>
#include <syscon.h>
#define AVE_GRST_DELAY_MSEC	40
#define AVE_MIN_XMITSIZE	60
#define AVE_SEND_TIMEOUT_COUNT	1000
#define AVE_MDIO_TIMEOUT_USEC	10000
#define AVE_HALT_TIMEOUT_USEC	10000
#define AVE_IDR			0x000	/* ID */
#define AVE_VR			0x004	/* Version */
#define AVE_GRR			0x008	/* Global Reset */
#define AVE_CFGR		0x00c	/* Configuration */
#define AVE_GIMR		0x100	/* Global Interrupt Mask */
#define AVE_GISR		0x104	/* Global Interrupt Status */
#define AVE_TXCR		0x200	/* TX Setup */
#define AVE_RXCR		0x204	/* RX Setup */
#define AVE_RXMAC1R		0x208	/* MAC address (lower) */
#define AVE_RXMAC2R		0x20c	/* MAC address (upper) */
#define AVE_MDIOCTR		0x214	/* MDIO Control */
#define AVE_MDIOAR		0x218	/* MDIO Address */
#define AVE_MDIOWDR		0x21c	/* MDIO Data */
#define AVE_MDIOSR		0x220	/* MDIO Status */
#define AVE_MDIORDR		0x224	/* MDIO Rd Data */
#define AVE_DESCC		0x300	/* Descriptor Control */
#define AVE_TXDC		0x304	/* TX Descriptor Configuration */
#define AVE_RXDC		0x308	/* RX Descriptor Ring0 Configuration */
#define AVE_IIRQC		0x34c	/* Interval IRQ Control */
#define AVE_DESC_SIZE_64	12	/* Descriptor Size */
#define AVE_TXDM_64		0x1000	/* Tx Descriptor Memory */
#define AVE_RXDM_64		0x1c00	/* Rx Descriptor Memory */
#define AVE_DESC_SIZE_32	8	/* Descriptor Size */
#define AVE_TXDM_32		0x1000	/* Tx Descriptor Memory */
#define AVE_RXDM_32		0x1800	/* Rx Descriptor Memory */
#define AVE_RSTCTRL		0x8028	/* Reset control */
#define AVE_RSTCTRL_RMIIRST	BIT(16)
#define AVE_LINKSEL		0x8034	/* Link speed setting */
#define AVE_LINKSEL_100M	BIT(0)
#define AVE_GRR_PHYRST		BIT(4)	/* Reset external PHY */
#define AVE_GRR_GRST		BIT(0)	/* Reset all MAC */
#define AVE_CFGR_MII		BIT(27)	/* Func mode (1:MII/RMII, 0:RGMII) */
#define AVE_GIMR_CLR		0
#define AVE_GISR_CLR		GENMASK(31, 0)
#define AVE_TXCR_FLOCTR		BIT(18)	/* Flow control */
#define AVE_TXCR_TXSPD_1G	BIT(17)
#define AVE_TXCR_TXSPD_100	BIT(16)
#define AVE_RXCR_RXEN		BIT(30)	/* Rx enable */
#define AVE_RXCR_FDUPEN		BIT(22)	/* Interface mode */
#define AVE_RXCR_FLOCTR		BIT(21)	/* Flow control */
#define AVE_MDIOCTR_RREQ	BIT(3)	/* Read request */
#define AVE_MDIOCTR_WREQ	BIT(2)	/* Write request */
#define AVE_MDIOSR_STS		BIT(0)	/* access status */
#define AVE_DESCC_RXDSTPSTS	BIT(20)
#define AVE_DESCC_RD0		BIT(8)	/* Enable Rx descriptor Ring0 */
#define AVE_DESCC_RXDSTP	BIT(4)	/* Pause Rx descriptor */
#define AVE_DESCC_TD		BIT(0)	/* Enable Tx descriptor */
#define AVE_DESC_SIZE(priv, num) \
#define AVE_STS_OWN		BIT(31)	/* Descriptor ownership */
#define AVE_STS_OK		BIT(27)	/* Normal transmit */
#define AVE_STS_1ST		BIT(26)	/* Head of buffer chain */
#define AVE_STS_LAST		BIT(25)	/* Tail of buffer chain */
#define AVE_STS_PKTLEN_TX_MASK	GENMASK(15, 0)
#define AVE_STS_PKTLEN_RX_MASK	GENMASK(10, 0)
#define AVE_DESC_OFS_CMDSTS	0
#define AVE_DESC_OFS_ADDRL	4
#define AVE_DESC_OFS_ADDRU	8
#define AVE_RXCR_MTU		1518
#define SG_ETPINMODE		0x540
#define SG_ETPINMODE_EXTPHY	BIT(1)	/* for LD11 */
#define SG_ETPINMODE_RMII(ins)	BIT(ins)
#define AVE_MAX_CLKS		4
#define AVE_MAX_RSTS		2
static int ave_remove(struct udevice *dev)
{
	struct ave_private *priv = dev_get_priv(dev);

	free(priv->phydev);
	mdio_unregister(priv->bus);
	mdio_free(priv->bus);
	reset_release_all(priv->rst, priv->nrsts);
	clk_release_all(priv->clk, priv->nclks);

	return 0;
}
