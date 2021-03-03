#include "implementation/global_implementation.h"
#include "controller/xhci.h"
#include "controller/xhcireg.h"
xhci_pci_detach(device_t self)
{

	struct xhci_softc *sc = device_get_softc(self);

	/* during module unload there are lots of children leftover */
	(void)device_delete_children(self);

	callout_drain(&sc->sc_callout);
	(void)xhci_halt_controller(sc);
	(void)xhci_reset_controller(sc);

	// release resouce
	if (sc->sc_irq_res) {
		(void)bus_teardown_intr(sc->sc_irq_res->start, sc);
		sc->sc_irq_res = NULL;
	}
	if (sc->sc_io_res) {
		iounmap((void *)sc->sc_io_res);
		sc->sc_io_res = NULL;
		sc->sc_io_tag = NULL;
		sc->sc_io_hdl = (uintptr_t)NULL;
		sc->sc_io_size = 0;
	}

	xhci_uninit(sc);

	return (0);
}
