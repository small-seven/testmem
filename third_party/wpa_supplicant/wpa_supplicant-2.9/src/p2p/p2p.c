#include "includes.h"
#include "common.h"
#include "eloop.h"
#include "common/defs.h"
#include "common/ieee802_11_defs.h"
#include "common/ieee802_11_common.h"
#include "common/wpa_ctrl.h"
#include "crypto/sha256.h"
#include "crypto/crypto.h"
#include "wps/wps_i.h"
#include "p2p_i.h"
#include "p2p.h"
#define P2P_SCAN_TIMEOUT 35
#ifndef P2P_PEER_EXPIRATION_AGE
#define P2P_PEER_EXPIRATION_AGE 60
#endif /* P2P_PEER_EXPIRATION_AGE */
static void p2p_device_free(struct p2p_data *p2p, struct p2p_device *dev)
{
	int i;

	if (p2p->go_neg_peer == dev) {
		/*
		 * If GO Negotiation is in progress, report that it has failed.
		 */
		p2p_go_neg_failed(p2p, -1);
	}
	if (p2p->invite_peer == dev)
		p2p->invite_peer = NULL;
	if (p2p->sd_peer == dev)
		p2p->sd_peer = NULL;
	if (p2p->pending_client_disc_go == dev)
		p2p->pending_client_disc_go = NULL;

	/* dev_lost() device, but only if it was previously dev_found() */
	if (dev->flags & P2P_DEV_REPORTED_ONCE)
		p2p->cfg->dev_lost(p2p->cfg->cb_ctx,
				   dev->info.p2p_device_addr);

	for (i = 0; i < P2P_MAX_WPS_VENDOR_EXT; i++) {
		wpabuf_free(dev->info.wps_vendor_ext[i]);
		dev->info.wps_vendor_ext[i] = NULL;
	}

	wpabuf_free(dev->info.wfd_subelems);
	wpabuf_free(dev->info.vendor_elems);
	wpabuf_free(dev->go_neg_conf);
	wpabuf_free(dev->info.p2ps_instance);

	os_free(dev);
}
#ifdef CONFIG_WIFI_DISPLAY
#endif /* CONFIG_WIFI_DISPLAY */
#ifdef CONFIG_WIFI_DISPLAY
#endif /* CONFIG_WIFI_DISPLAY */
#ifdef CONFIG_WIFI_DISPLAY
#endif /* CONFIG_WIFI_DISPLAY */
#ifdef CONFIG_WIFI_DISPLAY
#endif /* CONFIG_WIFI_DISPLAY */
#ifdef CONFIG_WIFI_DISPLAY
#endif /* CONFIG_WIFI_DISPLAY */
#ifdef CONFIG_WIFI_DISPLAY
#endif /* CONFIG_WIFI_DISPLAY */
#ifdef CONFIG_WIFI_DISPLAY
#endif /* CONFIG_WIFI_DISPLAY */
#ifdef CONFIG_WIFI_DISPLAY
#endif /* CONFIG_WIFI_DISPLAY */
#ifdef CONFIG_WIFI_DISPLAY
#endif /* CONFIG_WIFI_DISPLAY */
#ifdef CONFIG_WPS_NFC
#endif /* CONFIG_WPS_NFC */
