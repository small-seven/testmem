#include <linux/autoconf.h>
#include <linux/types.h>
#include <linux/kernel.h>
#include <linux/ioctl.h>
#include <linux/fs.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <linux/usb.h>
#include <linux/pci.h>
#include <linux/input.h>
#include <linux/types.h>
#include <linux/kdev_t.h>
#include <asm/uaccess.h>
#include "tusb.h"
#include "st_tusb.h"
#if 0
#endif
#if 0
#endif
#if 0
#else
#endif
static int test_hcd_remove()
{
	struct pci_dev *pdev = NULL;
	struct usb_hcd *hcd = NULL;
	struct hc_driver *hdrv = NULL;

	/* check that hcd pointer exists */
	if (!ltp_usb.pdev) {
		printk("tusb: pdev pointer not found\n");
		return 1;
	} else {
		pdev = ltp_usb.pdev;
		hcd = pci_get_drvdata(pdev);
	}

	if (!hdrv->stop) {
		printk("tusb: stop function not found\n");
		return 1;
	} else
		hcd->driver->stop(hcd);

	return 0;
}
#if 0
#endif
