#include "includes.h"
#include "common.h"
#include "common/ieee802_11_defs.h"
#include "common/gas.h"
#include "common/wpa_ctrl.h"
#include "utils/pcsc_funcs.h"
#include "utils/eloop.h"
#include "drivers/driver.h"
#include "eap_common/eap_defs.h"
#include "eap_peer/eap.h"
#include "eap_peer/eap_methods.h"
#include "eapol_supp/eapol_supp_sm.h"
#include "rsn_supp/wpa.h"
#include "wpa_supplicant_i.h"
#include "config.h"
#include "config_ssid.h"
#include "bss.h"
#include "scan.h"
#include "notify.h"
#include "driver_i.h"
#include "gas_query.h"
#include "hs20_supplicant.h"
#include "interworking.h"
#if defined(EAP_SIM) | defined(EAP_SIM_DYNAMIC)
#define INTERWORKING_3GPP
#else
#if defined(EAP_AKA) | defined(EAP_AKA_DYNAMIC)
#define INTERWORKING_3GPP
#else
#if defined(EAP_AKA_PRIME) | defined(EAP_AKA_PRIME_DYNAMIC)
#define INTERWORKING_3GPP
#endif
#endif
#endif
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
static void nai_realm_free(struct nai_realm *realms, u16 count)
{
	u16 i;

	if (realms == NULL)
		return;
	for (i = 0; i < count; i++) {
		os_free(realms[i].eap);
		os_free(realms[i].realm);
	}
	os_free(realms);
}
#ifdef INTERWORKING_3GPP
#endif /* INTERWORKING_3GPP */
#ifdef CONFIG_IEEE80211R
#endif /* CONFIG_IEEE80211R */
#ifdef INTERWORKING_3GPP
#endif /* INTERWORKING_3GPP */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef ANDROID
#endif /* ANDROID */
#ifdef PCSC_FUNCS
#endif /* PCSC_FUNCS */
#ifdef INTERWORKING_3GPP
#ifdef CONFIG_EAP_PROXY
#endif /* CONFIG_EAP_PROXY */
#ifdef PCSC_FUNCS
#endif /* PCSC_FUNCS */
#ifdef CONFIG_EAP_PROXY
#endif /* CONFIG_EAP_PROXY */
#if defined(PCSC_FUNCS) || defined(CONFIG_EAP_PROXY)
#endif /* PCSC_FUNCS || CONFIG_EAP_PROXY */
#endif /* INTERWORKING_3GPP */
#ifdef INTERWORKING_3GPP
#ifdef PCSC_FUNCS
#endif /* PCSC_FUNCS */
#ifdef CONFIG_EAP_PROXY
#endif /* CONFIG_EAP_PROXY */
#endif /* INTERWORKING_3GPP */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_MBO
#endif /* CONFIG_MBO */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_MBO
#endif /* CONFIG_MBO */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
