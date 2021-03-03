#include <los_memory.h>
#include "implementation/global_implementation.h"
#undef USB_DEBUG_VAR
#define USB_DEBUG_VAR   usb_debug
usb_linux_detach(device_t dev)
{
	struct usb_linux_softc *sc = device_get_softc(dev);
	struct usb_driver *udrv = NULL;

	mtx_lock(&Giant);
	if (sc == NULL) {
		mtx_unlock(&Giant);
		return (-1);
	}
	if (sc->sc_attached_list.le_prev) {
		LIST_REMOVE(sc, sc_attached_list);
		sc->sc_attached_list.le_prev = NULL;
		udrv = sc->sc_udrv;
		sc->sc_udrv = NULL;
	}
	mtx_unlock(&Giant);

	if (udrv && udrv->disconnect) {
		(udrv->disconnect) (sc->sc_ui);
	}
	/*
	 * Make sure that we free all FreeBSD USB transfers belonging to
	 * this Linux "usb_interface", hence they will most likely not be
	 * needed any more.
	 */
	usb_linux_cleanup_interface(sc->sc_fbsd_udev, sc->sc_ui);
	return (0);
}
usb_linux_create_usb_device(struct usb_device *udev, device_t dev)
{
	struct usb_config_descriptor *cd = usbd_get_config_descriptor(udev);
	struct usb_descriptor *desc;
	struct usb_interface_descriptor *id;
	struct usb_endpoint_descriptor *ed;
	struct usb_interface *p_ui = NULL;
	struct usb_host_interface *p_uhi = NULL;
	struct usb_host_endpoint *p_uhe = NULL;
	usb_size_t size;
	uint16_t niface_total;
	uint16_t nedesc;
	uint16_t iface_no_curr;
	uint16_t iface_index;
	uint8_t pass;
	uint8_t iface_no;

	/*
	 * We do two passes. One pass for computing necessary memory size
	 * and one pass to initialize all the allocated memory structures.
	 */
	for (pass = 0; pass < 2; pass++) {

		iface_no_curr = 0xFFFF;
		niface_total = 0;
		iface_index = 0;
		nedesc = 0;
		desc = NULL;

		/*
		 * Iterate over all the USB descriptors. Use the USB config
		 * descriptor pointer provided by the FreeBSD USB stack.
		 */
		while ((desc = usb_desc_foreach(cd, desc))) {
			/*
			 * Build up a tree according to the descriptors we
			 * find:
			 */
			switch (desc->bDescriptorType) {
			case UDESC_DEVICE:
				break;

			case UDESC_ENDPOINT:
				ed = (void *)desc;
				if ((ed->bLength < sizeof(*ed)) ||
				    (iface_index == 0))
					break;
				if (p_uhe != NULL) {
					usb_bcopy(ed, &p_uhe->desc, sizeof(p_uhe->desc));
					p_uhe->bsd_iface_index = iface_index - 1;
					TAILQ_INIT(&p_uhe->bsd_urb_list);
					p_uhe++;
				}
				if (p_uhi != NULL) {
					(p_uhi - 1)->desc.bNumEndpoints++;
				}
				nedesc++;
				break;

			case UDESC_INTERFACE:
				id = (void *)desc;
				if (id->bLength < sizeof(*id))
					break;
				if (p_uhi != NULL) {
					usb_bcopy(id, &p_uhi->desc, sizeof(p_uhi->desc));
					p_uhi->desc.bNumEndpoints = 0;
					p_uhi->endpoint = p_uhe;
					p_uhi->string = "";
					p_uhi->bsd_iface_index = iface_index;
					p_uhi++;
				}
				iface_no = id->bInterfaceNumber;
				niface_total++;
				if (iface_no_curr != iface_no) {
					if (p_ui) {
						p_ui->altsetting = p_uhi - 1;
						p_ui->cur_altsetting = p_uhi - 1;
						p_ui->num_altsetting = 1;
						p_ui->bsd_iface_index = iface_index;
						p_ui->linux_udev = udev;
						p_ui++;
					}
					iface_no_curr = iface_no;
					iface_index++;
				} else {
					if (p_ui) {
						(p_ui - 1)->num_altsetting++;
					}
				}
				break;

			default:
				break;
			}
		}

		if (pass == 0) {
			size = (sizeof(*p_uhe) * nedesc) +
			    (sizeof(*p_ui) * iface_index) +
			    (sizeof(*p_uhi) * niface_total);

			p_uhe = zalloc(size);
			if (p_uhe == NULL) {
				return (-1);
			}
			p_ui = (void *)(p_uhe + nedesc);
			p_uhi = (void *)(p_ui + iface_index);

			udev->linux_iface_start = p_ui;
			udev->linux_iface_end = p_ui + iface_index;
			udev->linux_endpoint_start = p_uhe;
			udev->linux_endpoint_end = p_uhe + nedesc;
			udev->devnum = device_get_unit(dev);
			usb_bcopy(&udev->ddesc, &udev->descriptor,
			    sizeof(udev->descriptor));
			usb_bcopy(udev->ctrl_ep.edesc, &udev->ep0.desc,
			    sizeof(udev->ep0.desc));
		}
	}
	return (0);
}
usb_alloc_urb(uint16_t iso_packets, uint16_t mem_flags)
{
	struct urb *urb;
	usb_size_t size;

	if (iso_packets == 0xFFFF) {
		/*
		 * FreeBSD specific magic value to ask for control transfer
		 * memory allocation:
		 */
		size = sizeof(*urb) + sizeof(struct usb_device_request) + mem_flags;
	} else {
		size = sizeof(*urb) + (iso_packets * sizeof(urb->iso_frame_desc[0]));
	}

	urb = (struct urb *)zalloc(size);
	if (urb) {
		cv_init(&urb->cv_wait, "URBWAIT");
		if (iso_packets == 0xFFFF) {
			urb->setup_packet = (void *)(urb + 1);
			urb->transfer_buffer = (void *)(urb->setup_packet +
			    sizeof(struct usb_device_request));
		} else {
			urb->number_of_packets = iso_packets;
		}
	} else {
		dprintf("Malloc failed in %s %d\n", __FUNCTION__, __LINE__);
	}

	return (urb);
}
usb_buffer_alloc(struct usb_device *dev, usb_size_t size, uint16_t mem_flags, uint8_t *dma_addr)
{
	return (zalloc(size));
}
usb_linux_free_device(struct usb_device *dev)
{
	struct usb_host_endpoint *uhe;
	struct usb_host_endpoint *uhe_end;
	int err;

	uhe = dev->linux_endpoint_start;
	uhe_end = dev->linux_endpoint_end;
	while (uhe != uhe_end) {
		err = usb_setup_endpoint(dev, uhe, 0);
		if (err != 0)
			DPRINTF("Error in %s, %d\n", __FUNCTION__, __LINE__);
		uhe++;
	}
	err = usb_setup_endpoint(dev, &dev->ep0, 0);
	if (err != 0)
		DPRINTF("Error in %s, %d\n", __FUNCTION__, __LINE__);
	free(dev->linux_endpoint_start);
	dev->linux_endpoint_start = NULL;
}
usb_buffer_free(struct usb_device *dev, usb_size_t size,
    void *addr, uint8_t dma_addr)
{
	free(addr);
}
usb_free_urb(struct urb *urb)
{
	if (urb == NULL) {
		return;
	}
	/* make sure that the current URB is not active */
	usb_kill_urb(urb);

	/* destroy condition variable */
	cv_destroy(&urb->cv_wait);

	/* just free it */
	free(urb);
}
usb_linux_cleanup_interface(struct usb_device *dev, struct usb_interface *iface)
{
	struct usb_host_interface *uhi;
	struct usb_host_interface *uhi_end;
	struct usb_host_endpoint *uhe;
	struct usb_host_endpoint *uhe_end;
	int err;

	uhi = iface->altsetting;
	uhi_end = iface->altsetting + iface->num_altsetting;
	while (uhi != uhi_end) {
		uhe = uhi->endpoint;
		uhe_end = uhi->endpoint + uhi->desc.bNumEndpoints;
		while (uhe != uhe_end) {
			err = usb_setup_endpoint(dev, uhe, 0);
			if (err != 0)
				DPRINTF("Error in %s, %d\n", __FUNCTION__, __LINE__);
			uhe++;
		}
		uhi++;
	}
}
usb_alloc_dma(int length)
{
	return memalign(USB_CACHE_ALIGN_SIZE, SKB_DATA_ALIGN(length));
}
usb_free_dma(char* buf)
{
	free(buf);
}
#undef USB_DEBUG_VAR
