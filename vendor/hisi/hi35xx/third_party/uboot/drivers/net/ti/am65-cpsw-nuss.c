#include <common.h>
#include <asm/io.h>
#include <asm/processor.h>
#include <clk.h>
#include <dm.h>
#include <dm/lists.h>
#include <dma-uclass.h>
#include <dm/of_access.h>
#include <miiphy.h>
#include <net.h>
#include <phy.h>
#include <power-domain.h>
#include <linux/soc/ti/ti-udma.h>
#include "cpsw_mdio.h"
#define AM65_CPSW_CPSWNU_MAX_PORTS 2
#define AM65_CPSW_SS_BASE		0x0
#define AM65_CPSW_SGMII_BASE	0x100
#define AM65_CPSW_MDIO_BASE	0xf00
#define AM65_CPSW_XGMII_BASE	0x2100
#define AM65_CPSW_CPSW_NU_BASE	0x20000
#define AM65_CPSW_CPSW_NU_ALE_BASE 0x1e000
#define AM65_CPSW_CPSW_NU_PORTS_OFFSET	0x1000
#define AM65_CPSW_CPSW_NU_PORT_MACSL_OFFSET	0x330
#define AM65_CPSW_MDIO_BUS_FREQ_DEF 1000000
#define AM65_CPSW_CTL_REG			0x4
#define AM65_CPSW_STAT_PORT_EN_REG	0x14
#define AM65_CPSW_PTYPE_REG		0x18
#define AM65_CPSW_CTL_REG_P0_ENABLE			BIT(2)
#define AM65_CPSW_CTL_REG_P0_TX_CRC_REMOVE		BIT(13)
#define AM65_CPSW_CTL_REG_P0_RX_PAD			BIT(14)
#define AM65_CPSW_P0_FLOW_ID_REG			0x8
#define AM65_CPSW_PN_RX_MAXLEN_REG		0x24
#define AM65_CPSW_PN_REG_SA_L			0x308
#define AM65_CPSW_PN_REG_SA_H			0x30c
#define AM65_CPSW_ALE_CTL_REG			0x8
#define AM65_CPSW_ALE_CTL_REG_ENABLE		BIT(31)
#define AM65_CPSW_ALE_CTL_REG_RESET_TBL		BIT(30)
#define AM65_CPSW_ALE_CTL_REG_BYPASS		BIT(4)
#define AM65_CPSW_ALE_PN_CTL_REG(x)		(0x40 + (x) * 4)
#define AM65_CPSW_ALE_PN_CTL_REG_MODE_FORWARD	0x3
#define AM65_CPSW_ALE_PN_CTL_REG_MAC_ONLY	BIT(11)
#define AM65_CPSW_MACSL_CTL_REG			0x0
#define AM65_CPSW_MACSL_CTL_REG_IFCTL_A		BIT(15)
#define AM65_CPSW_MACSL_CTL_REG_GIG		BIT(7)
#define AM65_CPSW_MACSL_CTL_REG_GMII_EN		BIT(5)
#define AM65_CPSW_MACSL_CTL_REG_LOOPBACK	BIT(1)
#define AM65_CPSW_MACSL_CTL_REG_FULL_DUPLEX	BIT(0)
#define AM65_CPSW_MACSL_RESET_REG		0x8
#define AM65_CPSW_MACSL_RESET_REG_RESET		BIT(0)
#define AM65_CPSW_MACSL_STATUS_REG		0x4
#define AM65_CPSW_MACSL_RESET_REG_PN_IDLE	BIT(31)
#define AM65_CPSW_MACSL_RESET_REG_PN_E_IDLE	BIT(30)
#define AM65_CPSW_MACSL_RESET_REG_PN_P_IDLE	BIT(29)
#define AM65_CPSW_MACSL_RESET_REG_PN_TX_IDLE	BIT(28)
#define AM65_CPSW_MACSL_RESET_REG_IDLE_MASK \
#define AM65_CPSW_CPPI_PKT_TYPE			0x7
#ifdef PKTSIZE_ALIGN
#define UDMA_RX_BUF_SIZE PKTSIZE_ALIGN
#else
#define UDMA_RX_BUF_SIZE ALIGN(1522, ARCH_DMA_MINALIGN)
#endif
#ifdef PKTBUFSRX
#define UDMA_RX_DESC_NUM PKTBUFSRX
#else
#define UDMA_RX_DESC_NUM 4
#endif
#define mac_hi(mac)	(((mac)[0] << 0) | ((mac)[1] << 8) |    \
#define mac_lo(mac)	(((mac)[4] << 0) | ((mac)[5] << 8))
#define AM65_GMII_SEL_MODE_MII		0
#define AM65_GMII_SEL_MODE_RMII		1
#define AM65_GMII_SEL_MODE_RGMII	2
#define AM65_GMII_SEL_RGMII_IDMODE	BIT(4)
