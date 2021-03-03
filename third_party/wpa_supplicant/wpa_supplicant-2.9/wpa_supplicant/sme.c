#include "includes.h"
#include "common.h"
#include "utils/eloop.h"
#include "common/ieee802_11_defs.h"
#include "common/ieee802_11_common.h"
#include "common/ocv.h"
#include "eapol_supp/eapol_supp_sm.h"
#include "common/wpa_common.h"
#include "common/sae.h"
#include "common/dpp.h"
#include "rsn_supp/wpa.h"
#include "rsn_supp/pmksa_cache.h"
#include "config.h"
#include "wpa_supplicant_i.h"
#include "driver_i.h"
#include "wpas_glue.h"
#include "wps_supplicant.h"
#include "p2p_supplicant.h"
#include "notify.h"
#include "bss.h"
#include "scan.h"
#include "sme.h"
#include "hs20_supplicant.h"
#define SME_AUTH_TIMEOUT 5
#define SME_ASSOC_TIMEOUT 5
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_SAE
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#endif /* CONFIG_SAE */
#ifdef CONFIG_IEEE80211R
#endif /* CONFIG_IEEE80211R */
#if defined(CONFIG_IEEE80211R) || defined(CONFIG_FILS)
#endif /* CONFIG_IEEE80211R || CONFIG_FILS */
#ifdef CONFIG_MBO
#endif /* CONFIG_MBO */
#ifdef IEEE8021X_EAPOL
#endif /* IEEE8021X_EAPOL */
#ifdef CONFIG_SAE
#ifdef CONFIG_DPP
#endif /* CONFIG_DPP */
#endif /* CONFIG_SAE */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifdef CONFIG_IEEE80211R
#endif /* CONFIG_IEEE80211R */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_FST
#endif /* CONFIG_FST */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_MBO
#endif /* CONFIG_MBO */
#ifdef CONFIG_SAE
#endif /* CONFIG_SAE */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_SAE
#endif /* CONFIG_SAE */
#ifdef CONFIG_SAE
#endif /* CONFIG_SAE */
#ifdef CONFIG_SAE
#endif /* CONFIG_SAE */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifdef CONFIG_IEEE80211R
#endif /* CONFIG_IEEE80211R */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifdef CONFIG_IEEE80211R
#endif /* CONFIG_IEEE80211R */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifdef CONFIG_HT_OVERRIDES
#endif /* CONFIG_HT_OVERRIDES */
#ifdef CONFIG_VHT_OVERRIDES
#endif /* CONFIG_VHT_OVERRIDES */
#ifdef CONFIG_FILS
#ifdef CONFIG_IEEE80211R
#endif /* CONFIG_IEEE80211R */
#endif /* CONFIG_FILS */
#ifdef CONFIG_OWE
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#endif /* CONFIG_OWE */
#ifdef CONFIG_DPP2
#endif /* CONFIG_DPP2 */
#ifdef CONFIG_HT_OVERRIDES
#endif /* CONFIG_HT_OVERRIDES */
#ifdef CONFIG_VHT_OVERRIDES
#endif /* CONFIG_VHT_OVERRIDES */
#ifdef CONFIG_IEEE80211R
#endif /* CONFIG_IEEE80211R */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_SAE
#endif /* CONFIG_SAE */
#ifdef CONFIG_SAE
#endif /* CONFIG_SAE */
#ifdef CONFIG_IEEE80211R
#endif /* CONFIG_IEEE80211R */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
void sme_deinit(struct wpa_supplicant *wpa_s)
{
	sme_clear_on_disassoc(wpa_s);

	eloop_cancel_timeout(sme_assoc_timer, wpa_s, NULL);
	eloop_cancel_timeout(sme_auth_timer, wpa_s, NULL);
	eloop_cancel_timeout(sme_obss_scan_timeout, wpa_s, NULL);
}
#ifdef CONFIG_IEEE80211W
#ifdef CONFIG_OCV
#endif /* CONFIG_OCV */
#ifdef CONFIG_OCV
#endif /* CONFIG_OCV */
#ifdef CONFIG_OCV
#endif /* CONFIG_OCV */
#endif /* CONFIG_IEEE80211W */
