#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_ERROR_C) || defined(MBEDTLS_ERROR_STRERROR_DUMMY)
#include "mbedtls/error.h"
#include <string.h>
#endif
#if defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#else
#define mbedtls_snprintf snprintf
#define mbedtls_time_t   time_t
#endif
#if defined(MBEDTLS_ERROR_C)
#include <stdio.h>
#if defined(MBEDTLS_AES_C)
#include "mbedtls/aes.h"
#endif
#if defined(MBEDTLS_ARC4_C)
#include "mbedtls/arc4.h"
#endif
#if defined(MBEDTLS_ARIA_C)
#include "mbedtls/aria.h"
#endif
#if defined(MBEDTLS_BASE64_C)
#include "mbedtls/base64.h"
#endif
#if defined(MBEDTLS_BIGNUM_C)
#include "mbedtls/bignum.h"
#endif
#if defined(MBEDTLS_BLOWFISH_C)
#include "mbedtls/blowfish.h"
#endif
#if defined(MBEDTLS_CAMELLIA_C)
#include "mbedtls/camellia.h"
#endif
#if defined(MBEDTLS_CCM_C)
#include "mbedtls/ccm.h"
#endif
#if defined(MBEDTLS_CHACHA20_C)
#include "mbedtls/chacha20.h"
#endif
#if defined(MBEDTLS_CHACHAPOLY_C)
#include "mbedtls/chachapoly.h"
#endif
#if defined(MBEDTLS_CIPHER_C)
#include "mbedtls/cipher.h"
#endif
#if defined(MBEDTLS_CMAC_C)
#include "mbedtls/cmac.h"
#endif
#if defined(MBEDTLS_CTR_DRBG_C)
#include "mbedtls/ctr_drbg.h"
#endif
#if defined(MBEDTLS_DES_C)
#include "mbedtls/des.h"
#endif
#if defined(MBEDTLS_DHM_C)
#include "mbedtls/dhm.h"
#endif
#if defined(MBEDTLS_ECP_C)
#include "mbedtls/ecp.h"
#endif
#if defined(MBEDTLS_ENTROPY_C)
#include "mbedtls/entropy.h"
#endif
#if defined(MBEDTLS_GCM_C)
#include "mbedtls/gcm.h"
#endif
#if defined(MBEDTLS_HKDF_C)
#include "mbedtls/hkdf.h"
#endif
#if defined(MBEDTLS_HMAC_DRBG_C)
#include "mbedtls/hmac_drbg.h"
#endif
#if defined(MBEDTLS_MD_C)
#include "mbedtls/md.h"
#endif
#if defined(MBEDTLS_MD2_C)
#include "mbedtls/md2.h"
#endif
#if defined(MBEDTLS_MD4_C)
#include "mbedtls/md4.h"
#endif
#if defined(MBEDTLS_MD5_C)
#include "mbedtls/md5.h"
#endif
#if defined(MBEDTLS_NET_C)
#include "mbedtls/net_sockets.h"
#endif
#if defined(MBEDTLS_OID_C)
#include "mbedtls/oid.h"
#endif
#if defined(MBEDTLS_PADLOCK_C)
#include "mbedtls/padlock.h"
#endif
#if defined(MBEDTLS_PEM_PARSE_C) || defined(MBEDTLS_PEM_WRITE_C)
#include "mbedtls/pem.h"
#endif
#if defined(MBEDTLS_PK_C)
#include "mbedtls/pk.h"
#endif
#if defined(MBEDTLS_PKCS12_C)
#include "mbedtls/pkcs12.h"
#endif
#if defined(MBEDTLS_PKCS5_C)
#include "mbedtls/pkcs5.h"
#endif
#if defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#endif
#if defined(MBEDTLS_POLY1305_C)
#include "mbedtls/poly1305.h"
#endif
#if defined(MBEDTLS_RIPEMD160_C)
#include "mbedtls/ripemd160.h"
#endif
#if defined(MBEDTLS_RSA_C)
#include "mbedtls/rsa.h"
#endif
#if defined(MBEDTLS_SHA1_C)
#include "mbedtls/sha1.h"
#endif
#if defined(MBEDTLS_SHA256_C)
#include "mbedtls/sha256.h"
#endif
#if defined(MBEDTLS_SHA512_C)
#include "mbedtls/sha512.h"
#endif
#if defined(MBEDTLS_SSL_TLS_C)
#include "mbedtls/ssl.h"
#endif
#if defined(MBEDTLS_THREADING_C)
#include "mbedtls/threading.h"
#endif
#if defined(MBEDTLS_X509_USE_C) || defined(MBEDTLS_X509_CREATE_C)
#include "mbedtls/x509.h"
#endif
#if defined(MBEDTLS_XTEA_C)
#include "mbedtls/xtea.h"
#endif
#if defined(MBEDTLS_CIPHER_C)
#endif /* MBEDTLS_CIPHER_C */
#if defined(MBEDTLS_DHM_C)
#endif /* MBEDTLS_DHM_C */
#if defined(MBEDTLS_ECP_C)
#endif /* MBEDTLS_ECP_C */
#if defined(MBEDTLS_MD_C)
#endif /* MBEDTLS_MD_C */
#if defined(MBEDTLS_PEM_PARSE_C) || defined(MBEDTLS_PEM_WRITE_C)
#endif /* MBEDTLS_PEM_PARSE_C || MBEDTLS_PEM_WRITE_C */
#if defined(MBEDTLS_PK_C)
#endif /* MBEDTLS_PK_C */
#if defined(MBEDTLS_PKCS12_C)
#endif /* MBEDTLS_PKCS12_C */
#if defined(MBEDTLS_PKCS5_C)
#endif /* MBEDTLS_PKCS5_C */
#if defined(MBEDTLS_RSA_C)
#endif /* MBEDTLS_RSA_C */
#if defined(MBEDTLS_SSL_TLS_C)
#endif /* MBEDTLS_SSL_TLS_C */
#if defined(MBEDTLS_X509_USE_C) || defined(MBEDTLS_X509_CREATE_C)
#endif /* MBEDTLS_X509_USE_C || MBEDTLS_X509_CREATE_C */
#if defined(MBEDTLS_AES_C)
#endif /* MBEDTLS_AES_C */
#if defined(MBEDTLS_ARC4_C)
#endif /* MBEDTLS_ARC4_C */
#if defined(MBEDTLS_ARIA_C)
#endif /* MBEDTLS_ARIA_C */
#if defined(MBEDTLS_ASN1_PARSE_C)
#endif /* MBEDTLS_ASN1_PARSE_C */
#if defined(MBEDTLS_BASE64_C)
#endif /* MBEDTLS_BASE64_C */
#if defined(MBEDTLS_BIGNUM_C)
#endif /* MBEDTLS_BIGNUM_C */
#if defined(MBEDTLS_BLOWFISH_C)
#endif /* MBEDTLS_BLOWFISH_C */
#if defined(MBEDTLS_CAMELLIA_C)
#endif /* MBEDTLS_CAMELLIA_C */
#if defined(MBEDTLS_CCM_C)
#endif /* MBEDTLS_CCM_C */
#if defined(MBEDTLS_CHACHA20_C)
#endif /* MBEDTLS_CHACHA20_C */
#if defined(MBEDTLS_CHACHAPOLY_C)
#endif /* MBEDTLS_CHACHAPOLY_C */
#if defined(MBEDTLS_CMAC_C)
#endif /* MBEDTLS_CMAC_C */
#if defined(MBEDTLS_CTR_DRBG_C)
#endif /* MBEDTLS_CTR_DRBG_C */
#if defined(MBEDTLS_DES_C)
#endif /* MBEDTLS_DES_C */
#if defined(MBEDTLS_ENTROPY_C)
#endif /* MBEDTLS_ENTROPY_C */
#if defined(MBEDTLS_GCM_C)
#endif /* MBEDTLS_GCM_C */
#if defined(MBEDTLS_HKDF_C)
#endif /* MBEDTLS_HKDF_C */
#if defined(MBEDTLS_HMAC_DRBG_C)
#endif /* MBEDTLS_HMAC_DRBG_C */
#if defined(MBEDTLS_MD2_C)
#endif /* MBEDTLS_MD2_C */
#if defined(MBEDTLS_MD4_C)
#endif /* MBEDTLS_MD4_C */
#if defined(MBEDTLS_MD5_C)
#endif /* MBEDTLS_MD5_C */
#if defined(MBEDTLS_NET_C)
#endif /* MBEDTLS_NET_C */
#if defined(MBEDTLS_OID_C)
#endif /* MBEDTLS_OID_C */
#if defined(MBEDTLS_PADLOCK_C)
#endif /* MBEDTLS_PADLOCK_C */
#if defined(MBEDTLS_PLATFORM_C)
#endif /* MBEDTLS_PLATFORM_C */
#if defined(MBEDTLS_POLY1305_C)
#endif /* MBEDTLS_POLY1305_C */
#if defined(MBEDTLS_RIPEMD160_C)
#endif /* MBEDTLS_RIPEMD160_C */
#if defined(MBEDTLS_SHA1_C)
#endif /* MBEDTLS_SHA1_C */
#if defined(MBEDTLS_SHA256_C)
#endif /* MBEDTLS_SHA256_C */
#if defined(MBEDTLS_SHA512_C)
#endif /* MBEDTLS_SHA512_C */
#if defined(MBEDTLS_THREADING_C)
#endif /* MBEDTLS_THREADING_C */
#if defined(MBEDTLS_XTEA_C)
#endif /* MBEDTLS_XTEA_C */
#else /* MBEDTLS_ERROR_C */
#if defined(MBEDTLS_ERROR_STRERROR_DUMMY)
#endif /* MBEDTLS_ERROR_STRERROR_DUMMY */
#endif /* MBEDTLS_ERROR_C */
