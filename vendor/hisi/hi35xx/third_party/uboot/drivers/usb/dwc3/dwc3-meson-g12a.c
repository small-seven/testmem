#include <common.h>
#include <asm-generic/io.h>
#include <dm.h>
#include <dm/device-internal.h>
#include <dm/lists.h>
#include <dwc3-uboot.h>
#include <generic-phy.h>
#include <linux/usb/ch9.h>
#include <linux/usb/gadget.h>
#include <malloc.h>
#include <regmap.h>
#include <usb.h>
#include "core.h"
#include "gadget.h"
#include <reset.h>
#include <clk.h>
#include <power/regulator.h>
#include <linux/bitfield.h>
#include <linux/bitops.h>
#include <linux/compat.h>
#define U2P_REG_SIZE						0x20
#define U2P_R0							0x0
#define U2P_R1							0x4
#define USB_R0							0x80
#define USB_R1							0x84
#define USB_R2							0x88
#define USB_R3							0x8c
#define USB_R4							0x90
#define USB_R5							0x94
#if CONFIG_IS_ENABLED(DM_REGULATOR)
#endif
#define U2P_REG_SIZE						0x20
#define USB_REG_OFFSET						0x80
#if CONFIG_IS_ENABLED(DM_REGULATOR)
#endif
#if CONFIG_IS_ENABLED(CLK)
#endif
#if CONFIG_IS_ENABLED(DM_REGULATOR)
#endif
static int dwc3_meson_g12a_remove(struct udevice *dev)
{
	struct dwc3_meson_g12a *priv = dev_get_platdata(dev);
	int i;

	reset_release_all(&priv->reset, 1);

	clk_release_all(&priv->clk, 1);

	for (i = 0 ; i < PHY_COUNT ; ++i) {
		if (!priv->phys[i].dev)
			continue;

		 generic_phy_exit(&priv->phys[i]);
	}

	return dm_scan_fdt_dev(dev);
}
