#include <common.h>
#include <env.h>
#include <lcd.h>
#include <asm/io.h>
#include <asm/gpio.h>
#include <asm/arch/cpu.h>
#include <asm/arch/pinmux.h>
#include <asm/arch/clock.h>
#include <asm/arch/mipi_dsim.h>
#include <asm/arch/watchdog.h>
#include <asm/arch/power.h>
#include <power/pmic.h>
#include <usb/dwc2_udc.h>
#include <power/max8997_pmic.h>
#include <power/max8997_muic.h>
#include <power/battery.h>
#include <power/max17042_fg.h>
#include <power/pmic.h>
#include <libtizen.h>
#include <usb.h>
#include <usb_mass_storage.h>
#include "setup.h"
#ifdef CONFIG_REVISION_TAG
#endif
#ifndef CONFIG_DM_I2C /* TODO(maintainer): Convert to driver model */
#endif
#ifndef CONFIG_DM_I2C /* TODO(maintainer): Convert to driver model */
#endif
#ifdef CONFIG_USB_GADGET
#ifndef CONFIG_DM_I2C /* TODO(maintainer): Convert to driver model */
#else
#endif
#endif
#ifndef CONFIG_DM_I2C /* TODO(maintainer): Convert to driver model */
#endif
#ifndef CONFIG_DM_I2C /* TODO(maintainer): Convert to driver model */
#endif
#ifdef CONFIG_LCD
#ifdef CONFIG_TIZEN
#endif
#ifdef CONFIG_S6E8AX0
#endif
#endif
