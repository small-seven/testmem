#include <common.h>
#include <env.h>
#include <spi.h>
#include <lcd.h>
#include <asm/io.h>
#include <asm/gpio.h>
#include <asm/arch/adc.h>
#include <asm/arch/pinmux.h>
#include <asm/arch/watchdog.h>
#include <ld9040.h>
#include <power/pmic.h>
#include <usb.h>
#include <usb/dwc2_udc.h>
#include <asm/arch/cpu.h>
#include <power/max8998_pmic.h>
#include <libtizen.h>
#include <samsung/misc.h>
#include <usb_mass_storage.h>
#include <asm/mach-types.h>
#define IS_RANGE(x, min, max)	((x) > (min) && (x) < (max))
#undef IS_RANGE
#ifdef CONFIG_USB_GADGET
#endif
#ifdef CONFIG_LCD
#ifdef CONFIG_TIZEN
#endif
#endif
