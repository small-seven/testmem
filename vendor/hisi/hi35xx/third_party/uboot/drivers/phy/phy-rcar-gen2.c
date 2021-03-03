#include <common.h>
#include <clk.h>
#include <div64.h>
#include <dm.h>
#include <fdtdec.h>
#include <generic-phy.h>
#include <reset.h>
#include <syscon.h>
#include <usb.h>
#include <asm/io.h>
#include <linux/bitops.h>
#include <power/regulator.h>
#define USBHS_LPSTS			0x02
#define USBHS_UGCTRL			0x80
#define USBHS_UGCTRL2			0x84
#define USBHS_UGSTS			0x88	/* From technical update */
#define USBHS_LPSTS_SUSPM		0x4000
#define USBHS_UGCTRL_CONNECT		BIT(2)
#define USBHS_UGCTRL_PLLRESET		BIT(0)
#define USBHS_UGCTRL2_USB2SEL		0x80000000
#define USBHS_UGCTRL2_USB2SEL_PCI	0x00000000
#define USBHS_UGCTRL2_USB2SEL_USB30	0x80000000
#define USBHS_UGCTRL2_USB0SEL		0x00000030
#define USBHS_UGCTRL2_USB0SEL_PCI	0x00000010
#define USBHS_UGCTRL2_USB0SEL_HS_USB	0x00000030
#define USBHS_UGSTS_LOCK		0x00000100 /* From technical update */
#define PHYS_PER_CHANNEL	2
static int rcar_gen2_phy_remove(struct udevice *dev)
{
	struct rcar_gen2_phy *priv = dev_get_priv(dev);

	clk_disable(&priv->clk);
	clk_free(&priv->clk);

	return 0;
}
