#ifndef __UBOOT__
#include <linux/kernel.h>
#include <linux/list.h>
#include <linux/timer.h>
#include <linux/module.h>
#include <linux/smp.h>
#include <linux/spinlock.h>
#include <linux/delay.h>
#include <linux/dma-mapping.h>
#include <linux/slab.h>
#else
#include <common.h>
#include <linux/usb/ch9.h>
#include "linux-compat.h"
#endif
#include "musb_core.h"
#define is_buffer_mapped(req) (is_dma_capable() && \
#ifndef CONFIG_USB_MUSB_PIO_ONLY
#else
#endif
#ifdef CONFIG_USB_INVENTRA_DMA
#endif
#ifndef	CONFIG_USB_MUSB_PIO_ONLY
#if defined(CONFIG_USB_INVENTRA_DMA) || defined(CONFIG_USB_UX500_DMA)
#elif defined(CONFIG_USB_TI_CPPI_DMA)
#elif defined(CONFIG_USB_TUSB_OMAP_DMA)
#endif
#endif
#if defined(CONFIG_USB_INVENTRA_DMA) || defined(CONFIG_USB_UX500_DMA)
#endif
#ifdef CONFIG_USB_INVENTRA_DMA
#endif
#ifdef CONFIG_USB_INVENTRA_DMA
#elif defined(CONFIG_USB_UX500_DMA)
#endif	/* Mentor's DMA */
#ifdef	CONFIG_USB_TUSB_OMAP_DMA
#endif
#if defined(CONFIG_USB_INVENTRA_DMA) || defined(CONFIG_USB_TUSB_OMAP_DMA) || \
#endif
#if defined(CONFIG_USB_INVENTRA_DMA) || defined(CONFIG_USB_TUSB_OMAP_DMA) || \
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
#if 0
#endif
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
#else
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
#ifndef __UBOOT__
#endif
#ifndef __UBOOT__
#endif
