#include "includes.h"
#include <gnutls/gnutls.h>
#include <gnutls/x509.h>
#ifdef PKCS12_FUNCS
#include <gnutls/pkcs12.h>
#endif /* PKCS12_FUNCS */
#if GNUTLS_VERSION_NUMBER >= 0x030103
#include <gnutls/ocsp.h>
#endif /* 3.1.3 */
#include "common.h"
#include "crypto/crypto.h"
#include "tls.h"
void tls_deinit(void *ssl_ctx)
{
	struct tls_global *global = ssl_ctx;
	if (global) {
		if (global->params_set)
			gnutls_certificate_free_credentials(global->xcred);
		os_free(global->session_data);
		os_free(global->ocsp_stapling_response);
		os_free(global);
	}

	tls_gnutls_ref_count--;
	if (tls_gnutls_ref_count == 0)
		gnutls_global_deinit();
}
void tls_connection_deinit(void *ssl_ctx, struct tls_connection *conn)
{
	if (conn == NULL)
		return;

	gnutls_certificate_free_credentials(conn->xcred);
	gnutls_deinit(conn->session);
	os_free(conn->pre_shared_secret);
	wpabuf_free(conn->push_buf);
	wpabuf_free(conn->pull_buf);
	os_free(conn->suffix_match);
	os_free(conn->domain_match);
	os_free(conn);
}
#if GNUTLS_VERSION_NUMBER >= 0x030300
#else /* < 3.3.0 */
#endif /* >= 3.3.0 */
#if GNUTLS_VERSION_NUMBER >= 0x03010b
#else
#endif
#if GNUTLS_VERSION_NUMBER >= 0x03010b
#else
#endif
#ifdef PKCS12_FUNCS
#endif /* PKCS12_FUNCS */
#if GNUTLS_VERSION_NUMBER >= 0x03010b
#else
#endif
#if GNUTLS_VERSION_NUMBER >= 0x03010b
#else
#endif
#ifdef PKCS12_FUNCS
#else /* PKCS12_FUNCS */
#endif /* PKCS12_FUNCS */
#if GNUTLS_VERSION_NUMBER >= 0x030103
#else /* 3.1.3 */
#endif /* 3.1.3 */
#if GNUTLS_VERSION_NUMBER >= 0x030103
#endif /* 3.1.3 */
#ifdef PKCS12_FUNCS
#endif /* PKCS12_FUNCS */
#if GNUTLS_VERSION_NUMBER >= 0x030103
#endif /* 3.1.3 */
#if GNUTLS_VERSION_NUMBER >= 0x030012
#else /* 3.0.18 */
#endif /* 3.0.18 */
#if GNUTLS_VERSION_NUMBER >= 0x030404
#else /* 3.4.4 */
#endif /* 3.4.4 */
#if GNUTLS_VERSION_NUMBER < 0x030300
#endif /* < 3.3.0 */
#if GNUTLS_VERSION_NUMBER >= 0x030103
#else /* GnuTLS 3.1.3 or newer */
#endif /* GnuTLS 3.1.3 or newer */
#if GNUTLS_VERSION_NUMBER >= 0x030300
#endif /* >= 3.3.0 */
#if GNUTLS_VERSION_NUMBER >= 0x030300
#else /* < 3.3.0 */
#endif
#if GNUTLS_VERSION_NUMBER >= 0x030104
#endif /* GnuTLS 3.1.4 or newer */
#ifdef CONFIG_SHA256
#endif /* CONFIG_SHA256 */
#ifdef CONFIG_SHA256
#endif /* CONFIG_SHA256 */
#if GNUTLS_VERSION_NUMBER >= 0x030300
#endif /* >= 3.3.0 */
#if GNUTLS_VERSION_NUMBER < 0x030300
#endif /* < 3.3.0 */
#if GNUTLS_VERSION_NUMBER >= 0x03010a
#endif /* GnuTLS 3.1.10 or newer */
void tls_connection_remove_session(struct tls_connection *conn)
{
}
