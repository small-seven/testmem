#include "includes.h"
#include <openssl/opensslv.h>
#include <openssl/err.h>
#include <openssl/des.h>
#include <openssl/aes.h>
#include <openssl/bn.h>
#include <openssl/evp.h>
#include <openssl/dh.h>
#include <openssl/hmac.h>
#include <openssl/rand.h>
#ifdef CONFIG_OPENSSL_CMAC
#include <openssl/cmac.h>
#endif /* CONFIG_OPENSSL_CMAC */
#ifdef CONFIG_ECC
#include <openssl/ec.h>
#endif /* CONFIG_ECC */
#include "common.h"
#include "utils/const_time.h"
#include "wpabuf.h"
#include "dh_group5.h"
#include "sha1.h"
#include "sha256.h"
#include "sha384.h"
#include "sha512.h"
#include "md5.h"
#include "aes_wrap.h"
#include "crypto.h"
#if OPENSSL_VERSION_NUMBER < 0x10100000L || \
static void HMAC_CTX_free(HMAC_CTX *ctx)
{
	if (!ctx)
		return;
	HMAC_CTX_cleanup(ctx);
	bin_clear_free(ctx, sizeof(*ctx));
}
static void EVP_MD_CTX_free(EVP_MD_CTX *ctx)
{
	if (!ctx)
		return;
	EVP_MD_CTX_cleanup(ctx);
	bin_clear_free(ctx, sizeof(*ctx));
}
#endif /* OpenSSL version < 1.1.0 */
#if OPENSSL_VERSION_NUMBER >= 0x10100000L && \
#elif !defined(OPENSSL_IS_BORINGSSL)
#else
#endif
#ifdef OPENSSL_NO_SHA256
#define NO_SHA256_WRAPPER
#endif
#ifdef OPENSSL_NO_SHA512
#define NO_SHA384_WRAPPER
#endif
#ifndef CONFIG_FIPS
#endif /* CONFIG_FIPS */
#ifndef CONFIG_NO_RC4
#ifdef OPENSSL_NO_RC4
#else /* OPENSSL_NO_RC4 */
#endif /* OPENSSL_NO_RC4 */
#endif /* CONFIG_NO_RC4 */
#ifndef CONFIG_FIPS
#endif /* CONFIG_FIPS */
#ifndef NO_SHA256_WRAPPER
#endif /* NO_SHA256_WRAPPER */
#ifndef NO_SHA384_WRAPPER
#endif /* NO_SHA384_WRAPPER */
#ifndef NO_SHA512_WRAPPER
#endif /* NO_SHA512_WRAPPER */
void aes_encrypt_deinit(void *ctx)
{
	EVP_CIPHER_CTX *c = ctx;
	u8 buf[16];
	int len = sizeof(buf);
	if (EVP_EncryptFinal_ex(c, buf, &len) != 1) {
		wpa_printf(MSG_ERROR, "OpenSSL: EVP_EncryptFinal_ex failed: "
			   "%s", ERR_error_string(ERR_get_error(), NULL));
	}
	if (len != 0) {
		wpa_printf(MSG_ERROR, "OpenSSL: Unexpected padding length %d "
			   "in AES encrypt", len);
	}
	EVP_CIPHER_CTX_free(c);
}
void aes_decrypt_deinit(void *ctx)
{
	EVP_CIPHER_CTX *c = ctx;
	u8 buf[16];
	int len = sizeof(buf);
	if (EVP_DecryptFinal_ex(c, buf, &len) != 1) {
		wpa_printf(MSG_ERROR, "OpenSSL: EVP_DecryptFinal_ex failed: "
			   "%s", ERR_error_string(ERR_get_error(), NULL));
	}
	if (len != 0) {
		wpa_printf(MSG_ERROR, "OpenSSL: Unexpected padding length %d "
			   "in AES decrypt", len);
	}
	EVP_CIPHER_CTX_free(c);
}
#ifndef CONFIG_FIPS
#ifndef CONFIG_OPENSSL_INTERNAL_AES_WRAP
#endif /* CONFIG_OPENSSL_INTERNAL_AES_WRAP */
#endif /* CONFIG_FIPS */
#ifndef CONFIG_NO_RC4
#ifndef OPENSSL_NO_RC4
#endif /* OPENSSL_NO_RC4 */
#endif /* CONFIG_NO_RC4 */
#ifndef OPENSSL_NO_AES
#ifndef OPENSSL_IS_BORINGSSL
#endif /* OPENSSL_IS_BORINGSSL */
#endif /* OPENSSL_NO_AES */
#ifndef OPENSSL_NO_DES
#endif /* OPENSSL_NO_DES */
#ifndef OPENSSL_NO_RC2
#endif /* OPENSSL_NO_RC2 */
#if OPENSSL_VERSION_NUMBER < 0x10100000L || \
#else
#endif
#if OPENSSL_VERSION_NUMBER < 0x10100000L || \
#else
#endif
void dh5_free(void *ctx)
{
	DH *dh;
	if (ctx == NULL)
		return;
	dh = ctx;
	DH_free(dh);
}
#ifndef OPENSSL_NO_MD5
#endif /* OPENSSL_NO_MD5 */
#ifndef OPENSSL_NO_SHA
#endif /* OPENSSL_NO_SHA */
#ifndef OPENSSL_NO_SHA256
#ifdef CONFIG_SHA256
#endif /* CONFIG_SHA256 */
#endif /* OPENSSL_NO_SHA256 */
#ifndef CONFIG_FIPS
#endif /* CONFIG_FIPS */
#ifdef CONFIG_SHA256
#endif /* CONFIG_SHA256 */
#ifdef CONFIG_SHA384
#endif /* CONFIG_SHA384 */
#ifdef CONFIG_SHA512
#endif /* CONFIG_SHA512 */
#ifdef CONFIG_OPENSSL_CMAC
#endif /* CONFIG_OPENSSL_CMAC */
#ifdef OPENSSL_IS_BORINGSSL
#else /* OPENSSL_IS_BORINGSSL */
#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
#endif
#endif
#ifdef OPENSSL_IS_BORINGSSL
#else /* OPENSSL_IS_BORINGSSL */
#endif /* OPENSSL_IS_BORINGSSL */
#ifndef OPENSSL_IS_BORINGSSL
#endif /* OPENSSL_IS_BORINGSSL */
#ifdef CONFIG_ECC
#ifdef NID_brainpoolP224r1
#endif /* NID_brainpoolP224r1 */
#ifdef NID_brainpoolP256r1
#endif /* NID_brainpoolP256r1 */
#ifdef NID_brainpoolP384r1
#endif /* NID_brainpoolP384r1 */
#ifdef NID_brainpoolP512r1
#endif /* NID_brainpoolP512r1 */
#endif /* CONFIG_ECC */
