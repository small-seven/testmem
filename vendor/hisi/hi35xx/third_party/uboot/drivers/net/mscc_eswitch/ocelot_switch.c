#include <common.h>
#include <config.h>
#include <dm.h>
#include <dm/of_access.h>
#include <dm/of_addr.h>
#include <fdt_support.h>
#include <linux/io.h>
#include <linux/ioport.h>
#include <miiphy.h>
#include <net.h>
#include <wait_bit.h>
#include "mscc_xfer.h"
#include "mscc_mac_table.h"
#include "mscc_miim.h"
#define PHY_CFG				0x0
#define PHY_CFG_ENA				0xF
#define PHY_CFG_COMMON_RST			BIT(4)
#define PHY_CFG_RST				(0xF << 5)
#define PHY_STAT			0x4
#define PHY_STAT_SUPERVISOR_COMPLETE		BIT(0)
#define ANA_PORT_VLAN_CFG(x)		(0x7000 + 0x100 * (x))
#define		ANA_PORT_VLAN_CFG_AWARE_ENA	BIT(20)
#define		ANA_PORT_VLAN_CFG_POP_CNT(x)	((x) << 18)
#define ANA_PORT_PORT_CFG(x)		(0x7070 + 0x100 * (x))
#define		ANA_PORT_PORT_CFG_RECV_ENA	BIT(6)
#define ANA_PGID(x)			(0x8c00 + 4 * (x))
#define HSIO_ANA_SERDES1G_DES_CFG		0x4c
#define		HSIO_ANA_SERDES1G_DES_CFG_BW_HYST(x)		((x) << 1)
#define		HSIO_ANA_SERDES1G_DES_CFG_BW_ANA(x)		((x) << 5)
#define		HSIO_ANA_SERDES1G_DES_CFG_MBTR_CTRL(x)		((x) << 8)
#define		HSIO_ANA_SERDES1G_DES_CFG_PHS_CTRL(x)		((x) << 13)
#define HSIO_ANA_SERDES1G_IB_CFG		0x50
#define		HSIO_ANA_SERDES1G_IB_CFG_RESISTOR_CTRL(x)	(x)
#define		HSIO_ANA_SERDES1G_IB_CFG_EQ_GAIN(x)		((x) << 6)
#define		HSIO_ANA_SERDES1G_IB_CFG_ENA_OFFSET_COMP	BIT(9)
#define		HSIO_ANA_SERDES1G_IB_CFG_ENA_DETLEV		BIT(11)
#define		HSIO_ANA_SERDES1G_IB_CFG_ENA_CMV_TERM		BIT(13)
#define		HSIO_ANA_SERDES1G_IB_CFG_ACJTAG_HYST(x)		((x) << 24)
#define HSIO_ANA_SERDES1G_OB_CFG		0x54
#define		HSIO_ANA_SERDES1G_OB_CFG_RESISTOR_CTRL(x)	(x)
#define		HSIO_ANA_SERDES1G_OB_CFG_VCM_CTRL(x)		((x) << 4)
#define		HSIO_ANA_SERDES1G_OB_CFG_CMM_BIAS_CTRL(x)	((x) << 10)
#define		HSIO_ANA_SERDES1G_OB_CFG_AMP_CTRL(x)		((x) << 13)
#define		HSIO_ANA_SERDES1G_OB_CFG_SLP(x)			((x) << 17)
#define HSIO_ANA_SERDES1G_SER_CFG		0x58
#define HSIO_ANA_SERDES1G_COMMON_CFG		0x5c
#define		HSIO_ANA_SERDES1G_COMMON_CFG_IF_MODE		BIT(0)
#define		HSIO_ANA_SERDES1G_COMMON_CFG_ENA_LANE		BIT(18)
#define		HSIO_ANA_SERDES1G_COMMON_CFG_SYS_RST		BIT(31)
#define HSIO_ANA_SERDES1G_PLL_CFG		0x60
#define		HSIO_ANA_SERDES1G_PLL_CFG_FSM_ENA		BIT(7)
#define		HSIO_ANA_SERDES1G_PLL_CFG_FSM_CTRL_DATA(x)	((x) << 8)
#define		HSIO_ANA_SERDES1G_PLL_CFG_ENA_RC_DIV2		BIT(21)
#define HSIO_DIG_SERDES1G_DFT_CFG0		0x68
#define HSIO_DIG_SERDES1G_MISC_CFG		0x7c
#define		HSIO_DIG_SERDES1G_MISC_CFG_LANE_RST		BIT(0)
#define HSIO_MCB_SERDES1G_CFG			0x88
#define		HSIO_MCB_SERDES1G_CFG_WR_ONE_SHOT		BIT(31)
#define		HSIO_MCB_SERDES1G_CFG_ADDR(x)			(x)
#define HSIO_HW_CFGSTAT_HW_CFG			0x10c
#define SYS_FRM_AGING			0x574
#define		SYS_FRM_AGING_ENA		BIT(20)
#define SYS_SYSTEM_RST_CFG		0x508
#define		SYS_SYSTEM_RST_MEM_INIT		BIT(0)
#define		SYS_SYSTEM_RST_MEM_ENA		BIT(1)
#define		SYS_SYSTEM_RST_CORE_ENA		BIT(2)
#define SYS_PORT_MODE(x)		(0x514 + 0x4 * (x))
#define		SYS_PORT_MODE_INCL_INJ_HDR(x)	((x) << 3)
#define		SYS_PORT_MODE_INCL_INJ_HDR_M	GENMASK(4, 3)
#define		SYS_PORT_MODE_INCL_XTR_HDR(x)	((x) << 1)
#define		SYS_PORT_MODE_INCL_XTR_HDR_M	GENMASK(2, 1)
#define	SYS_PAUSE_CFG(x)		(0x608 + 0x4 * (x))
#define		SYS_PAUSE_CFG_PAUSE_ENA		BIT(0)
#define QSYS_SWITCH_PORT_MODE(x)	(0x11234 + 0x4 * (x))
#define		QSYS_SWITCH_PORT_MODE_PORT_ENA	BIT(14)
#define	QSYS_QMAP			0x112d8
#define	QSYS_EGR_NO_SHARING		0x1129c
#define DEV_CLOCK_CFG			0x0
#define DEV_CLOCK_CFG_LINK_SPEED_1000		1
#define DEV_MAC_ENA_CFG			0x1c
#define		DEV_MAC_ENA_CFG_RX_ENA		BIT(4)
#define		DEV_MAC_ENA_CFG_TX_ENA		BIT(0)
#define DEV_MAC_IFG_CFG			0x30
#define		DEV_MAC_IFG_CFG_TX_IFG(x)	((x) << 8)
#define		DEV_MAC_IFG_CFG_RX_IFG2(x)	((x) << 4)
#define		DEV_MAC_IFG_CFG_RX_IFG1(x)	(x)
#define PCS1G_CFG			0x48
#define		PCS1G_MODE_CFG_SGMII_MODE_ENA	BIT(0)
#define PCS1G_MODE_CFG			0x4c
#define		PCS1G_MODE_CFG_UNIDIR_MODE_ENA	BIT(4)
#define		PCS1G_MODE_CFG_SGMII_MODE_ENA	BIT(0)
#define PCS1G_SD_CFG			0x50
#define PCS1G_ANEG_CFG			0x54
#define		PCS1G_ANEG_CFG_ADV_ABILITY(x)	((x) << 16)
#define QS_XTR_GRP_CFG(x)		(4 * (x))
#define QS_XTR_GRP_CFG_MODE(x)			((x) << 2)
#define		QS_XTR_GRP_CFG_STATUS_WORD_POS	BIT(1)
#define		QS_XTR_GRP_CFG_BYTE_SWAP	BIT(0)
#define QS_INJ_GRP_CFG(x)		(0x24 + (x) * 4)
#define		QS_INJ_GRP_CFG_MODE(x)		((x) << 2)
#define		QS_INJ_GRP_CFG_BYTE_SWAP	BIT(0)
#define IFH_INJ_BYPASS		BIT(31)
#define IFH_TAG_TYPE_C		0
#define MAC_VID			1
#define CPU_PORT		11
#define INTERNAL_PORT_MSK	0x2FF
#define IFH_LEN			4
#define ETH_ALEN		6
#define PGID_BROADCAST		13
#define PGID_UNICAST		14
#define PGID_SRC		80
#define REGS_NAMES_COUNT ARRAY_SIZE(regs_names) + 1
#define MAX_PORT 11
#define OCELOT_MIIM_BUS_COUNT 2
static int ocelot_remove(struct udevice *dev)
{
	struct ocelot_private *priv = dev_get_priv(dev);
	int i;

	for (i = 0; i < OCELOT_MIIM_BUS_COUNT; i++) {
		mdio_unregister(priv->bus[i]);
		mdio_free(priv->bus[i]);
	}

	return 0;
}
