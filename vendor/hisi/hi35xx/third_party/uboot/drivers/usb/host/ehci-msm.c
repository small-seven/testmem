#include <common.h>
#include <dm.h>
#include <errno.h>
#include <fdtdec.h>
#include <linux/libfdt.h>
#include <usb.h>
#include <usb/ehci-ci.h>
#include <usb/ulpi.h>
#include <wait_bit.h>
#include <asm/gpio.h>
#include <asm/io.h>
#include <linux/compat.h>
#include "ehci.h"
static int ehci_usb_remove(struct udevice *dev)
{
	struct msm_ehci_priv *p = dev_get_priv(dev);
	struct usb_ehci *ehci = p->ehci;
	int ret;

	ret = ehci_deregister(dev);
	if (ret)
		return ret;

	/* Stop controller. */
	clrbits_le32(&ehci->usbcmd, CMD_RUN);

	ret = ehci_shutdown_phy(dev, &p->phy);
	if (ret)
		return ret;

	ret = board_usb_init(0, USB_INIT_DEVICE); /* Board specific hook */
	if (ret < 0)
		return ret;

	/* Reset controller */
	setbits_le32(&ehci->usbcmd, CMD_RESET);

	/* Wait for reset */
	if (wait_for_bit_le32(&ehci->usbcmd, CMD_RESET, false, 30, false)) {
		printf("Stuck on USB reset.\n");
		return -ETIMEDOUT;
	}

	return 0;
}
#if defined(CONFIG_CI_UDC)
#endif
