#include "includes.h"
#include "common.h"
#include "crypto.h"
#include <wolfssl/options.h>
#include <wolfssl/wolfcrypt/md4.h>
#include <wolfssl/wolfcrypt/md5.h>
#include <wolfssl/wolfcrypt/sha.h>
#include <wolfssl/wolfcrypt/sha256.h>
#include <wolfssl/wolfcrypt/sha512.h>
#include <wolfssl/wolfcrypt/hmac.h>
#include <wolfssl/wolfcrypt/pwdbased.h>
#include <wolfssl/wolfcrypt/arc4.h>
#include <wolfssl/wolfcrypt/des3.h>
#include <wolfssl/wolfcrypt/aes.h>
#include <wolfssl/wolfcrypt/dh.h>
#include <wolfssl/wolfcrypt/cmac.h>
#include <wolfssl/wolfcrypt/ecc.h>
#include <wolfssl/openssl/bn.h>
#ifndef CONFIG_FIPS
#endif /* CONFIG_FIPS */
#ifndef NO_SHA256_WRAPPER
#endif /* NO_SHA256_WRAPPER */
#ifdef CONFIG_SHA384
#endif /* CONFIG_SHA384 */
#ifdef CONFIG_SHA512
#endif /* CONFIG_SHA512 */
#ifndef CONFIG_FIPS
#endif /* CONFIG_FIPS */
#ifdef CONFIG_SHA256
#endif /* CONFIG_SHA256 */
#ifdef CONFIG_SHA384
#endif /* CONFIG_SHA384 */
#ifdef CONFIG_SHA512
#endif /* CONFIG_SHA512 */
#ifdef CONFIG_DES
#endif /* CONFIG_DES */
void aes_encrypt_deinit(void *ctx)
{
	os_free(ctx);
}
void aes_decrypt_deinit(void *ctx)
{
	os_free(ctx);
}
#ifndef CONFIG_NO_RC4
#ifndef NO_RC4
#else /* NO_RC4 */
#endif /* NO_RC4 */
#endif /* CONFIG_NO_RC4 */
#if defined(EAP_IKEV2) || defined(EAP_IKEV2_DYNAMIC) \
#ifndef CONFIG_NO_RC4
#ifndef NO_RC4
#endif /* NO_RC4 */
#endif /* CONFIG_NO_RC4 */
#ifndef NO_AES
#endif /* NO_AES */
#ifndef NO_DES3
#endif /* NO_DES3 */
#ifndef CONFIG_NO_RC4
#ifndef NO_RC4
#endif /* NO_RC4 */
#endif /* CONFIG_NO_RC4 */
#ifndef NO_AES
#endif /* NO_AES */
#ifndef NO_DES3
#endif /* NO_DES3 */
#ifndef CONFIG_NO_RC4
#ifndef NO_RC4
#endif /* NO_RC4 */
#endif /* CONFIG_NO_RC4 */
#ifndef NO_AES
#endif /* NO_AES */
#ifndef NO_DES3
#endif /* NO_DES3 */
#endif
#ifdef CONFIG_WPS_NFC
#define RFC3526_LEN sizeof(RFC3526_PRIME_1536)
void dh5_free(void *ctx)
{
	if (!ctx)
		return;

	wc_FreeDhKey(ctx);
	XFREE(ctx, NULL, DYNAMIC_TYPE_TMP_BUFFER);
}
#endif /* CONFIG_WPS_NFC */
#ifdef CONFIG_FIPS
#endif /* CONFIG_FIPS */
#if defined(EAP_PWD) || defined(EAP_SERVER_PWD)
#ifndef NO_MD5
#endif /* NO_MD5 */
#ifndef NO_SHA
#endif /* NO_SHA */
#ifdef CONFIG_SHA256
#ifndef NO_SHA256
#endif /* NO_SHA256 */
#endif /* CONFIG_SHA256 */
#endif
#ifdef CONFIG_ECC
#ifdef HAVE_ECC_BRAINPOOL
#endif /* HAVE_ECC_BRAINPOOL */
#endif /* CONFIG_ECC */
