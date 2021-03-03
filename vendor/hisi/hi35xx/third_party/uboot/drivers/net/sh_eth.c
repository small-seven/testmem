#include <config.h>
#include <common.h>
#include <cpu_func.h>
#include <env.h>
#include <malloc.h>
#include <net.h>
#include <netdev.h>
#include <miiphy.h>
#include <linux/errno.h>
#include <asm/io.h>
#ifdef CONFIG_DM_ETH
#include <clk.h>
#include <dm.h>
#include <linux/mii.h>
#include <asm/gpio.h>
#endif
#include "sh_eth.h"
#ifndef CONFIG_SH_ETHER_USE_PORT
# error "Please define CONFIG_SH_ETHER_USE_PORT"
#endif
#ifndef CONFIG_SH_ETHER_PHY_ADDR
# error "Please define CONFIG_SH_ETHER_PHY_ADDR"
#endif
#if defined(CONFIG_SH_ETHER_CACHE_WRITEBACK) && \
#define flush_cache_wback(addr, len)    \
#else
#define flush_cache_wback(...)
#endif
#if defined(CONFIG_SH_ETHER_CACHE_INVALIDATE) && defined(CONFIG_ARM)
#define invalidate_cache(addr, len)		\
#else
#define invalidate_cache(...)
#endif
#define TIMEOUT_CNT 1000
#if defined(SH_ETH_TYPE_GETHER) || defined(SH_ETH_TYPE_RZ)
#else
#endif
#if defined(SH_ETH_TYPE_GETHER) || defined(SH_ETH_TYPE_RZ)
#endif
#if defined(SH_ETH_TYPE_GETHER) || defined(SH_ETH_TYPE_RZ)
#endif
static void sh_eth_tx_desc_free(struct sh_eth_dev *eth)
{
	struct sh_eth_info *port_info = &eth->port_info[eth->port];

	if (port_info->tx_desc_alloc) {
		free(port_info->tx_desc_alloc);
		port_info->tx_desc_alloc = NULL;
	}
}
static void sh_eth_rx_desc_free(struct sh_eth_dev *eth)
{
	struct sh_eth_info *port_info = &eth->port_info[eth->port];

	if (port_info->rx_desc_alloc) {
		free(port_info->rx_desc_alloc);
		port_info->rx_desc_alloc = NULL;
	}

	if (port_info->rx_buf_alloc) {
		free(port_info->rx_buf_alloc);
		port_info->rx_buf_alloc = NULL;
	}
}
#if defined(CONFIG_R8A77980)
#endif
#if defined(SH_ETH_TYPE_GETHER) || defined(SH_ETH_TYPE_RZ)
#endif
#if defined(SH_ETH_TYPE_GETHER)
#endif
#if defined(SH_ETH_TYPE_GETHER) || defined(SH_ETH_TYPE_RZ)
#endif
#if defined(CONFIG_CPU_SH7734) || defined(CONFIG_R8A7740)
#elif defined(CONFIG_RCAR_GEN2) || defined(CONFIG_R8A77980)
#endif
#if defined(SH_ETH_TYPE_GETHER)
#elif defined(CONFIG_CPU_SH7757) || defined(CONFIG_CPU_SH7752)
#elif defined(CONFIG_RCAR_GEN2) || defined(CONFIG_R8A77980)
#endif
#if defined(SH_ETH_TYPE_GETHER)
#elif defined(CONFIG_CPU_SH7757) || defined(CONFIG_CPU_SH7752)
#endif
#if defined(SH_ETH_TYPE_GETHER)
#endif
#ifndef CONFIG_DM_ETH
#else /* CONFIG_DM_ETH */
#if CONFIG_IS_ENABLED(CLK)
#endif
#if CONFIG_IS_ENABLED(CLK)
#endif
#if CONFIG_IS_ENABLED(CLK)
#endif
static int sh_ether_remove(struct udevice *udev)
{
	struct sh_ether_priv *priv = dev_get_priv(udev);
	struct sh_eth_dev *eth = &priv->shdev;
	struct sh_eth_info *port_info = &eth->port_info[eth->port];

#if CONFIG_IS_ENABLED(CLK)
	clk_disable(&priv->clk);
#endif
	free(port_info->phydev);
	mdio_unregister(priv->bus);
	mdio_free(priv->bus);

	if (dm_gpio_is_valid(&priv->reset_gpio))
		dm_gpio_free(udev, &priv->reset_gpio);

	return 0;
}
#endif
