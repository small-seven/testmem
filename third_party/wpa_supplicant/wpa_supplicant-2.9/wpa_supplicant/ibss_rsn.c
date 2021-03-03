#include "includes.h"
#include "common.h"
#include "common/wpa_ctrl.h"
#include "utils/eloop.h"
#include "l2_packet/l2_packet.h"
#include "rsn_supp/wpa.h"
#include "rsn_supp/wpa_ie.h"
#include "ap/wpa_auth.h"
#include "wpa_supplicant_i.h"
#include "driver_i.h"
#include "common/ieee802_11_defs.h"
#include "ibss_rsn.h"
static void ibss_rsn_free(struct ibss_rsn_peer *peer)
{
	eloop_cancel_timeout(ibss_rsn_auth_timeout, peer, NULL);
	wpa_auth_sta_deinit(peer->auth);
	wpa_sm_deinit(peer->supp);
	os_free(peer);
}
static u8 * supp_alloc_eapol(void *ctx, u8 type, const void *data,
			     u16 data_len, size_t *msg_len, void **data_pos)
{
	struct ieee802_1x_hdr *hdr;

	wpa_printf(MSG_DEBUG, "SUPP: %s(type=%d data_len=%d)",
		   __func__, type, data_len);

	*msg_len = sizeof(*hdr) + data_len;
	hdr = os_malloc(*msg_len);
	if (hdr == NULL)
		return NULL;

	hdr->version = 2;
	hdr->type = type;
	hdr->length = host_to_be16(data_len);

	if (data)
		os_memcpy(hdr + 1, data, data_len);
	else
		os_memset(hdr + 1, 0, data_len);

	if (data_pos)
		*data_pos = hdr + 1;

	return (u8 *) hdr;
}
void ibss_rsn_deinit(struct ibss_rsn *ibss_rsn)
{
	struct ibss_rsn_peer *peer, *prev;

	if (ibss_rsn == NULL)
		return;

	peer = ibss_rsn->peers;
	while (peer) {
		prev = peer;
		peer = peer->next;
		ibss_rsn_free(prev);
	}

	if (ibss_rsn->auth_group)
		wpa_deinit(ibss_rsn->auth_group);
	os_free(ibss_rsn);

}
