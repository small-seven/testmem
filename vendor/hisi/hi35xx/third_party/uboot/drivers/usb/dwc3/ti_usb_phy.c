#include <common.h>
#include <malloc.h>
#include <ti-usb-phy-uboot.h>
#include <linux/ioport.h>
#include <asm/io.h>
#include <asm/arch/sys_proto.h>
#include <dm.h>
#include "linux-compat.h"
#define PLL_STATUS		0x00000004
#define PLL_GO			0x00000008
#define PLL_CONFIGURATION1	0x0000000C
#define PLL_CONFIGURATION2	0x00000010
#define PLL_CONFIGURATION3	0x00000014
#define PLL_CONFIGURATION4	0x00000020
#define PLL_REGM_MASK		0x001FFE00
#define PLL_REGM_SHIFT		0x9
#define PLL_REGM_F_MASK		0x0003FFFF
#define PLL_REGM_F_SHIFT	0x0
#define PLL_REGN_MASK		0x000001FE
#define PLL_REGN_SHIFT		0x1
#define PLL_SELFREQDCO_MASK	0x0000000E
#define PLL_SELFREQDCO_SHIFT	0x1
#define PLL_SD_MASK		0x0003FC00
#define PLL_SD_SHIFT		10
#define SET_PLL_GO		0x1
#define PLL_LDOPWDN		BIT(15)
#define PLL_TICOPWDN		BIT(16)
#define PLL_LOCK		0x2
#define PLL_IDLE		0x1
#define OMAP_CTRL_DEV_PHY_PD				BIT(0)
#define OMAP_CTRL_USB3_PHY_PWRCTL_CLK_CMD_MASK		0x003FC000
#define OMAP_CTRL_USB3_PHY_PWRCTL_CLK_CMD_SHIFT		0xE
#define OMAP_CTRL_USB3_PHY_PWRCTL_CLK_FREQ_MASK		0xFFC00000
#define OMAP_CTRL_USB3_PHY_PWRCTL_CLK_FREQ_SHIFT	0x16
#define OMAP_CTRL_USB3_PHY_TX_RX_POWERON	0x3
#define OMAP_CTRL_USB3_PHY_TX_RX_POWEROFF	0x0
#define OMAP_CTRL_USB2_PHY_PD			BIT(28)
#define AM437X_CTRL_USB2_PHY_PD			BIT(0)
#define AM437X_CTRL_USB2_OTG_PD			BIT(1)
#define AM437X_CTRL_USB2_OTGVDET_EN		BIT(19)
#define AM437X_CTRL_USB2_OTGSESSEND_EN		BIT(20)
typedef unsigned int u32;

struct usb3_dpll_params {
	u16	m;
	u8	n;
	u8	freq:3;
	u8	sd;
	u32	mf;
};
#ifndef CONFIG_AM43XX
#endif
#if defined(CONFIG_DRA7XX)
#elif defined(CONFIG_AM43XX)
#endif
#if defined(CONFIG_DRA7XX)
#elif defined(CONFIG_AM43XX)
#endif
#ifndef CONFIG_AM43XX
#endif
#ifndef CONFIG_AM43XX
#endif
#ifndef CONFIG_AM43XX
#endif
