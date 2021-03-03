#include <common.h>
#include <usb.h>
#include <errno.h>
#include <linux/compiler.h>
#include <usb/ehci-ci.h>
#include <asm/io.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/clock.h>
#include <dm.h>
#include <power/regulator.h>
#include "ehci.h"
#define MX5_USBOTHER_REGS_OFFSET 0x800
#define MXC_OTG_OFFSET			0
#define MXC_H1_OFFSET			0x200
#define MXC_H2_OFFSET			0x400
#define MXC_H3_OFFSET			0x600
#define MXC_USBCTRL_OFFSET		0
#define MXC_USB_PHY_CTR_FUNC_OFFSET	0x8
#define MXC_USB_PHY_CTR_FUNC2_OFFSET	0xc
#define MXC_USB_CTRL_1_OFFSET		0x10
#define MXC_USBH2CTRL_OFFSET		0x14
#define MXC_USBH3CTRL_OFFSET		0x18
#define MXC_OTG_UCTRL_OWIE_BIT		(1 << 27)
#define MXC_OTG_UCTRL_OPM_BIT		(1 << 24)
#define MXC_OTG_UCTRL_O_PWR_POL_BIT	(1 << 24)
#define MXC_H1_UCTRL_H1UIE_BIT		(1 << 12)
#define MXC_H1_UCTRL_H1WIE_BIT		(1 << 11)
#define MXC_H1_UCTRL_H1PM_BIT		(1 << 8)
#define MXC_H1_UCTRL_H1_PWR_POL_BIT	(1 << 8)
#define MXC_OTG_PHYCTRL_OC_POL_BIT	(1 << 9)
#define MXC_OTG_PHYCTRL_OC_DIS_BIT	(1 << 8)
#define MXC_H1_OC_POL_BIT		(1 << 6)
#define MXC_H1_OC_DIS_BIT		(1 << 5)
#define MXC_OTG_PHYCTRL_PWR_POL_BIT	(1 << 3)
#define MXC_H2_UCTRL_H2_OC_POL_BIT	(1 << 31)
#define MXC_H2_UCTRL_H2_OC_DIS_BIT	(1 << 30)
#define MXC_H2_UCTRL_H2UIE_BIT		(1 << 8)
#define MXC_H2_UCTRL_H2WIE_BIT		(1 << 7)
#define MXC_H2_UCTRL_H2PM_BIT		(1 << 4)
#define MXC_H2_UCTRL_H2_PWR_POL_BIT	(1 << 4)
#define MXC_H3_UCTRL_H3_OC_POL_BIT	(1 << 31)
#define MXC_H3_UCTRL_H3_OC_DIS_BIT	(1 << 30)
#define MXC_H3_UCTRL_H3UIE_BIT		(1 << 8)
#define MXC_H3_UCTRL_H3WIE_BIT		(1 << 7)
#define MXC_H3_UCTRL_H3_PWR_POL_BIT	(1 << 4)
#define MXC_USB_CTRL_UH1_EXT_CLK_EN	(1 << 25)
#ifdef CONFIG_MX51
#endif
#ifdef CONFIG_MX51
#endif
#ifdef CONFIG_MX53
#endif
#ifdef CONFIG_MX51
#endif
#ifdef CONFIG_MX51
#endif
#ifdef CONFIG_MX53
#endif
#ifdef CONFIG_MX51
#endif
#ifdef CONFIG_MX53
#endif
#ifdef CONFIG_MX53
#endif
#if !CONFIG_IS_ENABLED(DM_USB)
#else /* CONFIG_IS_ENABLED(DM_USB) */
#endif /* !CONFIG_IS_ENABLED(DM_USB) */
