#include <common.h>
#include <console.h>
#include <env.h>
#include <linux/errno.h>
#include <linux/netdevice.h>
#include <linux/usb/ch9.h>
#include <linux/usb/cdc.h>
#include <linux/usb/gadget.h>
#include <net.h>
#include <usb.h>
#include <malloc.h>
#include <memalign.h>
#include <linux/ctype.h>
#include "gadget_chips.h"
#include "rndis.h"
#include <dm.h>
#include <dm/lists.h>
#include <dm/uclass-internal.h>
#include <dm/device-internal.h>
#define USB_NET_NAME "usb_ether"
#define atomic_read
#define DRIVER_DESC		"Ethernet Gadget"
#define DRIVER_VERSION		"May Day 2005"
#define RX_EXTRA	20		/* guard against rx overflows */
#ifndef	CONFIG_USB_ETH_RNDIS
#define rndis_uninit(x)		do {} while (0)
#define rndis_deregister(c)	do {} while (0)
#define rndis_exit()		do {} while (0)
#endif
#define	DEFAULT_FILTER	(USB_CDC_PACKET_TYPE_BROADCAST \
#define USB_CONNECT_TIMEOUT (3 * CONFIG_SYS_HZ)
#ifndef CONFIG_DM_ETH
#else
#endif
#define	WORK_RX_MEMORY		0
#ifndef CONFIG_DM_ETH
#else
#endif
#if	!defined(CONFIG_USB_ETH_SUBSET)
#elif	!defined(CONFIG_USB_ETH_CDC)
#else
#endif
#ifdef	CONFIG_USB_ETH_RNDIS
#else
#endif
#define	subset_active(dev)	(!is_cdc(dev) && !rndis_active(dev))
#define	cdc_active(dev)		(is_cdc(dev) && !rndis_active(dev))
#define DEFAULT_QLEN	2	/* double buffering by default */
#define	HS_BPS		(13 * 512 * 8 * 1000 * 8)
#define	FS_BPS		(19 *  64 * 1 * 1000 * 8)
#ifdef CONFIG_USB_GADGET_DUALSPEED
#define	DEVSPEED	USB_SPEED_HIGH
#ifdef CONFIG_USB_ETH_QMULT
#define qmult CONFIG_USB_ETH_QMULT
#else
#define qmult 5
#endif
#define qlen(gadget) \
#else	/* full speed (low speed doesn't do bulk) */
#define qmult		1
#define	DEVSPEED	USB_SPEED_FULL
#define qlen(gadget) DEFAULT_QLEN
#endif
#define CDC_VENDOR_NUM		0x0525	/* NetChip */
#define CDC_PRODUCT_NUM		0xa4a1	/* Linux-USB Ethernet Gadget */
#define	SIMPLE_VENDOR_NUM	0x049f	/* Compaq Computer Corp. */
#define	SIMPLE_PRODUCT_NUM	0x505a	/* Linux-USB "CDC Subset" Device */
#define RNDIS_VENDOR_NUM	0x0525	/* NetChip */
#define RNDIS_PRODUCT_NUM	0xa4a2	/* Ethernet/RNDIS Gadget */
#if defined(CONFIG_USB_GADGET_MANUFACTURER)
#else
#endif
#define STRING_MANUFACTURER		1
#define STRING_PRODUCT			2
#define STRING_ETHADDR			3
#define STRING_DATA			4
#define STRING_CONTROL			5
#define STRING_RNDIS_CONTROL		6
#define STRING_CDC			7
#define STRING_SUBSET			8
#define STRING_RNDIS			9
#define STRING_SERIALNUMBER		10
#define USB_BUFSIZ	256
#define DEV_CONFIG_VALUE	1	/* cdc or subset */
#define DEV_RNDIS_CONFIG_VALUE	2	/* rndis; optional */
#ifdef	CONFIG_USB_ETH_RNDIS
#endif
#ifdef	CONFIG_USB_ETH_CDC
#endif
#ifdef	CONFIG_USB_ETH_RNDIS
#endif
#if defined(CONFIG_USB_ETH_CDC) || defined(CONFIG_USB_ETH_RNDIS)
#endif	/* CDC || RNDIS */
#ifdef	CONFIG_USB_ETH_RNDIS
#endif
#ifndef CONFIG_USB_ETH_CDC
#ifdef CONFIG_USB_ETH_SUBSET
#endif
#endif
#if defined(CONFIG_USB_ETH_CDC) || defined(CONFIG_USB_ETH_RNDIS)
#define LOG2_STATUS_INTERVAL_MSEC	5	/* 1 << 5 == 32 msec */
#define STATUS_BYTECOUNT		16	/* 8 byte header + data */
#endif
#ifdef	CONFIG_USB_ETH_CDC
#endif
#ifdef	CONFIG_USB_ETH_RNDIS
#endif
#ifdef CONFIG_USB_ETH_SUBSET
#endif	/* SUBSET */
#ifdef CONFIG_USB_ETH_CDC
#endif /* CONFIG_USB_ETH_CDC */
#ifdef CONFIG_USB_ETH_SUBSET
#else
#endif
#ifdef	CONFIG_USB_ETH_RNDIS
#endif
#if defined(CONFIG_USB_ETH_CDC) || defined(CONFIG_USB_ETH_RNDIS)
#endif /* CONFIG_USB_ETH_CDC */
#ifdef CONFIG_USB_ETH_CDC
#endif /* CONFIG_USB_ETH_CDC */
#ifdef CONFIG_USB_ETH_SUBSET
#else
#endif
#ifdef	CONFIG_USB_ETH_RNDIS
#endif
#ifdef	CONFIG_USB_ETH_CDC
#endif
#ifdef	CONFIG_USB_ETH_SUBSET
#endif
#ifdef	CONFIG_USB_ETH_RNDIS
#endif
#if defined(CONFIG_USB_ETH_CDC) || defined(CONFIG_USB_ETH_RNDIS)
#endif
#define which_fn(t)	(hs ? hs_ ## t ## _function : fs_ ## t ## _function)
#ifdef	CONFIG_USB_ETH_RNDIS
#endif
#if defined(CONFIG_USB_ETH_CDC) || defined(CONFIG_USB_ETH_RNDIS)
#endif
#ifdef	CONFIG_USB_ETH_RNDIS
#endif
#ifdef CONFIG_USB_GADGET_DUALSPEED
#endif
#ifdef	CONFIG_USB_ETH_CDC
#endif
#ifdef CONFIG_USB_ETH_RNDIS
#endif	/* RNDIS */
#ifdef CONFIG_USB_ETH_CDC
#else
#endif /* CONFIG_USB_ETH_CDC */
#ifdef CONFIG_USB_ETH_CDC
#endif /* CONFIG_USB_ETH_CDC */
#ifdef CONFIG_USB_ETH_RNDIS
#endif	/* RNDIS */
#if 0
#endif
#ifdef CONFIG_USB_ETH_RNDIS
#ifndef CONFIG_DM_ETH
#else
#endif
#else
#define	rndis_control_ack	NULL
#endif	/* RNDIS */
#ifdef RNDIS_COMPLETE_SIGNAL_DISCONNECT
#endif
#ifdef RNDIS_COMPLETE_SIGNAL_DISCONNECT
#endif
#ifdef CONFIG_DM_ETH
#endif
#ifndef	CONFIG_USB_ETH_CDC
#endif
#ifndef	CONFIG_USB_ETH_RNDIS
#endif
#if defined(CONFIG_USB_GADGET_VENDOR_NUM) && defined(CONFIG_USB_GADGET_PRODUCT_NUM)
#else
#endif
#if defined(CONFIG_USB_GADGET_VENDOR_NUM) && defined(CONFIG_USB_GADGET_PRODUCT_NUM)
#else
#endif
#if defined(CONFIG_USB_ETH_CDC) || defined(CONFIG_USB_ETH_RNDIS)
#ifdef CONFIG_USB_ETH_CDC
#endif
#endif
#if defined(CONFIG_USB_ETH_CDC) || defined(CONFIG_USB_ETH_RNDIS)
#endif
#ifdef	CONFIG_USB_ETH_RNDIS
#endif
#ifndef CONFIG_DM_ETH
#else
#endif
#ifndef CONFIG_DM_ETH
#else
#endif
#if defined(CONFIG_USB_ETH_CDC) || defined(CONFIG_USB_ETH_RNDIS)
#endif
#ifndef CONFIG_DM_ETH
#else
#endif
#ifdef CONFIG_USBNET_DEV_ADDR
#endif
#ifdef CONFIG_USBNET_HOST_ADDR
#endif
#if 0
#endif
#ifndef CONFIG_DM_ETH
#else
#endif /* CONFIG_DM_ETH */
