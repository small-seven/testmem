#include "includes.h"
#include "common.h"
#include "pcsc_funcs.h"
#include "state_machine.h"
#include "ext_password.h"
#include "crypto/crypto.h"
#include "crypto/tls.h"
#include "crypto/sha256.h"
#include "common/wpa_ctrl.h"
#include "eap_common/eap_wsc_common.h"
#include "eap_i.h"
#include "eap_config.h"
#define STATE_MACHINE_DATA struct eap_sm
#define STATE_MACHINE_DEBUG_PREFIX "EAP"
#define EAP_MAX_AUTH_ROUNDS 50
#define EAP_CLIENT_TIMEOUT_DEFAULT 60
#if defined(CONFIG_CTRL_IFACE) || !defined(CONFIG_NO_STDOUT_DEBUG)
#endif /* CONFIG_CTRL_IFACE || !CONFIG_NO_STDOUT_DEBUG */
static void eap_sm_free_key(struct eap_sm *sm)
{
	if (sm->eapKeyData) {
		bin_clear_free(sm->eapKeyData, sm->eapKeyDataLen);
		sm->eapKeyData = NULL;
	}
}
static void eap_deinit_prev_method(struct eap_sm *sm, const char *txt)
{
	ext_password_free(sm->ext_pw_buf);
	sm->ext_pw_buf = NULL;

	if (sm->m == NULL || sm->eap_method_priv == NULL)
		return;

	wpa_printf(MSG_DEBUG, "EAP: deinitialize previously used EAP method "
		   "(%d, %s) at %s", sm->selectedMethod, sm->m->name, txt);
	sm->m->deinit(sm, sm->eap_method_priv);
	sm->eap_method_priv = NULL;
	sm->m = NULL;
}
#if defined(PCSC_FUNCS) || defined(CONFIG_EAP_PROXY)
#endif /* PCSC_FUNCS || CONFIG_EAP_PROXY */
#ifdef CONFIG_ERP
#ifdef CONFIG_EAP_PROXY
#endif /* CONFIG_EAP_PROXY */
#endif /* CONFIG_ERP */
void eap_peer_erp_free_keys(struct eap_sm *sm)
{
#ifdef CONFIG_ERP
	struct eap_erp_key *erp, *tmp;

	dl_list_for_each_safe(erp, tmp, &sm->erp_keys, struct eap_erp_key, list)
		eap_peer_erp_free_key(erp);
#endif /* CONFIG_ERP */
}
#ifdef CONFIG_ERP
#endif /* CONFIG_ERP */
#ifdef CONFIG_ERP
#endif /* CONFIG_ERP */
#ifdef PCSC_FUNCS
#endif /* PCSC_FUNCS */
#ifdef PCSC_FUNCS
#else /* PCSC_FUNCS */
#endif /* PCSC_FUNCS */
#ifdef CONFIG_ERP
#endif /* CONFIG_ERP */
#ifdef CONFIG_ERP
#endif /* CONFIG_ERP */
#ifdef CONFIG_FIPS
#endif /* CONFIG_FIPS */
void eap_peer_sm_deinit(struct eap_sm *sm)
{
	if (sm == NULL)
		return;
	eap_deinit_prev_method(sm, "EAP deinit");
	eap_sm_abort(sm);
	if (sm->ssl_ctx2)
		tls_deinit(sm->ssl_ctx2);
	tls_deinit(sm->ssl_ctx);
	eap_peer_erp_free_keys(sm);
	os_free(sm);
}
#ifdef CONFIG_CTRL_IFACE
#endif /* CONFIG_CTRL_IFACE */
#if defined(CONFIG_CTRL_IFACE) || !defined(CONFIG_NO_STDOUT_DEBUG)
#endif /* CONFIG_CTRL_IFACE || !CONFIG_NO_STDOUT_DEBUG */
#ifdef CONFIG_CTRL_IFACE
#endif /* CONFIG_CTRL_IFACE */
#if defined(CONFIG_CTRL_IFACE) || !defined(CONFIG_NO_STDOUT_DEBUG)
#endif /* CONFIG_CTRL_IFACE || !CONFIG_NO_STDOUT_DEBUG */
#ifndef CONFIG_NO_CONFIG_BLOBS
#endif /* CONFIG_NO_CONFIG_BLOBS */
#ifndef CONFIG_NO_CONFIG_BLOBS
#else /* CONFIG_NO_CONFIG_BLOBS */
#endif /* CONFIG_NO_CONFIG_BLOBS */
