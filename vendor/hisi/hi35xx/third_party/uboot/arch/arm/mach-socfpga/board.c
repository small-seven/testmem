#include <common.h>
#include <errno.h>
#include <fdtdec.h>
#include <asm/arch/reset_manager.h>
#include <asm/arch/clock_manager.h>
#include <asm/arch/misc.h>
#include <asm/io.h>
#include <usb.h>
#include <usb/dwc2_udc.h>
#ifndef CONFIG_ARM64
#endif
#ifdef CONFIG_USB_GADGET
#endif
