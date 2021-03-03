#include <common.h>
#include <command.h>
#include <dm.h>
#include <env.h>
#include <errno.h>
#include <memalign.h>
#include <asm/processor.h>
#include <asm/unaligned.h>
#include <linux/ctype.h>
#include <linux/list.h>
#include <asm/byteorder.h>
#ifdef CONFIG_SANDBOX
#include <asm/state.h>
#endif
#include <asm/unaligned.h>
#include <usb.h>
#define USB_BUFSIZ	512
#define HUB_SHORT_RESET_TIME	20
#define HUB_LONG_RESET_TIME	200
#define PORT_OVERCURRENT_MAX_SCAN_COUNT		3
#if CONFIG_IS_ENABLED(DM_USB)
#endif
#if CONFIG_IS_ENABLED(DM_USB)
#endif
#ifdef CONFIG_SANDBOX
#endif
#if !CONFIG_IS_ENABLED(DM_USB)
static struct usb_hub_device *usb_hub_allocate(void)
{
	if (usb_hub_index < USB_MAX_HUB)
		return &hub_dev[usb_hub_index++];

	printf("ERROR: USB_MAX_HUB (%d) reached\n", USB_MAX_HUB);
	return NULL;
}
#endif
#define MAX_TRIES 5
#if CONFIG_IS_ENABLED(DM_USB)
#else
#endif
#if CONFIG_IS_ENABLED(DM_USB)
#else
#endif
#ifndef CONFIG_USB_EHCI_FARADAY
#endif
#if !CONFIG_IS_ENABLED(DM_USB)
#else
#endif
#if CONFIG_IS_ENABLED(DM_USB)
#endif
#if CONFIG_IS_ENABLED(DM_USB)
#endif
