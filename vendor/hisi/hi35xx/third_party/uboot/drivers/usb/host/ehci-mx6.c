#include <common.h>
#include <usb.h>
#include <errno.h>
#include <wait_bit.h>
#include <linux/compiler.h>
#include <usb/ehci-ci.h>
#include <asm/io.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/clock.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm/mach-imx/sys_proto.h>
#include <dm.h>
#include <asm/mach-types.h>
#include <power/regulator.h>
#include <linux/usb/otg.h>
#include "ehci.h"
#define USB_OTGREGS_OFFSET	0x000
#define USB_H1REGS_OFFSET	0x200
#define USB_H2REGS_OFFSET	0x400
#define USB_H3REGS_OFFSET	0x600
#define USB_OTHERREGS_OFFSET	0x800
#define USB_H1_CTRL_OFFSET	0x04
#define USBPHY_CTRL				0x00000030
#define USBPHY_CTRL_SET				0x00000034
#define USBPHY_CTRL_CLR				0x00000038
#define USBPHY_CTRL_TOG				0x0000003c
#define USBPHY_PWD				0x00000000
#define USBPHY_CTRL_SFTRST			0x80000000
#define USBPHY_CTRL_CLKGATE			0x40000000
#define USBPHY_CTRL_ENUTMILEVEL3		0x00008000
#define USBPHY_CTRL_ENUTMILEVEL2		0x00004000
#define USBPHY_CTRL_OTG_ID			0x08000000
#define ANADIG_USB2_CHRG_DETECT_EN_B		0x00100000
#define ANADIG_USB2_CHRG_DETECT_CHK_CHRG_B	0x00080000
#define ANADIG_USB2_PLL_480_CTRL_BYPASS		0x00010000
#define ANADIG_USB2_PLL_480_CTRL_ENABLE		0x00002000
#define ANADIG_USB2_PLL_480_CTRL_POWER		0x00001000
#define ANADIG_USB2_PLL_480_CTRL_EN_USB_CLKS	0x00000040
#define USBNC_OFFSET		0x200
#define USBNC_PHY_STATUS_OFFSET	0x23C
#define USBNC_PHYSTATUS_ID_DIG	(1 << 4) /* otg_id status */
#define USBNC_PHYCFG2_ACAENB	(1 << 4) /* otg_id detection enable */
#define UCTRL_PWR_POL		(1 << 9) /* OTG Polarity of Power Pin */
#define UCTRL_OVER_CUR_POL	(1 << 8) /* OTG Polarity of Overcurrent */
#define UCTRL_OVER_CUR_DIS	(1 << 7) /* Disable OTG Overcurrent Detection */
#define UCMD_RUN_STOP           (1 << 0) /* controller run/stop */
#define UCMD_RESET		(1 << 1) /* controller reset */
#if defined(CONFIG_MX6) || defined(CONFIG_MX7ULP)
#if defined(USB_PHY1_BASE_ADDR)
#endif
#if defined(CONFIG_MX7ULP)
#else
#endif
#if defined(CONFIG_MX7ULP)
#else
#endif
#elif defined(CONFIG_MX7)
#endif
#if defined(CONFIG_MX6)
#elif defined(CONFIG_MX7) || defined(CONFIG_MX7ULP)
#endif
#if CONFIG_MACH_TYPE == MACH_TYPE_MX6Q_ARM2
#else
#endif
#ifdef CONFIG_MXC_USB_OTG_HACTIVE
#else
#endif
#if defined(CONFIG_MX6) || defined(CONFIG_MX7ULP)
#endif
#if !CONFIG_IS_ENABLED(DM_USB)
#if defined(CONFIG_MX6)
#elif defined(CONFIG_MX7) || defined(CONFIG_MX7ULP)
#endif
#else
#if CONFIG_IS_ENABLED(DM_REGULATOR)
#endif
#if CONFIG_IS_ENABLED(DM_REGULATOR)
#endif
#if CONFIG_IS_ENABLED(DM_REGULATOR)
#endif
#endif
