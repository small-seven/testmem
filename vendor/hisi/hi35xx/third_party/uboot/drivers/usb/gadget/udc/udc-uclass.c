#include <common.h>
#include <dm.h>
#include <dm/device-internal.h>
#include <linux/usb/gadget.h>
#if CONFIG_IS_ENABLED(DM_USB_GADGET)
#define MAX_UDC_DEVICES 4
#if CONFIG_IS_ENABLED(DM_DEVICE_REMOVE)
#else
#endif
#endif
