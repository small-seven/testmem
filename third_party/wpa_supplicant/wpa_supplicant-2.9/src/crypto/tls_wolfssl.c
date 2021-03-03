#include "includes.h"
#include "common.h"
#include "crypto.h"
#include "crypto/sha1.h"
#include "crypto/sha256.h"
#include "tls.h"
#include <wolfssl/options.h>
#include <wolfssl/ssl.h>
#include <wolfssl/error-ssl.h>
#include <wolfssl/wolfcrypt/asn.h>
#if defined(EAP_FAST) || defined(EAP_FAST_DYNAMIC) || defined(EAP_SERVER_FAST)
#define HAVE_AESGCM
#include <wolfssl/wolfcrypt/aes.h>
#endif
#if !defined(CONFIG_FIPS) &&                             \
#define WOLFSSL_NEED_EAP_FAST_PRF
#endif
#define SECRET_LEN          48
#define RAN_LEN             32
#define SESSION_TICKET_LEN  256
#if defined(EAP_FAST) || defined(EAP_FAST_DYNAMIC) || defined(EAP_SERVER_FAST)
#endif
#ifdef DEBUG_WOLFSSL
#endif /* DEBUG_WOLFSSL */
void tls_deinit(void *ssl_ctx)
{
	struct tls_context *context = wolfSSL_CTX_get_ex_data(ssl_ctx, 0);

	if (context != tls_global)
		os_free(context);

	wolfSSL_CTX_free((WOLFSSL_CTX *) ssl_ctx);

	tls_ref_count--;
	if (tls_ref_count == 0) {
		wolfSSL_Cleanup();
		os_free(tls_global);
		tls_global = NULL;
	}
}
#ifdef DEBUG_WOLFSSL
#if 0
#endif
#endif /* DEBUG_WOLFSSL */
void tls_connection_deinit(void *tls_ctx, struct tls_connection *conn)
{
	if (!conn)
		return;

	wpa_printf(MSG_DEBUG, "SSL: connection deinit");

	/* parts */
	wolfSSL_free(conn->ssl);
	os_free(conn->subject_match);
	os_free(conn->alt_subject_match);
	os_free(conn->suffix_match);
	os_free(conn->domain_match);

	/* self */
	os_free(conn);
}
#ifdef CONFIG_SHA256
#endif /* CONFIG_SHA256 */
#ifdef CONFIG_SHA256
#endif /* CONFIG_SHA256 */
#ifdef CONFIG_SHA256
#endif /* CONFIG_SHA256 */
#ifdef HAVE_OCSP_WOLFSSL
#endif /* HAVE_OCSP_WOLFSSL */
#ifdef CONFIG_SHA256
#else /* CONFIG_SHA256 */
#endif /* CONFIG_SHA256 */
#ifdef HAVE_SESSION_TICKET
#if 0
#endif
#endif /* HAVE_SESSION_TICKET */
#ifdef HAVE_CERTIFICATE_STATUS_REQUEST
#endif /* HAVE_CERTIFICATE_STATUS_REQUEST */
#ifdef HAVE_CERTIFICATE_STATUS_REQUEST_V2
#endif /* HAVE_CERTIFICATE_STATUS_REQUEST_V2 */
#if !defined(HAVE_CERTIFICATE_STATUS_REQUEST) && \
#ifdef HAVE_OCSP
#else /* HAVE_OCSP */
#endif /* HAVE_OCSP */
#endif /* !HAVE_CERTIFICATE_STATUS_REQUEST &&
#ifdef HAVE_OCSP
#endif /* HAVE_OCSP */
#ifdef HAVE_SESSION_TICKET
#endif /* HAVE_SESSION_TICKET */
#ifdef HAVE_OCSP
#endif /* HAVE_OCSP */
#define SEED_LEN	(RAN_LEN + RAN_LEN)
#if defined(EAP_FAST) || defined(EAP_FAST_DYNAMIC) || defined(EAP_SERVER_FAST)
#endif /* EAP_FAST || EAP_FAST_DYNAMIC || EAP_SERVER_FAST */
#if defined(EAP_FAST) || defined(EAP_FAST_DYNAMIC) || defined(EAP_SERVER_FAST)
#else /* EAP_FAST || EAP_FAST_DYNAMIC || EAP_SERVER_FAST */
#endif /* EAP_FAST || EAP_FAST_DYNAMIC || EAP_SERVER_FAST */
void tls_connection_remove_session(struct tls_connection *conn)
{
	WOLFSSL_SESSION *sess;

	sess = wolfSSL_get_session(conn->ssl);
	if (!sess)
		return;

	wolfSSL_SSL_SESSION_set_timeout(sess, 0);
	wpa_printf(MSG_DEBUG,
		   "wolfSSL: Removed cached session to disable session resumption");
}
