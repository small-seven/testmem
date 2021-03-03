#include "includes.h"
#include "common.h"
#include "crypto/sha256.h"
#include "eap_i.h"
#include "state_machine.h"
#include "common/wpa_ctrl.h"
#define STATE_MACHINE_DATA struct eap_sm
#define STATE_MACHINE_DEBUG_PREFIX "EAP"
#define EAP_MAX_AUTH_ROUNDS 50
#ifdef CONFIG_ERP
#endif /* CONFIG_ERP */
#define EAP_COPY(dst, src) \
#ifdef CONFIG_ERP
#endif /* CONFIG_ERP */
#ifdef CONFIG_ERP
#endif /* CONFIG_ERP */
#ifdef CONFIG_ERP
#endif /* CONFIG_ERP */
#ifdef CONFIG_ERP
#endif /* CONFIG_ERP */
void eap_user_free(struct eap_user *user)
{
	if (user == NULL)
		return;
	bin_clear_free(user->password, user->password_len);
	user->password = NULL;
	bin_clear_free(user->salt, user->salt_len);
	user->salt = NULL;
	os_free(user);
}
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
void eap_server_sm_deinit(struct eap_sm *sm)
{
	if (sm == NULL)
		return;
	wpa_printf(MSG_DEBUG, "EAP: Server state machine removed");
	if (sm->m && sm->eap_method_priv)
		sm->m->reset(sm, sm->eap_method_priv);
	wpabuf_free(sm->eap_if.eapReqData);
	bin_clear_free(sm->eap_if.eapKeyData, sm->eap_if.eapKeyDataLen);
	os_free(sm->eap_if.eapSessionId);
	wpabuf_free(sm->lastReqData);
	wpabuf_free(sm->eap_if.eapRespData);
	os_free(sm->identity);
	os_free(sm->serial_num);
	os_free(sm->pac_opaque_encr_key);
	os_free(sm->eap_fast_a_id);
	os_free(sm->eap_fast_a_id_info);
	wpabuf_free(sm->eap_if.aaaEapReqData);
	wpabuf_free(sm->eap_if.aaaEapRespData);
	bin_clear_free(sm->eap_if.aaaEapKeyData, sm->eap_if.aaaEapKeyDataLen);
	eap_user_free(sm->user);
	wpabuf_free(sm->assoc_wps_ie);
	wpabuf_free(sm->assoc_p2p_ie);
	os_free(sm);
}
#ifdef CONFIG_ERP
#endif /* CONFIG_ERP */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
