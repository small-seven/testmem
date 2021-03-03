#include <los_queue.h>
#include "implementation/global_implementation.h"
#include "implementation/usbdevs.h"
#include "usb_serial.h"
#undef USB_DEBUG_VAR
#define	USB_DEBUG_VAR   u3g_debug
#ifdef LOSCFG_USB_DEBUG
#endif
#define	U3G_MAXPORTS		12
#define	U3G_CONFIG_INDEX	1
#define	U3G_BSIZE		2048
#define	U3G_TXSIZE		(U3G_BSIZE / U3G_TXFRAMES)
#define	U3G_TXFRAMES		4
#define	U3GSP_GPRS		0
#define	U3GSP_EDGE		1
#define	U3GSP_CDMA		2
#define	U3GSP_UMTS		3
#define	U3GSP_HSDPA		4
#define	U3GSP_HSUPA		5
#define	U3GSP_HSPA		6
#define	U3GSP_MAX		7
#define	U3GINIT_HUAWEI		1	/* Requires Huawei init command */
#define	U3GINIT_SIERRA		2	/* Requires Sierra init command */
#define	U3GINIT_SCSIEJECT	3	/* Requires SCSI eject command */
#define	U3GINIT_REZERO		4	/* Requires SCSI rezero command */
#define	U3GINIT_ZTESTOR		5	/* Requires ZTE SCSI command */
#define	U3GINIT_CMOTECH		6	/* Requires CMOTECH SCSI command */
#define	U3GINIT_WAIT		7	/* Device reappears after a delay */
#define	U3GINIT_SAEL_M460	8	/* Requires vendor init */
#define	U3GINIT_HUAWEISCSI	9	/* Requires Huawei SCSI init command */
#define	 U3GINIT_HUAWEISCSI2 10
#define	 U3GINIT_HUAWEISCSI3 11
#define	U3GINIT_TCT		12		/* Requires TCT Mobile init command */
#define	U3G_DEV(v,p,i) { USB_VPI(USB_VENDOR_##v, USB_PRODUCT_##v##_##p, i) }
#undef	U3G_DEV
u3g_detach(device_t dev)
{
	struct u3g_softc *sc = (struct u3g_softc *)device_get_softc(dev);
	uint8_t subunit;

	DPRINTF("sc=%p\n", sc);

	/* NOTE: It is not dangerous to detach more ports than attached! */
	ucom_detach(&sc->sc_super_ucom, sc->sc_ucom);

	for (subunit = 0; subunit != U3G_MAXPORTS; subunit++)
		usbd_transfer_unsetup(sc->sc_xfer[subunit], U3G_N_TRANSFER);

	if (ucom_unref(&sc->sc_super_ucom)) {
		mtx_destroy(&sc->sc_mtx);
	}

	return (0);
}
u3g_free_softc(struct u3g_softc *sc)
{
	if (ucom_unref(&sc->sc_super_ucom)) {
		mtx_destroy(&sc->sc_mtx);
		free(sc);
	}
}
u3g_free(struct ucom_softc *ucom)
{
	u3g_free_softc((struct u3g_softc *)ucom->sc_parent);
}
#undef USB_DEBUG_VAR
