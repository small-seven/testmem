#include <common.h>
#include <console.h>
#include <dm.h>
#include <env.h>
#include <errno.h>
#include <malloc.h>
#include <memalign.h>
#include <stdio_dev.h>
#include <watchdog.h>
#include <asm/byteorder.h>
#include <usb.h>
#ifdef CONFIG_SYS_CONSOLE_OVERWRITE_ROUTINE
#else
#endif
#define REPEAT_RATE	40		/* 40msec -> 25cps */
#define REPEAT_DELAY	10		/* 10 x REPEAT_RATE = 400msec */
#define NUM_LOCK	0x53
#define CAPS_LOCK	0x39
#define SCROLL_LOCK	0x47
#define LEFT_CNTR	(1 << 0)
#define LEFT_SHIFT	(1 << 1)
#define LEFT_ALT	(1 << 2)
#define LEFT_GUI	(1 << 3)
#define RIGHT_CNTR	(1 << 4)
#define RIGHT_SHIFT	(1 << 5)
#define RIGHT_ALT	(1 << 6)
#define RIGHT_GUI	(1 << 7)
#define USB_KBD_BUFFER_LEN	0x20
#define DEVNAME			"usbkbd"
#ifdef CONFIG_USB_KEYBOARD_FN_KEYS
#else
#endif
#define USB_KBD_NUMLOCK		(1 << 0)
#define USB_KBD_CAPSLOCK	(1 << 1)
#define USB_KBD_SCROLLLOCK	(1 << 2)
#define USB_KBD_CTRL		(1 << 3)
#define USB_KBD_LEDMASK		\
#define CAPITAL_MASK	0x20
#ifdef CONFIG_USB_KEYBOARD_FN_KEYS
#else
#endif /* CONFIG_USB_KEYBOARD_FN_KEYS */
#if defined(CONFIG_SYS_USB_EVENT_POLL)
#elif defined(CONFIG_SYS_USB_EVENT_POLL_VIA_CONTROL_EP) || \
#if defined(CONFIG_SYS_USB_EVENT_POLL_VIA_CONTROL_EP)
#else
#endif
#endif
#ifdef CONFIG_CMD_NET
#endif
#if !defined(CONFIG_SYS_USB_EVENT_POLL_VIA_CONTROL_EP) && \
#else
#endif
#ifdef CONFIG_SYS_USB_EVENT_POLL_VIA_INT_QUEUE
#elif defined(CONFIG_SYS_USB_EVENT_POLL_VIA_CONTROL_EP)
#else
#endif
#if CONFIG_IS_ENABLED(CONSOLE_MUX)
#else
#endif
#if !CONFIG_IS_ENABLED(DM_USB)
#if CONFIG_IS_ENABLED(SYS_STDIO_DEREGISTER)
#if CONFIG_IS_ENABLED(CONSOLE_MUX)
#endif
#ifdef CONFIG_SYS_USB_EVENT_POLL_VIA_INT_QUEUE
#endif
#else
#endif
#endif
#if CONFIG_IS_ENABLED(DM_USB)
static int usb_kbd_remove(struct udevice *dev)
{
	struct usb_device *udev = dev_get_parent_priv(dev);
	struct usb_kbd_pdata *data;
	struct stdio_dev *sdev;
	int ret;

	sdev = stdio_get_by_name(DEVNAME);
	if (!sdev) {
		ret = -ENXIO;
		goto err;
	}
	data = udev->privptr;
	if (stdio_deregister_dev(sdev, true)) {
		ret = -EPERM;
		goto err;
	}
#if CONFIG_IS_ENABLED(CONSOLE_MUX)
	if (iomux_doenv(stdin, env_get("stdin"))) {
		ret = -ENOLINK;
		goto err;
	}
#endif
#ifdef CONFIG_SYS_USB_EVENT_POLL_VIA_INT_QUEUE
	destroy_int_queue(udev, data->intq);
#endif
	free(data->new);
	free(data);

	return 0;
err:
	printf("%s: warning, ret=%d", __func__, ret);
	return ret;
}
#endif
