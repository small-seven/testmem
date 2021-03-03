#include <common.h>
#include <clk.h>
#include <cpu_func.h>
#include <dm.h>
#include <init.h>
#include <ram.h>
#include <syscon.h>
#include <asm/io.h>
#include <asm/arch-rockchip/boot_mode.h>
#include <asm/arch-rockchip/clock.h>
#include <asm/arch-rockchip/periph.h>
#include <asm/arch-rockchip/misc.h>
#include <power/regulator.h>
#ifdef CONFIG_DM_REGULATOR
#endif
#if !defined(CONFIG_SYS_DCACHE_OFF) && !defined(CONFIG_ARM64)
#endif
#if defined(CONFIG_USB_GADGET)
#include <usb.h>
#if defined(CONFIG_USB_GADGET_DWC2_OTG)
#include <usb/dwc2_udc.h>
#ifdef CONFIG_ROCKCHIP_RK3288
#endif
#endif /* CONFIG_USB_GADGET_DWC2_OTG */
#if defined(CONFIG_USB_DWC3_GADGET) && !defined(CONFIG_DM_USB_GADGET)
#include <dwc3-uboot.h>
#endif /* CONFIG_USB_DWC3_GADGET */
#endif /* CONFIG_USB_GADGET */
#if CONFIG_IS_ENABLED(FASTBOOT)
#endif
#ifdef CONFIG_MISC_INIT_R
#endif
