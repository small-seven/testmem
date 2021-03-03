#include <common.h>
#include <miiphy.h>
#define MIIM_CIS82xx_AUX_CONSTAT	0x1c
#define MIIM_CIS82xx_AUXCONSTAT_INIT	0x0004
#define MIIM_CIS82xx_AUXCONSTAT_DUPLEX	0x0020
#define MIIM_CIS82xx_AUXCONSTAT_SPEED	0x0018
#define MIIM_CIS82xx_AUXCONSTAT_GBIT	0x0010
#define MIIM_CIS82xx_AUXCONSTAT_100	0x0008
#define MIIM_CIS82xx_EXT_CON1		0x17
#define MIIM_CIS8201_EXTCON1_INIT	0x0000
#define MIIM_CIS8204_EPHY_CON		0x17
#define MIIM_CIS8204_EPHYCON_INIT	0x0006
#define MIIM_CIS8204_EPHYCON_RGMII	0x1100
#define MIIM_CIS8204_SLED_CON		0x1b
#define MIIM_CIS8204_SLEDCON_INIT	0x1115
#define MII_VSC8601_EPHY_CTL		0x17
#define MII_VSC8601_EPHY_CTL_RGMII_SKEW	(1 << 8)
#define PHY_EXT_PAGE_ACCESS    0x1f
#define PHY_EXT_PAGE_ACCESS_GENERAL	0x10
#define PHY_EXT_PAGE_ACCESS_EXTENDED3	0x3
#define MIIM_VSC8574_MAC_SERDES_CON	0x10
#define MIIM_VSC8574_MAC_SERDES_ANEG	0x80
#define MIIM_VSC8574_GENERAL18		0x12
#define MIIM_VSC8574_GENERAL19		0x13
#define MIIM_VSC8574_18G_SGMII		0x80f0
#define MIIM_VSC8574_18G_QSGMII		0x80e0
#define MIIM_VSC8574_18G_CMDSTAT	0x8000
#define MIIM_VSC8514_MAC_SERDES_CON     0x10
#define MIIM_VSC8514_GENERAL18		0x12
#define MIIM_VSC8514_GENERAL19		0x13
#define MIIM_VSC8514_GENERAL23		0x17
#define MIIM_VSC8514_18G_QSGMII		0x80e0
#define MIIM_VSC8514_18G_CMDSTAT	0x8000
#define MIIM_VSC8664_SERDES_AND_SIGDET	0x13
#define MIIM_VSC8664_ADDITIONAL_DEV	0x16
#define MIIM_VSC8664_EPHY_CON		0x17
#define MIIM_VSC8664_LED_CON		0x1E
#define PHY_EXT_PAGE_ACCESS_EXTENDED	0x0001
