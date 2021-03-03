#include <common.h>
#include <asm/arch/hardware.h>
#include <asm/byteorder.h>
#include <asm/io.h>
#include <usbdevice.h>
#include <usb/pxa27x_udc.h>
#include <usb/udc.h>
#include "ep0.h"
#define UDC_MAX_ENDPOINTS	24
#ifdef USBDDBG
#else
#define udc_dump_buffer(name, buf, len)		/* void */
#endif
#if defined(USBDDBG) && defined(USBDPARANOIA)
#endif
#if defined(USBDDBG) && defined(USBDPARANOIA)
#endif
#if defined(USBDDBG) && defined(USBDPARANOIA)
#endif
#define UDCCR_OEN		(1 << 31)   /* On-the-Go Enable */
#define UDCCR_MASK_BITS     	(UDCCR_OEN | UDCCR_UDE)
#ifdef CONFIG_USB_DEV_PULLUP_GPIO
#else
#endif
#ifdef CONFIG_USB_DEV_PULLUP_GPIO
#else
#endif
