#include <sys/cdefs.h>
#include <lwip/netif.h>
#include <lwip/dhcp.h>
#include <lwip/netifapi.h>
#include <lwip/inet.h>
#include "if_urndisreg.h"
#undef USB_DEBUG_VAR
#define	USB_DEBUG_VAR   urndis_debug
#ifdef LOSCFG_USB_DEBUG
#endif
urndis_detach(device_t dev)
{
	struct urndis_softc *sc = device_get_softc(dev);
	struct usb_ether *ue = &sc->sc_ue;

	/* stop all USB transfers first */
	usbd_transfer_unsetup(sc->sc_xfer, URNDIS_N_TRANSFER);

	uether_ifdetach(ue);

	URNDIS_LOCK(sc);
	(void)urndis_ctrl_halt(sc);
	URNDIS_UNLOCK(sc);

	mtx_destroy(&sc->sc_mtx);

	return (0);
}
#define		OFFSET_OF(type, field) \
#undef USB_DEBUG_VAR
