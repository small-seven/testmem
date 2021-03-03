#include "includes.h"
#include "common.h"
#include "state_machine.h"
#include "wpabuf.h"
#include "eloop.h"
#include "crypto/crypto.h"
#include "crypto/md5.h"
#include "common/eapol_common.h"
#include "eap_peer/eap.h"
#include "eap_peer/eap_config.h"
#include "eap_peer/eap_proxy.h"
#include "eapol_supp_sm.h"
#define STATE_MACHINE_DATA struct eapol_sm
#define STATE_MACHINE_DEBUG_PREFIX "EAPOL"
#ifdef CONFIG_EAP_PROXY
#endif /* CONFIG_EAP_PROXY */
#ifdef CONFIG_EAP_PROXY
#endif /* CONFIG_EAP_PROXY */
#define IEEE8021X_ENCR_KEY_LEN 32
#define IEEE8021X_SIGN_KEY_LEN 32
#ifndef CONFIG_FIPS
#ifndef CONFIG_NO_RC4
#endif /* CONFIG_NO_RC4 */
#ifdef CONFIG_NO_RC4
#else /* CONFIG_NO_RC4 */
#endif /* CONFIG_NO_RC4 */
#endif /* CONFIG_FIPS */
#ifdef CONFIG_EAP_PROXY
#endif /* CONFIG_EAP_PROXY */
#ifdef CONFIG_EAP_PROXY
#endif /* CONFIG_EAP_PROXY */
#ifdef CONFIG_EAP_PROXY
#endif /* CONFIG_EAP_PROXY */
#ifdef CONFIG_CTRL_IFACE
#endif /* CONFIG_CTRL_IFACE */
#if defined(CONFIG_CTRL_IFACE) || !defined(CONFIG_NO_STDOUT_DEBUG)
#endif /* CONFIG_CTRL_IFACE || !CONFIG_NO_STDOUT_DEBUG */
#ifdef CONFIG_CTRL_IFACE
#ifdef CONFIG_EAP_PROXY
#endif /* CONFIG_EAP_PROXY */
#endif /* CONFIG_CTRL_IFACE */
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifdef CONFIG_EAP_PROXY
#endif /* CONFIG_EAP_PROXY */
#ifdef CONFIG_MACSEC
#endif /* CONFIG_MACSEC */
#ifdef CONFIG_EAP_PROXY
#endif /* CONFIG_EAP_PROXY */
#ifdef CONFIG_EAP_PROXY
#endif /* CONFIG_EAP_PROXY */
#ifdef CONFIG_EAP_PROXY
#endif /* CONFIG_EAP_PROXY */
#ifdef CONFIG_EAP_PROXY
#endif /* CONFIG_EAP_PROXY */
#ifndef CONFIG_NO_CONFIG_BLOBS
#endif /* CONFIG_NO_CONFIG_BLOBS */
#ifndef CONFIG_NO_CONFIG_BLOBS
#else /* CONFIG_NO_CONFIG_BLOBS */
#endif /* CONFIG_NO_CONFIG_BLOBS */
#if defined(CONFIG_CTRL_IFACE) || !defined(CONFIG_NO_STDOUT_DEBUG)
#else /* CONFIG_CTRL_IFACE || !CONFIG_NO_STDOUT_DEBUG */
#define eapol_sm_eap_param_needed NULL
#endif /* CONFIG_CTRL_IFACE || !CONFIG_NO_STDOUT_DEBUG */
#ifdef CONFIG_EAP_PROXY
#endif /* CONFIG_EAP_PROXY */
#ifdef CONFIG_EAP_PROXY
#endif /* CONFIG_EAP_PROXY */
#ifdef CONFIG_EAP_PROXY
#endif /* CONFIG_EAP_PROXY */
void eapol_sm_deinit(struct eapol_sm *sm)
{
	if (sm == NULL)
		return;
	eloop_cancel_timeout(eapol_sm_step_timeout, NULL, sm);
	eloop_cancel_timeout(eapol_port_timers_tick, NULL, sm);
	eap_peer_sm_deinit(sm->eap);
#ifdef CONFIG_EAP_PROXY
	eap_proxy_deinit(sm->eap_proxy);
#endif /* CONFIG_EAP_PROXY */
	os_free(sm->last_rx_key);
	wpabuf_free(sm->eapReqData);
	os_free(sm->ctx);
	os_free(sm);
}
#ifdef CONFIG_EAP_PROXY
#endif /* CONFIG_EAP_PROXY */
#ifdef CONFIG_ERP
#else /* CONFIG_ERP */
#endif /* CONFIG_ERP */
#ifdef CONFIG_ERP
#endif /* CONFIG_ERP */
#ifdef CONFIG_ERP
#else /* CONFIG_ERP */
#endif /* CONFIG_ERP */
#ifdef CONFIG_ERP
#else /* CONFIG_ERP */
#endif /* CONFIG_ERP */
