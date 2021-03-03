#include "utils/includes.h"
#include "utils/common.h"
#include "utils/eloop.h"
#include "utils/os.h"
#include "common/ieee802_11_defs.h"
#include "common/ieee802_11_common.h"
#include "crypto/sha256.h"
#include "crypto/crypto.h"
#include "crypto/aes_wrap.h"
#include "rsn_supp/wpa.h"
#include "rsn_supp/wpa_ie.h"
#include "rsn_supp/wpa_i.h"
#include "drivers/driver.h"
#include "l2_packet/l2_packet.h"
#ifdef CONFIG_TDLS_TESTING
#define TDLS_TESTING_LONG_FRAME BIT(0)
#define TDLS_TESTING_ALT_RSN_IE BIT(1)
#define TDLS_TESTING_DIFF_BSSID BIT(2)
#define TDLS_TESTING_SHORT_LIFETIME BIT(3)
#define TDLS_TESTING_WRONG_LIFETIME_RESP BIT(4)
#define TDLS_TESTING_WRONG_LIFETIME_CONF BIT(5)
#define TDLS_TESTING_LONG_LIFETIME BIT(6)
#define TDLS_TESTING_CONCURRENT_INIT BIT(7)
#define TDLS_TESTING_NO_TPK_EXPIRATION BIT(8)
#define TDLS_TESTING_DECLINE_RESP BIT(9)
#define TDLS_TESTING_IGNORE_AP_PROHIBIT BIT(10)
#define TDLS_TESTING_WRONG_MIC BIT(11)
#define TDLS_TESTING_DOUBLE_TPK_M2 BIT(12)
#endif /* CONFIG_TDLS_TESTING */
#define TPK_LIFETIME 43200 /* 12 hours */
#define TPK_M1_RETRY_COUNT 3
#define TPK_M1_TIMEOUT 5000 /* in milliseconds */
#define TPK_M2_RETRY_COUNT 10
#define TPK_M2_TIMEOUT 500 /* in milliseconds */
#define TDLS_MIC_LEN		16
#define TDLS_TIMEOUT_LEN	4
#define TDLS_MAX_IE_LEN 80
#define IEEE80211_MAX_SUPP_RATES 32
static void wpa_tdls_peer_free(struct wpa_sm *sm, struct wpa_tdls_peer *peer)
{
	wpa_tdls_peer_clear(sm, peer);
	wpa_tdls_peer_remove_from_list(sm, peer);
	os_free(peer);
}
#ifdef CONFIG_TDLS_TESTING
#endif /* CONFIG_TDLS_TESTING */
#ifdef CONFIG_TDLS_TESTING
#endif /* CONFIG_TDLS_TESTING */
#ifdef CONFIG_TDLS_TESTING
#endif /* CONFIG_TDLS_TESTING */
#ifdef CONFIG_TDLS_TESTING
#endif /* CONFIG_TDLS_TESTING */
#ifdef CONFIG_TDLS_TESTING
#endif /* CONFIG_TDLS_TESTING */
#ifdef CONFIG_TDLS_TESTING
#endif /* CONFIG_TDLS_TESTING */
#ifdef CONFIG_TDLS_TESTING
#endif /* CONFIG_TDLS_TESTING */
#ifdef CONFIG_TDLS_TESTING
#endif /* CONFIG_TDLS_TESTING */
#ifdef CONFIG_TDLS_TESTING
#endif /* CONFIG_TDLS_TESTING */
#ifdef CONFIG_TDLS_TESTING
#endif /* CONFIG_TDLS_TESTING */
#ifdef CONFIG_TDLS_TESTING
#endif /* CONFIG_TDLS_TESTING */
#ifdef CONFIG_TDLS_TESTING
#endif /* CONFIG_TDLS_TESTING */
#ifdef CONFIG_TDLS_TESTING
#endif /* CONFIG_TDLS_TESTING */
#ifdef CONFIG_TDLS_TESTING
#endif /* CONFIG_TDLS_TESTING */
#ifdef CONFIG_TDLS_TESTING
#endif /* CONFIG_TDLS_TESTING */
#ifdef CONFIG_TDLS_TESTING
#endif /* CONFIG_TDLS_TESTING */
#if 0
#endif
#ifdef CONFIG_TDLS_TESTING
#endif /* CONFIG_TDLS_TESTING */
#ifdef CONFIG_TDLS_TESTING
#endif /* CONFIG_TDLS_TESTING */
#if 0
#endif
#ifdef CONFIG_TDLS_TESTING
#endif /* CONFIG_TDLS_TESTING */
#ifdef CONFIG_TDLS_TESTING
#endif /* CONFIG_TDLS_TESTING */
#ifdef CONFIG_TDLS_TESTING
#endif /* CONFIG_TDLS_TESTING */
#ifdef CONFIG_TDLS_TESTING
#endif /* CONFIG_TDLS_TESTING */
#ifdef CONFIG_TDLS_TESTING
#endif /* CONFIG_TDLS_TESTING */
#ifdef CONFIG_TDLS_TESTING
#endif /* CONFIG_TDLS_TESTING */
void wpa_tdls_remove(struct wpa_sm *sm, const u8 *addr)
{
	struct wpa_tdls_peer *peer;

	if (sm->tdls_disabled || !sm->tdls_supported)
		return;

	for (peer = sm->tdls; peer; peer = peer->next) {
		if (os_memcmp(peer->addr, addr, ETH_ALEN) == 0)
			break;
	}

	if (peer == NULL || !peer->tpk_success)
		return;

	if (sm->tdls_external_setup) {
		/*
		 * Disable previous link to allow renegotiation to be completed
		 * on AP path.
		 */
		wpa_tdls_do_teardown(sm, peer,
				     WLAN_REASON_TDLS_TEARDOWN_UNSPECIFIED);
	}
}
