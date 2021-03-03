#include "includes.h"
#include <assert.h>
#include "common.h"
#include "config.h"
#include "eapol_supp/eapol_supp_sm.h"
#include "eloop.h"
#include "rsn_supp/wpa.h"
#include "eap_peer/eap.h"
#include "wpa_supplicant_i.h"
#include "l2_packet/l2_packet.h"
#include "ctrl_iface.h"
#include "pcsc_funcs.h"
#include "rsn_supp/preauth.h"
#include "rsn_supp/pmksa_cache.h"
#include "drivers/driver.h"
static u8 * wpa_alloc_eapol(const struct wpa_supplicant *wpa_s, u8 type,
			    const void *data, u16 data_len,
			    size_t *msg_len, void **data_pos)
{
	struct ieee802_1x_hdr *hdr;

	*msg_len = sizeof(*hdr) + data_len;
	hdr = os_malloc(*msg_len);
	if (hdr == NULL)
		return NULL;

	hdr->version = wpa_s->conf->eapol_version;
	hdr->type = type;
	hdr->length = htons(data_len);

	if (data)
		os_memcpy(hdr + 1, data, data_len);
	else
		os_memset(hdr + 1, 0, data_len);

	if (data_pos)
		*data_pos = hdr + 1;

	return (u8 *) hdr;
}
static u8 * _wpa_alloc_eapol(void *wpa_s, u8 type,
			     const void *data, u16 data_len,
			     size_t *msg_len, void **data_pos)
{
	return wpa_alloc_eapol(wpa_s, type, data, data_len, msg_len, data_pos);
}
static int wpa_supplicant_remove_pmkid(void *wpa_s, void *network_ctx,
				       const u8 *bssid, const u8 *pmkid,
				       const u8 *fils_cache_id)
{
	printf("%s - not implemented\n", __func__);
	return -1;
}
