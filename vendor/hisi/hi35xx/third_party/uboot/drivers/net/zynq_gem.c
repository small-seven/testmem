#include <clk.h>
#include <common.h>
#include <cpu_func.h>
#include <dm.h>
#include <net.h>
#include <netdev.h>
#include <config.h>
#include <console.h>
#include <malloc.h>
#include <asm/io.h>
#include <phy.h>
#include <miiphy.h>
#include <wait_bit.h>
#include <watchdog.h>
#include <asm/system.h>
#include <asm/arch/hardware.h>
#include <asm/arch/sys_proto.h>
#include <linux/errno.h>
#define ZYNQ_GEM_PHYMNTNC_OP_MASK	0x40020000 /* operation mask bits */
#define ZYNQ_GEM_PHYMNTNC_OP_R_MASK	0x20000000 /* read operation */
#define ZYNQ_GEM_PHYMNTNC_OP_W_MASK	0x10000000 /* write operation */
#define ZYNQ_GEM_PHYMNTNC_PHYAD_SHIFT_MASK	23 /* Shift bits for PHYAD */
#define ZYNQ_GEM_PHYMNTNC_PHREG_SHIFT_MASK	18 /* Shift bits for PHREG */
#define ZYNQ_GEM_RXBUF_EOF_MASK		0x00008000 /* End of frame. */
#define ZYNQ_GEM_RXBUF_SOF_MASK		0x00004000 /* Start of frame. */
#define ZYNQ_GEM_RXBUF_LEN_MASK		0x00003FFF /* Mask for length field */
#define ZYNQ_GEM_RXBUF_WRAP_MASK	0x00000002 /* Wrap bit, last BD */
#define ZYNQ_GEM_RXBUF_NEW_MASK		0x00000001 /* Used bit.. */
#define ZYNQ_GEM_RXBUF_ADD_MASK		0xFFFFFFFC /* Mask for address */
#define ZYNQ_GEM_TXBUF_WRAP_MASK	0x40000000
#define ZYNQ_GEM_TXBUF_LAST_MASK	0x00008000 /* Last buffer */
#define ZYNQ_GEM_TXBUF_USED_MASK	0x80000000 /* Used by Hw */
#define ZYNQ_GEM_NWCTRL_TXEN_MASK	0x00000008 /* Enable transmit */
#define ZYNQ_GEM_NWCTRL_RXEN_MASK	0x00000004 /* Enable receive */
#define ZYNQ_GEM_NWCTRL_MDEN_MASK	0x00000010 /* Enable MDIO port */
#define ZYNQ_GEM_NWCTRL_STARTTX_MASK	0x00000200 /* Start tx (tx_go) */
#define ZYNQ_GEM_NWCFG_SPEED100		0x00000001 /* 100 Mbps operation */
#define ZYNQ_GEM_NWCFG_SPEED1000	0x00000400 /* 1Gbps operation */
#define ZYNQ_GEM_NWCFG_FDEN		0x00000002 /* Full Duplex mode */
#define ZYNQ_GEM_NWCFG_FSREM		0x00020000 /* FCS removal */
#define ZYNQ_GEM_NWCFG_SGMII_ENBL	0x08000000 /* SGMII Enable */
#define ZYNQ_GEM_NWCFG_PCS_SEL		0x00000800 /* PCS select */
#ifdef CONFIG_ARM64
#define ZYNQ_GEM_NWCFG_MDCCLKDIV	0x00100000 /* Div pclk by 64, max 160MHz */
#else
#define ZYNQ_GEM_NWCFG_MDCCLKDIV	0x000c0000 /* Div pclk by 48, max 120MHz */
#endif
#ifdef CONFIG_ARM64
# define ZYNQ_GEM_DBUS_WIDTH	(1 << 21) /* 64 bit bus */
#else
# define ZYNQ_GEM_DBUS_WIDTH	(0 << 21) /* 32 bit bus */
#endif
#define ZYNQ_GEM_NWCFG_INIT		(ZYNQ_GEM_DBUS_WIDTH | \
#define ZYNQ_GEM_NWSR_MDIOIDLE_MASK	0x00000004 /* PHY management idle */
#define ZYNQ_GEM_DMACR_BLENGTH		0x00000004 /* INCR4 AHB bursts */
#define ZYNQ_GEM_DMACR_RXSIZE		0x00000300
#define ZYNQ_GEM_DMACR_TXSIZE		0x00000400
#define ZYNQ_GEM_DMACR_RXBUF		0x00180000
#if defined(CONFIG_PHYS_64BIT)
# define ZYNQ_GEM_DMA_BUS_WIDTH		BIT(30) /* 64 bit bus */
#else
# define ZYNQ_GEM_DMA_BUS_WIDTH		(0 << 30) /* 32 bit bus */
#endif
#define ZYNQ_GEM_DMACR_INIT		(ZYNQ_GEM_DMACR_BLENGTH | \
#define ZYNQ_GEM_TSR_DONE		0x00000020 /* Tx done mask */
#define ZYNQ_GEM_PCS_CTL_ANEG_ENBL	0x1000
#define ZYNQ_GEM_DCFG_DBG6_DMA_64B	BIT(23)
#define PHY_DETECT_REG  1
#define PHY_DETECT_MASK 0x1808
#define ZYNQ_GEM_TXBUF_FRMLEN_MASK	0x000007ff
#define ZYNQ_GEM_TXBUF_EXHAUSTED	0x08000000
#define ZYNQ_GEM_TXBUF_UNDERRUN		0x10000000
#define ZYNQ_GEM_FREQUENCY_10	2500000UL
#define ZYNQ_GEM_FREQUENCY_100	25000000UL
#define ZYNQ_GEM_FREQUENCY_1000	125000000UL
#define LADDR_LOW	0
#define LADDR_HIGH	1
#define STAT_SIZE	44
#if defined(CONFIG_PHYS_64BIT)
#endif
#define RX_BUF 32
#define BD_SPACE	0x100000
#define BD_SEPRN_SPACE	(RX_BUF * sizeof(struct emac_bd))
#define TX_FREE_DESC	2
#if defined(CONFIG_PHYS_64BIT)
#else
#endif
#if defined(CONFIG_PHYS_64BIT)
#endif
#if defined(CONFIG_PHYS_64BIT)
#endif
#if defined(CONFIG_PHYS_64BIT)
#endif
#if defined(CONFIG_PHYS_64BIT)
#endif
#ifdef CONFIG_ARM64
#endif
#if defined(CONFIG_PHYS_64BIT)
#endif
#if defined(CONFIG_PHYS_64BIT)
#endif
#if defined(CONFIG_PHYS_64BIT)
#endif
#if defined(CONFIG_PHYS_64BIT)
#else
#endif
static int zynq_gem_remove(struct udevice *dev)
{
	struct zynq_gem_priv *priv = dev_get_priv(dev);

	free(priv->phydev);
	mdio_unregister(priv->bus);
	mdio_free(priv->bus);

	return 0;
}
