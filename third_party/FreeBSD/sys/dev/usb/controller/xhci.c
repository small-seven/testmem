#include "implementation/global_implementation.h"
#include "controller/xhci.h"
#include "controller/xhcireg.h"
#define XHCI_BUS2SC(bus) \
#ifdef USB_DEBUG
#else
#define xhciroute 0
#define xhcidma32 0
#define xhcictlstep 0
#endif
#ifndef USB_DEBUG_VAR
#define USB_DEBUG_VAR xhcidebug
#endif
#define XHCI_INTR_ENDPT 1
#define XHCI_DO_CMD_TIMEOUT  1000
#ifdef USB_DEBUG
#endif
#ifdef USB_DEBUG
#endif
#ifdef USB_DEBUG
#else
#endif
#ifdef USB_DEBUG
#endif
xhci_uninit(struct xhci_softc *sc)
{
	/*
	 * NOTE: At this point the control transfer process is gone
	 * and "xhci_configure_msg" is no longer called. Consequently
	 * waiting for the configuration messages to complete is not
	 * needed.
	 */
	usb_bus_mem_free_all(&sc->sc_bus, &xhci_iterate_hw_softc);

	cv_destroy(&sc->sc_cmd_cv);
	sx_destroy(&sc->sc_cmd_sx);
}
#ifdef USB_DEBUG
#endif
#ifdef USB_DEBUG
#endif
#ifdef USB_DEBUG
#endif
#ifdef USB_DEBUG
#endif
#ifdef USB_DEBUG
#endif
xhci_alloc_device_ext(struct usb_device *udev)
{
	struct xhci_softc *sc = XHCI_BUS2SC(udev->bus);
	struct usb_page_search buf_dev;
	struct usb_page_search buf_ep;
	struct xhci_trb *trb;
	struct usb_page_cache *pc;
	struct usb_page *pg;
	uint64_t addr;
	uint8_t index;
	uint8_t i;

	index = udev->controller_slot_id;

	pc = &sc->sc_hw.devs[index].device_pc;
	pg = &sc->sc_hw.devs[index].device_pg;

	/* need to initialize the page cache */
	pc->tag_parent = sc->sc_bus.dma_parent_tag;

	if (usb_pc_alloc_mem(pc, pg, sc->sc_ctx_is_64_byte ?
	    (2 * sizeof(struct xhci_dev_ctx)) :
	    sizeof(struct xhci_dev_ctx), XHCI_PAGE_SIZE))
		goto error;

	usbd_get_page(pc, 0, &buf_dev);

	pc = &sc->sc_hw.devs[index].input_pc;
	pg = &sc->sc_hw.devs[index].input_pg;

	/* need to initialize the page cache */
	pc->tag_parent = sc->sc_bus.dma_parent_tag;

	if (usb_pc_alloc_mem(pc, pg, sc->sc_ctx_is_64_byte ?
	    (2 * sizeof(struct xhci_input_dev_ctx)) :
	    sizeof(struct xhci_input_dev_ctx), XHCI_PAGE_SIZE)) {
		goto error;
	}

	/* initialize all endpoint LINK TRBs */

	for (i = 0; i != XHCI_MAX_ENDPOINTS; i++) {

		pc = &sc->sc_hw.devs[index].endpoint_pc[i];
		pg = &sc->sc_hw.devs[index].endpoint_pg[i];

		/* need to initialize the page cache */
		pc->tag_parent = sc->sc_bus.dma_parent_tag;

		if (usb_pc_alloc_mem(pc, pg,
		    sizeof(struct xhci_dev_endpoint_trbs), XHCI_TRB_ALIGN)) {
			goto error;
		}

		/* lookup endpoint TRB ring */
		usbd_get_page(pc, 0, &buf_ep);

		/* get TRB pointer */
		trb = buf_ep.buffer;
		trb += XHCI_MAX_TRANSFERS - 1;

		/* get TRB start address */
		addr = buf_ep.physaddr;

		/* create LINK TRB */
		trb->qwTrb0 = htole64(addr);
		trb->dwTrb2 = htole32(XHCI_TRB_2_IRQ_SET(0));
		trb->dwTrb3 = htole32(XHCI_TRB_3_CYCLE_BIT |
		    XHCI_TRB_3_TYPE_SET(XHCI_TRB_TYPE_LINK));

		usb_pc_cpu_flush(pc);
	}

	xhci_set_slot_pointer(sc, index, buf_dev.physaddr);

	return (USB_ERR_NORMAL_COMPLETION);

error:
	xhci_free_device_ext(udev);

	return (USB_ERR_NOMEM);
}
xhci_free_device_ext(struct usb_device *udev)
{
	struct xhci_softc *sc = XHCI_BUS2SC(udev->bus);
	uint8_t index;
	uint8_t i;

	index = udev->controller_slot_id;
	xhci_set_slot_pointer(sc, index, 0);

	usb_pc_free_mem(&sc->sc_hw.devs[index].device_pc);
	usb_pc_free_mem(&sc->sc_hw.devs[index].input_pc);
	for (i = 0; i != XHCI_MAX_ENDPOINTS; i++)
		usb_pc_free_mem(&sc->sc_hw.devs[index].endpoint_pc[i]);
}
xhci_transfer_remove(struct usb_xfer *xfer, usb_error_t error)
{
	struct xhci_endpoint_ext *pepext;

	if (xfer->flags_int.bandwidth_reclaimed) {
		xfer->flags_int.bandwidth_reclaimed = 0;

		pepext = xhci_get_endpoint_ext(xfer->xroot->udev,
		    xfer->endpoint->edesc);

		pepext->trb_used[xfer->stream_id]--;

		pepext->xfer[xfer->qh_pos] = NULL;

		if (error && (pepext->trb_running != 0)) {
			pepext->trb_halted = 1;
			pepext->trb_running = 0;
		}
	}
}
#ifdef USB_DEBUG
#endif
#ifdef USB_DEBUG
#endif
#define	HSETW(ptr, val) ptr = { (uint8_t)(val), (uint8_t)((val) >> 8) }
#define	C(x,y) ((x) | ((y) << 8))
xhci_ep_uninit(struct usb_device *udev, struct usb_endpoint *ep)
{

}
xhci_device_uninit(struct usb_device *udev)
{
	struct xhci_softc *sc = XHCI_BUS2SC(udev->bus);
	uint8_t index;

	/* no init for root HUB */
	if (udev->parent_hub == NULL)
		return;

	XHCI_CMD_LOCK(sc);

	index = udev->controller_slot_id;

	if (index <= sc->sc_noslot) {
		(void)xhci_cmd_disable_slot(sc, index);
		sc->sc_hw.devs[index].state = XHCI_ST_DISABLED;

		/* free device extension */
		xhci_free_device_ext(udev);
	}

	XHCI_CMD_UNLOCK(sc);
}
