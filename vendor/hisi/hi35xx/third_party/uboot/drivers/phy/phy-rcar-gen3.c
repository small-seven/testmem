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
#define USB2_INT_ENABLE		0x000
#define USB2_USBCTR		0x00c
#define USB2_SPD_RSM_TIMSET	0x10c
#define USB2_OC_TIMSET		0x110
#define USB2_COMMCTRL		0x600
#define USB2_OBINTSTA		0x604
#define USB2_OBINTEN		0x608
#define USB2_VBCTRL		0x60c
#define USB2_LINECTRL1		0x610
#define USB2_ADPCTRL		0x630
#define USB2_USBCTR_PLL_RST	BIT(1)
#define USB2_SPD_RSM_TIMSET_INIT	0x014e029b
#define USB2_OC_TIMSET_INIT		0x000209ab
#define USB2_COMMCTRL_OTG_PERI		BIT(31)	/* 1 = Peripheral mode */
#define USB2_LINECTRL1_DP_RPD		BIT(18)
#define USB2_LINECTRL1_DM_RPD		BIT(16)
#define USB2_ADPCTRL_DRVVBUS		BIT(4)
static int rcar_gen3_phy_remove(struct udevice *dev)
{
	struct rcar_gen3_phy *priv = dev_get_priv(dev);

	clk_disable(&priv->clk);
	clk_free(&priv->clk);

	return 0;
}
