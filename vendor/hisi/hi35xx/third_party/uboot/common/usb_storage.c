#include <common.h>
#include <command.h>
#include <dm.h>
#include <errno.h>
#include <mapmem.h>
#include <memalign.h>
#include <asm/byteorder.h>
#include <asm/processor.h>
#include <dm/device-internal.h>
#include <dm/lists.h>
#include <part.h>
#include <usb.h>
#undef BBB_COMDAT_TRACE
#undef BBB_XPORT_TRACE
#include <scsi.h>
#define US_DIRECTION(x) ((us_direction[x>>3] >> (x & 7)) & 1)
#if !CONFIG_IS_ENABLED(BLK)
#endif
typedef int (*trans_cmnd)(struct scsi_cmd *cb, struct us_data *data);
typedef int (*trans_reset)(struct us_data *data);

struct us_data {
	struct usb_device *pusb_dev;	 /* this usb_device */

	unsigned int	flags;			/* from filter initially */
#	define USB_READY	(1 << 0)
	unsigned char	ifnum;			/* interface number */
	unsigned char	ep_in;			/* in endpoint */
	unsigned char	ep_out;			/* out ....... */
	unsigned char	ep_int;			/* interrupt . */
	unsigned char	subclass;		/* as in overview */
	unsigned char	protocol;		/* .............. */
	unsigned char	attention_done;		/* force attn on first cmd */
	unsigned short	ip_data;		/* interrupt data */
	int		action;			/* what to do */
	int		ip_wanted;		/* needed */
	int		*irq_handle;		/* for USB int requests */
	unsigned int	irqpipe;	 	/* pipe for release_irq */
	unsigned char	irqmaxp;		/* max packed for irq Pipe */
	unsigned char	irqinterval;		/* Intervall for IRQ Pipe */
	struct scsi_cmd	*srb;			/* current srb */
	trans_reset	transport_reset;	/* reset routine */
	trans_cmnd	transport;		/* transport routine */
	unsigned short	max_xfer_blk;		/* maximum transfer blocks */
};
#if !CONFIG_IS_ENABLED(BLK)
#endif
#define USB_STOR_TRANSPORT_GOOD	   0
#define USB_STOR_TRANSPORT_FAILED -1
#define USB_STOR_TRANSPORT_ERROR  -2
#if CONFIG_IS_ENABLED(BLK)
#else
#endif
#if CONFIG_IS_ENABLED(BLK)
#else
#endif
#if CONFIG_IS_ENABLED(BLK)
#else
#endif
#if CONFIG_IS_ENABLED(BLK)
#else
#endif
#if !CONFIG_IS_ENABLED(DM_USB)
#endif
#ifdef	DEBUG
#endif
#ifdef DEBUG
#endif
#ifdef BBB_COMDAT_TRACE
#endif
#ifdef DEBUG
#endif
#define USB_TRANSPORT_UNKNOWN_RETRY 5
#define USB_TRANSPORT_NOT_READY_RETRY 10
#ifdef BBB_XPORT_TRACE
#endif
#ifdef BBB_XPORT_TRACE
#endif
#ifdef BBB_XPORT_TRACE
#endif
#if CONFIG_IS_ENABLED(DM_USB)
#endif
#ifdef CONFIG_USB_BIN_FIXUP
#endif /* CONFIG_USB_BIN_FIXUP */
#if CONFIG_IS_ENABLED(BLK)
#else
#endif
#if CONFIG_IS_ENABLED(BLK)
#endif
#if CONFIG_IS_ENABLED(BLK)
#else
#endif
#if CONFIG_IS_ENABLED(BLK)
#else
#endif
#if CONFIG_IS_ENABLED(BLK)
#endif
#if CONFIG_IS_ENABLED(BLK)
#else
#endif
#ifdef CONFIG_USB_BIN_FIXUP
#endif /* CONFIG_USB_BIN_FIXUP */
#if 0
#endif
#if CONFIG_IS_ENABLED(DM_USB)
#if CONFIG_IS_ENABLED(BLK)
#endif
#endif
#if CONFIG_IS_ENABLED(BLK)
#else
#endif
