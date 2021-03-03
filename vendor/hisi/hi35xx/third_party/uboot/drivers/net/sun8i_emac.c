#include <cpu_func.h>
#include <asm/io.h>
#include <asm/arch/clock.h>
#include <asm/arch/gpio.h>
#include <common.h>
#include <clk.h>
#include <dm.h>
#include <fdt_support.h>
#include <linux/err.h>
#include <malloc.h>
#include <miiphy.h>
#include <net.h>
#include <reset.h>
#include <dt-bindings/pinctrl/sun4i-a10.h>
#ifdef CONFIG_DM_GPIO
#include <asm-generic/gpio.h>
#endif
#define MDIO_CMD_MII_BUSY		BIT(0)
#define MDIO_CMD_MII_WRITE		BIT(1)
#define MDIO_CMD_MII_PHY_REG_ADDR_MASK	0x000001f0
#define MDIO_CMD_MII_PHY_REG_ADDR_SHIFT	4
#define MDIO_CMD_MII_PHY_ADDR_MASK	0x0001f000
#define MDIO_CMD_MII_PHY_ADDR_SHIFT	12
#define CONFIG_TX_DESCR_NUM	32
#define CONFIG_RX_DESCR_NUM	32
#define CONFIG_ETH_BUFSIZE	2048 /* Note must be dma aligned */
#define CONFIG_ETH_RXSIZE	2044 /* Note must fit in ETH_BUFSIZE */
#define TX_TOTAL_BUFSIZE	(CONFIG_ETH_BUFSIZE * CONFIG_TX_DESCR_NUM)
#define RX_TOTAL_BUFSIZE	(CONFIG_ETH_BUFSIZE * CONFIG_RX_DESCR_NUM)
#define H3_EPHY_DEFAULT_VALUE	0x58000
#define H3_EPHY_DEFAULT_MASK	GENMASK(31, 15)
#define H3_EPHY_ADDR_SHIFT	20
#define REG_PHY_ADDR_MASK	GENMASK(4, 0)
#define H3_EPHY_LED_POL		BIT(17)	/* 1: active low, 0: active high */
#define H3_EPHY_SHUTDOWN	BIT(16)	/* 1: shutdown, 0: power up */
#define H3_EPHY_SELECT		BIT(15) /* 1: internal PHY, 0: external PHY */
#define SC_RMII_EN		BIT(13)
#define SC_EPIT			BIT(2) /* 1: RGMII, 0: MII */
#define SC_ETCS_MASK		GENMASK(1, 0)
#define SC_ETCS_EXT_GMII	0x1
#define SC_ETCS_INT_GMII	0x2
#define SC_ETXDC_MASK		GENMASK(12, 10)
#define SC_ETXDC_OFFSET		10
#define SC_ERXDC_MASK		GENMASK(9, 5)
#define SC_ERXDC_OFFSET		5
#define CONFIG_MDIO_TIMEOUT	(3 * CONFIG_SYS_HZ)
#define AHB_GATE_OFFSET_EPHY	0
#define SUN8I_IOMUX_H3		2
#define SUN8I_IOMUX_R40	5
#define SUN8I_IOMUX		4
#define EMAC_CTL0		0x00
#define EMAC_CTL1		0x04
#define EMAC_INT_STA		0x08
#define EMAC_INT_EN		0x0c
#define EMAC_TX_CTL0		0x10
#define EMAC_TX_CTL1		0x14
#define EMAC_TX_FLOW_CTL	0x1c
#define EMAC_TX_DMA_DESC	0x20
#define EMAC_RX_CTL0		0x24
#define EMAC_RX_CTL1		0x28
#define EMAC_RX_DMA_DESC	0x34
#define EMAC_MII_CMD		0x48
#define EMAC_MII_DATA		0x4c
#define EMAC_ADDR0_HIGH		0x50
#define EMAC_ADDR0_LOW		0x54
#define EMAC_TX_DMA_STA		0xb0
#define EMAC_TX_CUR_DESC	0xb4
#define EMAC_TX_CUR_BUF		0xb8
#define EMAC_RX_DMA_STA		0xc0
#define EMAC_RX_CUR_DESC	0xc4
#ifdef CONFIG_DM_GPIO
#endif
#if defined(CONFIG_DM_GPIO)
#endif
#if defined(CONFIG_DM_GPIO)
#endif
#ifdef CONFIG_DM_GPIO
#endif
#ifdef CONFIG_DM_GPIO
#endif
