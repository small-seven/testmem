#include "implementation/global_implementation.h"
#define	usb_port_reset_recovery_max	2000	/* ms */
#define	PORTNO_TO_NBIT(portno, i)	(1U << (portno - (i << 5)))
#undef USB_DEBUG_VAR
#define	USB_DEBUG_VAR   usb_debug
#ifdef LOSCFG_USB_DEBUG
#ifdef USB_REQ_DEBUG
#endif	/* USB_REQ_DEBUG */
#endif	/* LOSCFG_USB_DEBUG */
#ifdef USB_REQ_DEBUG
#endif
#if (USB_HAVE_USER_IO == 0)
#endif
#if USB_HAVE_USER_IO
#endif
#ifdef USB_REQ_DEBUG
#endif
#ifdef USB_REQ_DEBUG
#endif
#if USB_HAVE_USER_IO
#endif
#ifdef USB_REQ_DEBUG
#endif
#if USB_HAVE_USER_IO
#endif
usbd_alloc_config_desc(struct usb_device *udev, uint32_t size)
{
	if (size > USB_CONFIG_MAX) {
		DPRINTF("Configuration descriptor too big\n");
		return (NULL);
	}
#if (USB_HAVE_FIXED_CONFIG == 0)
	return (bsd_malloc(size, M_USBDEV, M_ZERO | M_WAITOK));
#else
	(void)memset_s(udev->config_data, sizeof(udev->config_data), 0, sizeof(udev->config_data));
	return (udev->config_data);
#endif
}
usbd_free_config_desc(struct usb_device *udev, void *ptr)
{
#if (USB_HAVE_FIXED_CONFIG == 0)
	bsd_free(ptr, M_USBDEV);
#endif
}
#if USB_HAVE_TT_SUPPORT
#endif
#undef USB_DEBUG_VAR
