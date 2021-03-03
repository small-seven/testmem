#include "implementation/global_implementation.h"
#include "linux/workqueue.h"
#if USB_HAVE_DEVICE_TOPOLOGY
#include "implementation/usb_btree.h"
#endif
#define	UHUB_DEBOUNCE_TIMEOUT 1500	/* ms */
#define	UHUB_DEBOUNCE_STEP 25		/* ms */
#define	UHUB_DEBOUNCE_STABLE 100	/* ms */
#define	UHUB_INTR_INTERVAL 250		/* ms */
#define	UHUB_DELAY_FOR_READY 2000	/* ms */
#if USB_HAVE_TT_SUPPORT
#endif
#undef USB_DEBUG_VAR
#define	USB_DEBUG_VAR uhub_debug
#ifdef LOSCFG_USB_DEBUG
#endif
#if USB_HAVE_POWERD
#endif
#if (USB_HAVE_FIXED_PORT != 0)
#endif
#define	UHUB_USB_PORT_ERRORS_MAX 4
#define	UHUB_FLAG_DID_EXPLORE 0x01
#define	UHUB_PROTO(sc) ((sc)->sc_udev->ddesc.bDeviceProtocol)
#define	UHUB_IS_HIGH_SPEED(sc) (UHUB_PROTO(sc) != UDPROTO_FSHUB)
#define	UHUB_IS_SINGLE_TT(sc) (UHUB_PROTO(sc) == UDPROTO_HSHUBSTT)
#define	UHUB_IS_MULTI_TT(sc) (UHUB_PROTO(sc) == UDPROTO_HSHUBMTT)
#define	UHUB_IS_SUPER_SPEED(sc) (UHUB_PROTO(sc) == UDPROTO_SSHUB)
#if USB_HAVE_TT_SUPPORT
#endif
#if USB_HAVE_TT_SUPPORT
#endif
#if USB_HAVE_TT_SUPPORT
#endif
#if USB_HAVE_TT_SUPPORT
#endif
#if USB_HAVE_TT_SUPPORT
#endif
#if defined (LOSCFG_DRIVERS_USB_HOST_EHCI) && defined (LOSCFG_DRIVERS_USB2_DEVICE_CONTROLLER)
#endif
#if defined (LOSCFG_DRIVERS_USB_HOST_EHCI) && defined (LOSCFG_DRIVERS_USB2_DEVICE_CONTROLLER)
#endif
#if defined (LOSCFG_DRIVERS_USB_HOST_EHCI) && defined (LOSCFG_DRIVERS_USB_DWC_DRIVER)
#endif
#if USB_HAVE_DEVICE_TOPOLOGY
#endif
#if (USB_HAVE_FIXED_PORT == 0)
#else
#endif
#if USB_HAVE_TT_SUPPORT
#endif
#if USB_HAVE_DEVICE_TOPOLOGY
#endif
#if USB_HAVE_DEVICE_TOPOLOGY
#endif
#if (USB_HAVE_FIXED_PORT == 0)
#endif
uhub_detach(device_t dev)
{
	struct uhub_softc *sc = device_get_softc(dev);
	struct usb_hub *hub;
	struct usb_bus *bus;
	struct usb_device *child;
	uint8_t x;
#if USB_HAVE_DEVICE_TOPOLOGY
	struct node_info cur_info, parent_info;
#endif

	if (sc == NULL)
		return -1;

	hub = sc->sc_udev->hub;
	bus = sc->sc_udev->bus;
	if (hub == NULL)		/* must be partially working */
		return (0);

#if USB_HAVE_DEVICE_TOPOLOGY
	parent_info.nameunit = device_get_nameunit(device_get_parent(dev));
	parent_info.port_no = sc->sc_udev->port_no;

	cur_info.nameunit = device_get_nameunit(dev);
	cur_info.port_no = 1;
	(void)usbd_remove_bt_node(hub_tree, &parent_info, &cur_info);
#endif

	/* Make sure interrupt transfer is gone. */
	usbd_transfer_unsetup(sc->sc_xfer, UHUB_N_TRANSFER);

	/* Detach all ports */
	for (x = 0; x != hub->nports; x++) {

		child = usb_bus_port_get_device(bus, hub->ports + x);

		if (child == NULL) {
			continue;
		}

		/*
		 * Free USB device and all subdevices, if any.
		 */
		usb_free_device(child, 0);
	}

#if USB_HAVE_TT_SUPPORT
	/* Make sure our TT messages are not queued anywhere */
	USB_BUS_LOCK(bus);
	usb_proc_mwait(USB_BUS_TT_PROC(bus),
	    &hub->tt_msg[0], &hub->tt_msg[1]);
	USB_BUS_UNLOCK(bus);
#endif

#if (USB_HAVE_FIXED_PORT == 0)
	bsd_free(hub, M_USBDEV);
#endif
	sc->sc_udev->hub = NULL;

	mtx_destroy(&sc->sc_mtx);

	return (0);
}
usb_hs_bandwidth_alloc(struct usb_xfer *xfer)
{
	struct usb_device *udev;
	uint8_t slot;
	uint8_t mask;
	uint8_t speed;

	udev = xfer->xroot->udev;

	if (udev->flags.usb_mode != USB_MODE_HOST)
		return;		/* not supported */

	xfer->endpoint->refcount_bw++;
	if (xfer->endpoint->refcount_bw != 1)
		return;		/* already allocated */

	speed = usbd_get_speed(udev);

	switch (xfer->endpoint->edesc->bmAttributes & UE_XFERTYPE) {
	case UE_INTERRUPT:
		/* allocate a microframe slot */

		mask = 0x01;
		slot = usb_hs_bandwidth_adjust(udev,
		    xfer->max_frame_size, USB_HS_MICRO_FRAMES_MAX, mask);

		xfer->endpoint->usb_uframe = slot;
		xfer->endpoint->usb_smask = mask << slot;

		if ((speed != USB_SPEED_FULL) &&
		    (speed != USB_SPEED_LOW)) {
			xfer->endpoint->usb_cmask = 0x00 ;
		} else {
			xfer->endpoint->usb_cmask = (-(0x04 << slot)) & 0xFE;
		}
		break;

	case UE_ISOCHRONOUS:
		switch (usbd_xfer_get_fps_shift(xfer)) {
		case 0:
			mask = 0xFF;
			break;
		case 1:
			mask = 0x55;
			break;
		case 2:
			mask = 0x11;
			break;
		default:
			mask = 0x01;
			break;
		}

		/* allocate a microframe multi-slot */

		slot = usb_hs_bandwidth_adjust(udev,
		    xfer->max_frame_size, USB_HS_MICRO_FRAMES_MAX, mask);

		xfer->endpoint->usb_uframe = slot;
		xfer->endpoint->usb_cmask = 0;
		xfer->endpoint->usb_smask = mask << slot;
		break;

	default:
		xfer->endpoint->usb_uframe = 0;
		xfer->endpoint->usb_cmask = 0;
		xfer->endpoint->usb_smask = 0;
		break;
	}

	DPRINTFN(11, "slot=%d, mask=0x%02x\n",
	    xfer->endpoint->usb_uframe,
	    xfer->endpoint->usb_smask >> xfer->endpoint->usb_uframe);
}
usb_hs_bandwidth_free(struct usb_xfer *xfer)
{
	struct usb_device *udev;
	uint8_t slot;
	uint8_t mask;

	udev = xfer->xroot->udev;

	if (udev->flags.usb_mode != USB_MODE_HOST)
		return;		/* not supported */

	xfer->endpoint->refcount_bw--;
	if (xfer->endpoint->refcount_bw != 0)
		return;		/* still allocated */

	switch (xfer->endpoint->edesc->bmAttributes & UE_XFERTYPE) {
	case UE_INTERRUPT:
	case UE_ISOCHRONOUS:

		slot = xfer->endpoint->usb_uframe;
		mask = xfer->endpoint->usb_smask;

		/* free microframe slot(s): */
		(void)usb_hs_bandwidth_adjust(udev,
		    -xfer->max_frame_size, slot, mask >> slot);

		DPRINTFN(11, "slot=%d, mask=0x%02x\n",
		    slot, mask >> slot);

		xfer->endpoint->usb_uframe = 0;
		xfer->endpoint->usb_cmask = 0;
		xfer->endpoint->usb_smask = 0;
		break;

	default:
		break;
	}
}
#if USB_HAVE_TT_SUPPORT
usbd_fs_isoc_schedule_alloc_slot(struct usb_xfer *isoc_xfer, uint16_t isoc_time)
{
	struct usb_xfer *xfer;
	struct usb_xfer *pipe_xfer;
	struct usb_bus *bus;
	usb_frlength_t len;
	usb_frlength_t data_len;
	uint16_t delta;
	uint16_t slot;
	uint8_t retval;

	data_len = 0;
	slot = 0;

	bus = isoc_xfer->xroot->bus;

	TAILQ_FOREACH(xfer, &bus->intr_q.head, wait_entry) {

		/* skip self, if any */

		if (xfer == isoc_xfer)
			continue;

		/* check if this USB transfer is going through the same TT */

		if (xfer->xroot->udev->parent_hs_hub !=
		    isoc_xfer->xroot->udev->parent_hs_hub) {
			continue;
		}
		if ((isoc_xfer->xroot->udev->parent_hs_hub->
		    ddesc.bDeviceProtocol == UDPROTO_HSHUBMTT) &&
		    (xfer->xroot->udev->hs_port_no !=
		    isoc_xfer->xroot->udev->hs_port_no)) {
			continue;
		}
		if (xfer->endpoint->methods != isoc_xfer->endpoint->methods)
			continue;

		/* check if isoc_time is part of this transfer */

		delta = xfer->isoc_time_complete - isoc_time;
		if ((delta > 0) && (delta <= xfer->nframes)) {
			delta = xfer->nframes - delta;

			len = xfer->frlengths[delta];
			len += 8;
			len *= 7;
			len /= 6;

			data_len += len;
		}

		/*
		 * Check double buffered transfers. Only stream ID
		 * equal to zero is valid here!
		 */
		TAILQ_FOREACH(pipe_xfer, &xfer->endpoint->endpoint_q[0].head,
		    wait_entry) {

			/* skip self, if any */

			if (pipe_xfer == isoc_xfer)
				continue;

			/* check if isoc_time is part of this transfer */

			delta = pipe_xfer->isoc_time_complete - isoc_time;
			if ((delta > 0) && (delta <= pipe_xfer->nframes)) {
				delta = pipe_xfer->nframes - delta;

				len = pipe_xfer->frlengths[delta];
				len += 8;
				len *= 7;
				len /= 6;

				data_len += len;
			}
		}
	}

	while (data_len >= USB_FS_BYTES_PER_HS_UFRAME) {
		data_len -= USB_FS_BYTES_PER_HS_UFRAME;
		slot++;
	}

	/* check for overflow */

	if (slot >= USB_FS_ISOC_UFRAME_MAX)
		return (255);

	retval = slot;

	delta = isoc_xfer->isoc_time_complete - isoc_time;
	if ((delta > 0) && (delta <= isoc_xfer->nframes)) {
		delta = isoc_xfer->nframes - delta;

		len = isoc_xfer->frlengths[delta];
		len += 8;
		len *= 7;
		len /= 6;

		data_len += len;
	}

	while (data_len >= USB_FS_BYTES_PER_HS_UFRAME) {
		data_len -= USB_FS_BYTES_PER_HS_UFRAME;
		slot++;
	}

	/* check for overflow */

	if (slot >= USB_FS_ISOC_UFRAME_MAX)
		return (255);

	return (retval);
}
#endif
#if USB_HAVE_UGEN
#endif
#if USB_HAVE_UGEN
#endif
#if USB_HAVE_POWERD
#endif
#if USB_HAVE_POWERD
#endif
#if USB_HAVE_POWERD
#endif
#if USB_HAVE_POWERD
#endif
#if USB_HAVE_POWERD
#else
#endif
#undef USB_DEBUG_VAR
