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
#define ANA_PORT_VLAN_CFG(x)			(0xc000 + 0x100 * (x))
#define		ANA_PORT_VLAN_CFG_AWARE_ENA		BIT(20)
#define		ANA_PORT_VLAN_CFG_POP_CNT(x)		((x) << 18)
#define ANA_PORT_PORT_CFG(x)			(0xc070 + 0x100 * (x))
#define		ANA_PORT_PORT_CFG_RECV_ENA		BIT(6)
#define ANA_PGID(x)				(0x9c00 + 4 * (x))
#define HSIO_ANA_SERDES1G_DES_CFG		0x3c
#define		HSIO_ANA_SERDES1G_DES_CFG_BW_HYST(x)		((x) << 1)
#define		HSIO_ANA_SERDES1G_DES_CFG_BW_ANA(x)		((x) << 5)
#define		HSIO_ANA_SERDES1G_DES_CFG_MBTR_CTRL(x)		((x) << 8)
#define		HSIO_ANA_SERDES1G_DES_CFG_PHS_CTRL(x)		((x) << 13)
#define HSIO_ANA_SERDES1G_IB_CFG		0x40
#define		HSIO_ANA_SERDES1G_IB_CFG_RESISTOR_CTRL(x)	(x)
#define		HSIO_ANA_SERDES1G_IB_CFG_EQ_GAIN(x)		((x) << 6)
#define		HSIO_ANA_SERDES1G_IB_CFG_ENA_OFFSET_COMP	BIT(9)
#define		HSIO_ANA_SERDES1G_IB_CFG_ENA_DETLEV		BIT(11)
#define		HSIO_ANA_SERDES1G_IB_CFG_ENA_CMV_TERM		BIT(13)
#define		HSIO_ANA_SERDES1G_IB_CFG_DET_LEV(x)		((x) << 19)
#define		HSIO_ANA_SERDES1G_IB_CFG_ACJTAG_HYST(x)		((x) << 24)
#define HSIO_ANA_SERDES1G_OB_CFG		0x44
#define		HSIO_ANA_SERDES1G_OB_CFG_RESISTOR_CTRL(x)	(x)
#define		HSIO_ANA_SERDES1G_OB_CFG_VCM_CTRL(x)		((x) << 4)
#define		HSIO_ANA_SERDES1G_OB_CFG_CMM_BIAS_CTRL(x)	((x) << 10)
#define		HSIO_ANA_SERDES1G_OB_CFG_AMP_CTRL(x)		((x) << 13)
#define		HSIO_ANA_SERDES1G_OB_CFG_SLP(x)			((x) << 17)
#define HSIO_ANA_SERDES1G_SER_CFG		0x48
#define HSIO_ANA_SERDES1G_COMMON_CFG		0x4c
#define		HSIO_ANA_SERDES1G_COMMON_CFG_IF_MODE		BIT(0)
#define		HSIO_ANA_SERDES1G_COMMON_CFG_ENA_LANE		BIT(18)
#define		HSIO_ANA_SERDES1G_COMMON_CFG_SYS_RST		BIT(31)
#define HSIO_ANA_SERDES1G_PLL_CFG		0x50
#define		HSIO_ANA_SERDES1G_PLL_CFG_FSM_ENA		BIT(7)
#define		HSIO_ANA_SERDES1G_PLL_CFG_FSM_CTRL_DATA(x)	((x) << 8)
#define		HSIO_ANA_SERDES1G_PLL_CFG_ENA_RC_DIV2		BIT(21)
#define HSIO_DIG_SERDES1G_DFT_CFG0		0x58
#define HSIO_DIG_SERDES1G_MISC_CFG		0x6c
#define		HSIO_DIG_SERDES1G_MISC_CFG_LANE_RST		BIT(0)
#define HSIO_MCB_SERDES1G_CFG			0x74
#define		HSIO_MCB_SERDES1G_CFG_WR_ONE_SHOT	BIT(31)
#define		HSIO_MCB_SERDES1G_CFG_ADDR(x)		(x)
#define SYS_FRM_AGING				0x584
#define		SYS_FRM_AGING_ENA			BIT(20)
#define SYS_SYSTEM_RST_CFG			0x518
#define		SYS_SYSTEM_RST_MEM_INIT			BIT(5)
#define		SYS_SYSTEM_RST_MEM_ENA			BIT(6)
#define		SYS_SYSTEM_RST_CORE_ENA			BIT(7)
#define SYS_PORT_MODE(x)			(0x524 + 0x4 * (x))
#define		SYS_PORT_MODE_INCL_INJ_HDR(x)		((x) << 4)
#define		SYS_PORT_MODE_INCL_XTR_HDR(x)		((x) << 2)
#define SYS_PAUSE_CFG(x)			(0x65c + 0x4 * (x))
#define		SYS_PAUSE_CFG_PAUSE_ENA			BIT(0)
#define QSYS_SWITCH_PORT_MODE(x)		(0x15a34 + 0x4 * (x))
#define		QSYS_SWITCH_PORT_MODE_PORT_ENA		BIT(13)
#define QSYS_EGR_NO_SHARING			0x15a9c
#define QSYS_QMAP				0x15adc
#define DEV_CLOCK_CFG				0x0
#define DEV_CLOCK_CFG_LINK_SPEED_1000			1
#define DEV_MAC_ENA_CFG				0x10
#define		DEV_MAC_ENA_CFG_RX_ENA			BIT(4)
#define		DEV_MAC_ENA_CFG_TX_ENA			BIT(0)
#define DEV_MAC_IFG_CFG				0x24
#define		DEV_MAC_IFG_CFG_TX_IFG(x)		((x) << 8)
#define		DEV_MAC_IFG_CFG_RX_IFG2(x)		((x) << 4)
#define		DEV_MAC_IFG_CFG_RX_IFG1(x)		(x)
#define PCS1G_CFG				0x3c
#define		PCS1G_MODE_CFG_SGMII_MODE_ENA		BIT(0)
#define PCS1G_MODE_CFG				0x40
#define PCS1G_SD_CFG				0x44
#define PCS1G_ANEG_CFG				0x48
#define		PCS1G_ANEG_CFG_ADV_ABILITY(x)		((x) << 16)
#define QS_XTR_GRP_CFG(x)			(4 * (x))
#define		QS_XTR_GRP_CFG_MODE(x)			((x) << 2)
#define		QS_XTR_GRP_CFG_BYTE_SWAP		BIT(0)
#define QS_INJ_GRP_CFG(x)			(0x24 + (x) * 4)
#define		QS_INJ_GRP_CFG_MODE(x)			((x) << 2)
#define		QS_INJ_GRP_CFG_BYTE_SWAP		BIT(0)
#define IFH_INJ_BYPASS		BIT(31)
#define IFH_TAG_TYPE_C		0
#define MAC_VID			1
#define CPU_PORT		11
#define INTERNAL_PORT_MSK	0xFF
#define IFH_LEN			4
#define ETH_ALEN		6
#define PGID_BROADCAST		13
#define PGID_UNICAST		14
#define REGS_NAMES_COUNT ARRAY_SIZE(regs_names) + 1
#define MAX_PORT 11
#define SERVAL_MIIM_BUS_COUNT 2
static int serval_remove(struct udevice *dev)
{
	struct serval_private *priv = dev_get_priv(dev);
	int i;

	for (i = 0; i < SERVAL_MIIM_BUS_COUNT; i++) {
		mdio_unregister(priv->bus[i]);
		mdio_free(priv->bus[i]);
	}

	return 0;
}
