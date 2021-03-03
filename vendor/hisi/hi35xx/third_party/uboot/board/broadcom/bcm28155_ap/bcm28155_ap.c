#include <common.h>
#include <asm/io.h>
#include <asm/mach-types.h>
#include <env.h>
#include <mmc.h>
#include <asm/kona-common/kona_sdhci.h>
#include <asm/kona-common/clk.h>
#include <asm/arch/sysmap.h>
#include <usb.h>
#include <usb/dwc2_udc.h>
#include <g_dnl.h>
#define SECWATCHDOG_SDOGCR_OFFSET	0x00000000
#define SECWATCHDOG_SDOGCR_EN_SHIFT	27
#define SECWATCHDOG_SDOGCR_SRSTEN_SHIFT	26
#define SECWATCHDOG_SDOGCR_CLKS_SHIFT	20
#define SECWATCHDOG_SDOGCR_LD_SHIFT	0
#ifndef CONFIG_USB_SERIALNO
#define CONFIG_USB_SERIALNO "1234567890"
#endif
#ifdef CONFIG_MMC_SDHCI_KONA
#endif
#ifdef CONFIG_USB_GADGET
#endif
