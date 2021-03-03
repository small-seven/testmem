#include <common.h>
#include <cpu_func.h>
#include <dm.h>
#include <env.h>
#include <malloc.h>
#include <memalign.h>
#include <miiphy.h>
#include <net.h>
#include <netdev.h>
#include <power/regulator.h>
#include <asm/io.h>
#include <linux/errno.h>
#include <linux/compiler.h>
#include <asm/arch/clock.h>
#include <asm/arch/imx-regs.h>
#include <asm/mach-imx/sys_proto.h>
#include <asm-generic/gpio.h>
#include "fec_mxc.h"
#define FEC_XFER_TIMEOUT	5000
#define FEC_DMA_RX_MINALIGN	64
#ifndef CONFIG_MII
#error "CONFIG_MII has to be defined!"
#endif
#ifndef CONFIG_FEC_XCV_TYPE
#define CONFIG_FEC_XCV_TYPE MII100
#endif
#ifdef CONFIG_MX28
#define CONFIG_FEC_MXC_SWAP_PACKET
#endif
#define RXDESC_PER_CACHELINE (ARCH_DMA_MINALIGN/sizeof(struct fec_bd))
#if ((ARCH_DMA_MINALIGN < 16) || (ARCH_DMA_MINALIGN % 16 != 0))
#error "ARCH_DMA_MINALIGN must be multiple of 16!"
#endif
#if ((PKTALIGN < ARCH_DMA_MINALIGN) || \
#error "PKTALIGN must be multiple of ARCH_DMA_MINALIGN!"
#endif
#undef DEBUG
#ifdef CONFIG_FEC_MXC_SWAP_PACKET
#endif
#ifndef imx_get_fecclk
#endif
#ifdef FEC_QUIRK_ENET_MAC
#endif
#ifndef CONFIG_PHYLIB
#if !defined(CONFIG_FEC_MXC_NO_ANEG)
#ifdef CONFIG_MX27
#endif
#endif
#ifndef CONFIG_FEC_FIXED_SPEED
#endif /* CONFIG_FEC_FIXED_SPEED */
#endif
#ifdef CONFIG_DM_ETH
#else
#endif
#ifdef CONFIG_DM_ETH
#else
#endif
#ifdef CONFIG_DM_ETH
#else
#endif
#ifdef CONFIG_DM_ETH
#else
#endif
#ifdef FEC_QUIRK_ENET_MAC
#endif
#if defined(CONFIG_MX25) || defined(CONFIG_MX53) || defined(CONFIG_MX6SL)
#endif
#ifdef CONFIG_PHYLIB
#elif CONFIG_FEC_FIXED_SPEED
#else
#endif
#ifdef FEC_QUIRK_ENET_MAC
#endif
#ifdef CONFIG_DM_ETH
#else
#endif
#ifdef CONFIG_DM_ETH
#else
#endif
#ifdef CONFIG_DM_ETH
#else
#endif
#ifndef CONFIG_PHYLIB
#endif
#ifdef CONFIG_DM_ETH
#else
#endif
#ifdef CONFIG_DM_ETH
#else
#endif
#ifdef CONFIG_DM_ETH
#else
#endif
#ifdef CONFIG_DM_ETH
#else
#endif
#ifdef CONFIG_FEC_MXC_SWAP_PACKET
#endif
#ifdef CONFIG_DM_ETH
#else
#endif
#ifdef CONFIG_DM_ETH
#else
#endif
#ifdef CONFIG_DM_ETH
#else
#endif
#ifdef CONFIG_DM_ETH
#else
#endif
#ifdef CONFIG_DM_ETH
#else
#endif
#ifdef CONFIG_DM_ETH
#else
#endif
#ifdef CONFIG_FEC_MXC_SWAP_PACKET
#endif
#ifdef CONFIG_DM_ETH
#else
#endif
#ifndef CONFIG_DM_ETH
#ifdef CONFIG_PHYLIB
#else
#endif
#ifdef CONFIG_PHYLIB
#else
#endif
#ifdef CONFIG_PHYLIB
#endif
#ifdef CONFIG_FEC_MXC_MDIO_BASE
#else
#endif
#ifdef CONFIG_PHYLIB
#else
#endif
#ifdef CONFIG_PHYLIB
#endif
#ifdef CONFIG_FEC_MXC_PHYADDR
#endif
#ifndef CONFIG_PHYLIB
#endif
#else
#ifdef CONFIG_FEC_MXC_PHYADDR
#endif
#ifdef CONFIG_DM_GPIO
#endif
#ifdef CONFIG_DM_REGULATOR
#endif
#ifdef CONFIG_DM_GPIO
#endif
#ifdef CONFIG_FEC_MXC_MDIO_BASE
#else
#endif
static int fecmxc_remove(struct udevice *dev)
{
	struct fec_priv *priv = dev_get_priv(dev);

	free(priv->phydev);
	fec_free_descs(priv);
	mdio_unregister(priv->bus);
	mdio_free(priv->bus);

#ifdef CONFIG_DM_REGULATOR
	if (priv->phy_supply)
		regulator_set_enable(priv->phy_supply, false);
#endif

	return 0;
}
#ifdef CONFIG_DM_REGULATOR
#endif
#ifdef CONFIG_DM_GPIO
#endif
#endif
