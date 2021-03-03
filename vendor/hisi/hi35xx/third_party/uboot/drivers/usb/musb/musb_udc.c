#include <common.h>
#include <serial.h>
#include <usbdevice.h>
#include <usb/udc.h>
#include "../gadget/ep0.h"
#include "musb_core.h"
#if defined(CONFIG_USB_OMAP3)
#include "omap3.h"
#elif defined(CONFIG_USB_AM35X)
#include "am35x.h"
#endif
#include "musb_debug.h"
#define MAX_ENDPOINT 15
#define GET_ENDPOINT(dev,ep)						\
#define SET_EP0_STATE(s)						\
#ifdef MUSB_DEBUG
#else
#define musb_db_regs()
#endif /* DEBUG_MUSB */
