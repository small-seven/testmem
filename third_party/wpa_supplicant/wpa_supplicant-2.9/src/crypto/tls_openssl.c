#include "includes.h"
#ifndef CONFIG_SMARTCARD
#ifndef OPENSSL_NO_ENGINE
#ifndef ANDROID
#define OPENSSL_NO_ENGINE
#endif
#endif
#endif
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <openssl/opensslv.h>
#include <openssl/pkcs12.h>
#include <openssl/x509v3.h>
#ifndef OPENSSL_NO_ENGINE
#include <openssl/engine.h>
#endif /* OPENSSL_NO_ENGINE */
#ifndef OPENSSL_NO_DSA
#include <openssl/dsa.h>
#endif
#ifndef OPENSSL_NO_DH
#include <openssl/dh.h>
#endif
#include "common.h"
#include "crypto.h"
#include "sha1.h"
#include "sha256.h"
#include "tls.h"
#include "tls_openssl.h"
#if !defined(CONFIG_FIPS) &&                             \
#define OPENSSL_NEED_EAP_FAST_PRF
#endif
#if defined(EAP_FAST) || defined(EAP_FAST_DYNAMIC) || \
#define EAP_FAST_OR_TEAP
#endif
#if defined(OPENSSL_IS_BORINGSSL)
typedef size_t stack_index_t;
#else
typedef int stack_index_t;
#endif

#ifdef SSL_set_tlsext_status_type
#ifndef OPENSSL_NO_TLSEXT
#define HAVE_OCSP
#include <openssl/ocsp.h>
#endif /* OPENSSL_NO_TLSEXT */
#endif /* SSL_set_tlsext_status_type */

#if (OPENSSL_VERSION_NUMBER < 0x10100000L || \
     (defined(LIBRESSL_VERSION_NUMBER) && \
      LIBRESSL_VERSION_NUMBER < 0x20700000L)) && \
    !defined(BORINGSSL_API_VERSION)
/*
 * SSL_get_client_random() and SSL_get_server_random() were added in OpenSSL
 * 1.1.0 and newer BoringSSL revisions. Provide compatibility wrappers for
 * older versions.
 */

static size_t SSL_get_client_random(const SSL *ssl, unsigned char *out,
				    size_t outlen)
{
	if (!ssl->s3 || outlen < SSL3_RANDOM_SIZE)
		return 0;
	os_memcpy(out, ssl->s3->client_random, SSL3_RANDOM_SIZE);
	return SSL3_RANDOM_SIZE;
}
#ifdef OPENSSL_NEED_EAP_FAST_PRF
#endif /* OPENSSL_NEED_EAP_FAST_PRF */
#endif
#if OPENSSL_VERSION_NUMBER < 0x10100000L || \
#ifdef CONFIG_SUITEB
#endif /* CONFIG_SUITEB */
#endif
#ifdef ANDROID
#include <openssl/pem.h>
#include <keystore/keystore_get.h>
#endif /* ANDROID */
#if defined(ANDROID) || !defined(OPENSSL_NO_ENGINE)
#endif /* OPENSSL_NO_ENGINE */
#ifdef CONFIG_NO_STDOUT_DEBUG
#define tls_show_errors(l, f, t) _tls_show_errors()
#else /* CONFIG_NO_STDOUT_DEBUG */
#endif /* CONFIG_NO_STDOUT_DEBUG */
#ifdef CONFIG_NATIVE_WINDOWS
#include <wincrypt.h>
#ifdef __MINGW32_VERSION
#define CERT_SYSTEM_STORE_CURRENT_USER (1 << 16)
#define CERT_STORE_READONLY_FLAG 0x00008000
#define CERT_STORE_OPEN_EXISTING_FLAG 0x00004000
#endif /* __MINGW32_VERSION */
static void cryptoapi_free_data(struct cryptoapi_rsa_data *priv)
{
	if (priv == NULL)
		return;
	if (priv->crypt_prov && priv->free_crypt_prov)
		CryptReleaseContext(priv->crypt_prov, 0);
	if (priv->cert)
		CertFreeCertificateContext(priv->cert);
	os_free(priv);
}
#ifdef UNICODE
#endif /* UNICODE */
#ifdef UNICODE
#else /* UNICODE */
#endif /* UNICODE */
#else /* CONFIG_NATIVE_WINDOWS */
#endif /* CONFIG_NATIVE_WINDOWS */
#ifndef OPENSSL_NO_ENGINE
#endif /* OPENSSL_NO_ENGINE */
#ifdef CONFIG_FIPS
#ifdef OPENSSL_FIPS
#else /* OPENSSL_FIPS */
#endif /* OPENSSL_FIPS */
#endif /* CONFIG_FIPS */
#if OPENSSL_VERSION_NUMBER < 0x10100000L || \
#ifndef OPENSSL_NO_SHA256
#endif /* OPENSSL_NO_SHA256 */
#ifdef PKCS12_FUNCS
#ifndef OPENSSL_NO_RC2
#endif /* OPENSSL_NO_RC2 */
#endif  /* PKCS12_FUNCS */
#endif /* < 1.1.0 */
#ifdef SSL_MODE_NO_AUTO_CHAIN
#endif /* SSL_MODE_NO_AUTO_CHAIN */
#ifndef OPENSSL_NO_ENGINE
#endif /* OPENSSL_NO_ENGINE */
void tls_deinit(void *ssl_ctx)
{
	struct tls_data *data = ssl_ctx;
	SSL_CTX *ssl = data->ssl;
	struct tls_context *context = SSL_CTX_get_app_data(ssl);
	if (context != tls_global)
		os_free(context);
	if (data->tls_session_lifetime > 0)
		SSL_CTX_flush_sessions(ssl, 0);
	os_free(data->ca_cert);
	SSL_CTX_free(ssl);

	tls_openssl_ref_count--;
	if (tls_openssl_ref_count == 0) {
#if OPENSSL_VERSION_NUMBER < 0x10100000L || \
	(defined(LIBRESSL_VERSION_NUMBER) && \
	 LIBRESSL_VERSION_NUMBER < 0x20700000L)
#ifndef OPENSSL_NO_ENGINE
		ENGINE_cleanup();
#endif /* OPENSSL_NO_ENGINE */
		CRYPTO_cleanup_all_ex_data();
		ERR_remove_thread_state(NULL);
		ERR_free_strings();
		EVP_cleanup();
#endif /* < 1.1.0 */
		os_free(tls_global->ocsp_stapling_response);
		tls_global->ocsp_stapling_response = NULL;
		os_free(tls_global);
		tls_global = NULL;
	}

	os_free(data->check_cert_subject);
	os_free(data);
}
#ifndef OPENSSL_NO_ENGINE
#define CKR_PIN_INCORRECT 0x000000a0
#define CKR_PIN_INVALID 0x000000a1
#define CKR_PIN_LEN_RANGE 0x000000a2
#define ERR_LIB_PKCS11	ERR_LIB_USER
#endif /* OPENSSL_NO_ENGINE */
#ifdef ANDROID
#endif /* ANDROID */
#if defined(ANDROID) && defined(OPENSSL_IS_BORINGSSL)
#if !defined(OPENSSL_NO_ENGINE)
#error "This code depends on OPENSSL_NO_ENGINE being defined by BoringSSL."
#endif
#endif /* ANDROID && OPENSSL_IS_BORINGSSL */
#ifndef OPENSSL_NO_ENGINE
#ifdef ANDROID
#endif
#ifndef ANDROID
#endif
#else /* OPENSSL_NO_ENGINE */
#endif /* OPENSSL_NO_ENGINE */
#if defined(ANDROID) || !defined(OPENSSL_NO_ENGINE)
#if !defined(OPENSSL_IS_BORINGSSL)
#endif /* !OPENSSL_IS_BORINGSSL */
#endif /* ANDROID || !OPENSSL_NO_ENGINE */
#ifdef CONFIG_SUITEB
#endif /* CONFIG_SUITEB */
#ifdef CONFIG_SUITEB
#endif /* CONFIG_SUITEB */
#ifdef SSL_OP_NO_COMPRESSION
#endif /* SSL_OP_NO_COMPRESSION */
#ifdef SSL_OP_ENABLE_MIDDLEBOX_COMPAT
#endif
void tls_connection_deinit(void *ssl_ctx, struct tls_connection *conn)
{
	if (conn == NULL)
		return;
	if (conn->success_data) {
		/*
		 * Make sure ssl_clear_bad_session() does not remove this
		 * session.
		 */
		SSL_set_quiet_shutdown(conn->ssl, 1);
		SSL_shutdown(conn->ssl);
	}
	SSL_free(conn->ssl);
	tls_engine_deinit(conn);
	os_free(conn->subject_match);
	os_free(conn->altsubject_match);
	os_free(conn->suffix_match);
	os_free(conn->domain_match);
	os_free(conn->check_cert_subject);
	os_free(conn->session_ticket);
	os_free(conn);
}
#ifndef CONFIG_NATIVE_WINDOWS
#endif /* CONFIG_NATIVE_WINDOWS */
#ifndef CONFIG_NATIVE_WINDOWS
#endif /* CONFIG_NATIVE_WINDOWS */
#ifdef CONFIG_NATIVE_WINDOWS
#else /* CONFIG_NATIVE_WINDOWS */
#endif /* CONFIG_NATIVE_WINDOWS */
#ifdef CONFIG_SHA256
#endif /* CONFIG_SHA256 */
#ifdef CONFIG_SHA256
#endif /* CONFIG_SHA256 */
#ifdef CONFIG_SHA256
#endif /* CONFIG_SHA256 */
#ifdef CONFIG_SUITEB
#endif /* CONFIG_SUITEB */
#ifdef OPENSSL_IS_BORINGSSL
#endif /* OPENSSL_IS_BORINGSSL */
#ifndef OPENSSL_NO_STDIO
#endif /* OPENSSL_NO_STDIO */
#ifdef CONFIG_SHA256
#else /* CONFIG_SHA256 */
#endif /* CONFIG_SHA256 */
#ifdef ANDROID
#endif /* ANDROID */
#ifdef CONFIG_NATIVE_WINDOWS
#endif /* CONFIG_NATIVE_WINDOWS */
#ifndef OPENSSL_NO_STDIO
#else /* OPENSSL_NO_STDIO */
#endif /* OPENSSL_NO_STDIO */
#ifndef OPENSSL_NO_STDIO
#endif /* OPENSSL_NO_STDIO */
#ifdef CONFIG_SUITEB
#if OPENSSL_VERSION_NUMBER >= 0x10002000L
#endif /* OPENSSL_VERSION_NUMBER */
#endif /* CONFIG_SUITEB */
#ifdef SSL_OP_NO_TICKET
#endif /* SSL_OP_NO_TICKET */
#ifdef SSL_OP_NO_TLSv1
#endif /* SSL_OP_NO_TLSv1 */
#ifdef SSL_OP_NO_TLSv1_1
#endif /* SSL_OP_NO_TLSv1_1 */
#ifdef SSL_OP_NO_TLSv1_2
#endif /* SSL_OP_NO_TLSv1_2 */
#ifdef SSL_OP_NO_TLSv1_3
#endif /* SSL_OP_NO_TLSv1_3 */
#if OPENSSL_VERSION_NUMBER >= 0x10100000L
#endif /* >= 1.1.0 */
#ifdef CONFIG_SUITEB
#ifdef OPENSSL_IS_BORINGSSL
#endif /* OPENSSL_IS_BORINGSSL */
#if OPENSSL_VERSION_NUMBER >= 0x10002000L
#ifdef OPENSSL_IS_BORINGSSL
#else /* OPENSSL_IS_BORINGSSL */
#endif /* OPENSSL_IS_BORINGSSL */
#else /* OPENSSL_VERSION_NUMBER < 0x10002000L */
#endif /* OPENSSL_VERSION_NUMBER */
#ifdef OPENSSL_IS_BORINGSSL
#else /* OPENSSL_IS_BORINGSSL */
#endif /* OPENSSL_IS_BORINGSSL */
#else /* CONFIG_SUITEB */
#endif /* CONFIG_SUITEB */
#ifndef TEAP_DH_ANON_CS
#define TEAP_DH_ANON_CS \
#endif
#if OPENSSL_VERSION_NUMBER >= 0x10100000L && \
#endif
#ifdef PKCS12_FUNCS
#if OPENSSL_VERSION_NUMBER < 0x10002000L || defined(LIBRESSL_VERSION_NUMBER)
#endif /* OPENSSL_VERSION_NUMBER < 0x10002000L */
#endif /* PKCS12_FUNCS */
#ifdef ANDROID
#endif /* ANDROID */
#ifndef OPENSSL_NO_STDIO
#if OPENSSL_VERSION_NUMBER >= 0x10100000L && \
#else
#endif
#else /* OPENSSL_NO_STDIO */
#endif /* OPENSSL_NO_STDIO */
#ifndef OPENSSL_NO_STDIO
#else /* OPENSSL_NO_STDIO */
#endif /* OPENSSL_NO_STDIO */
#ifdef PKCS12_FUNCS
#if OPENSSL_VERSION_NUMBER >= 0x10002000L && !defined(LIBRESSL_VERSION_NUMBER)
#ifndef OPENSSL_IS_BORINGSSL
#endif /* OPENSSL_IS_BORINGSSL */
#else /* OPENSSL_VERSION_NUMBER >= 0x10002000L */
#endif /* OPENSSL_VERSION_NUMBER >= 0x10002000L */
#endif  /* PKCS12_FUNCS */
#ifdef PKCS12_FUNCS
#else /* PKCS12_FUNCS */
#endif  /* PKCS12_FUNCS */
#ifdef PKCS12_FUNCS
#else /* PKCS12_FUNCS */
#endif  /* PKCS12_FUNCS */
#ifndef OPENSSL_NO_ENGINE
#endif /* OPENSSL_NO_ENGINE */
#ifndef OPENSSL_NO_ENGINE
#else /* OPENSSL_NO_ENGINE */
#endif /* OPENSSL_NO_ENGINE */
#ifndef OPENSSL_NO_ENGINE
#else /* OPENSSL_NO_ENGINE */
#endif /* OPENSSL_NO_ENGINE */
#if defined(ANDROID) || !defined(OPENSSL_NO_ENGINE)
#else /* OPENSSL_NO_ENGINE */
#endif /* OPENSSL_NO_ENGINE */
#ifndef OPENSSL_NO_STDIO
#endif /* OPENSSL_NO_STDIO */
#ifndef OPENSSL_NO_STDIO
#else /* OPENSSL_NO_STDIO */
#endif /* OPENSSL_NO_STDIO */
#ifdef OPENSSL_NO_DH
#else /* OPENSSL_NO_DH */
#ifndef OPENSSL_NO_DSA
#endif /* !OPENSSL_NO_DSA */
#endif /* OPENSSL_NO_DH */
#ifdef OPENSSL_NO_DH
#else /* OPENSSL_NO_DH */
#ifndef OPENSSL_NO_DSA
#endif /* !OPENSSL_NO_DSA */
#endif /* OPENSSL_NO_DH */
#ifdef OPENSSL_NEED_EAP_FAST_PRF
#if OPENSSL_VERSION_NUMBER < 0x10100000L || \
#else
#endif
#endif /* OPENSSL_NEED_EAP_FAST_PRF */
#ifdef OPENSSL_NEED_EAP_FAST_PRF
#else /* OPENSSL_NEED_EAP_FAST_PRF */
#endif /* OPENSSL_NEED_EAP_FAST_PRF */
#ifdef CONFIG_SUITEB
#endif /* CONFIG_SUITEB */
#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
#ifdef EAP_FAST_OR_TEAP
#endif /* EAP_FAST_OR_TEAP */
#endif
#ifdef EAP_FAST_OR_TEAP
#endif /* EAP_FAST_OR_TEAP */
#ifdef HAVE_OCSP
#ifndef CONFIG_NO_STDOUT_DEBUG
#endif /* CONFIG_NO_STDOUT_DEBUG */
#ifndef CONFIG_NO_STDOUT_DEBUG
#endif /* CONFIG_NO_STDOUT_DEBUG */
#endif /* HAVE_OCSP */
#if defined(EAP_FAST) || defined(EAP_FAST_DYNAMIC) || defined(EAP_SERVER_FAST)
#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
#endif
#if OPENSSL_VERSION_NUMBER >= 0x10101000L
#ifdef SSL_OP_NO_TLSv1_3
#endif /* SSL_OP_NO_TLSv1_3 */
#endif
#endif /* EAP_FAST || EAP_FAST_DYNAMIC || EAP_SERVER_FAST */
#ifdef CONFIG_SUITEB
#ifdef OPENSSL_IS_BORINGSSL
#endif /* OPENSSL_IS_BORINGSSL */
#endif /* CONFIG_SUITEB */
#ifndef OPENSSL_IS_BORINGSSL
#ifndef OPENSSL_NO_EC
#if (OPENSSL_VERSION_NUMBER >= 0x10002000L) && \
#endif /* >= 1.0.2 && < 1.1.0 */
#endif /* OPENSSL_NO_EC */
#endif /* OPENSSL_IS_BORINGSSL */
#if defined(OPENSSL_IS_BORINGSSL) || (OPENSSL_VERSION_NUMBER < 0x10002000L)
#else /* OPENSSL_IS_BORINGSSL || < 1.0.2 */
#ifndef OPENSSL_NO_EC
#else /* OPENSSL_NO_EC */
#endif /* OPENSSL_NO_EC */
#endif /* OPENSSL_IS_BORINGSSL */
#ifdef OPENSSL_IS_BORINGSSL
#else /* OPENSSL_IS_BORINGSSL */
#ifdef HAVE_OCSP
#else /* HAVE_OCSP */
#endif /* HAVE_OCSP */
#endif /* OPENSSL_IS_BORINGSSL */
#if !defined(LIBRESSL_VERSION_NUMBER) && !defined(BORINGSSL_API_VERSION)
#endif
#if !defined(LIBRESSL_VERSION_NUMBER) && !defined(BORINGSSL_API_VERSION)
#endif
#ifndef OPENSSL_IS_BORINGSSL
#ifndef OPENSSL_NO_EC
#if (OPENSSL_VERSION_NUMBER >= 0x10002000L) && \
#endif /* >= 1.0.2 && < 1.1.0 */
#endif /* OPENSSL_NO_EC */
#endif /* OPENSSL_IS_BORINGSSL */
#if defined(OPENSSL_IS_BORINGSSL) || (OPENSSL_VERSION_NUMBER < 0x10002000L)
#else /* OPENSSL_IS_BORINGSSL || < 1.0.2 */
#ifndef OPENSSL_NO_EC
#if OPENSSL_VERSION_NUMBER < 0x10100000L
#endif
#else /* OPENSSL_NO_EC */
#endif /* OPENSSL_NO_EC */
#endif /* OPENSSL_IS_BORINGSSL */
#ifdef SSL_OP_NO_TICKET
#endif /*  SSL_OP_NO_TICKET */
#ifdef HAVE_OCSP
#endif /* HAVE_OCSP */
#ifdef EAP_FAST_OR_TEAP
#if (defined(OPENSSL_IS_BORINGSSL) || OPENSSL_VERSION_NUMBER >= 0x10100000L) && !defined(LIBRESSL_VERSION_NUMBER)
#else /* OPENSSL_IS_BORINGSSL */
#endif /* OPENSSL_IS_BORINGSSL */
#if OPENSSL_VERSION_NUMBER < 0x10100000L || \
#else
#endif
#endif /* EAP_FAST_OR_TEAP */
#ifdef EAP_FAST_OR_TEAP
#else /* EAP_FAST_OR_TEAP */
#endif /* EAP_FAST_OR_TEAP */
#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
#else
#endif
void tls_connection_remove_session(struct tls_connection *conn)
{
	SSL_SESSION *sess;

	sess = SSL_get_session(conn->ssl);
	if (!sess)
		return;

	if (SSL_CTX_remove_session(conn->ssl_ctx, sess) != 1)
		wpa_printf(MSG_DEBUG,
			   "OpenSSL: Session was not cached");
	else
		wpa_printf(MSG_DEBUG,
			   "OpenSSL: Removed cached session to disable session resumption");
}
#if OPENSSL_VERSION_NUMBER >= 0x10101000L && !defined(LIBRESSL_VERSION_NUMBER)
#else
#endif
