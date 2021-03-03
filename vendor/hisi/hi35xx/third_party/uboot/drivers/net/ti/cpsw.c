#include <common.h>
#include <command.h>
#include <cpu_func.h>
#include <net.h>
#include <miiphy.h>
#include <malloc.h>
#include <net.h>
#include <netdev.h>
#include <cpsw.h>
#include <linux/errno.h>
#include <asm/gpio.h>
#include <asm/io.h>
#include <phy.h>
#include <asm/arch/cpu.h>
#include <dm.h>
#include "cpsw_mdio.h"
#define BITMASK(bits)		(BIT(bits) - 1)
#define NUM_DESCS		(PKTBUFSRX * 2)
#define PKT_MIN			60
#define PKT_MAX			(1500 + 14 + 4 + 4)
#define CLEAR_BIT		1
#define GIGABITEN		BIT(7)
#define FULLDUPLEXEN		BIT(0)
#define MIIEN			BIT(15)
#define CTL_EXT_EN		BIT(18)
#define CPDMA_TXCONTROL		0x004
#define CPDMA_RXCONTROL		0x014
#define CPDMA_SOFTRESET		0x01c
#define CPDMA_RXFREE		0x0e0
#define CPDMA_TXHDP_VER1	0x100
#define CPDMA_TXHDP_VER2	0x200
#define CPDMA_RXHDP_VER1	0x120
#define CPDMA_RXHDP_VER2	0x220
#define CPDMA_TXCP_VER1		0x140
#define CPDMA_TXCP_VER2		0x240
#define CPDMA_RXCP_VER1		0x160
#define CPDMA_RXCP_VER2		0x260
#define CPDMA_DESC_SOP		BIT(31)
#define CPDMA_DESC_EOP		BIT(30)
#define CPDMA_DESC_OWNER	BIT(29)
#define CPDMA_DESC_EOQ		BIT(28)
#define CPDMA_TIMEOUT		100 /* msecs */
#ifdef CONFIG_AM33XX
#elif defined(CONFIG_TI814X)
#endif
#define ALE_ENTRY_BITS		68
#define ALE_ENTRY_WORDS		DIV_ROUND_UP(ALE_ENTRY_BITS, 32)
#define ALE_CONTROL		0x08
#define ALE_UNKNOWNVLAN		0x18
#define ALE_TABLE_CONTROL	0x20
#define ALE_TABLE		0x34
#define ALE_PORTCTL		0x40
#define ALE_TABLE_WRITE		BIT(31)
#define ALE_TYPE_FREE			0
#define ALE_TYPE_ADDR			1
#define ALE_TYPE_VLAN			2
#define ALE_TYPE_VLAN_ADDR		3
#define ALE_UCAST_PERSISTANT		0
#define ALE_UCAST_UNTOUCHED		1
#define ALE_UCAST_OUI			2
#define ALE_UCAST_TOUCHED		3
#define ALE_MCAST_FWD			0
#define ALE_MCAST_BLOCK_LEARN_FWD	1
#define ALE_MCAST_FWD_LEARN		2
#define ALE_MCAST_FWD_2			3
#define ALE_SECURE	1
#define ALE_BLOCKED	2
#define AM33XX_GMII_SEL_MODE_MII	0
#define AM33XX_GMII_SEL_MODE_RMII	1
#define AM33XX_GMII_SEL_MODE_RGMII	2
#define AM33XX_GMII_SEL_RGMII1_IDMODE	BIT(4)
#define AM33XX_GMII_SEL_RGMII2_IDMODE	BIT(5)
#define AM33XX_GMII_SEL_RMII1_IO_CLK_EN	BIT(6)
#define AM33XX_GMII_SEL_RMII2_IO_CLK_EN	BIT(7)
#define GMII_SEL_MODE_MASK		0x3
#define desc_write(desc, fld, val)	__raw_writel((u32)(val), &(desc)->fld)
#define desc_read(desc, fld)		__raw_readl(&(desc)->fld)
#define desc_read_ptr(desc, fld)	((void *)__raw_readl(&(desc)->fld))
#define chan_write(chan, fld, val)	__raw_writel((u32)(val), (chan)->fld)
#define chan_read(chan, fld)		__raw_readl((chan)->fld)
#define chan_read_ptr(chan, fld)	((void *)__raw_readl((chan)->fld))
#define for_active_slave(slave, priv) \
#define for_each_slave(slave, priv) \
#ifdef CONFIG_DM_ETH
#else
#endif
#define DEFINE_ALE_FIELD(name, start, bits)				\
static int cpsw_ale_match_free(struct cpsw_priv *priv)
{
	u32 ale_entry[ALE_ENTRY_WORDS];
	int type, idx;

	for (idx = 0; idx < priv->data->ale_entries; idx++) {
		cpsw_ale_read(priv, idx, ale_entry);
		type = cpsw_ale_get_entry_type(ale_entry);
		if (type == ALE_TYPE_FREE)
			return idx;
	}
	return -ENOENT;
}
#define cpsw_ale_enable(priv, val)	cpsw_ale_control(priv, 31, val)
#define cpsw_ale_clear(priv, val)	cpsw_ale_control(priv, 30, val)
#define cpsw_ale_vlan_aware(priv, val)	cpsw_ale_control(priv,  2, val)
#define mac_hi(mac)	(((mac)[0] << 0) | ((mac)[1] << 8) |	\
#define mac_lo(mac)	(((mac)[4] << 0) | ((mac)[5] << 8))
#ifdef CONFIG_DM_ETH
#else
#endif
static void cpdma_desc_free(struct cpsw_priv *priv, struct cpdma_desc *desc)
{
	if (desc) {
		desc_write(desc, hw_next, priv->desc_free);
		priv->desc_free = desc;
	}
}
#ifdef CONFIG_DM_ETH
#endif
#ifndef CONFIG_DM_ETH
#else
#if CONFIG_IS_ENABLED(OF_CONTROL)
#endif
#if CONFIG_IS_ENABLED(OF_CONTROL)
#endif
#endif /* CONFIG_DM_ETH */
