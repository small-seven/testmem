#include <common.h>
#include <command.h>
#include <console.h>
#include <dm.h>
#include <dm/lists.h>
#include <net.h>
#include <phy.h>
#include <errno.h>
#include <miiphy.h>
#include <malloc.h>
#include <asm/ti-common/keystone_nav.h>
#include <asm/ti-common/keystone_net.h>
#include <asm/ti-common/keystone_serdes.h>
#include <asm/arch/psc_defs.h>
#include "cpsw_mdio.h"
#ifdef KEYSTONE2_EMAC_GIG_ENABLE
#define emac_gigabit_enable(x)	keystone2_eth_gigabit_enable(x)
#else
#define emac_gigabit_enable(x)	/* no gigabit to enable */
#endif
#define RX_BUFF_NUMS	24
#define RX_BUFF_LEN	1520
#define MAX_SIZE_STREAM_BUFFER RX_BUFF_LEN
#define SGMII_ANEG_TIMEOUT		4000
#define mac_hi(mac)     (((mac)[0] << 0) | ((mac)[1] << 8) |    \
#define mac_lo(mac)     (((mac)[4] << 0) | ((mac)[5] << 8))
#ifdef CONFIG_KSNET_NETCP_V1_0
#define EMAC_EMACSW_BASE_OFS		0x90800
#define EMAC_EMACSW_PORT_BASE_OFS	(EMAC_EMACSW_BASE_OFS + 0x60)
#define CPGMACSL_REG_SA_LO		0x10
#define CPGMACSL_REG_SA_HI		0x14
#define DEVICE_EMACSW_BASE(base, x)	((base) + EMAC_EMACSW_PORT_BASE_OFS +  \
#elif defined(CONFIG_KSNET_NETCP_V1_5)
#define EMAC_EMACSW_PORT_BASE_OFS	0x222000
#define CPGMACSL_REG_SA_LO		0x308
#define CPGMACSL_REG_SA_HI		0x30c
#define DEVICE_EMACSW_BASE(base, x)	((base) + EMAC_EMACSW_PORT_BASE_OFS +  \
#endif
#ifdef CONFIG_SOC_K2G
#else
#endif
#ifndef CONFIG_SOC_K2HK
#endif
#ifndef CONFIG_SOC_K2G
#if defined(CONFIG_SOC_K2E) || defined(CONFIG_SOC_K2L)
#endif
#endif
#ifdef CONFIG_SOC_K2G
#else
#endif
#ifndef CONFIG_SOC_K2G
#endif
#ifndef CONFIG_SOC_K2G
#endif
#ifdef CONFIG_DM_ETH
#endif
int ks2_eth_remove(struct udevice *dev)
{
	struct ks2_eth_priv *priv = dev_get_priv(dev);

	cpsw_mdio_free(priv->mdio_bus);

	return 0;
}
