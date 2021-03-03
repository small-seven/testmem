#include <common.h>
#include <asm-generic/io.h>
#include <clk.h>
#include <dm.h>
#include <linux/io.h>
#include <linux/usb/otg.h>
#include <malloc.h>
#include "core.h"
#define USBSS_PID		0x0
#define	USBSS_W1		0x4
#define USBSS_STATIC_CONFIG	0x8
#define USBSS_PHY_TEST		0xc
#define	USBSS_DEBUG_CTRL	0x10
#define	USBSS_DEBUG_INFO	0x14
#define	USBSS_DEBUG_LINK_STATE	0x18
#define	USBSS_DEVICE_CTRL	0x1c
#define USBSS_W1_PWRUP_RST		BIT(0)
#define USBSS_W1_OVERCURRENT_SEL	BIT(8)
#define USBSS_W1_MODESTRAP_SEL		BIT(9)
#define USBSS_W1_OVERCURRENT		BIT(16)
#define USBSS_W1_MODESTRAP_MASK		GENMASK(18, 17)
#define USBSS_W1_MODESTRAP_SHIFT	17
#define USBSS_W1_USB2_ONLY		BIT(19)
#define USBSS1_STATIC_PLL_REF_SEL_MASK	GENMASK(8, 5)
#define USBSS1_STATIC_PLL_REF_SEL_SHIFT	5
#define USBSS1_STATIC_LOOPBACK_MODE_MASK	GENMASK(4, 3)
#define USBSS1_STATIC_LOOPBACK_MODE_SHIFT	3
#define USBSS1_STATIC_VBUS_SEL_MASK	GENMASK(2, 1)
#define USBSS1_STATIC_VBUS_SEL_SHIFT	1
#define USBSS1_STATIC_LANE_REVERSE	BIT(0)
static int cdns_ti_remove(struct udevice *dev)
{
	struct cdns_ti *data = dev_get_platdata(dev);
	u32 reg;

	/* put device back to RESET*/
	reg = cdns_ti_readl(data, USBSS_W1);
	reg &= ~USBSS_W1_PWRUP_RST;
	cdns_ti_writel(data, USBSS_W1, reg);

	return 0;
}
