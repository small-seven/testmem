#undef DEBUG
#include <common.h>
#include <clk.h>
#include <dm.h>
#include <generic-phy.h>
#include <malloc.h>
#include <reset.h>
#include <linux/errno.h>
#include <linux/list.h>
#include <linux/usb/ch9.h>
#include <linux/usb/otg.h>
#include <linux/usb/gadget.h>
#include <asm/byteorder.h>
#include <asm/unaligned.h>
#include <asm/io.h>
#include <asm/mach-types.h>
#include <power/regulator.h>
#include "dwc2_udc_otg_regs.h"
#include "dwc2_udc_otg_priv.h"
#define OTG_DMA_MODE		1
#define DEBUG_SETUP 0
#define DEBUG_EP0 0
#define DEBUG_ISR 0
#define DEBUG_OUT_EP 0
#define DEBUG_IN_EP 0
#include <usb/dwc2_udc.h>
#define EP0_CON		0
#define EP_MASK		0xF
#define DRIVER_VERSION "15 March 2009"
#define create_proc_files() do {} while (0)
#define remove_proc_files() do {} while (0)
#include "dwc2_udc_otg_xfer_dma.c"
#define BYTES2MAXP(x)	(x / 8)
#define MAXP2BYTES(x)	(x * 8)
#if !CONFIG_IS_ENABLED(DM_USB_GADGET)
#else /* !CONFIG_IS_ENABLED(DM_USB_GADGET) */
#endif /* !CONFIG_IS_ENABLED(DM_USB_GADGET) */
#ifdef DEBUG
#endif
#ifdef CONFIG_USB_GADGET_DWC2_OTG_PHY_BUS_WIDTH_8
#else
#endif
#if CONFIG_IS_ENABLED(DM_USB_GADGET)
#endif
#if !CONFIG_IS_ENABLED(DM_USB_GADGET)
#else /* CONFIG_IS_ENABLED(DM_USB_GADGET) */
static int dwc2_udc_otg_remove(struct udevice *dev)
{
	struct dwc2_priv_data *priv = dev_get_priv(dev);

	usb_del_gadget_udc(&the_controller->gadget);

	reset_release_bulk(&priv->resets);

	clk_release_bulk(&priv->clks);

	dwc2_phy_shutdown(dev, priv->phys, priv->num_phys);

	return dm_scan_fdt_dev(dev);
}
#endif /* CONFIG_IS_ENABLED(DM_USB_GADGET) */
