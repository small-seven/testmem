#include <common.h>
#include <command.h>
#include <console.h>
#include <dm.h>
#include <dm/uclass-internal.h>
#include <memalign.h>
#include <asm/byteorder.h>
#include <asm/unaligned.h>
#include <part.h>
#include <usb.h>
#ifdef CONFIG_USB_STORAGE
#endif
#if defined(CONFIG_USB_HOST_ETHER) && !defined(CONFIG_DM_ETH)
#endif
#ifdef CONFIG_DM_USB
#else
#endif
#ifdef CONFIG_DM_USB
#else
#endif
#ifdef CONFIG_DM_USB
#else
#endif
#ifdef CONFIG_DM_USB
#else
#endif
#ifdef CONFIG_DM_USB
typedef void (*usb_dev_func_t)(struct usb_device *udev);

static void usb_for_each_root_dev(usb_dev_func_t func)
{
	struct udevice *bus;

	for (uclass_find_first_device(UCLASS_USB, &bus);
		bus;
		uclass_find_next_device(&bus)) {
		struct usb_device *udev;
		struct udevice *dev;

		if (!device_active(bus))
			continue;

		device_find_first_child(bus, &dev);
		if (dev && device_active(dev)) {
			udev = dev_get_parent_priv(dev);
			func(udev);
		}
#endif
#ifdef CONFIG_DM_USB
#else
#endif
#ifdef CONFIG_USB_STORAGE
#endif /* CONFIG_USB_STORAGE */
#if !defined CONFIG_DM_USB && defined CONFIG_USB_KEYBOARD
#endif
# ifdef CONFIG_USB_STORAGE
# endif
#ifndef CONFIG_DM_USB
# ifdef CONFIG_USB_KEYBOARD
# endif
#endif /* !CONFIG_DM_USB */
#ifdef CONFIG_USB_HOST_ETHER
# ifdef CONFIG_DM_ETH
#  ifndef CONFIG_DM_USB
#   error "You must use CONFIG_DM_USB if you want to use CONFIG_USB_HOST_ETHER with CONFIG_DM_ETH"
#  endif
# else
# endif
#endif
#ifdef CONFIG_DM_USB
#endif
#ifdef CONFIG_DM_USB
#else
#endif
#ifdef CONFIG_USB_STORAGE
#else
#endif /* CONFIG_USB_STORAGE */
#ifdef CONFIG_USB_STORAGE
#endif /* CONFIG_USB_STORAGE */
#ifdef CONFIG_USB_STORAGE
#endif /* CONFIG_USB_STORAGE */
