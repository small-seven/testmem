#include <sys/cdefs.h>
#include "implementation/global_implementation.h"
#include "input/usb_rdesc.h"
#include "implementation/usbdevs.h"
#undef USB_DEBUG_VAR
#define	USB_DEBUG_VAR uhid_debug
#ifdef LOSCFG_USB_DEBUG
#endif
#define	UHID_BSIZE	1024		/* bytes, buffer size */
#define	UHID_FRAME_NUM 	  50		/* bytes, frame number */
#define	UHID_FLAG_IMMED        0x01	/* set if read should be immediate */
#define	UHID_FLAG_STATIC_DESC  0x04	/* set if report descriptors are
uhid_detach(device_t dev)
{
	struct uhid_softc *sc = device_get_softc(dev);

	usb_fifo_detach(&sc->sc_fifo);

	usbd_transfer_unsetup(sc->sc_xfer, UHID_N_TRANSFER);

	if (sc->sc_repdesc_ptr) {
		if (!(sc->sc_flags & UHID_FLAG_STATIC_DESC)) {
			free(sc->sc_repdesc_ptr);
		}
	}
	mtx_destroy(&sc->sc_mtx);

	return (0);
}
