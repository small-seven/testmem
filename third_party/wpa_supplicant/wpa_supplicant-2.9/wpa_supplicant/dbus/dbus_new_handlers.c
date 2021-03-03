#include "includes.h"
#include "common.h"
#include "common/ieee802_11_defs.h"
#include "eap_peer/eap_methods.h"
#include "eapol_supp/eapol_supp_sm.h"
#include "rsn_supp/wpa.h"
#include "ap/hostapd.h"
#include "ap/sta_info.h"
#include "ap/ap_drv_ops.h"
#include "../config.h"
#include "../wpa_supplicant_i.h"
#include "../driver_i.h"
#include "../notify.h"
#include "../bss.h"
#include "../scan.h"
#include "../autoscan.h"
#include "../ap.h"
#include "dbus_new_helpers.h"
#include "dbus_new.h"
#include "dbus_new_handlers.h"
#include "dbus_dict_helpers.h"
#include "dbus_common_i.h"
#include "drivers/driver.h"
#ifdef CONFIG_MESH
#include "ap/hostapd.h"
#include "ap/sta_info.h"
#endif /* CONFIG_MESH */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifdef CONFIG_AP
#endif /* CONFIG_AP */
#ifdef CONFIG_IBSS_RSN
#endif /* CONFIG_IBSS_RSN */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_INTERWORKING
#endif /* CONFIG_INTERWORKING */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_MESH
#endif /* CONFIG_MESH */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifdef CONFIG_IEEE80211R
#endif /* CONFIG_IEEE80211R */
#ifdef CONFIG_SHA384
#endif /* CONFIG_SHA384 */
#define FREQS_ALLOC_CHUNK 32
#ifdef CONFIG_AUTOSCAN
#endif /* CONFIG_AUTOSCAN */
#ifdef IEEE8021X_EAPOL
#else /* IEEE8021X_EAPOL */
#endif /* IEEE8021X_EAPOL */
#ifndef CONFIG_NO_CONFIG_BLOBS
#endif /* CONFIG_NO_CONFIG_BLOBS */
#ifdef CONFIG_AUTOSCAN
#endif /* CONFIG_AUTOSCAN */
#ifdef CONFIG_TDLS
#endif /* CONFIG_TDLS */
#ifndef CONFIG_NO_CONFIG_WRITE
#endif /* CONFIG_NO_CONFIG_WRITE */
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifdef CONFIG_MESH
#endif /* CONFIG_MESH */
#ifdef CONFIG_WNM
#else /* CONFIG_WNM */
#endif /* CONFIG_WNM */
#ifdef CONFIG_AP
#endif /* CONFIG_AP */
#ifdef CONFIG_AP
#else /* CONFIG_AP */
#endif /* CONFIG_AP */
#ifdef CONFIG_AP
#else /* CONFIG_AP */
#endif /* CONFIG_AP */
#ifdef CONFIG_AP
#else /* CONFIG_AP */
#endif /* CONFIG_AP */
#ifdef CONFIG_AP
#else /* CONFIG_AP */
#endif /* CONFIG_AP */
#ifdef CONFIG_AP
#else /* CONFIG_AP */
#endif /* CONFIG_AP */
#ifdef CONFIG_AP
#else /* CONFIG_AP */
#endif /* CONFIG_AP */
#ifdef CONFIG_AP
#else /* CONFIG_AP */
#endif /* CONFIG_AP */
#ifdef CONFIG_SUITEB
#endif /* CONFIG_SUITEB */
#ifdef CONFIG_SUITEB192
#endif /* CONFIG_SUITEB192 */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifdef CONFIG_SAE
#endif /* CONFIG_SAE */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifdef CONFIG_AP
#endif /* CONFIG_AP */
DBusMessage * wpas_dbus_handler_vendor_elem_remove(DBusMessage *message,
						   struct wpa_supplicant *wpa_s)
{
	u8 *ielems;
	int len;
	struct ieee802_11_elems elems;
	DBusMessageIter	iter, array;
	dbus_int32_t frame_id;

	dbus_message_iter_init(message, &iter);
	dbus_message_iter_get_basic(&iter, &frame_id);
	if (frame_id < 0 || frame_id >= NUM_VENDOR_ELEM_FRAMES) {
		return dbus_message_new_error(message, DBUS_ERROR_INVALID_ARGS,
					      "Invalid ID");
	}

	dbus_message_iter_next(&iter);
	dbus_message_iter_recurse(&iter, &array);
	dbus_message_iter_get_fixed_array(&array, &ielems, &len);
	if (!ielems || len == 0) {
		return dbus_message_new_error(message, DBUS_ERROR_INVALID_ARGS,
					      "Invalid value");
	}

	wpa_s = wpas_vendor_elem(wpa_s, frame_id);

	if (len == 1 && *ielems == '*') {
		wpabuf_free(wpa_s->vendor_elem[frame_id]);
		wpa_s->vendor_elem[frame_id] = NULL;
		wpas_vendor_elem_update(wpa_s);
		return NULL;
	}

	if (!wpa_s->vendor_elem[frame_id]) {
		return dbus_message_new_error(message, DBUS_ERROR_INVALID_ARGS,
					      "ID value does not exist");
	}

	if (ieee802_11_parse_elems(ielems, len, &elems, 0) == ParseFailed) {
		return dbus_message_new_error(message, DBUS_ERROR_INVALID_ARGS,
					      "Parse error");
	}

	if (wpas_vendor_elem_remove(wpa_s, frame_id, ielems, len) == 0)
		return NULL;

	return dbus_message_new_error(message, DBUS_ERROR_INVALID_ARGS,
				      "Not found");
}
#ifdef CONFIG_MESH
#endif /* CONFIG_MESH */
