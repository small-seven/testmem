#include <common.h>
#include <phy.h>
#include <linux/compat.h>
#include <malloc.h>
#include <dm.h>
#include <dt-bindings/net/ti-dp83867.h>
#define DP83867_DEVADDR		0x1f
#define MII_DP83867_PHYCTRL	0x10
#define MII_DP83867_MICR	0x12
#define MII_DP83867_CFG2	0x14
#define MII_DP83867_BISCR	0x16
#define DP83867_CTRL		0x1f
#define DP83867_CFG4		0x0031
#define DP83867_RGMIICTL	0x0032
#define DP83867_STRAP_STS1	0x006E
#define DP83867_STRAP_STS2	0x006f
#define DP83867_RGMIIDCTL	0x0086
#define DP83867_IO_MUX_CFG	0x0170
#define DP83867_SW_RESET	BIT(15)
#define DP83867_SW_RESTART	BIT(14)
#define MII_DP83867_MICR_AN_ERR_INT_EN		BIT(15)
#define MII_DP83867_MICR_SPEED_CHNG_INT_EN	BIT(14)
#define MII_DP83867_MICR_DUP_MODE_CHNG_INT_EN	BIT(13)
#define MII_DP83867_MICR_PAGE_RXD_INT_EN	BIT(12)
#define MII_DP83867_MICR_AUTONEG_COMP_INT_EN	BIT(11)
#define MII_DP83867_MICR_LINK_STS_CHNG_INT_EN	BIT(10)
#define MII_DP83867_MICR_FALSE_CARRIER_INT_EN	BIT(8)
#define MII_DP83867_MICR_SLEEP_MODE_CHNG_INT_EN	BIT(4)
#define MII_DP83867_MICR_WOL_INT_EN		BIT(3)
#define MII_DP83867_MICR_XGMII_ERR_INT_EN	BIT(2)
#define MII_DP83867_MICR_POL_CHNG_INT_EN	BIT(1)
#define MII_DP83867_MICR_JABBER_INT_EN		BIT(0)
#define DP83867_RGMII_TX_CLK_DELAY_EN		BIT(1)
#define DP83867_RGMII_RX_CLK_DELAY_EN		BIT(0)
#define DP83867_STRAP_STS1_RESERVED		BIT(11)
#define DP83867_STRAP_STS2_CLK_SKEW_TX_MASK	GENMASK(6, 4)
#define DP83867_STRAP_STS2_CLK_SKEW_TX_SHIFT	4
#define DP83867_STRAP_STS2_CLK_SKEW_RX_MASK	GENMASK(2, 0)
#define DP83867_STRAP_STS2_CLK_SKEW_RX_SHIFT	0
#define DP83867_STRAP_STS2_CLK_SKEW_NONE	BIT(2)
#define DP83867_PHYCR_FIFO_DEPTH_SHIFT		14
#define DP83867_PHYCR_FIFO_DEPTH_MASK		GENMASK(15, 14)
#define DP83867_PHYCR_RESERVED_MASK	BIT(11)
#define DP83867_MDI_CROSSOVER		5
#define DP83867_MDI_CROSSOVER_MDIX	2
#define DP83867_PHYCTRL_SGMIIEN			0x0800
#define DP83867_PHYCTRL_RXFIFO_SHIFT	12
#define DP83867_PHYCTRL_TXFIFO_SHIFT	14
#define DP83867_RGMII_TX_CLK_DELAY_MAX		0xf
#define DP83867_RGMII_TX_CLK_DELAY_SHIFT	4
#define DP83867_RGMII_RX_CLK_DELAY_MAX		0xf
#define MII_DP83867_CFG2_SPEEDOPT_10EN		0x0040
#define MII_DP83867_CFG2_SGMII_AUTONEGEN	0x0080
#define MII_DP83867_CFG2_SPEEDOPT_ENH		0x0100
#define MII_DP83867_CFG2_SPEEDOPT_CNT		0x0800
#define MII_DP83867_CFG2_SPEEDOPT_INTLOW	0x2000
#define MII_DP83867_CFG2_MASK			0x003F
#define DEFAULT_FIFO_DEPTH	DP83867_PHYCR_FIFO_DEPTH_4_B_NIB
#define DP83867_IO_MUX_CFG_IO_IMPEDANCE_CTRL	0x1f
#define DP83867_IO_MUX_CFG_IO_IMPEDANCE_MAX	0x0
#define DP83867_IO_MUX_CFG_IO_IMPEDANCE_MIN	0x1f
#define DP83867_IO_MUX_CFG_CLK_O_DISABLE	BIT(6)
#define DP83867_IO_MUX_CFG_CLK_O_SEL_SHIFT	8
#define DP83867_IO_MUX_CFG_CLK_O_SEL_MASK	\
#define DP83867_CFG4_PORT_MIRROR_EN		BIT(0)
#if defined(CONFIG_DM_ETH)
#else
#endif
