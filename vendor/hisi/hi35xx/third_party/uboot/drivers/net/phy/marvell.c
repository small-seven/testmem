#include <common.h>
#include <errno.h>
#include <phy.h>
#define PHY_AUTONEGOTIATE_TIMEOUT 5000
#define MII_MARVELL_PHY_PAGE		22
#define MIIM_88E1xxx_PHY_STATUS		0x11
#define MIIM_88E1xxx_PHYSTAT_SPEED	0xc000
#define MIIM_88E1xxx_PHYSTAT_GBIT	0x8000
#define MIIM_88E1xxx_PHYSTAT_100	0x4000
#define MIIM_88E1xxx_PHYSTAT_DUPLEX	0x2000
#define MIIM_88E1xxx_PHYSTAT_SPDDONE	0x0800
#define MIIM_88E1xxx_PHYSTAT_LINK	0x0400
#define MIIM_88E1xxx_PHY_SCR		0x10
#define MIIM_88E1xxx_PHY_MDI_X_AUTO	0x0060
#define MIIM_88E1111_PHY_LED_CONTROL	24
#define MIIM_88E1111_PHY_LED_DIRECT	0x4100
#define MIIM_88E1111_PHY_LED_COMBINE	0x411C
#define MIIM_88E1111_PHY_EXT_CR		0x14
#define MIIM_88E1111_RX_DELAY		0x80
#define MIIM_88E1111_TX_DELAY		0x2
#define MIIM_88E1111_PHY_EXT_SR		0x1b
#define MIIM_88E1111_HWCFG_MODE_MASK		0xf
#define MIIM_88E1111_HWCFG_MODE_COPPER_RGMII	0xb
#define MIIM_88E1111_HWCFG_MODE_FIBER_RGMII	0x3
#define MIIM_88E1111_HWCFG_MODE_SGMII_NO_CLK	0x4
#define MIIM_88E1111_HWCFG_MODE_COPPER_RTBI	0x9
#define MIIM_88E1111_HWCFG_FIBER_COPPER_AUTO	0x8000
#define MIIM_88E1111_HWCFG_FIBER_COPPER_RES	0x2000
#define MIIM_88E1111_COPPER		0
#define MIIM_88E1111_FIBER		1
#define MIIM_88E1118_PHY_PAGE		22
#define MIIM_88E1118_PHY_LED_PAGE	3
#define MIIM_88E1121_PHY_LED_CTRL	16
#define MIIM_88E1121_PHY_LED_PAGE	3
#define MIIM_88E1121_PHY_LED_DEF	0x0030
#define MIIM_88E1121_PHY_IRQ_EN		18
#define MIIM_88E1121_PHY_IRQ_STATUS	19
#define MIIM_88E1121_PHY_PAGE		22
#define MIIM_88E1145_PHY_EXT_CR 20
#define MIIM_M88E1145_RGMII_RX_DELAY	0x0080
#define MIIM_M88E1145_RGMII_TX_DELAY	0x0002
#define MIIM_88E1145_PHY_LED_CONTROL	24
#define MIIM_88E1145_PHY_LED_DIRECT	0x4100
#define MIIM_88E1145_PHY_PAGE	29
#define MIIM_88E1145_PHY_CAL_OV 30
#define MIIM_88E1149_PHY_PAGE	29
#define MIIM_88E1310_PHY_LED_CTRL	16
#define MIIM_88E1310_PHY_IRQ_EN		18
#define MIIM_88E1310_PHY_RGMII_CTRL	21
#define MIIM_88E1310_PHY_PAGE		22
#define MIIM_88E151x_PHY_MSCR		21
#define MIIM_88E151x_RGMII_RX_DELAY	BIT(5)
#define MIIM_88E151x_RGMII_TX_DELAY	BIT(4)
#define MIIM_88E151x_RGMII_RXTX_DELAY	(BIT(5) | BIT(4))
#define MIIM_88E151x_LED_FUNC_CTRL	16
#define MIIM_88E151x_LED_FLD_SZ		4
#define MIIM_88E151x_LED0_OFFS		(0 * MIIM_88E151x_LED_FLD_SZ)
#define MIIM_88E151x_LED1_OFFS		(1 * MIIM_88E151x_LED_FLD_SZ)
#define MIIM_88E151x_LED0_ACT		3
#define MIIM_88E151x_LED1_100_1000_LINK	6
#define MIIM_88E151x_LED_TIMER_CTRL	18
#define MIIM_88E151x_INT_EN_OFFS	7
#define MIIM_88E151x_GENERAL_CTRL	20
#define MIIM_88E151x_MODE_SGMII		1
#define MIIM_88E151x_RESET_OFFS		15
