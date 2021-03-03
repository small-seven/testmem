#include <common.h>
#include <clk.h>
#include <dm.h>
#include <generic-phy.h>
#include <phy-sun4i-usb.h>
#include <reset.h>
#include <asm/arch/cpu.h>
#include <asm/arch/clock.h>
#include <asm/arch/gpio.h>
#include <asm-generic/gpio.h>
#include <dm/lists.h>
#include <dm/root.h>
#include <linux/usb/musb.h>
#include "linux-compat.h"
#include "musb_core.h"
#include "musb_uboot.h"
#define  USBC_REG_o_ISCR	0x0400
#define  USBC_REG_o_PHYCTL	0x0404
#define  USBC_REG_o_PHYBIST	0x0408
#define  USBC_REG_o_PHYTUNE	0x040c
#define  USBC_REG_o_VEND0	0x0043
#define  USBC_BP_ISCR_VBUS_VALID_FROM_DATA	30
#define  USBC_BP_ISCR_VBUS_VALID_FROM_VBUS	29
#define  USBC_BP_ISCR_EXT_ID_STATUS		28
#define  USBC_BP_ISCR_EXT_DM_STATUS		27
#define  USBC_BP_ISCR_EXT_DP_STATUS		26
#define  USBC_BP_ISCR_MERGED_VBUS_STATUS	25
#define  USBC_BP_ISCR_MERGED_ID_STATUS		24
#define  USBC_BP_ISCR_ID_PULLUP_EN		17
#define  USBC_BP_ISCR_DPDM_PULLUP_EN		16
#define  USBC_BP_ISCR_FORCE_ID			14
#define  USBC_BP_ISCR_FORCE_VBUS_VALID		12
#define  USBC_BP_ISCR_VBUS_VALID_SRC		10
#define  USBC_BP_ISCR_HOSC_EN			7
#define  USBC_BP_ISCR_VBUS_CHANGE_DETECT	6
#define  USBC_BP_ISCR_ID_CHANGE_DETECT		5
#define  USBC_BP_ISCR_DPDM_CHANGE_DETECT	4
#define  USBC_BP_ISCR_IRQ_ENABLE		3
#define  USBC_BP_ISCR_VBUS_CHANGE_DETECT_EN	2
#define  USBC_BP_ISCR_ID_CHANGE_DETECT_EN	1
#define  USBC_BP_ISCR_DPDM_CHANGE_DETECT_EN	0
#define OFF_SUN6I_AHB_RESET0	0x2c0
#define to_sunxi_glue(d)	container_of(d, struct sunxi_glue, dev)
#define SUNXI_MUSB_MAX_EP_NUM		6
#define SUNXI_MUSB_RAM_BITS		11
#define SUNXI_MUSB_MAX_EP_NUM_H3	5
#ifdef CONFIG_USB_MUSB_HOST
#endif
#ifdef CONFIG_USB_MUSB_HOST
#else
#endif
static int musb_usb_remove(struct udevice *dev)
{
	struct sunxi_glue *glue = dev_get_priv(dev);
	struct musb_host_data *host = &glue->mdata;

	musb_stop(host->host);
	free(host->host);
	host->host = NULL;

	return 0;
}
#ifdef CONFIG_USB_MUSB_HOST
#else
#endif
#ifdef CONFIG_USB_MUSB_HOST
#endif
