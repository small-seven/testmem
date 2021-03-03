#include <sys/cdefs.h>
#include <lwip/netif.h>
#include <lwip/dhcp.h>
#include <lwip/netifapi.h>
#include <lwip/inet.h>
#include "implementation/global_implementation.h"
#include "usb_ethernet.h"
#include "if_axgereg.h"
#define	IFF_DRV_OACTIVE  IFF_MASTER
#define	IFF_SIMPLEX	  IFF_SLAVE
#undef USB_DEBUG_VAR
#define	USB_DEBUG_VAR   axge_debug
#ifdef LOSCFG_USB_DEBUG
#endif
axge_write_mem(struct axge_softc *sc, uint8_t cmd, uint16_t index,
			    uint16_t val, void *buf, unsigned int len)
{
	struct usb_device_request req;

	req.bmRequestType = UT_WRITE_VENDOR_DEVICE;
	req.bRequest = cmd;
	USETW(req.wValue, val);
	USETW(req.wIndex, index);
	USETW(req.wLength, len);

	if (uether_do_request(&sc->sc_ue, &req, buf, 1000)) {
		/* Error ignored. */
	}
}
axge_read_mem(struct axge_softc *sc, uint8_t cmd, uint16_t index,
			    uint16_t val, void *buf, int len)
{
	struct usb_device_request req;

	AXGE_LOCK_ASSERT(sc, MA_OWNED);

	req.bmRequestType = UT_READ_VENDOR_DEVICE;
	req.bRequest = cmd;
	USETW(req.wValue, val);
	USETW(req.wIndex, index);
	USETW(req.wLength, len);

	return (uether_do_request(&sc->sc_ue, &req, buf, 1000));
}
axge_detach(device_t dev)
{
	struct axge_softc *sc = device_get_softc(dev);
	struct usb_ether *ue = &sc->sc_ue;

	usbd_transfer_unsetup(sc->sc_xfer, AXGE_N_TRANSFER);
	uether_ifdetach(ue);
	mtx_destroy(&sc->sc_mtx);

	return (0);
}
#if ETH_PAD_SIZE
#endif
#if ETH_PAD_SIZE
#endif
#undef USB_DEBUG_VAR
