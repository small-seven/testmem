#include <common.h>
#include <dm.h>
#include <dm/device-internal.h>
#include <dm/lists.h>
#include <asm/arch/hardware.h>
#include <asm/arch/da8xx-usb.h>
#include <linux/usb/otg.h>
#include <asm/omap_musb.h>
#include <generic-phy.h>
#include "linux-compat.h"
#include "musb_core.h"
#include "musb_uboot.h"
#define DA8XX_USB_REVISION_REG	0x00
#define DA8XX_USB_CTRL_REG	0x04
#define DA8XX_USB_STAT_REG	0x08
#define DA8XX_USB_EMULATION_REG 0x0c
#define DA8XX_USB_SRP_FIX_TIME_REG 0x18
#define DA8XX_USB_INTR_SRC_REG	0x20
#define DA8XX_USB_INTR_SRC_SET_REG 0x24
#define DA8XX_USB_INTR_SRC_CLEAR_REG 0x28
#define DA8XX_USB_INTR_MASK_REG 0x2c
#define DA8XX_USB_INTR_MASK_SET_REG 0x30
#define DA8XX_USB_INTR_MASK_CLEAR_REG 0x34
#define DA8XX_USB_INTR_SRC_MASKED_REG 0x38
#define DA8XX_USB_END_OF_INTR_REG 0x3c
#define DA8XX_USB_GENERIC_RNDIS_EP_SIZE_REG(n) (0x50 + (((n) - 1) << 2))
#define DA8XX_SOFT_RESET_MASK	1
#define DA8XX_USB_TX_EP_MASK	0x1f		/* EP0 + 4 Tx EPs */
#define DA8XX_USB_RX_EP_MASK	0x1e		/* 4 Rx EPs */
#define DA8XX_INTR_USB_SHIFT	16
#define DA8XX_INTR_USB_MASK	(0x1ff << DA8XX_INTR_USB_SHIFT) /* 8 Mentor */
#define DA8XX_INTR_DRVVBUS	0x100
#define DA8XX_INTR_RX_SHIFT	8
#define DA8XX_INTR_RX_MASK	(DA8XX_USB_RX_EP_MASK << DA8XX_INTR_RX_SHIFT)
#define DA8XX_INTR_TX_SHIFT	0
#define DA8XX_INTR_TX_MASK	(DA8XX_USB_TX_EP_MASK << DA8XX_INTR_TX_SHIFT)
#define DA8XX_MENTOR_CORE_OFFSET 0x400
static int da8xx_musb_remove(struct udevice *dev)
{
	struct musb_host_data *host = dev_get_priv(dev);

	musb_stop(host->host);

	return 0;
}
