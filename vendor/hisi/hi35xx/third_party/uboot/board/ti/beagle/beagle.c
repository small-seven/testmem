#include <common.h>
#include <dm.h>
#include <env.h>
#include <ns16550.h>
#include <serial.h>
#ifdef CONFIG_LED_STATUS
#include <status_led.h>
#endif
#include <twl4030.h>
#include <linux/mtd/rawnand.h>
#include <asm/io.h>
#include <asm/arch/mmc_host_def.h>
#include <asm/arch/mux.h>
#include <asm/arch/mem.h>
#include <asm/arch/sys_proto.h>
#include <asm/gpio.h>
#include <asm/mach-types.h>
#include <asm/omap_musb.h>
#include <linux/errno.h>
#include <linux/usb/ch9.h>
#include <linux/usb/gadget.h>
#include <linux/usb/musb.h>
#include "beagle.h"
#include <command.h>
#ifdef CONFIG_USB_EHCI_HCD
#include <usb.h>
#include <asm/ehci-omap.h>
#endif
#define TWL4030_I2C_BUS			0
#define EXPANSION_EEPROM_I2C_BUS	1
#define EXPANSION_EEPROM_I2C_ADDRESS	0x50
#define TINCANTOOLS_ZIPPY		0x01000100
#define TINCANTOOLS_ZIPPY2		0x02000100
#define TINCANTOOLS_TRAINER		0x04000100
#define TINCANTOOLS_SHOWDOG		0x03000100
#define KBADC_BEAGLEFPGA		0x01000600
#define LW_BEAGLETOUCH			0x01000700
#define BRAINMUX_LCDOG			0x01000800
#define BRAINMUX_LCDOGTOUCH		0x02000800
#define BBTOYS_WIFI			0x01000B00
#define BBTOYS_VGA			0x02000B00
#define BBTOYS_LCD			0x03000B00
#define BCT_BRETTL3			0x01000F00
#define BCT_BRETTL4			0x02000F00
#define LSR_COM6L_ADPT			0x01001300
#define BEAGLE_NO_EEPROM		0xffffffff
#if defined(CONFIG_LED_STATUS) && defined(CONFIG_LED_STATUS_BOOT_ENABLE)
#endif
#if defined(CONFIG_SPL_OS_BOOT)
#endif /* CONFIG_SPL_OS_BOOT */
#ifdef CONFIG_SPL_BUILD
#endif
#ifdef CONFIG_VIDEO_OMAP3
#endif
#ifdef CONFIG_USB_MUSB_OMAP2PLUS
#if defined(CONFIG_USB_MUSB_HOST)
#elif defined(CONFIG_USB_MUSB_GADGET)
#else
#error "Please define either CONFIG_USB_MUSB_HOST or CONFIG_USB_MUSB_GADGET"
#endif
#endif
#ifdef CONFIG_VIDEO_OMAP3
#endif
#ifdef CONFIG_USB_MUSB_OMAP2PLUS
#endif
#if defined(CONFIG_MTDIDS_DEFAULT) && defined(CONFIG_MTDPARTS_DEFAULT)
#endif
#if defined(CONFIG_MMC)
#endif
#if defined(CONFIG_MMC)
#endif
#if defined(CONFIG_USB_EHCI_HCD) && !defined(CONFIG_SPL_BUILD)
#endif /* CONFIG_USB_EHCI_HCD */
#if defined(CONFIG_USB_ETHER) && defined(CONFIG_USB_MUSB_GADGET)
#endif
