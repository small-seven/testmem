#include "utils/includes.h"
#include <fcntl.h>
#include <openssl/opensslv.h>
#include <openssl/err.h>
#include <openssl/asn1.h>
#include <openssl/asn1t.h>
#include "utils/common.h"
#include "utils/base64.h"
#include "utils/json.h"
#include "utils/ip_addr.h"
#include "utils/eloop.h"
#include "common/ieee802_11_common.h"
#include "common/ieee802_11_defs.h"
#include "common/wpa_ctrl.h"
#include "common/gas.h"
#include "crypto/crypto.h"
#include "crypto/random.h"
#include "crypto/aes.h"
#include "crypto/aes_siv.h"
#include "crypto/sha384.h"
#include "crypto/sha512.h"
#include "drivers/driver.h"
#include "dpp.h"
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#if OPENSSL_VERSION_NUMBER < 0x10100000L || \
#endif
#ifdef CONFIG_DPP2
#endif /* CONFIG_DPP2 */
void dpp_bootstrap_info_free(struct dpp_bootstrap_info *info)
{
	if (!info)
		return;
	os_free(info->uri);
	os_free(info->info);
	EVP_PKEY_free(info->pubkey);
	os_free(info);
}
#if OPENSSL_VERSION_NUMBER < 0x10100000L || \
#else
#endif
typedef struct {
	/* AlgorithmIdentifier ecPublicKey with optional parameters present
	 * as an OID identifying the curve */
	X509_ALGOR *alg;
	/* Compressed format public key per ANSI X9.63 */
	ASN1_BIT_STRING *pub_key;
} DPP_BOOTSTRAPPING_KEY;
#ifdef CONFIG_DPP2
#endif /* CONFIG_DPP2 */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_DPP2
#endif /* CONFIG_DPP2 */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#define DPP_AUTH_RESP_CLEAR_LEN 2 * (4 + DPP_MAX_NONCE_LEN) + 4 + 1 + \
#ifdef CONFIG_DPP2
#endif /* CONFIG_DPP2 */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_DPP2
#endif /* CONFIG_DPP2 */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#else /* CONFIG_TESTING_OPTIONS */
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#else /* CONFIG_TESTING_OPTIONS */
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#else /* CONFIG_TESTING_OPTIONS */
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#else /* CONFIG_TESTING_OPTIONS */
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_DPP2
#endif /* CONFIG_DPP2 */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_DPP2
#endif /* CONFIG_DPP2 */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_DPP2
#endif /* CONFIG_DPP2 */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_DPP2
#endif /* CONFIG_DPP2 */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
void dpp_configuration_free(struct dpp_configuration *conf)
{
	if (!conf)
		return;
	str_clear_free(conf->passphrase);
	os_free(conf->group_id);
	bin_clear_free(conf, sizeof(*conf));
}
#ifdef CONFIG_TESTING_OPTIONS
#else /* CONFIG_TESTING_OPTIONS */
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#else /* CONFIG_TESTING_OPTIONS */
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_DPP2
#endif /* CONFIG_DPP2 */
void dpp_configurator_free(struct dpp_configurator *conf)
{
	if (!conf)
		return;
	EVP_PKEY_free(conf->csign);
	os_free(conf->kid);
	os_free(conf);
}
#ifdef CONFIG_TESTING_OPTIONS
#if OPENSSL_VERSION_NUMBER >= 0x10100000L || defined(OPENSSL_IS_BORINGSSL)
#else /* >=1.1.0 or OPENSSL_IS_BORINGSSL */
#endif /* >= 1.1.0 or OPENSSL_IS_BORINGSSL */
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#else /* CONFIG_TESTING_OPTIONS */
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#else /* CONFIG_TESTING_OPTIONS */
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
void dpp_pkex_free(struct dpp_pkex *pkex)
{
	if (!pkex)
		return;

	os_free(pkex->identifier);
	os_free(pkex->code);
	EVP_PKEY_free(pkex->x);
	EVP_PKEY_free(pkex->y);
	EVP_PKEY_free(pkex->peer_bootstrap_key);
	wpabuf_free(pkex->exchange_req);
	wpabuf_free(pkex->exchange_resp);
	os_free(pkex);
}
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_DPP2
void dpp_pfs_free(struct dpp_pfs *pfs)
{
	if (!pfs)
		return;
	crypto_ecdh_deinit(pfs->ecdh);
	wpabuf_free(pfs->ie);
	wpabuf_clear_free(pfs->secret);
	os_free(pfs);
}
#endif /* CONFIG_DPP2 */
int dpp_bootstrap_remove(struct dpp_global *dpp, const char *id)
{
	unsigned int id_val;

	if (os_strcmp(id, "*") == 0) {
		id_val = 0;
	} else {
		id_val = atoi(id);
		if (id_val == 0)
			return -1;
	}

	return dpp_bootstrap_del(dpp, id_val);
}
int dpp_configurator_remove(struct dpp_global *dpp, const char *id)
{
	unsigned int id_val;

	if (os_strcmp(id, "*") == 0) {
		id_val = 0;
	} else {
		id_val = atoi(id);
		if (id_val == 0)
			return -1;
	}

	return dpp_configurator_del(dpp, id_val);
}
#ifdef CONFIG_DPP2
static void dpp_connection_free(struct dpp_connection *conn)
{
	if (conn->sock >= 0) {
		wpa_printf(MSG_DEBUG, "DPP: Close Controller socket %d",
			   conn->sock);
		eloop_unregister_sock(conn->sock, EVENT_TYPE_READ);
		eloop_unregister_sock(conn->sock, EVENT_TYPE_WRITE);
		close(conn->sock);
	}
	wpabuf_free(conn->msg);
	wpabuf_free(conn->msg_out);
	dpp_auth_deinit(conn->auth);
	os_free(conn);
}
static void dpp_connection_remove(struct dpp_connection *conn)
{
	dl_list_del(&conn->list);
	dpp_connection_free(conn);
}
static void dpp_relay_controller_free(struct dpp_relay_controller *ctrl)
{
	struct dpp_connection *conn, *tmp;

	dl_list_for_each_safe(conn, tmp, &ctrl->conn, struct dpp_connection,
			      list)
		dpp_connection_remove(conn);
	os_free(ctrl);
}
#endif /* CONFIG_DPP2 */
#ifdef CONFIG_DPP2
#endif /* CONFIG_DPP2 */
#ifdef CONFIG_DPP2
#endif /* CONFIG_DPP2 */
#ifdef CONFIG_DPP2
#endif /* CONFIG_DPP2 */
#ifdef CONFIG_DPP2
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_IPV6
#endif /* CONFIG_IPV6 */
#ifdef CONFIG_IPV6
#endif /* CONFIG_IPV6 */
static void dpp_controller_free(struct dpp_controller *ctrl)
{
	struct dpp_connection *conn, *tmp;

	if (!ctrl)
		return;

	dl_list_for_each_safe(conn, tmp, &ctrl->conn, struct dpp_connection,
			      list)
		dpp_connection_remove(conn);

	if (ctrl->sock >= 0) {
		close(ctrl->sock);
		eloop_unregister_sock(ctrl->sock, EVENT_TYPE_READ);
	}
	os_free(ctrl->configurator_params);
	os_free(ctrl);
}
#endif /* CONFIG_DPP2 */
