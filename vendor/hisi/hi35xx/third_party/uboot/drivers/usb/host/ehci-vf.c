#include <common.h>
#include <dm.h>
#include <usb.h>
#include <errno.h>
#include <linux/compiler.h>
#include <asm/io.h>
#include <asm-generic/gpio.h>
#include <asm/arch/clock.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/crm_regs.h>
#include <asm/mach-imx/iomux-v3.h>
#include <asm/mach-imx/regs-usbphy.h>
#include <usb/ehci-ci.h>
#include <linux/libfdt.h>
#include <fdtdec.h>
#include "ehci.h"
#define USB_NC_REG_OFFSET				0x00000800
#define ANADIG_PLL_CTRL_EN_USB_CLKS		(1 << 6)
#define UCTRL_OVER_CUR_POL	(1 << 8) /* OTG Polarity of Overcurrent */
#define UCTRL_OVER_CUR_DIS	(1 << 7) /* Disable OTG Overcurrent Detection */
#define UCMD_RUN_STOP		(1 << 0) /* controller run/stop */
#define UCMD_RESET			(1 << 1) /* controller reset */
#if !CONFIG_IS_ENABLED(DM_USB)
#else
#endif
