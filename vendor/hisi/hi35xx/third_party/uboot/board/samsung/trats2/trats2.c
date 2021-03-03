#include <common.h>
#include <lcd.h>
#include <asm/gpio.h>
#include <asm/arch/pinmux.h>
#include <asm/arch/power.h>
#include <asm/arch/mipi_dsim.h>
#include <power/pmic.h>
#include <power/max77686_pmic.h>
#include <power/battery.h>
#include <power/max77693_pmic.h>
#include <power/max77693_muic.h>
#include <power/max77693_fg.h>
#include <libtizen.h>
#include <errno.h>
#include <usb.h>
#include <usb/dwc2_udc.h>
#include <usb_mass_storage.h>
#ifndef CONFIG_DM_I2C /* TODO(maintainer): Convert to driver model */
#endif
#ifdef CONFIG_USB_GADGET
#ifndef CONFIG_DM_I2C /* TODO(maintainer): Convert to driver model */
#endif
#ifndef CONFIG_DM_I2C /* TODO(maintainer): Convert to driver model */
#else
#endif
#endif
#ifdef CONFIG_LCD
#ifndef CONFIG_DM_I2C /* TODO(maintainer): Convert to driver model */
#endif
#ifndef CONFIG_DM_I2C /* TODO(maintainer): Convert to driver model */
#endif
#ifdef CONFIG_TIZEN
#endif
#ifdef CONFIG_S6E8AX0
#endif
#endif /* LCD */
