#ifndef __UBOOT__
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/slab.h>
#include <linux/init.h>
#include <linux/list.h>
#include <linux/kobject.h>
#include <linux/prefetch.h>
#include <linux/platform_device.h>
#include <linux/io.h>
#else
#include <common.h>
#include <usb.h>
#include <linux/errno.h>
#include <linux/usb/ch9.h>
#include <linux/usb/gadget.h>
#include <linux/usb/musb.h>
#include <asm/io.h>
#include "linux-compat.h"
#include "usb-compat.h"
#endif
#include "musb_core.h"
#define TA_WAIT_BCON(m) max_t(int, (m)->a_wait_bcon, OTG_TIME_A_WAIT_BCON)
#define DRIVER_AUTHOR "Mentor Graphics, Texas Instruments, Nokia"
#define DRIVER_DESC "Inventra Dual-Role USB Controller Driver"
#define MUSB_VERSION "6.0"
#define DRIVER_INFO DRIVER_DESC ", v" MUSB_VERSION
#define MUSB_DRIVER_NAME "musb-hdrc"
#ifndef __UBOOT__
#endif
#if !defined(CONFIG_USB_MUSB_TUSB6010)
#if !defined(CONFIG_USB_MUSB_AM35X) && !defined(CONFIG_USB_MUSB_PIC32)
#endif
#endif	/* normal PIO */
#ifndef __UBOOT__
#endif
#ifndef __UBOOT__
#endif
#ifndef __UBOOT__
#endif
#ifndef __UBOOT__
#endif
#ifndef __UBOOT__
#endif
#if 0
#endif
#ifndef __UBOOT__
#else
#endif
#ifdef __UBOOT__
#endif
#ifndef __UBOOT__
#endif
#ifndef __UBOOT__
#else
#endif
#ifdef __UBOOT__
#endif
#ifndef __UBOOT__
#endif
#if defined(CONFIG_USB_MUSB_TUSB6010)			\
#elif defined(CONFIG_USB_MUSB_UX500)			\
#else
#endif
#ifndef CONFIG_USB_MUSB_DISABLE_BULK_COMBINE_SPLIT
#else
#endif
#ifndef	CONFIG_USB_OTG_BLACKLIST_HUB
#endif
#if defined(CONFIG_USB_MUSB_TUSB6010) || defined (CONFIG_USB_MUSB_TUSB6010_MODULE)
#endif
#if defined(CONFIG_SOC_OMAP2430) || defined(CONFIG_SOC_OMAP3430) || \
#else
#define generic_interrupt	NULL
#endif
#ifndef CONFIG_USB_MUSB_PIO_ONLY
#ifndef CONFIG_USB_TUSB_OMAP_DMA
#endif
#else
#define use_dma			0
#endif
#ifdef CONFIG_SYSFS
#endif	/* sysfs */
#ifndef __UBOOT__
#endif
#ifndef __UBOOT__
#else
#endif
#ifndef __UBOOT__
#endif
static void musb_free(struct musb *musb)
{
	/* this has multiple entry modes. it handles fault cleanup after
	 * probe(), where things may be partially set up, as well as rmmod
	 * cleanup after everything's been de-activated.
	 */

#ifdef CONFIG_SYSFS
	sysfs_remove_group(&musb->controller->kobj, &musb_attr_group);
#endif

	if (musb->nIrq >= 0) {
		if (musb->irq_wake)
			disable_irq_wake(musb->nIrq);
		free_irq(musb->nIrq, musb);
	}
	if (is_dma_capable() && musb->dma_controller) {
		struct dma_controller	*c = musb->dma_controller;

		(void) c->stop(c);
		dma_controller_destroy(c);
	}

	kfree(musb);
}
#ifndef __UBOOT__
#else
#endif
#ifndef __UBOOT__
#else
#endif
#ifndef __UBOOT__
#endif
#ifndef CONFIG_USB_MUSB_PIO_ONLY
#endif
#ifndef __UBOOT__
#endif
#ifndef __UBOOT__
#endif
#ifndef __UBOOT__
#endif
#ifndef __UBOOT__
#endif
#ifndef __UBOOT__
#endif
#ifdef CONFIG_SYSFS
#endif
#ifndef __UBOOT__
#else
#endif
#ifndef __UBOOT__
#endif
#ifndef __UBOOT__
#else
#endif
#ifndef CONFIG_USB_MUSB_PIO_ONLY
#endif
#ifndef __UBOOT__
#ifndef CONFIG_USB_MUSB_PIO_ONLY
#endif
static int __devexit musb_remove(struct platform_device *pdev)
{
	struct musb	*musb = dev_to_musb(&pdev->dev);
	void __iomem	*ctrl_base = musb->ctrl_base;

	/* this gets called on rmmod.
	 *  - Host mode: host may still be active
	 *  - Peripheral mode: peripheral is deactivated (or never-activated)
	 *  - OTG mode: both roles are deactivated (or never-activated)
	 */
	musb_exit_debugfs(musb);
	musb_shutdown(pdev);

	musb_free(musb);
	iounmap(ctrl_base);
	device_init_wakeup(&pdev->dev, 0);
#ifndef CONFIG_USB_MUSB_PIO_ONLY
	pdev->dev.dma_mask = orig_dma_mask;
#endif
	return 0;
}
#ifdef	CONFIG_PM
#define MUSB_DEV_PM_OPS (&musb_dev_pm_ops)
#else
#define	MUSB_DEV_PM_OPS	NULL
#endif
#endif
