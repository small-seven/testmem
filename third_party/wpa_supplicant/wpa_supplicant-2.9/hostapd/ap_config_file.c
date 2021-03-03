#include "utils/includes.h"
#ifndef CONFIG_NATIVE_WINDOWS
#include <grp.h>
#endif /* CONFIG_NATIVE_WINDOWS */
#include "utils/common.h"
#include "utils/uuid.h"
#include "common/ieee802_11_defs.h"
#include "crypto/sha256.h"
#include "crypto/tls.h"
#include "drivers/driver.h"
#include "eap_server/eap.h"
#include "radius/radius_client.h"
#include "ap/wpa_auth.h"
#include "ap/ap_config.h"
#include "config_file.h"
#ifndef CONFIG_NO_VLAN
#endif /* CONFIG_NO_VLAN */
void hostapd_remove_acl_mac(struct mac_acl_entry **acl, int *num,
			    const u8 *addr)
{
	int i = 0;

	while (i < *num) {
		if (os_memcmp((*acl)[i].addr, addr, ETH_ALEN) == 0) {
			os_remove_in_array(*acl, *num, sizeof(**acl), i);
			(*num)--;
		} else {
			i++;
		}
	}
}
#ifdef EAP_SERVER
#ifdef CONFIG_SQLITE
#else /* CONFIG_SQLITE */
#endif /* CONFIG_SQLITE */
#ifndef CONFIG_NO_RADIUS
#endif /* CONFIG_NO_RADIUS */
#endif /* EAP_SERVER */
#ifndef CONFIG_NO_RADIUS
#endif /* CONFIG_NO_RADIUS */
#ifdef CONFIG_IEEE80211R_AP
#ifdef CONFIG_SHA384
#endif /* CONFIG_SHA384 */
#endif /* CONFIG_IEEE80211R_AP */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_SAE
#endif /* CONFIG_SAE */
#ifdef CONFIG_SUITEB
#endif /* CONFIG_SUITEB */
#ifdef CONFIG_SUITEB192
#endif /* CONFIG_SUITEB192 */
#ifdef CONFIG_FILS
#ifdef CONFIG_IEEE80211R_AP
#endif /* CONFIG_IEEE80211R_AP */
#endif /* CONFIG_FILS */
#ifdef CONFIG_OWE
#endif /* CONFIG_OWE */
#ifdef CONFIG_DPP
#endif /* CONFIG_DPP */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_IEEE80211R_AP
#endif /* CONFIG_IEEE80211R_AP */
#ifdef CONFIG_IEEE80211N
#endif /* CONFIG_IEEE80211N */
#ifdef CONFIG_IEEE80211AC
#endif /* CONFIG_IEEE80211AC */
#ifdef CONFIG_IEEE80211AX
#endif /* CONFIG_IEEE80211AX */
#ifdef CONFIG_INTERWORKING
#endif /* CONFIG_INTERWORKING */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_ACS
#endif /* CONFIG_ACS */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifdef EAP_SERVER
#endif /* EAP_SERVER */
#ifdef CONFIG_AIRTIME_POLICY
#endif /* CONFIG_AIRTIME_POLICY */
#ifdef CONFIG_SAE
#endif /* CONFIG_SAE */
#ifdef CONFIG_DPP2
#endif /* CONFIG_DPP2 */
#ifdef CONFIG_MACSEC
#else /* CONFIG_MACSEC */
#endif /* CONFIG_MACSEC */
#ifdef EAP_SERVER
#ifdef EAP_SERVER_FAST
#endif /* EAP_SERVER_FAST */
#ifdef EAP_SERVER_TEAP
#endif /* EAP_SERVER_TEAP */
#ifdef EAP_SERVER_SIM
#endif /* EAP_SERVER_SIM */
#ifdef EAP_SERVER_TNC
#endif /* EAP_SERVER_TNC */
#ifdef EAP_SERVER_PWD
#endif /* EAP_SERVER_PWD */
#ifdef CONFIG_ERP
#endif /* CONFIG_ERP */
#endif /* EAP_SERVER */
#ifdef CONFIG_IAPP
#endif /* CONFIG_IAPP */
#ifndef CONFIG_NO_RADIUS
#endif /* CONFIG_NO_RADIUS */
#ifdef CONFIG_RSN_PREAUTH
#endif /* CONFIG_RSN_PREAUTH */
#ifdef CONFIG_IEEE80211R_AP
#endif /* CONFIG_IEEE80211R_AP */
#ifndef CONFIG_NO_CTRL_IFACE
#ifndef CONFIG_NATIVE_WINDOWS
#endif /* CONFIG_NATIVE_WINDOWS */
#endif /* CONFIG_NO_CTRL_IFACE */
#ifdef RADIUS_SERVER
#endif /* RADIUS_SERVER */
#ifndef CONFIG_ACS
#else /* CONFIG_ACS */
#endif /* CONFIG_ACS */
#ifdef CONFIG_ACS
#endif /* CONFIG_ACS */
#ifndef CONFIG_NO_VLAN
#ifdef CONFIG_FULL_DYNAMIC_VLAN
#endif /* CONFIG_FULL_DYNAMIC_VLAN */
#endif /* CONFIG_NO_VLAN */
#ifdef CONFIG_IEEE80211W
#endif /* CONFIG_IEEE80211W */
#ifdef CONFIG_OCV
#endif /* CONFIG_OCV */
#ifdef CONFIG_IEEE80211N
#endif /* CONFIG_IEEE80211N */
#ifdef CONFIG_IEEE80211AC
#endif /* CONFIG_IEEE80211AC */
#ifdef CONFIG_IEEE80211AX
#endif /* CONFIG_IEEE80211AX */
#ifdef CONFIG_WPS
#ifdef CONFIG_WPS_NFC
#endif /* CONFIG_WPS_NFC */
#endif /* CONFIG_WPS */
#ifdef CONFIG_P2P_MANAGER
#endif /* CONFIG_P2P_MANAGER */
#ifdef CONFIG_RSN_TESTING
#endif /* CONFIG_RSN_TESTING */
#ifdef CONFIG_WNM_AP
#endif /* CONFIG_WNM_AP */
#ifdef CONFIG_INTERWORKING
#endif /* CONFIG_INTERWORKING */
#ifdef CONFIG_RADIUS_TEST
#endif /* CONFIG_RADIUS_TEST */
#ifdef CONFIG_PROXYARP
#endif /* CONFIG_PROXYARP */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_MBO
#endif /* CONFIG_MBO */
#ifdef CONFIG_TESTING_OPTIONS
#define PARSE_TEST_PROBABILITY(_val)				\
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_SAE
#endif /* CONFIG_SAE */
#ifdef CONFIG_FST
#endif /* CONFIG_FST */
#ifdef CONFIG_FILS
#endif /* CONFIG_FILS */
#ifdef CONFIG_DPP
#ifdef CONFIG_DPP2
#endif /* CONFIG_DPP2 */
#endif /* CONFIG_DPP */
#ifdef CONFIG_OWE
#endif /* CONFIG_OWE */
#ifdef CONFIG_AIRTIME_POLICY
#endif /* CONFIG_AIRTIME_POLICY */
#ifdef CONFIG_MACSEC
#endif /* CONFIG_MACSEC */
#ifndef WPA_IGNORE_CONFIG_ERRORS
#endif /* WPA_IGNORE_CONFIG_ERRORS */
