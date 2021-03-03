#include <common.h>
#include <cpu_func.h>
#include <dm.h>
#include <asm/byteorder.h>
#include <usb.h>
#include <malloc.h>
#include <watchdog.h>
#include <asm/cache.h>
#include <asm/unaligned.h>
#include <linux/errno.h>
#include <usb/xhci.h>
#include "../drivers/phy/hibvt/usb_hisi.h"
#ifndef CONFIG_USB_MAX_CONTROLLER_COUNT
#define CONFIG_USB_MAX_CONTROLLER_COUNT 1
#endif
#if !CONFIG_IS_ENABLED(DM_USB)
#endif
#if CONFIG_IS_ENABLED(DM_USB)
#else
#endif
#if !CONFIG_IS_ENABLED(DM_USB)
int usb_alloc_device(struct usb_device *udev)
{
	return _xhci_alloc_device(udev);
}
#endif
#if !CONFIG_IS_ENABLED(DM_USB)
#endif /* CONFIG_IS_ENABLED(DM_USB) */
#if CONFIG_IS_ENABLED(DM_USB)
#endif
