#include <sys/cdefs.h>
#include <lwip/netifapi.h>
#include "implementation/global_implementation.h"
#include "net/usb_ethernet.h"
#define	USE_LWIP_BUFFER 0
#define	IFQ_MAXLEN	50
if_alloc(void)
{
	struct los_eth_driver *sc;
	struct eth_drv_sc *drv_sc;

	sc = (struct los_eth_driver *)zalloc(sizeof(struct los_eth_driver));
	if (sc == NULL) {
		return (NULL);
	}

	drv_sc = (struct eth_drv_sc *)zalloc(sizeof(struct eth_drv_sc));
	if (drv_sc == NULL) {
		free(sc);
		return (NULL);
	}

	drv_sc->funs = (struct eth_hwr_funs*)zalloc(sizeof(struct eth_hwr_funs));
	if (drv_sc->funs == NULL) {
		PRINTK("could not allocate eth_hwr_funs\n");
		free(sc);
		free(drv_sc);
		return (NULL);
	}
	sc->driver_context = drv_sc;

	return (sc);
}
if_free(struct los_eth_driver * sc)
{
	struct eth_drv_sc *drv_sc;
	if (sc == NULL) {
		return;
	}

	drv_sc = (struct eth_drv_sc *)sc->driver_context;
	if (drv_sc != NULL) {
		if (drv_sc->funs) {
			free(drv_sc->funs);
			drv_sc->funs = NULL;
		}
		free(drv_sc);
		sc->driver_context = NULL;
		free(sc);
	}
}
uether_ifdetach(struct usb_ether *ue)
{
	struct los_eth_driver *sc;
	struct eth_drv_sc *drv_sc;
	struct pbuf *m;

	/* wait for any post attach or other command to complete */
	usb_proc_drain(&ue->ue_tq);

	/* read "ifnet" pointer after taskqueue drain */
	sc = ue->ue_drv_sc;
	if (sc != NULL) {
		drv_sc = ( struct eth_drv_sc *)sc->driver_context;
		/* we are not running any more */
		UE_LOCK(ue);
		drv_sc->state &= ~IFF_DRV_RUNNING;
		UE_UNLOCK(ue);

		/* drain any callouts */
		callout_drain(&ue->ue_watchdog);

		/* detach ethernet */
		for (;;) {
			UE_LOCK(ue);
			IF_DEQUEUE(&(ue->ue_txq), m);
			UE_UNLOCK(ue);
			if (m == NULL)
				break;
			uether_freebuf(m);
		}
		for (;;) {
			UE_LOCK(ue);
			IF_DEQUEUE(&(ue->ue_rxq), m);
			UE_UNLOCK(ue);
			if (m == NULL)
				break;
			uether_freebuf(m);
		}

		(void)netifapi_dhcp_stop(&sc->ac_if);
		(void)netifapi_dhcp_cleanup(&sc->ac_if);
		(void)netifapi_netif_remove(&sc->ac_if);

		/* free interface instance */
		if_free(sc);
		ue->ue_drv_sc = NULL;
	}

	/* free taskqueue, if any */
	usb_proc_free(&ue->ue_tq);

	(void)LOS_EventDestroy(&ue->ue_event);
}
#if USE_LWIP_BUFFER
#if ETH_PAD_SIZE
#endif
#else
uether_freebuf(struct pbuf *buf)
{
	if(buf != NULL) {
		if(buf->payload) {
			free(buf->payload);
			buf->payload = NULL;
		}
		free(buf);
	}
}
#endif
#if USE_LWIP_BUFFER
#if ETH_PAD_SIZE
#endif
#else
#endif
