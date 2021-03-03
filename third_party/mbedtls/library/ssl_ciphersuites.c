#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_SSL_TLS_C)
#if defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#else
#include <stdlib.h>
#endif
#include "mbedtls/ssl_ciphersuites.h"
#include "mbedtls/ssl.h"
#include <string.h>
#if defined(MBEDTLS_SSL_CIPHERSUITES)
#else
#endif /* MBEDTLS_SSL_CIPHERSUITES */
#if defined(MBEDTLS_CHACHAPOLY_C) && \
#if defined(MBEDTLS_KEY_EXCHANGE_ECDHE_RSA_ENABLED)
#endif
#if defined(MBEDTLS_KEY_EXCHANGE_ECDHE_ECDSA_ENABLED)
#endif
#if defined(MBEDTLS_KEY_EXCHANGE_DHE_RSA_ENABLED)
#endif
#if defined(MBEDTLS_KEY_EXCHANGE_PSK_ENABLED)
#endif
#if defined(MBEDTLS_KEY_EXCHANGE_ECDHE_PSK_ENABLED)
#endif
#if defined(MBEDTLS_KEY_EXCHANGE_DHE_PSK_ENABLED)
#endif
#if defined(MBEDTLS_KEY_EXCHANGE_RSA_PSK_ENABLED)
#endif
#endif /* MBEDTLS_CHACHAPOLY_C &&
#if defined(MBEDTLS_KEY_EXCHANGE_ECDHE_ECDSA_ENABLED)
#if defined(MBEDTLS_AES_C)
#if defined(MBEDTLS_SHA1_C)
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#endif /* MBEDTLS_SHA1_C */
#if defined(MBEDTLS_SHA256_C)
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#if defined(MBEDTLS_GCM_C)
#endif /* MBEDTLS_GCM_C */
#endif /* MBEDTLS_SHA256_C */
#if defined(MBEDTLS_SHA512_C)
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#if defined(MBEDTLS_GCM_C)
#endif /* MBEDTLS_GCM_C */
#endif /* MBEDTLS_SHA512_C */
#if defined(MBEDTLS_CCM_C)
#endif /* MBEDTLS_CCM_C */
#endif /* MBEDTLS_AES_C */
#if defined(MBEDTLS_CAMELLIA_C)
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#if defined(MBEDTLS_SHA256_C)
#endif /* MBEDTLS_SHA256_C */
#if defined(MBEDTLS_SHA512_C)
#endif /* MBEDTLS_SHA512_C */
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#if defined(MBEDTLS_GCM_C)
#if defined(MBEDTLS_SHA256_C)
#endif /* MBEDTLS_SHA256_C */
#if defined(MBEDTLS_SHA512_C)
#endif /* MBEDTLS_SHA512_C */
#endif /* MBEDTLS_GCM_C */
#endif /* MBEDTLS_CAMELLIA_C */
#if defined(MBEDTLS_DES_C)
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#if defined(MBEDTLS_SHA1_C)
#endif /* MBEDTLS_SHA1_C */
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#endif /* MBEDTLS_DES_C */
#if defined(MBEDTLS_ARC4_C)
#if defined(MBEDTLS_SHA1_C)
#endif /* MBEDTLS_SHA1_C */
#endif /* MBEDTLS_ARC4_C */
#if defined(MBEDTLS_CIPHER_NULL_CIPHER)
#if defined(MBEDTLS_SHA1_C)
#endif /* MBEDTLS_SHA1_C */
#endif /* MBEDTLS_CIPHER_NULL_CIPHER */
#endif /* MBEDTLS_KEY_EXCHANGE_ECDHE_ECDSA_ENABLED */
#if defined(MBEDTLS_KEY_EXCHANGE_ECDHE_RSA_ENABLED)
#if defined(MBEDTLS_AES_C)
#if defined(MBEDTLS_SHA1_C)
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#endif /* MBEDTLS_SHA1_C */
#if defined(MBEDTLS_SHA256_C)
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#if defined(MBEDTLS_GCM_C)
#endif /* MBEDTLS_GCM_C */
#endif /* MBEDTLS_SHA256_C */
#if defined(MBEDTLS_SHA512_C)
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#if defined(MBEDTLS_GCM_C)
#endif /* MBEDTLS_GCM_C */
#endif /* MBEDTLS_SHA512_C */
#endif /* MBEDTLS_AES_C */
#if defined(MBEDTLS_CAMELLIA_C)
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#if defined(MBEDTLS_SHA256_C)
#endif /* MBEDTLS_SHA256_C */
#if defined(MBEDTLS_SHA512_C)
#endif /* MBEDTLS_SHA512_C */
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#if defined(MBEDTLS_GCM_C)
#if defined(MBEDTLS_SHA256_C)
#endif /* MBEDTLS_SHA256_C */
#if defined(MBEDTLS_SHA512_C)
#endif /* MBEDTLS_SHA512_C */
#endif /* MBEDTLS_GCM_C */
#endif /* MBEDTLS_CAMELLIA_C */
#if defined(MBEDTLS_DES_C)
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#if defined(MBEDTLS_SHA1_C)
#endif /* MBEDTLS_SHA1_C */
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#endif /* MBEDTLS_DES_C */
#if defined(MBEDTLS_ARC4_C)
#if defined(MBEDTLS_SHA1_C)
#endif /* MBEDTLS_SHA1_C */
#endif /* MBEDTLS_ARC4_C */
#if defined(MBEDTLS_CIPHER_NULL_CIPHER)
#if defined(MBEDTLS_SHA1_C)
#endif /* MBEDTLS_SHA1_C */
#endif /* MBEDTLS_CIPHER_NULL_CIPHER */
#endif /* MBEDTLS_KEY_EXCHANGE_ECDHE_RSA_ENABLED */
#if defined(MBEDTLS_KEY_EXCHANGE_DHE_RSA_ENABLED)
#if defined(MBEDTLS_AES_C)
#if defined(MBEDTLS_SHA512_C) && defined(MBEDTLS_GCM_C)
#endif /* MBEDTLS_SHA512_C && MBEDTLS_GCM_C */
#if defined(MBEDTLS_SHA256_C)
#if defined(MBEDTLS_GCM_C)
#endif /* MBEDTLS_GCM_C */
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#endif /* MBEDTLS_SHA256_C */
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#if defined(MBEDTLS_SHA1_C)
#endif /* MBEDTLS_SHA1_C */
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#if defined(MBEDTLS_CCM_C)
#endif /* MBEDTLS_CCM_C */
#endif /* MBEDTLS_AES_C */
#if defined(MBEDTLS_CAMELLIA_C)
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#if defined(MBEDTLS_SHA256_C)
#endif /* MBEDTLS_SHA256_C */
#if defined(MBEDTLS_SHA1_C)
#endif /* MBEDTLS_SHA1_C */
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#if defined(MBEDTLS_GCM_C)
#if defined(MBEDTLS_SHA256_C)
#endif /* MBEDTLS_SHA256_C */
#if defined(MBEDTLS_SHA512_C)
#endif /* MBEDTLS_SHA512_C */
#endif /* MBEDTLS_GCM_C */
#endif /* MBEDTLS_CAMELLIA_C */
#if defined(MBEDTLS_DES_C)
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#if defined(MBEDTLS_SHA1_C)
#endif /* MBEDTLS_SHA1_C */
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#endif /* MBEDTLS_DES_C */
#endif /* MBEDTLS_KEY_EXCHANGE_DHE_RSA_ENABLED */
#if defined(MBEDTLS_KEY_EXCHANGE_RSA_ENABLED)
#if defined(MBEDTLS_AES_C)
#if defined(MBEDTLS_SHA512_C) && defined(MBEDTLS_GCM_C)
#endif /* MBEDTLS_SHA512_C && MBEDTLS_GCM_C */
#if defined(MBEDTLS_SHA256_C)
#if defined(MBEDTLS_GCM_C)
#endif /* MBEDTLS_GCM_C */
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#endif /* MBEDTLS_SHA256_C */
#if defined(MBEDTLS_SHA1_C)
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#endif /* MBEDTLS_SHA1_C */
#if defined(MBEDTLS_CCM_C)
#endif /* MBEDTLS_CCM_C */
#endif /* MBEDTLS_AES_C */
#if defined(MBEDTLS_CAMELLIA_C)
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#if defined(MBEDTLS_SHA256_C)
#endif /* MBEDTLS_SHA256_C */
#if defined(MBEDTLS_SHA1_C)
#endif /* MBEDTLS_SHA1_C */
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#if defined(MBEDTLS_GCM_C)
#if defined(MBEDTLS_SHA256_C)
#endif /* MBEDTLS_SHA256_C */
#if defined(MBEDTLS_SHA1_C)
#endif /* MBEDTLS_SHA1_C */
#endif /* MBEDTLS_GCM_C */
#endif /* MBEDTLS_CAMELLIA_C */
#if defined(MBEDTLS_DES_C)
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#if defined(MBEDTLS_SHA1_C)
#endif /* MBEDTLS_SHA1_C */
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#endif /* MBEDTLS_DES_C */
#if defined(MBEDTLS_ARC4_C)
#if defined(MBEDTLS_MD5_C)
#endif
#if defined(MBEDTLS_SHA1_C)
#endif
#endif /* MBEDTLS_ARC4_C */
#endif /* MBEDTLS_KEY_EXCHANGE_RSA_ENABLED */
#if defined(MBEDTLS_KEY_EXCHANGE_ECDH_RSA_ENABLED)
#if defined(MBEDTLS_AES_C)
#if defined(MBEDTLS_SHA1_C)
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#endif /* MBEDTLS_SHA1_C */
#if defined(MBEDTLS_SHA256_C)
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#if defined(MBEDTLS_GCM_C)
#endif /* MBEDTLS_GCM_C */
#endif /* MBEDTLS_SHA256_C */
#if defined(MBEDTLS_SHA512_C)
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#if defined(MBEDTLS_GCM_C)
#endif /* MBEDTLS_GCM_C */
#endif /* MBEDTLS_SHA512_C */
#endif /* MBEDTLS_AES_C */
#if defined(MBEDTLS_CAMELLIA_C)
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#if defined(MBEDTLS_SHA256_C)
#endif /* MBEDTLS_SHA256_C */
#if defined(MBEDTLS_SHA512_C)
#endif /* MBEDTLS_SHA512_C */
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#if defined(MBEDTLS_GCM_C)
#if defined(MBEDTLS_SHA256_C)
#endif /* MBEDTLS_SHA256_C */
#if defined(MBEDTLS_SHA512_C)
#endif /* MBEDTLS_SHA512_C */
#endif /* MBEDTLS_GCM_C */
#endif /* MBEDTLS_CAMELLIA_C */
#if defined(MBEDTLS_DES_C)
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#if defined(MBEDTLS_SHA1_C)
#endif /* MBEDTLS_SHA1_C */
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#endif /* MBEDTLS_DES_C */
#if defined(MBEDTLS_ARC4_C)
#if defined(MBEDTLS_SHA1_C)
#endif /* MBEDTLS_SHA1_C */
#endif /* MBEDTLS_ARC4_C */
#if defined(MBEDTLS_CIPHER_NULL_CIPHER)
#if defined(MBEDTLS_SHA1_C)
#endif /* MBEDTLS_SHA1_C */
#endif /* MBEDTLS_CIPHER_NULL_CIPHER */
#endif /* MBEDTLS_KEY_EXCHANGE_ECDH_RSA_ENABLED */
#if defined(MBEDTLS_KEY_EXCHANGE_ECDH_ECDSA_ENABLED)
#if defined(MBEDTLS_AES_C)
#if defined(MBEDTLS_SHA1_C)
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#endif /* MBEDTLS_SHA1_C */
#if defined(MBEDTLS_SHA256_C)
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#if defined(MBEDTLS_GCM_C)
#endif /* MBEDTLS_GCM_C */
#endif /* MBEDTLS_SHA256_C */
#if defined(MBEDTLS_SHA512_C)
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#if defined(MBEDTLS_GCM_C)
#endif /* MBEDTLS_GCM_C */
#endif /* MBEDTLS_SHA512_C */
#endif /* MBEDTLS_AES_C */
#if defined(MBEDTLS_CAMELLIA_C)
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#if defined(MBEDTLS_SHA256_C)
#endif /* MBEDTLS_SHA256_C */
#if defined(MBEDTLS_SHA512_C)
#endif /* MBEDTLS_SHA512_C */
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#if defined(MBEDTLS_GCM_C)
#if defined(MBEDTLS_SHA256_C)
#endif /* MBEDTLS_SHA256_C */
#if defined(MBEDTLS_SHA512_C)
#endif /* MBEDTLS_SHA512_C */
#endif /* MBEDTLS_GCM_C */
#endif /* MBEDTLS_CAMELLIA_C */
#if defined(MBEDTLS_DES_C)
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#if defined(MBEDTLS_SHA1_C)
#endif /* MBEDTLS_SHA1_C */
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#endif /* MBEDTLS_DES_C */
#if defined(MBEDTLS_ARC4_C)
#if defined(MBEDTLS_SHA1_C)
#endif /* MBEDTLS_SHA1_C */
#endif /* MBEDTLS_ARC4_C */
#if defined(MBEDTLS_CIPHER_NULL_CIPHER)
#if defined(MBEDTLS_SHA1_C)
#endif /* MBEDTLS_SHA1_C */
#endif /* MBEDTLS_CIPHER_NULL_CIPHER */
#endif /* MBEDTLS_KEY_EXCHANGE_ECDH_ECDSA_ENABLED */
#if defined(MBEDTLS_KEY_EXCHANGE_PSK_ENABLED)
#if defined(MBEDTLS_AES_C)
#if defined(MBEDTLS_GCM_C)
#if defined(MBEDTLS_SHA256_C)
#endif /* MBEDTLS_SHA256_C */
#if defined(MBEDTLS_SHA512_C)
#endif /* MBEDTLS_SHA512_C */
#endif /* MBEDTLS_GCM_C */
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#if defined(MBEDTLS_SHA256_C)
#endif /* MBEDTLS_SHA256_C */
#if defined(MBEDTLS_SHA512_C)
#endif /* MBEDTLS_SHA512_C */
#if defined(MBEDTLS_SHA1_C)
#endif /* MBEDTLS_SHA1_C */
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#if defined(MBEDTLS_CCM_C)
#endif /* MBEDTLS_CCM_C */
#endif /* MBEDTLS_AES_C */
#if defined(MBEDTLS_CAMELLIA_C)
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#if defined(MBEDTLS_SHA256_C)
#endif /* MBEDTLS_SHA256_C */
#if defined(MBEDTLS_SHA512_C)
#endif /* MBEDTLS_SHA512_C */
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#if defined(MBEDTLS_GCM_C)
#if defined(MBEDTLS_SHA256_C)
#endif /* MBEDTLS_SHA256_C */
#if defined(MBEDTLS_SHA512_C)
#endif /* MBEDTLS_SHA512_C */
#endif /* MBEDTLS_GCM_C */
#endif /* MBEDTLS_CAMELLIA_C */
#if defined(MBEDTLS_DES_C)
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#if defined(MBEDTLS_SHA1_C)
#endif /* MBEDTLS_SHA1_C */
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#endif /* MBEDTLS_DES_C */
#if defined(MBEDTLS_ARC4_C)
#if defined(MBEDTLS_SHA1_C)
#endif /* MBEDTLS_SHA1_C */
#endif /* MBEDTLS_ARC4_C */
#endif /* MBEDTLS_KEY_EXCHANGE_PSK_ENABLED */
#if defined(MBEDTLS_KEY_EXCHANGE_DHE_PSK_ENABLED)
#if defined(MBEDTLS_AES_C)
#if defined(MBEDTLS_GCM_C)
#if defined(MBEDTLS_SHA256_C)
#endif /* MBEDTLS_SHA256_C */
#if defined(MBEDTLS_SHA512_C)
#endif /* MBEDTLS_SHA512_C */
#endif /* MBEDTLS_GCM_C */
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#if defined(MBEDTLS_SHA256_C)
#endif /* MBEDTLS_SHA256_C */
#if defined(MBEDTLS_SHA512_C)
#endif /* MBEDTLS_SHA512_C */
#if defined(MBEDTLS_SHA1_C)
#endif /* MBEDTLS_SHA1_C */
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#if defined(MBEDTLS_CCM_C)
#endif /* MBEDTLS_CCM_C */
#endif /* MBEDTLS_AES_C */
#if defined(MBEDTLS_CAMELLIA_C)
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#if defined(MBEDTLS_SHA256_C)
#endif /* MBEDTLS_SHA256_C */
#if defined(MBEDTLS_SHA512_C)
#endif /* MBEDTLS_SHA512_C */
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#if defined(MBEDTLS_GCM_C)
#if defined(MBEDTLS_SHA256_C)
#endif /* MBEDTLS_SHA256_C */
#if defined(MBEDTLS_SHA512_C)
#endif /* MBEDTLS_SHA512_C */
#endif /* MBEDTLS_GCM_C */
#endif /* MBEDTLS_CAMELLIA_C */
#if defined(MBEDTLS_DES_C)
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#if defined(MBEDTLS_SHA1_C)
#endif /* MBEDTLS_SHA1_C */
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#endif /* MBEDTLS_DES_C */
#if defined(MBEDTLS_ARC4_C)
#if defined(MBEDTLS_SHA1_C)
#endif /* MBEDTLS_SHA1_C */
#endif /* MBEDTLS_ARC4_C */
#endif /* MBEDTLS_KEY_EXCHANGE_DHE_PSK_ENABLED */
#if defined(MBEDTLS_KEY_EXCHANGE_ECDHE_PSK_ENABLED)
#if defined(MBEDTLS_AES_C)
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#if defined(MBEDTLS_SHA256_C)
#endif /* MBEDTLS_SHA256_C */
#if defined(MBEDTLS_SHA512_C)
#endif /* MBEDTLS_SHA512_C */
#if defined(MBEDTLS_SHA1_C)
#endif /* MBEDTLS_SHA1_C */
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#endif /* MBEDTLS_AES_C */
#if defined(MBEDTLS_CAMELLIA_C)
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#if defined(MBEDTLS_SHA256_C)
#endif /* MBEDTLS_SHA256_C */
#if defined(MBEDTLS_SHA512_C)
#endif /* MBEDTLS_SHA512_C */
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#endif /* MBEDTLS_CAMELLIA_C */
#if defined(MBEDTLS_DES_C)
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#if defined(MBEDTLS_SHA1_C)
#endif /* MBEDTLS_SHA1_C */
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#endif /* MBEDTLS_DES_C */
#if defined(MBEDTLS_ARC4_C)
#if defined(MBEDTLS_SHA1_C)
#endif /* MBEDTLS_SHA1_C */
#endif /* MBEDTLS_ARC4_C */
#endif /* MBEDTLS_KEY_EXCHANGE_ECDHE_PSK_ENABLED */
#if defined(MBEDTLS_KEY_EXCHANGE_RSA_PSK_ENABLED)
#if defined(MBEDTLS_AES_C)
#if defined(MBEDTLS_GCM_C)
#if defined(MBEDTLS_SHA256_C)
#endif /* MBEDTLS_SHA256_C */
#if defined(MBEDTLS_SHA512_C)
#endif /* MBEDTLS_SHA512_C */
#endif /* MBEDTLS_GCM_C */
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#if defined(MBEDTLS_SHA256_C)
#endif /* MBEDTLS_SHA256_C */
#if defined(MBEDTLS_SHA512_C)
#endif /* MBEDTLS_SHA512_C */
#if defined(MBEDTLS_SHA1_C)
#endif /* MBEDTLS_SHA1_C */
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#endif /* MBEDTLS_AES_C */
#if defined(MBEDTLS_CAMELLIA_C)
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#if defined(MBEDTLS_SHA256_C)
#endif /* MBEDTLS_SHA256_C */
#if defined(MBEDTLS_SHA512_C)
#endif /* MBEDTLS_SHA512_C */
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#if defined(MBEDTLS_GCM_C)
#if defined(MBEDTLS_SHA256_C)
#endif /* MBEDTLS_SHA256_C */
#if defined(MBEDTLS_SHA512_C)
#endif /* MBEDTLS_SHA512_C */
#endif /* MBEDTLS_GCM_C */
#endif /* MBEDTLS_CAMELLIA_C */
#if defined(MBEDTLS_DES_C)
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#if defined(MBEDTLS_SHA1_C)
#endif /* MBEDTLS_SHA1_C */
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#endif /* MBEDTLS_DES_C */
#if defined(MBEDTLS_ARC4_C)
#if defined(MBEDTLS_SHA1_C)
#endif /* MBEDTLS_SHA1_C */
#endif /* MBEDTLS_ARC4_C */
#endif /* MBEDTLS_KEY_EXCHANGE_RSA_PSK_ENABLED */
#if defined(MBEDTLS_KEY_EXCHANGE_ECJPAKE_ENABLED)
#if defined(MBEDTLS_AES_C)
#if defined(MBEDTLS_CCM_C)
#endif /* MBEDTLS_CCM_C */
#endif /* MBEDTLS_AES_C */
#endif /* MBEDTLS_KEY_EXCHANGE_ECJPAKE_ENABLED */
#if defined(MBEDTLS_ENABLE_WEAK_CIPHERSUITES)
#if defined(MBEDTLS_CIPHER_NULL_CIPHER)
#if defined(MBEDTLS_KEY_EXCHANGE_RSA_ENABLED)
#if defined(MBEDTLS_MD5_C)
#endif
#if defined(MBEDTLS_SHA1_C)
#endif
#if defined(MBEDTLS_SHA256_C)
#endif
#endif /* MBEDTLS_KEY_EXCHANGE_RSA_ENABLED */
#if defined(MBEDTLS_KEY_EXCHANGE_PSK_ENABLED)
#if defined(MBEDTLS_SHA1_C)
#endif /* MBEDTLS_SHA1_C */
#if defined(MBEDTLS_SHA256_C)
#endif
#if defined(MBEDTLS_SHA512_C)
#endif
#endif /* MBEDTLS_KEY_EXCHANGE_PSK_ENABLED */
#if defined(MBEDTLS_KEY_EXCHANGE_DHE_PSK_ENABLED)
#if defined(MBEDTLS_SHA1_C)
#endif /* MBEDTLS_SHA1_C */
#if defined(MBEDTLS_SHA256_C)
#endif
#if defined(MBEDTLS_SHA512_C)
#endif
#endif /* MBEDTLS_KEY_EXCHANGE_DHE_PSK_ENABLED */
#if defined(MBEDTLS_KEY_EXCHANGE_ECDHE_PSK_ENABLED)
#if defined(MBEDTLS_SHA1_C)
#endif /* MBEDTLS_SHA1_C */
#if defined(MBEDTLS_SHA256_C)
#endif
#if defined(MBEDTLS_SHA512_C)
#endif
#endif /* MBEDTLS_KEY_EXCHANGE_ECDHE_PSK_ENABLED */
#if defined(MBEDTLS_KEY_EXCHANGE_RSA_PSK_ENABLED)
#if defined(MBEDTLS_SHA1_C)
#endif /* MBEDTLS_SHA1_C */
#if defined(MBEDTLS_SHA256_C)
#endif
#if defined(MBEDTLS_SHA512_C)
#endif
#endif /* MBEDTLS_KEY_EXCHANGE_RSA_PSK_ENABLED */
#endif /* MBEDTLS_CIPHER_NULL_CIPHER */
#if defined(MBEDTLS_DES_C)
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#if defined(MBEDTLS_KEY_EXCHANGE_DHE_RSA_ENABLED)
#if defined(MBEDTLS_SHA1_C)
#endif /* MBEDTLS_SHA1_C */
#endif /* MBEDTLS_KEY_EXCHANGE_DHE_RSA_ENABLED */
#if defined(MBEDTLS_KEY_EXCHANGE_RSA_ENABLED)
#if defined(MBEDTLS_SHA1_C)
#endif /* MBEDTLS_SHA1_C */
#endif /* MBEDTLS_KEY_EXCHANGE_RSA_ENABLED */
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#endif /* MBEDTLS_DES_C */
#endif /* MBEDTLS_ENABLE_WEAK_CIPHERSUITES */
#if defined(MBEDTLS_ARIA_C)
#if defined(MBEDTLS_KEY_EXCHANGE_RSA_ENABLED)
#if (defined(MBEDTLS_GCM_C) && defined(MBEDTLS_SHA512_C))
#endif
#if (defined(MBEDTLS_CIPHER_MODE_CBC) && defined(MBEDTLS_SHA512_C))
#endif
#if (defined(MBEDTLS_GCM_C) && defined(MBEDTLS_SHA256_C))
#endif
#if (defined(MBEDTLS_CIPHER_MODE_CBC) && defined(MBEDTLS_SHA256_C))
#endif
#endif /* MBEDTLS_KEY_EXCHANGE_RSA_ENABLED */
#if defined(MBEDTLS_KEY_EXCHANGE_RSA_PSK_ENABLED)
#if (defined(MBEDTLS_GCM_C) && defined(MBEDTLS_SHA512_C))
#endif
#if (defined(MBEDTLS_CIPHER_MODE_CBC) && defined(MBEDTLS_SHA512_C))
#endif
#if (defined(MBEDTLS_GCM_C) && defined(MBEDTLS_SHA256_C))
#endif
#if (defined(MBEDTLS_CIPHER_MODE_CBC) && defined(MBEDTLS_SHA256_C))
#endif
#endif /* MBEDTLS_KEY_EXCHANGE_RSA_PSK_ENABLED */
#if defined(MBEDTLS_KEY_EXCHANGE_PSK_ENABLED)
#if (defined(MBEDTLS_GCM_C) && defined(MBEDTLS_SHA512_C))
#endif
#if (defined(MBEDTLS_CIPHER_MODE_CBC) && defined(MBEDTLS_SHA512_C))
#endif
#if (defined(MBEDTLS_GCM_C) && defined(MBEDTLS_SHA256_C))
#endif
#if (defined(MBEDTLS_CIPHER_MODE_CBC) && defined(MBEDTLS_SHA256_C))
#endif
#endif /* MBEDTLS_KEY_EXCHANGE_PSK_ENABLED */
#if defined(MBEDTLS_KEY_EXCHANGE_ECDH_RSA_ENABLED)
#if (defined(MBEDTLS_GCM_C) && defined(MBEDTLS_SHA512_C))
#endif
#if (defined(MBEDTLS_CIPHER_MODE_CBC) && defined(MBEDTLS_SHA512_C))
#endif
#if (defined(MBEDTLS_GCM_C) && defined(MBEDTLS_SHA256_C))
#endif
#if (defined(MBEDTLS_CIPHER_MODE_CBC) && defined(MBEDTLS_SHA256_C))
#endif
#endif /* MBEDTLS_KEY_EXCHANGE_ECDH_RSA_ENABLED */
#if defined(MBEDTLS_KEY_EXCHANGE_ECDHE_RSA_ENABLED)
#if (defined(MBEDTLS_GCM_C) && defined(MBEDTLS_SHA512_C))
#endif
#if (defined(MBEDTLS_CIPHER_MODE_CBC) && defined(MBEDTLS_SHA512_C))
#endif
#if (defined(MBEDTLS_GCM_C) && defined(MBEDTLS_SHA256_C))
#endif
#if (defined(MBEDTLS_CIPHER_MODE_CBC) && defined(MBEDTLS_SHA256_C))
#endif
#endif /* MBEDTLS_KEY_EXCHANGE_ECDHE_RSA_ENABLED */
#if defined(MBEDTLS_KEY_EXCHANGE_ECDHE_PSK_ENABLED)
#if (defined(MBEDTLS_CIPHER_MODE_CBC) && defined(MBEDTLS_SHA512_C))
#endif
#if (defined(MBEDTLS_CIPHER_MODE_CBC) && defined(MBEDTLS_SHA256_C))
#endif
#endif /* MBEDTLS_KEY_EXCHANGE_ECDHE_PSK_ENABLED */
#if defined(MBEDTLS_KEY_EXCHANGE_ECDHE_ECDSA_ENABLED)
#if (defined(MBEDTLS_GCM_C) && defined(MBEDTLS_SHA512_C))
#endif
#if (defined(MBEDTLS_CIPHER_MODE_CBC) && defined(MBEDTLS_SHA512_C))
#endif
#if (defined(MBEDTLS_GCM_C) && defined(MBEDTLS_SHA256_C))
#endif
#if (defined(MBEDTLS_CIPHER_MODE_CBC) && defined(MBEDTLS_SHA256_C))
#endif
#endif /* MBEDTLS_KEY_EXCHANGE_ECDHE_ECDSA_ENABLED */
#if defined(MBEDTLS_KEY_EXCHANGE_ECDH_ECDSA_ENABLED)
#if (defined(MBEDTLS_GCM_C) && defined(MBEDTLS_SHA512_C))
#endif
#if (defined(MBEDTLS_CIPHER_MODE_CBC) && defined(MBEDTLS_SHA512_C))
#endif
#if (defined(MBEDTLS_GCM_C) && defined(MBEDTLS_SHA256_C))
#endif
#if (defined(MBEDTLS_CIPHER_MODE_CBC) && defined(MBEDTLS_SHA256_C))
#endif
#endif /* MBEDTLS_KEY_EXCHANGE_ECDH_ECDSA_ENABLED */
#if defined(MBEDTLS_KEY_EXCHANGE_DHE_RSA_ENABLED)
#if (defined(MBEDTLS_GCM_C) && defined(MBEDTLS_SHA512_C))
#endif
#if (defined(MBEDTLS_CIPHER_MODE_CBC) && defined(MBEDTLS_SHA512_C))
#endif
#if (defined(MBEDTLS_GCM_C) && defined(MBEDTLS_SHA256_C))
#endif
#if (defined(MBEDTLS_CIPHER_MODE_CBC) && defined(MBEDTLS_SHA256_C))
#endif
#endif /* MBEDTLS_KEY_EXCHANGE_DHE_RSA_ENABLED */
#if defined(MBEDTLS_KEY_EXCHANGE_DHE_PSK_ENABLED)
#if (defined(MBEDTLS_GCM_C) && defined(MBEDTLS_SHA512_C))
#endif
#if (defined(MBEDTLS_CIPHER_MODE_CBC) && defined(MBEDTLS_SHA512_C))
#endif
#if (defined(MBEDTLS_GCM_C) && defined(MBEDTLS_SHA256_C))
#endif
#if (defined(MBEDTLS_CIPHER_MODE_CBC) && defined(MBEDTLS_SHA256_C))
#endif
#endif /* MBEDTLS_KEY_EXCHANGE_DHE_PSK_ENABLED */
#endif /* MBEDTLS_ARIA_C */
#if defined(MBEDTLS_SSL_CIPHERSUITES)
#else
#define MAX_CIPHERSUITES    sizeof( ciphersuite_definitions     ) /         \
#if defined(MBEDTLS_REMOVE_ARC4_CIPHERSUITES)
#endif /* MBEDTLS_REMOVE_ARC4_CIPHERSUITES */
#if defined(MBEDTLS_REMOVE_3DES_CIPHERSUITES)
#endif /* MBEDTLS_REMOVE_3DES_CIPHERSUITES */
#endif /* MBEDTLS_SSL_CIPHERSUITES */
#if defined(MBEDTLS_PK_C)
#endif /* MBEDTLS_PK_C */
#if defined(MBEDTLS_ECDH_C) || defined(MBEDTLS_ECDSA_C) || \
#endif /* MBEDTLS_ECDH_C || MBEDTLS_ECDSA_C || MBEDTLS_KEY_EXCHANGE_ECJPAKE_ENABLED*/
#if defined(MBEDTLS_KEY_EXCHANGE__SOME__PSK_ENABLED)
#endif /* MBEDTLS_KEY_EXCHANGE__SOME__PSK_ENABLED */
#endif /* MBEDTLS_SSL_TLS_C */
