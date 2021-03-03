#define CONFIG_USB_PXA25X_SMALL
#define DRIVER_NAME "pxa25x_udc_linux"
#define ARCH_HAS_PREFETCH
#include <common.h>
#include <errno.h>
#include <asm/byteorder.h>
#include <asm/system.h>
#include <asm/mach-types.h>
#include <asm/unaligned.h>
#include <linux/compat.h>
#include <malloc.h>
#include <asm/io.h>
#include <asm/arch/pxa.h>
#include <linux/usb/ch9.h>
#include <linux/usb/gadget.h>
#include <asm/arch/pxa-regs.h>
#include "pxa25x_udc.h"
#define DRIVER_VERSION	"18-August-2012"
#define DRIVER_DESC	"PXA 25x USB Device Controller driver"
#ifdef DEBUG
#else /* DEBUG */
#endif /* DEBUG */
#ifndef	CONFIG_USB_PXA25X_SMALL
#endif
#ifndef CONFIG_USB_PXA25X_SMALL
#endif /* !CONFIG_USB_PXA25X_SMALL */
