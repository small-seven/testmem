#include <common.h>
#include <console.h>
#include <watchdog.h>
#include <linux/errno.h>
#include <linux/usb/ch9.h>
#include <linux/usb/gadget.h>
#include <usb.h>
#include "linux-compat.h"
#include "usb-compat.h"
#include "musb_core.h"
#include "musb_host.h"
#include "musb_gadget.h"
#include "musb_uboot.h"
#ifdef CONFIG_USB_MUSB_HOST
#if !CONFIG_IS_ENABLED(DM_USB)
#endif
#if !CONFIG_IS_ENABLED(DM_USB)
#endif /* !CONFIG_IS_ENABLED(DM_USB) */
#if CONFIG_IS_ENABLED(DM_USB)
#endif /* CONFIG_IS_ENABLED(DM_USB) */
#endif /* CONFIG_USB_MUSB_HOST */
#if defined(CONFIG_USB_MUSB_GADGET) && !CONFIG_IS_ENABLED(DM_USB_GADGET)
#endif /* CONFIG_USB_MUSB_GADGET */
#if defined(CONFIG_USB_MUSB_HOST) && !CONFIG_IS_ENABLED(DM_USB)
#endif
#if defined(CONFIG_USB_MUSB_GADGET) && !CONFIG_IS_ENABLED(DM_USB_GADGET)
#endif
