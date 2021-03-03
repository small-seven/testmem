#include <sys/cdefs.h>
#include <unistd.h>
#include <los_queue.h>
#ifdef LOSCFG_NET_LWIP_SACK
#include <lwip/netif.h>
#include <lwip/dhcp.h>
#include <lwip/netifapi.h>
#endif
#include "implementation/global_implementation.h"
#include "fs/fs.h"
#undef USB_DEBUG_VAR
#define	USB_DEBUG_VAR   ucom_debug
#ifdef LOSCFG_USB_DEBUG
#endif
#define	UCOM_CONS_BUFSIZE 1024
#ifndef CONFIG_DISABLE_POLL
#endif
#define	UCOM_UNIT_MAX		128	/* maximum number of units */
#define	UCOM_TTY_PREFIX		"U"
ucom_unit_free(int unit)
{
	return;
}
ucom_detach(struct ucom_super_softc *ssc, struct ucom_softc *sc)
{
	int subunit;

	if (!(ssc->sc_flag & UCOM_FLAG_ATTACHED))
		return;		/* not initialized */
	usb_proc_drain(&ssc->sc_tq);

	for (subunit = 0; subunit < ssc->sc_subunits; subunit++) {
		if (sc[subunit].sc_flag & UCOM_FLAG_ATTACHED) {

			ucom_detach_tty(ssc, &sc[subunit]);

			/* avoid duplicate detach */
			sc[subunit].sc_flag &= ~UCOM_FLAG_ATTACHED;
		}
	}

	tty_fd = -1;

	(void)u3g_tx_deinit();

	usb_proc_free(&ssc->sc_tq);

	free(ucom_cons_rx_buf);
	free(ucom_cons_tx_buf);
	ucom_cons_rx_buf = NULL;
	ucom_cons_tx_buf = NULL;

	(void)ucom_unref(ssc);

	if (ssc->sc_flag & UCOM_FLAG_WAIT_REFS)
		ucom_drain(ssc);

	/* make sure we don't detach twice */
	ssc->sc_flag &= ~UCOM_FLAG_ATTACHED;

	ucom_cons_softc = NULL;
}
ucom_detach_tty(struct ucom_super_softc *ssc, struct ucom_softc *sc)
{
	/* the config thread has been stopped when we get here */

	UCOM_MTX_LOCK(sc);
	sc->sc_flag |= UCOM_FLAG_GONE;
	sc->sc_flag &= ~(UCOM_FLAG_HL_READY | UCOM_FLAG_LL_READY);
	ucom_close(sc);	/* close, if any */
	UCOM_MTX_UNLOCK(sc);

	(void)unregister_driver(sc->sc_name);

	UCOM_MTX_LOCK(sc);
	/*
	 * make sure that read and write transfers are stopped
	 */
	if (sc->sc_callback->ucom_stop_read)
		(sc->sc_callback->ucom_stop_read) (sc);
	if (sc->sc_callback->ucom_stop_write)
		(sc->sc_callback->ucom_stop_write) (sc);
	UCOM_MTX_UNLOCK(sc);
}
ucom_free_unit(struct ucom_super_softc *ssc)
{
	if (!(ssc->sc_flag & UCOM_FLAG_FREE_UNIT))
		return;

	ucom_unit_free(ssc->sc_unit);

	ssc->sc_flag &= ~UCOM_FLAG_FREE_UNIT;
}
u3g_tx_deinit(VOID)
{
	UINT32 ret;

	ret = LOS_TaskDelete(g_u3g_tx_taskid);
	if (ret != LOS_OK) {
		return (ret);
	}

	ret = LOS_TaskDelete(g_u3g_rx_taskid);
	if (ret != LOS_OK) {
		return (ret);
	}

	ret = LOS_QueueDelete(m_uw_ucom_handler_queue);
	if (ret != LOS_OK) {
		return (ret);
	}

	return (LOS_OK);
}
#ifdef LOSCFG_NET_LWIP_SACK
#endif
#undef USB_DEBUG_VAR
