#include <common.h>
#include <netdev.h>
#include <twl4030.h>
#include <asm/io.h>
#include <asm/arch/mmc_host_def.h>
#include <asm/arch/mem.h>
#include <asm/arch/mux.h>
#include <asm/arch/sys_proto.h>
#include <asm/arch/gpio.h>
#include <asm/gpio.h>
#include <asm/mach-types.h>
#include <usb.h>
#include <asm/ehci-omap.h>
#include "tao3530.h"
#ifdef CONFIG_SPL_BUILD
#if defined(CONFIG_SYS_BOARD_OMAP3_HA)
#endif
#endif
#if defined(CONFIG_SYS_BOARD_OMAP3_HA)
#endif
#if defined(CONFIG_MMC)
#endif
#if defined(CONFIG_MMC)
#endif
#if defined(CONFIG_USB_EHCI_HCD) && !defined(CONFIG_SPL_BUILD)
#endif /* CONFIG_USB_EHCI_HCD */
