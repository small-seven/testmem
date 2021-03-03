#include <common.h>
#include <linux/usb/musb.h>
#include "linux-compat.h"
#include "musb_core.h"
#include "musb_uboot.h"
#define PIC32_TX_EP_MASK	0x0f		/* EP0 + 7 Tx EPs */
#define PIC32_RX_EP_MASK	0x0e		/* 7 Rx EPs */
#define MUSB_SOFTRST		0x7f
#define  MUSB_SOFTRST_NRST	BIT(0)
#define  MUSB_SOFTRST_NRSTX	BIT(1)
#define USBCRCON		0
#define  USBCRCON_USBWKUPEN	BIT(0)  /* Enable Wakeup Interrupt */
#define  USBCRCON_USBRIE	BIT(1)  /* Enable Remote resume Interrupt */
#define  USBCRCON_USBIE		BIT(2)  /* Enable USB General interrupt */
#define  USBCRCON_SENDMONEN	BIT(3)  /* Enable Session End VBUS monitoring */
#define  USBCRCON_BSVALMONEN	BIT(4)  /* Enable B-Device VBUS monitoring */
#define  USBCRCON_ASVALMONEN	BIT(5)  /* Enable A-Device VBUS monitoring */
#define  USBCRCON_VBUSMONEN	BIT(6)  /* Enable VBUS monitoring */
#define  USBCRCON_PHYIDEN	BIT(7)  /* PHY ID monitoring enable */
#define  USBCRCON_USBIDVAL	BIT(8)  /* USB ID value */
#define  USBCRCON_USBIDOVEN	BIT(9)  /* USB ID override enable */
#define  USBCRCON_USBWK		BIT(24) /* USB Wakeup Status */
#define  USBCRCON_USBRF		BIT(25) /* USB Resume Status */
#define  USBCRCON_USBIF		BIT(26) /* USB General Interrupt Status */
#define to_pic32_musb_data(d)	\
#ifdef CONFIG_USB_MUSB_HOST
#else
#endif
static int musb_usb_remove(struct udevice *dev)
{
	struct pic32_musb_data *pdata = dev_get_priv(dev);

	musb_stop(pdata->mdata.host);

	return 0;
}
#ifdef CONFIG_USB_MUSB_HOST
#endif
