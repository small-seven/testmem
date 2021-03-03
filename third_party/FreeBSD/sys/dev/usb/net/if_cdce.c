#include <sys/cdefs.h>
#include "los_crc32.h"
#include "implementation/global_implementation.h"
#include "usb_ethernet.h"
#include "if_cdcereg.h"
#if CDCE_HAVE_NCM
#endif
#undef USB_DEBUG_VAR
#define	USB_DEBUG_VAR	cdce_debug
#ifdef LOSCFG_USB_DEBUG
#endif
#if CDCE_HAVE_NCM
#endif
#if CDCE_HAVE_NCM
#endif
#if CDCE_HAVE_NCM
#endif
cdce_detach(device_t dev)
{
	struct cdce_softc *sc = (struct cdce_softc *)device_get_softc(dev);
	struct usb_ether *ue = &sc->sc_ue;

	/* stop all USB transfers first */
	usbd_transfer_unsetup(sc->sc_xfer, CDCE_N_TRANSFER);
	uether_ifdetach(ue);
	mtx_destroy(&sc->sc_mtx);

	return (0);
}
cdce_free_queue(struct pbuf **ppm, uint8_t n)
{
	uint8_t x;
	for (x = 0; x != n; x++) {
		if (ppm[x] != NULL) {
			uether_freebuf(ppm[x]);
			ppm[x] = NULL;
		}
	}
}
#if CDCE_HAVE_NCM
#ifdef LOSCFG_USB_DEBUG
#endif
#endif
#undef USB_DEBUG_VAR
