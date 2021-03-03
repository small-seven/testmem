#include <sys/cdefs.h>
#include <lwip/netif.h>
#include <lwip/dhcp.h>
#include <lwip/netifapi.h>
#include <lwip/inet.h>
#include "implementation/global_implementation.h"
#include "usb_ethernet.h"
#include "if_axereg.h"
#include "mii.h"
#define	AXE_178_MAX_FRAME_BURST	1
#define	AXE_CSUM_FEATURES		(CSUM_IP | CSUM_TCP | CSUM_UDP)
#undef USB_DEBUG_VAR
#define	USB_DEBUG_VAR	axe_debug
#ifdef LOSCFG_USB_DEBUG
#endif
#define	IFF_DRV_OACTIVE  IFF_MASTER
#define	IFF_SIMPLEX		IFF_SLAVE
#define	AXE_GPIO_WRITE(x, y)	do { \
#undef	AXE_GPIO_WRITE
axe_detach(device_t dev)
{
	struct axe_softc *sc = device_get_softc(dev);
	struct usb_ether *ue = &sc->sc_ue;

	usbd_transfer_unsetup(sc->sc_xfer, AXE_N_TRANSFER);
	uether_ifdetach(ue);
	mtx_destroy(&sc->sc_mtx);

	return (0);
}
#if (AXE_BULK_BUF_SIZE >= 0x10000)
#error "Please update axe_bulk_read_callback()!"
#endif
#if ETH_PAD_SIZE
#endif
#if ETH_PAD_SIZE
#endif
#if ((AXE_BULK_BUF_SIZE >= 0x10000) || (AXE_BULK_BUF_SIZE < (MCLBYTES+4)))
#error "Please update axe_bulk_write_callback()!"
#endif
#undef USB_DEBUG_VAR
