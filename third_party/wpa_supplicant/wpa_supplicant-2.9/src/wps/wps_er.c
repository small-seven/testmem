#include "includes.h"
#include "common.h"
#include "base64.h"
#include "uuid.h"
#include "eloop.h"
#include "httpread.h"
#include "http_client.h"
#include "http_server.h"
#include "upnp_xml.h"
#include "wps_i.h"
#include "wps_upnp.h"
#include "wps_upnp_i.h"
#include "wps_er.h"
static void wps_er_sta_free(struct wps_er_sta *sta)
{
	wps_er_sta_event(sta->ap->er->wps, sta, WPS_EV_ER_ENROLLEE_REMOVE);
	if (sta->wps)
		wps_deinit(sta->wps);
	os_free(sta->manufacturer);
	os_free(sta->model_name);
	os_free(sta->model_number);
	os_free(sta->serial_number);
	os_free(sta->dev_name);
	http_client_free(sta->http);
	eloop_cancel_timeout(wps_er_sta_timeout, sta, NULL);
	os_free(sta->cred);
	os_free(sta);
}
static void wps_er_ap_free(struct wps_er_ap *ap)
{
	http_client_free(ap->http);
	ap->http = NULL;

	os_free(ap->location);
	os_free(ap->friendly_name);
	os_free(ap->manufacturer);
	os_free(ap->manufacturer_url);
	os_free(ap->model_description);
	os_free(ap->model_name);
	os_free(ap->model_number);
	os_free(ap->model_url);
	os_free(ap->serial_number);
	os_free(ap->udn);
	os_free(ap->upc);

	os_free(ap->scpd_url);
	os_free(ap->control_url);
	os_free(ap->event_sub_url);

	os_free(ap->ap_settings);

	os_free(ap);
}
void wps_er_ap_remove(struct wps_er *er, struct in_addr *addr)
{
	struct wps_er_ap *ap;
	dl_list_for_each(ap, &er->ap, struct wps_er_ap, list) {
		if (ap->addr.s_addr == addr->s_addr) {
			wps_er_ap_remove_entry(er, ap);
			return;
		}
	}
}
#ifdef CONFIG_WPS_NFC
#endif /* CONFIG_WPS_NFC */
