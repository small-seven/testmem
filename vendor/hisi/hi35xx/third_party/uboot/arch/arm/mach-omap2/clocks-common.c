#include <common.h>
#include <i2c.h>
#include <asm/omap_common.h>
#include <asm/gpio.h>
#include <asm/arch/clock.h>
#include <asm/arch/sys_proto.h>
#include <asm/utils.h>
#include <asm/omap_gpio.h>
#include <asm/emif.h>
#ifndef CONFIG_SPL_BUILD
#define printf(fmt, args...)
#define puts(s)
#endif
#ifdef CONFIG_SYS_OMAP_ABE_SYSCK
#else
#endif
#ifdef CONFIG_DRIVER_TI_CPSW
#endif
#if defined(CONFIG_USB_EHCI_OMAP) || defined(CONFIG_USB_XHCI_OMAP) || \
#endif
#if defined(CONFIG_USB_EHCI_OMAP) || defined(CONFIG_USB_XHCI_OMAP) || \
#endif
#ifdef CONFIG_DRIVER_TI_CPSW
#endif
#ifdef CONFIG_IODELAY_RECALIBRATION
#endif
#ifdef CONFIG_IODELAY_RECALIBRATION
#endif
#if !defined(CONFIG_DM_I2C)
#endif
