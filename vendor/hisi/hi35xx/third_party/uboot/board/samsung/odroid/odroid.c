#include <common.h>
#include <asm/arch/pinmux.h>
#include <asm/arch/power.h>
#include <asm/arch/clock.h>
#include <asm/arch/gpio.h>
#include <asm/gpio.h>
#include <asm/arch/cpu.h>
#include <dm.h>
#include <env.h>
#include <power/pmic.h>
#include <power/regulator.h>
#include <power/max77686_pmic.h>
#include <errno.h>
#include <mmc.h>
#include <usb.h>
#include <usb/dwc2_udc.h>
#include <samsung/misc.h>
#include "setup.h"
#ifdef CONFIG_BOARD_TYPES
#endif
#ifdef CONFIG_SET_DFU_ALT_INFO
#endif
#ifdef CONFIG_CMD_USB
#endif
#ifdef CONFIG_USB_GADGET
#endif
#if defined(CONFIG_USB_GADGET) || defined(CONFIG_CMD_USB)
#ifdef CONFIG_BOARD_TYPES
#else
#endif /* CONFIG_BOARD_TYPES */
#ifdef CONFIG_CMD_USB
#endif
#endif
