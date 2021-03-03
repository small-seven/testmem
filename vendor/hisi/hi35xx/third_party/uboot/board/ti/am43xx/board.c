#include <common.h>
#include <eeprom.h>
#include <env.h>
#include <i2c.h>
#include <init.h>
#include <linux/errno.h>
#include <spl.h>
#include <usb.h>
#include <asm/omap_sec_common.h>
#include <asm/arch/clock.h>
#include <asm/arch/sys_proto.h>
#include <asm/arch/mux.h>
#include <asm/arch/ddr_defs.h>
#include <asm/arch/gpio.h>
#include <asm/emif.h>
#include <asm/omap_common.h>
#include "../common/board_detect.h"
#include "board.h"
#include <power/pmic.h>
#include <power/tps65218.h>
#include <power/tps62362.h>
#include <miiphy.h>
#include <cpsw.h>
#include <linux/usb/gadget.h>
#include <dwc3-uboot.h>
#include <dwc3-omap-uboot.h>
#include <ti-usb-phy-uboot.h>
#ifdef CONFIG_TI_I2C_BOARD_DETECT
#endif
#ifndef CONFIG_SKIP_LOWLEVEL_INIT
#ifndef CONFIG_DM_I2C
#else
#endif
#ifndef CONFIG_DM_I2C
#else
#endif
#ifndef CONFIG_DM_I2C
#endif
#endif
#ifndef CONFIG_DM_I2C
#endif
#ifndef CONFIG_DM_I2C
#endif
#ifndef CONFIG_DM_I2C
#endif
#ifdef CONFIG_BOARD_LATE_INIT
#if CONFIG_IS_ENABLED(DM_USB) && CONFIG_IS_ENABLED(OF_CONTROL)
#endif
#ifdef CONFIG_ENV_VARS_UBOOT_RUNTIME_CONFIG
#endif
#if CONFIG_IS_ENABLED(DM_USB) && CONFIG_IS_ENABLED(OF_CONTROL)
#endif
#endif
#if !CONFIG_IS_ENABLED(DM_USB_GADGET)
#ifdef CONFIG_USB_DWC3
#endif /* CONFIG_USB_DWC3 */
#if defined(CONFIG_USB_DWC3) || defined(CONFIG_USB_XHCI_OMAP)
#ifdef CONFIG_USB_DWC3
#endif
#ifdef CONFIG_USB_DWC3
#endif
#endif /* defined(CONFIG_USB_DWC3) || defined(CONFIG_USB_XHCI_OMAP) */
#endif /* !CONFIG_IS_ENABLED(DM_USB_GADGET) */
#ifdef CONFIG_DRIVER_TI_CPSW
#endif
#if defined(CONFIG_OF_LIBFDT) && defined(CONFIG_OF_BOARD_SETUP)
#endif
#if defined(CONFIG_SPL_LOAD_FIT) || defined(CONFIG_DTB_RESELECT)
#endif
#ifdef CONFIG_DTB_RESELECT
#endif
#ifdef CONFIG_TI_SECURE_DEVICE
#endif
