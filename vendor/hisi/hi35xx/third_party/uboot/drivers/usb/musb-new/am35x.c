#ifndef __UBOOT__
#include <linux/init.h>
#include <linux/module.h>
#include <linux/clk.h>
#include <linux/err.h>
#include <linux/io.h>
#include <linux/platform_device.h>
#include <linux/dma-mapping.h>
#include <plat/usb.h>
#else
#include <common.h>
#include <asm/omap_musb.h>
#include "linux-compat.h"
#endif
#include "musb_core.h"
#define USB_REVISION_REG	0x00
#define USB_CTRL_REG		0x04
#define USB_STAT_REG		0x08
#define USB_EMULATION_REG	0x0c
#define USB_AUTOREQ_REG		0x14
#define USB_SRP_FIX_TIME_REG	0x18
#define USB_TEARDOWN_REG	0x1c
#define EP_INTR_SRC_REG		0x20
#define EP_INTR_SRC_SET_REG	0x24
#define EP_INTR_SRC_CLEAR_REG	0x28
#define EP_INTR_MASK_REG	0x2c
#define EP_INTR_MASK_SET_REG	0x30
#define EP_INTR_MASK_CLEAR_REG	0x34
#define EP_INTR_SRC_MASKED_REG	0x38
#define CORE_INTR_SRC_REG	0x40
#define CORE_INTR_SRC_SET_REG	0x44
#define CORE_INTR_SRC_CLEAR_REG	0x48
#define CORE_INTR_MASK_REG	0x4c
#define CORE_INTR_MASK_SET_REG	0x50
#define CORE_INTR_MASK_CLEAR_REG 0x54
#define CORE_INTR_SRC_MASKED_REG 0x58
#define USB_END_OF_INTR_REG	0x60
#define AM35X_SOFT_RESET_MASK	1
#define AM35X_INTR_USB_SHIFT	16
#define AM35X_INTR_USB_MASK	(0x1ff << AM35X_INTR_USB_SHIFT)
#define AM35X_INTR_DRVVBUS	0x100
#define AM35X_INTR_RX_SHIFT	16
#define AM35X_INTR_TX_SHIFT	0
#define AM35X_TX_EP_MASK	0xffff		/* EP0 + 15 Tx EPs */
#define AM35X_RX_EP_MASK	0xfffe		/* 15 Rx EPs */
#define AM35X_TX_INTR_MASK	(AM35X_TX_EP_MASK << AM35X_INTR_TX_SHIFT)
#define AM35X_RX_INTR_MASK	(AM35X_RX_EP_MASK << AM35X_INTR_RX_SHIFT)
#define USB_MENTOR_CORE_OFFSET	0x400
#define glue_to_musb(g)		platform_get_drvdata(g->musb)
#ifndef __UBOOT__
#else
#endif
#ifdef __UBOOT__
#endif
#ifndef __UBOOT__
#define portstate(stmt)		stmt
#define	POLL_SECONDS	2
#endif
#ifndef __UBOOT__
#else
#endif
#ifdef __UBOOT__
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
static int __devexit am35x_remove(struct platform_device *pdev)
{
	struct am35x_glue	*glue = platform_get_drvdata(pdev);

	platform_device_del(glue->musb);
	platform_device_put(glue->musb);
	clk_disable(glue->clk);
	clk_disable(glue->phy_clk);
	clk_put(glue->clk);
	clk_put(glue->phy_clk);
	kfree(glue);

	return 0;
}
#ifdef CONFIG_PM
#define DEV_PM_OPS	&am35x_pm_ops
#else
#define DEV_PM_OPS	NULL
#endif
#endif
