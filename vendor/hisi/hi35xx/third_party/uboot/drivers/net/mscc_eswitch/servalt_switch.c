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
#include "mscc_miim.h"
#define PHY_CFG				0x0
#define PHY_CFG_ENA				0x3
#define PHY_CFG_COMMON_RST			BIT(2)
#define PHY_CFG_RST				(0x3 << 3)
#define PHY_STAT			0x4
#define PHY_STAT_SUPERVISOR_COMPLETE		BIT(0)
#define ANA_AC_RAM_CTRL_RAM_INIT		0x14fdc
#define ANA_AC_STAT_GLOBAL_CFG_PORT_RESET	0x15474
#define ANA_CL_PORT_VLAN_CFG(x)			(0xa018 + 0xc8 * (x))
#define		ANA_CL_PORT_VLAN_CFG_AWARE_ENA			BIT(19)
#define		ANA_CL_PORT_VLAN_CFG_POP_CNT(x)			((x) << 17)
#define ANA_L2_COMMON_FWD_CFG			0x18498
#define		ANA_L2_COMMON_FWD_CFG_CPU_DMAC_COPY_ENA	BIT(6)
#define ASM_CFG_STAT_CFG			0xb08
#define ASM_CFG_PORT(x)				(0xb74 + 0x4 * (x))
#define		ASM_CFG_PORT_NO_PREAMBLE_ENA		BIT(8)
#define		ASM_CFG_PORT_INJ_FORMAT_CFG(x)		((x) << 1)
#define ASM_RAM_CTRL_RAM_INIT			0xbfc
#define DEV_DEV_CFG_DEV_RST_CTRL	0x0
#define		DEV_DEV_CFG_DEV_RST_CTRL_SPEED_SEL(x)	((x) << 20)
#define DEV_MAC_CFG_MAC_ENA		0x24
#define		DEV_MAC_CFG_MAC_ENA_RX_ENA		BIT(4)
#define		DEV_MAC_CFG_MAC_ENA_TX_ENA		BIT(0)
#define DEV_MAC_CFG_MAC_IFG		0x3c
#define		DEV_MAC_CFG_MAC_IFG_TX_IFG(x)		((x) << 8)
#define		DEV_MAC_CFG_MAC_IFG_RX_IFG2(x)		((x) << 4)
#define		DEV_MAC_CFG_MAC_IFG_RX_IFG1(x)		(x)
#define DEV_PCS1G_CFG_PCS1G_CFG		0x48
#define		DEV_PCS1G_CFG_PCS1G_CFG_PCS_ENA		BIT(0)
#define DEV_PCS1G_CFG_PCS1G_MODE	0x4c
#define DEV_PCS1G_CFG_PCS1G_SD		0x50
#define DEV_PCS1G_CFG_PCS1G_ANEG	0x54
#define		DEV_PCS1G_CFG_PCS1G_ANEG_ADV_ABILITY(x)	((x) << 16)
#define LRN_COMMON_ACCESS_CTRL			0x0
#define		LRN_COMMON_ACCESS_CTRL_MAC_TABLE_ACCESS_SHOT	BIT(0)
#define LRN_COMMON_MAC_ACCESS_CFG0		0x4
#define LRN_COMMON_MAC_ACCESS_CFG1		0x8
#define LRN_COMMON_MAC_ACCESS_CFG2		0xc
#define		LRN_COMMON_MAC_ACCESS_CFG2_MAC_ENTRY_ADDR(x)	(x)
#define		LRN_COMMON_MAC_ACCESS_CFG2_MAC_ENTRY_TYPE(x)	((x) << 12)
#define		LRN_COMMON_MAC_ACCESS_CFG2_MAC_ENTRY_VLD	BIT(15)
#define		LRN_COMMON_MAC_ACCESS_CFG2_MAC_ENTRY_LOCKED	BIT(16)
#define		LRN_COMMON_MAC_ACCESS_CFG2_MAC_ENTRY_CPU_COPY	BIT(23)
#define		LRN_COMMON_MAC_ACCESS_CFG2_MAC_ENTRY_CPU_QU(x)	((x) << 24)
#define QFWD_SYSTEM_SWITCH_PORT_MODE(x)		(0x4400 + 0x4 * (x))
#define		QFWD_SYSTEM_SWITCH_PORT_MODE_PORT_ENA		BIT(17)
#define QS_XTR_GRP_CFG(x)		(4 * (x))
#define QS_INJ_GRP_CFG(x)		(0x24 + (x) * 4)
#define QSYS_SYSTEM_RESET_CFG			0x1048
#define QSYS_CALCFG_CAL_AUTO			0x1134
#define QSYS_CALCFG_CAL_CTRL			0x113c
#define		QSYS_CALCFG_CAL_CTRL_CAL_MODE(x)		((x) << 11)
#define QSYS_RAM_CTRL_RAM_INIT			0x1140
#define REW_RAM_CTRL_RAM_INIT			0xFFF4
#define MAC_VID			0
#define CPU_PORT		11
#define IFH_LEN			7
#define ETH_ALEN		6
#define PGID_BROADCAST		50
#define PGID_UNICAST		51
#define REGS_NAMES_COUNT ARRAY_SIZE(regs_names) + 1
#define MAX_PORT 2
#define SERVALT_MIIM_BUS_COUNT 2
static int servalt_remove(struct udevice *dev)
{
	struct servalt_private *priv = dev_get_priv(dev);
	int i;

	for (i = 0; i < SERVALT_MIIM_BUS_COUNT; i++) {
		mdio_unregister(priv->bus[i]);
		mdio_free(priv->bus[i]);
	}

	return 0;
}
