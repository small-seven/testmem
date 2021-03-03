#include <common.h>
#include <dm.h>
#include <serial.h>
#include <dm/device-internal.h>
#include <dm/lists.h>
#include <linux/usb/otg.h>
#include <asm/omap_common.h>
#include <asm/omap_musb.h>
#include <twl4030.h>
#include <twl6030.h>
#include "linux-compat.h"
#include "musb_core.h"
#include "omap2430.h"
#include "musb_uboot.h"
#ifdef CONFIG_TWL4030_USB
#endif
#ifdef CONFIG_TWL6030_POWER
#endif
#ifdef CONFIG_OMAP44XX
#endif
#if CONFIG_IS_ENABLED(DM_USB)
#if 0 /* In a perfect world, mode would be set to OTG, mode 3 from DT */
#else /* MUSB_OTG, it doesn't work */
#ifdef CONFIG_USB_MUSB_HOST /* Host seems to be the only option that works */
#else /* For that matter, MUSB_PERIPHERAL doesn't either */
#endif
#endif
#ifdef CONFIG_USB_MUSB_HOST
#else
#endif
#ifdef CONFIG_USB_MUSB_HOST
#else
#endif
static int omap2430_musb_remove(struct udevice *dev)
{
	struct musb_host_data *host = dev_get_priv(dev);

	musb_stop(host->host);

	return 0;
}
#ifdef CONFIG_USB_MUSB_HOST
#else
#endif
#ifdef CONFIG_USB_MUSB_HOST
#endif
#endif /* CONFIG_IS_ENABLED(DM_USB) */
