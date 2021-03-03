#include <common.h>
#include <clk.h>
#include <cpu_func.h>
#include <dm.h>
#include <errno.h>
#include <miiphy.h>
#include <malloc.h>
#include <pci.h>
#include <reset.h>
#include <linux/compiler.h>
#include <linux/err.h>
#include <linux/kernel.h>
#include <asm/io.h>
#include <power/regulator.h>
#include "designware.h"
#ifdef CONFIG_DM_ETH
#else
#endif
#ifdef CONFIG_DM_ETH
#else
#endif
#if defined(CONFIG_DM_ETH) && defined(CONFIG_DM_GPIO)
#endif
#if defined(CONFIG_DM_ETH) && defined(CONFIG_DM_GPIO)
#endif
#if defined(CONFIG_DW_ALTDESCRIPTOR)
#else
#endif
#ifndef CONFIG_DW_MAC_FORCE_THRESHOLD_MODE
#else
#endif
#ifdef CONFIG_DW_AXI_BURST_LEN
#endif
#define ETH_ZLEN	60
#if defined(CONFIG_DW_ALTDESCRIPTOR)
#else
#endif
#ifdef CONFIG_PHY_ADDR
#endif
#ifndef CONFIG_DM_ETH
#endif
#ifdef CONFIG_DM_ETH
#ifdef CONFIG_DM_PCI
#endif
#ifdef CONFIG_CLK
#endif
#if defined(CONFIG_DM_REGULATOR)
#endif
#ifdef CONFIG_DM_PCI
#endif
#ifdef CONFIG_CLK
#endif
static int designware_eth_remove(struct udevice *dev)
{
	struct dw_eth_dev *priv = dev_get_priv(dev);

	free(priv->phydev);
	mdio_unregister(priv->bus);
	mdio_free(priv->bus);

#ifdef CONFIG_CLK
	return clk_release_all(priv->clocks, priv->clock_count);
#else
	return 0;
#endif
}
#ifdef CONFIG_DM_GPIO
#endif
#ifdef CONFIG_DM_GPIO
#endif
#ifdef CONFIG_DM_GPIO
#endif
#endif
