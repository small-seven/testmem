#ifndef __UBOOT__
#include <linux/init.h>
#include <linux/io.h>
#include <linux/err.h>
#include <linux/platform_device.h>
#include <linux/dma-mapping.h>
#include <linux/pm_runtime.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/of_address.h>
#include <plat/usb.h>
#else
#include <common.h>
#include <asm/omap_musb.h>
#include "linux-compat.h"
#endif
#include "musb_core.h"
#ifndef __UBOOT__
#else
#endif
#ifndef __UBOOT__
#else
#endif
#ifndef __UBOOT__
#else
#endif
#ifndef __UBOOT__
#endif
#ifndef __UBOOT__
#endif
#ifndef __UBOOT__
#else
#endif
#ifndef __UBOOT__
#endif
#ifndef __UBOOT__
#endif
#ifndef __UBOOT__
#else
#endif
#ifndef __UBOOT__
#endif
#ifndef __UBOOT__
#endif
#ifndef __UBOOT__
#endif
#ifndef __UBOOT__
#else
#endif
#ifndef __UBOOT__
#endif
#ifndef __UBOOT__
#endif
#ifndef __UBOOT__
#else
#endif
#ifndef __UBOOT__
#endif
#ifndef __UBOOT__
#endif
#ifndef __UBOOT__
static int __devexit dsps_remove(struct platform_device *pdev)
{
	struct dsps_glue *glue = platform_get_drvdata(pdev);

	/* delete the child platform device */
	dsps_delete_musb_pdev(glue);

	/* disable usbss clocks */
	pm_runtime_put(&pdev->dev);
	pm_runtime_disable(&pdev->dev);
	kfree(glue->wrp);
	kfree(glue);
	return 0;
}
#ifdef CONFIG_PM_SLEEP
#endif
#endif
#ifndef __UBOOT__
#endif
