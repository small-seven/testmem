#include <common.h>
#include <palmas.h>
#include <asm/arch/omap.h>
#include <asm/arch/sys_proto.h>
#include <asm/arch/mmc_host_def.h>
#include <tca642x.h>
#include <usb.h>
#include <linux/usb/gadget.h>
#include <dwc3-uboot.h>
#include <dwc3-omap-uboot.h>
#include <ti-usb-phy-uboot.h>
#include "mux_data.h"
#if defined(CONFIG_USB_EHCI_HCD) || defined(CONFIG_USB_XHCI_OMAP)
#include <sata.h>
#include <usb.h>
#include <asm/gpio.h>
#include <asm/mach-types.h>
#include <asm/arch/clock.h>
#include <asm/arch/ehci.h>
#include <asm/ehci-omap.h>
#include <asm/arch/sata.h>
#define DIE_ID_REG_BASE     (OMAP54XX_L4_CORE_BASE + 0x2000)
#define DIE_ID_REG_OFFSET	0x200
#endif
#ifdef CONFIG_USB_DWC3
#endif
#if defined(CONFIG_USB_EHCI_HCD) || defined(CONFIG_USB_XHCI_OMAP)
#ifdef CONFIG_USB_XHCI_OMAP
#endif
#endif
#ifdef CONFIG_PALMAS_POWER
#endif
#if defined(CONFIG_MMC)
#endif
#ifdef CONFIG_USB_EHCI_HCD
#endif
#ifdef CONFIG_USB_XHCI_OMAP
#ifdef CONFIG_PALMAS_USB_SS_PWR
#endif
#endif
