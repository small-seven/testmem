#include <common.h>
#include <dm.h>
#include <errno.h>
#include <memalign.h>
#include <usb.h>
#include <dm/device-internal.h>
#include <dm/lists.h>
#include <dm/uclass-internal.h>
int usb_alloc_device(struct usb_device *udev)
{
	struct udevice *bus = udev->controller_dev;
	struct dm_usb_ops *ops = usb_get_ops(bus);

	/* This is only requird by some controllers - current XHCI */
	if (!ops->alloc_device)
		return 0;

	return ops->alloc_device(bus, udev);
}
#ifdef CONFIG_USB_STORAGE
#endif
#ifdef CONFIG_SANDBOX
#endif
#if !defined(CONFIG_DM_ETH) && defined(CONFIG_USB_HOST_ETHER)
#endif
