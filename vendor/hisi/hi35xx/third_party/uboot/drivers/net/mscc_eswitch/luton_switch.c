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
#define ANA_PORT_VLAN_CFG(x)		(0x00 + 0x80 * (x))
#define		ANA_PORT_VLAN_CFG_AWARE_ENA	BIT(20)
#define		ANA_PORT_VLAN_CFG_POP_CNT(x)	((x) << 18)
#define ANA_PORT_CPU_FWD_CFG(x)		(0x50 + 0x80 * (x))
#define		ANA_PORT_CPU_FWD_CFG_SRC_COPY_ENA	BIT(1)
#define ANA_PORT_PORT_CFG(x)		(0x60 + 0x80 * (x))
#define		ANA_PORT_PORT_CFG_RECV_ENA	BIT(5)
#define ANA_PGID(x)			(0x1000 + 4 * (x))
#define SYS_FRM_AGING			0x8300
#define SYS_SYSTEM_RST_CFG		0x81b0
#define		SYS_SYSTEM_RST_MEM_INIT		BIT(0)
#define		SYS_SYSTEM_RST_MEM_ENA		BIT(1)
#define		SYS_SYSTEM_RST_CORE_ENA		BIT(2)
#define SYS_PORT_MODE(x)		(0x81bc + 0x4 * (x))
#define		SYS_PORT_MODE_INCL_INJ_HDR	BIT(0)
#define SYS_SWITCH_PORT_MODE(x)		(0x8294 + 0x4 * (x))
#define		SYS_SWITCH_PORT_MODE_PORT_ENA	BIT(3)
#define SYS_EGR_NO_SHARING		0x8378
#define SYS_SCH_CPU			0x85a0
#define REW_PORT_CFG(x)			(0x8 + 0x80 * (x))
#define		REW_PORT_CFG_IFH_INSERT_ENA	BIT(7)
#define GCB_DEVCPU_RST_SOFT_CHIP_RST	0x90
#define		GCB_DEVCPU_RST_SOFT_CHIP_RST_SOFT_PHY	BIT(1)
#define GCB_MISC_STAT			0x11c
#define		GCB_MISC_STAT_PHY_READY			BIT(3)
#define	QS_XTR_MAP(x)			(0x10 + 4 * (x))
#define		QS_XTR_MAP_GRP			BIT(4)
#define		QS_XTR_MAP_ENA			BIT(0)
#define HSIO_PLL5G_CFG_PLL5G_CFG2	0x8
#define HSIO_RCOMP_CFG_CFG0		0x20
#define		HSIO_RCOMP_CFG_CFG0_MODE_SEL(x)			((x) << 8)
#define		HSIO_RCOMP_CFG_CFG0_RUN_CAL			BIT(12)
#define HSIO_RCOMP_STATUS		0x24
#define		HSIO_RCOMP_STATUS_BUSY				BIT(12)
#define		HSIO_RCOMP_STATUS_RCOMP_M			GENMASK(3, 0)
#define HSIO_SERDES6G_ANA_CFG_DES_CFG	0x64
#define		HSIO_SERDES6G_ANA_CFG_DES_CFG_BW_ANA(x)		((x) << 1)
#define		HSIO_SERDES6G_ANA_CFG_DES_CFG_BW_HYST(x)	((x) << 5)
#define		HSIO_SERDES6G_ANA_CFG_DES_CFG_MBTR_CTRL(x)	((x) << 10)
#define		HSIO_SERDES6G_ANA_CFG_DES_CFG_PHS_CTRL(x)	((x) << 13)
#define HSIO_SERDES6G_ANA_CFG_IB_CFG	0x68
#define		HSIO_SERDES6G_ANA_CFG_IB_CFG_RESISTOR_CTRL(x)	(x)
#define		HSIO_SERDES6G_ANA_CFG_IB_CFG_VBCOM(x)		((x) << 4)
#define		HSIO_SERDES6G_ANA_CFG_IB_CFG_VBAC(x)		((x) << 7)
#define		HSIO_SERDES6G_ANA_CFG_IB_CFG_RT(x)		((x) << 9)
#define		HSIO_SERDES6G_ANA_CFG_IB_CFG_RF(x)		((x) << 14)
#define HSIO_SERDES6G_ANA_CFG_IB_CFG1	0x6c
#define		HSIO_SERDES6G_ANA_CFG_IB_CFG1_RST		BIT(0)
#define		HSIO_SERDES6G_ANA_CFG_IB_CFG1_ENA_OFFSDC	BIT(2)
#define		HSIO_SERDES6G_ANA_CFG_IB_CFG1_ENA_OFFSAC	BIT(3)
#define		HSIO_SERDES6G_ANA_CFG_IB_CFG1_ANEG_MODE	BIT(6)
#define		HSIO_SERDES6G_ANA_CFG_IB_CFG1_CHF		BIT(7)
#define		HSIO_SERDES6G_ANA_CFG_IB_CFG1_C(x)		((x) << 8)
#define HSIO_SERDES6G_ANA_CFG_OB_CFG	0x70
#define		HSIO_SERDES6G_ANA_CFG_OB_CFG_SR(x)		((x) << 4)
#define		HSIO_SERDES6G_ANA_CFG_OB_CFG_SR_H		BIT(8)
#define		HSIO_SERDES6G_ANA_CFG_OB_CFG_POST0(x)		((x) << 23)
#define		HSIO_SERDES6G_ANA_CFG_OB_CFG_POL		BIT(29)
#define		HSIO_SERDES6G_ANA_CFG_OB_CFG_ENA1V_MODE	BIT(30)
#define HSIO_SERDES6G_ANA_CFG_OB_CFG1	0x74
#define		HSIO_SERDES6G_ANA_CFG_OB_CFG1_LEV(x)		(x)
#define		HSIO_SERDES6G_ANA_CFG_OB_CFG1_ENA_CAS(x)	((x) << 6)
#define HSIO_SERDES6G_ANA_CFG_COMMON_CFG 0x7c
#define		HSIO_SERDES6G_ANA_CFG_COMMON_CFG_IF_MODE(x)	(x)
#define		HSIO_SERDES6G_ANA_CFG_COMMON_CFG_ENA_LANE	BIT(18)
#define		HSIO_SERDES6G_ANA_CFG_COMMON_CFG_SYS_RST	BIT(31)
#define HSIO_SERDES6G_ANA_CFG_PLL_CFG	0x80
#define		HSIO_SERDES6G_ANA_CFG_PLL_CFG_FSM_ENA		BIT(7)
#define		HSIO_SERDES6G_ANA_CFG_PLL_CFG_FSM_CTRL_DATA(x)	((x) << 8)
#define HSIO_SERDES6G_ANA_CFG_SER_CFG	0x84
#define HSIO_SERDES6G_DIG_CFG_MISC_CFG	0x88
#define		HSIO_SERDES6G_DIG_CFG_MISC_CFG_LANE_RST		BIT(0)
#define HSIO_MCB_SERDES6G_CFG		0xac
#define		HSIO_MCB_SERDES6G_CFG_WR_ONE_SHOT		BIT(31)
#define		HSIO_MCB_SERDES6G_CFG_ADDR(x)			(x)
#define DEV_GMII_PORT_MODE_CLK		0x0
#define		DEV_GMII_PORT_MODE_CLK_PHY_RST	BIT(0)
#define DEV_GMII_MAC_CFG_MAC_ENA	0xc
#define		DEV_GMII_MAC_CFG_MAC_ENA_RX_ENA		BIT(4)
#define		DEV_GMII_MAC_CFG_MAC_ENA_TX_ENA		BIT(0)
#define DEV_PORT_MODE_CLK		0x4
#define		DEV_PORT_MODE_CLK_PHY_RST		BIT(2)
#define		DEV_PORT_MODE_CLK_LINK_SPEED_1000	1
#define DEV_MAC_CFG_MAC_ENA		0x10
#define		DEV_MAC_CFG_MAC_ENA_RX_ENA		BIT(4)
#define		DEV_MAC_CFG_MAC_ENA_TX_ENA		BIT(0)
#define DEV_MAC_CFG_MAC_IFG		0x24
#define		DEV_MAC_CFG_MAC_IFG_TX_IFG(x)		((x) << 8)
#define		DEV_MAC_CFG_MAC_IFG_RX_IFG2(x)		((x) << 4)
#define		DEV_MAC_CFG_MAC_IFG_RX_IFG1(x)		(x)
#define DEV_PCS1G_CFG_PCS1G_CFG		0x40
#define		DEV_PCS1G_CFG_PCS1G_CFG_PCS_ENA		BIT(0)
#define DEV_PCS1G_CFG_PCS1G_MODE	0x44
#define DEV_PCS1G_CFG_PCS1G_SD		0x48
#define DEV_PCS1G_CFG_PCS1G_ANEG	0x4c
#define		DEV_PCS1G_CFG_PCS1G_ANEG_ADV_ABILITY(x)	((x) << 16)
#define IFH_INJ_BYPASS		BIT(31)
#define IFH_TAG_TYPE_C		0
#define MAC_VID			1
#define CPU_PORT		26
#define INTERNAL_PORT_MSK	0xFFFFFF
#define IFH_LEN			2
#define ETH_ALEN		6
#define PGID_BROADCAST		28
#define PGID_UNICAST		29
#define PGID_SRC		80
#define REGS_NAMES_COUNT ARRAY_SIZE(regs_names) + 1
#define MAX_PORT 24
#define MIN_INT_PORT	0
#define PORT10		10
#define PORT11		11
#define MAX_INT_PORT	12
#define MIN_EXT_PORT	MAX_INT_PORT
#define MAX_EXT_PORT	MAX_PORT
#define LUTON_MIIM_BUS_COUNT 2
static int luton_remove(struct udevice *dev)
{
	struct luton_private *priv = dev_get_priv(dev);
	int i;

	for (i = 0; i < LUTON_MIIM_BUS_COUNT; i++) {
		mdio_unregister(priv->bus[i]);
		mdio_free(priv->bus[i]);
	}

	return 0;
}
