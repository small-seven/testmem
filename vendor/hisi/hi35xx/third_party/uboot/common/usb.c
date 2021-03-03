#include <common.h>
#include <command.h>
#include <dm.h>
#include <memalign.h>
#include <asm/processor.h>
#include <linux/compiler.h>
#include <linux/ctype.h>
#include <asm/byteorder.h>
#include <asm/unaligned.h>
#include <errno.h>
#include <usb.h>
#define USB_BUFSIZ	512
#if !CONFIG_IS_ENABLED(DM_USB)
#ifndef CONFIG_USB_MAX_CONTROLLER_COUNT
#define CONFIG_USB_MAX_CONTROLLER_COUNT 1
#endif
#endif /* !CONFIG_IS_ENABLED(DM_USB) */
#ifdef DEBUG
#endif
#if !CONFIG_IS_ENABLED(DM_USB)
void usb_free_device(struct udevice *controller)
{
	dev_index--;
	debug("Freeing device node: %d\n", dev_index);
	memset(&usb_dev[dev_index], 0, sizeof(struct usb_device));
	usb_dev[dev_index].devnum = -1;
}
#endif /* !CONFIG_IS_ENABLED(DM_USB) */
#if !CONFIG_IS_ENABLED(DM_USB)
#ifdef CONFIG_USB_XHCI_HCD
#endif
#endif
#if CONFIG_IS_ENABLED(DM_USB)
#else
#endif
#if CONFIG_IS_ENABLED(DM_USB)
#else
#endif
