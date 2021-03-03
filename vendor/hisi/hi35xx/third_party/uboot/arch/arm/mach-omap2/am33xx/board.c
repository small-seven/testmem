#include <common.h>
#include <dm.h>
#include <debug_uart.h>
#include <errno.h>
#include <ns16550.h>
#include <spl.h>
#include <asm/arch/cpu.h>
#include <asm/arch/hardware.h>
#include <asm/arch/omap.h>
#include <asm/arch/ddr_defs.h>
#include <asm/arch/clock.h>
#include <asm/arch/gpio.h>
#include <asm/arch/i2c.h>
#include <asm/arch/mem.h>
#include <asm/arch/mmc_host_def.h>
#include <asm/arch/sys_proto.h>
#include <asm/io.h>
#include <asm/emif.h>
#include <asm/gpio.h>
#include <asm/omap_common.h>
#include <i2c.h>
#include <miiphy.h>
#include <cpsw.h>
#include <linux/errno.h>
#include <linux/compiler.h>
#include <linux/usb/ch9.h>
#include <linux/usb/gadget.h>
#include <linux/usb/musb.h>
#include <asm/omap_musb.h>
#include <asm/davinci_rtc.h>
#define AM43XX_EMIF_BASE				0x4C000000
#define AM43XX_SDRAM_CONFIG_OFFSET			0x8
#define AM43XX_SDRAM_TYPE_MASK				0xE0000000
#define AM43XX_SDRAM_TYPE_SHIFT				29
#define AM43XX_SDRAM_TYPE_DDR3				3
#define AM43XX_READ_WRITE_LEVELING_CTRL_OFFSET		0xDC
#define AM43XX_RDWRLVLFULL_START			0x80000000
#ifndef CONFIG_SKIP_LOWLEVEL_INIT
#endif
#if !CONFIG_IS_ENABLED(OF_CONTROL)
# ifdef CONFIG_SYS_NS16550_COM2
#  ifdef CONFIG_SYS_NS16550_COM3
#  endif
# endif
#  ifdef CONFIG_SYS_NS16550_COM2
#   ifdef CONFIG_SYS_NS16550_COM3
#   endif
#  endif
#ifdef CONFIG_DM_I2C
#endif
#ifdef CONFIG_DM_GPIO
#ifdef CONFIG_AM43XX
#endif
#ifdef CONFIG_AM43XX
#endif
#endif
#endif
#ifndef CONFIG_DM_GPIO
#ifdef CONFIG_AM43XX
#endif
#endif
#if defined(CONFIG_MMC_OMAP_HS)
#endif
#define RTC_MAGIC_VAL		0x8cd0
#define RTC_BOARD_TYPE_SHIFT	16
#if (defined(CONFIG_USB_MUSB_GADGET) || defined(CONFIG_USB_MUSB_HOST)) && \
#if CONFIG_IS_ENABLED(DM_USB) && !CONFIG_IS_ENABLED(OF_CONTROL)
#if CONFIG_AM335X_USB0_MODE == MUSB_PERIPHERAL
#elif CONFIG_AM335X_USB0_MODE == MUSB_HOST
#endif
#if CONFIG_AM335X_USB1_MODE == MUSB_PERIPHERAL
#elif CONFIG_AM335X_USB1_MODE == MUSB_HOST
#endif
#else
#define CM_PHY_PWRDN			(1 << 0)
#define CM_PHY_OTG_PWRDN		(1 << 1)
#define OTGVDET_EN			(1 << 19)
#define OTGSESSENDEN			(1 << 20)
#ifdef CONFIG_AM335X_USB0
#endif
#ifdef CONFIG_AM335X_USB1
#endif
#ifdef CONFIG_AM335X_USB0
#endif
#ifdef CONFIG_AM335X_USB1
#endif
#endif
#else	/* CONFIG_USB_MUSB_* && CONFIG_AM335X_USB* && !CONFIG_DM_USB */
#if defined(CONFIG_DM_ETH) && defined(CONFIG_USB_ETHER)
#endif
#endif /* CONFIG_USB_MUSB_* && CONFIG_AM335X_USB* && !CONFIG_DM_USB */
#ifndef CONFIG_SKIP_LOWLEVEL_INIT
#if defined(CONFIG_SPL_AM33XX_ENABLE_RTC32K_OSC) || \
#endif
#if defined(CONFIG_SPL_BUILD) && defined(CONFIG_SPL_RTC_DDR_SUPPORT)
#endif
#if defined(CONFIG_SPL_BUILD) && defined(CONFIG_SPL_RTC_DDR_SUPPORT)
#endif
#if defined(CONFIG_SPL_AM33XX_ENABLE_RTC32K_OSC)
#endif
#if defined(CONFIG_SPL_BUILD) && defined(CONFIG_SPL_RTC_DDR_SUPPORT)
#endif
#if defined(CONFIG_SPL_BUILD) && defined(CONFIG_SPL_RTC_DDR_SUPPORT)
#endif
#ifdef CONFIG_NOR_BOOT
#endif
#ifdef CONFIG_SPL_BUILD
#endif
#ifdef CONFIG_DEBUG_UART_OMAP
#endif
#ifdef CONFIG_SPL_BUILD
#endif
#ifdef CONFIG_TI_I2C_BOARD_DETECT
#endif
#if defined(CONFIG_SPL_AM33XX_ENABLE_RTC32K_OSC)
#endif
#ifdef CONFIG_SPL_BUILD
#endif
#endif
#ifndef CONFIG_SKIP_LOWLEVEL_INIT
#endif
