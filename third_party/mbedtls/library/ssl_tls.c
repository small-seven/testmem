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
#define mbedtls_calloc    calloc
#define mbedtls_free      free
#endif
#include "mbedtls/debug.h"
#include "mbedtls/ssl.h"
#include "mbedtls/ssl_internal.h"
#include "mbedtls/platform_util.h"
#include <string.h>
#if defined(MBEDTLS_X509_CRT_PARSE_C)
#include "mbedtls/oid.h"
#endif
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#else
#endif
#define SSL_DONT_FORCE_FLUSH 0
#define SSL_FORCE_FLUSH      1
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#if defined(MBEDTLS_SSL_MAX_FRAGMENT_LENGTH)
#endif
#endif /* MBEDTLS_SSL_PROTO_DTLS */
#if defined(MBEDTLS_SSL_MAX_FRAGMENT_LENGTH)
#endif /* MBEDTLS_SSL_MAX_FRAGMENT_LENGTH */
#if defined(MBEDTLS_SSL_CLI_C)
#if defined(MBEDTLS_X509_CRT_PARSE_C)
#endif /* MBEDTLS_X509_CRT_PARSE_C */
#if defined(MBEDTLS_SSL_SESSION_TICKETS) && defined(MBEDTLS_SSL_CLI_C)
#endif /* MBEDTLS_SSL_SESSION_TICKETS && MBEDTLS_SSL_CLI_C */
#endif /* MBEDTLS_SSL_CLI_C */
#if defined(MBEDTLS_SSL_HW_RECORD_ACCEL)
#endif /* MBEDTLS_SSL_HW_RECORD_ACCEL */
#if defined(MBEDTLS_SSL_PROTO_SSL3)
#endif /* MBEDTLS_SSL_PROTO_SSL3 */
#if defined(MBEDTLS_SSL_PROTO_TLS1) || defined(MBEDTLS_SSL_PROTO_TLS1_1)
#endif /* MBEDTLS_SSL_PROTO_TLS1) || MBEDTLS_SSL_PROTO_TLS1_1 */
#if defined(MBEDTLS_SSL_PROTO_TLS1_2)
#if defined(MBEDTLS_SHA256_C)
#endif /* MBEDTLS_SHA256_C */
#if defined(MBEDTLS_SHA512_C)
#endif /* MBEDTLS_SHA512_C */
#endif /* MBEDTLS_SSL_PROTO_TLS1_2 */
#if defined(MBEDTLS_SSL_PROTO_SSL3) || defined(MBEDTLS_SSL_PROTO_TLS1) || \
#endif
#if defined(MBEDTLS_SSL_PROTO_SSL3)
#endif
#if defined(MBEDTLS_SSL_PROTO_TLS1) || defined(MBEDTLS_SSL_PROTO_TLS1_1)
#endif
#if defined(MBEDTLS_SSL_PROTO_TLS1_2)
#if defined(MBEDTLS_SHA256_C)
#endif
#if defined(MBEDTLS_SHA512_C)
#endif
#endif /* MBEDTLS_SSL_PROTO_TLS1_2 */
#if defined(MBEDTLS_SSL_PROTO_SSL3)
#endif
#if defined(MBEDTLS_SSL_PROTO_TLS1) || defined(MBEDTLS_SSL_PROTO_TLS1_1)
#endif
#if defined(MBEDTLS_SSL_PROTO_TLS1_2)
#if defined(MBEDTLS_SHA512_C)
#endif
#if defined(MBEDTLS_SHA256_C)
#endif
#endif /* MBEDTLS_SSL_PROTO_TLS1_2 */
#if defined(MBEDTLS_SSL_EXTENDED_MASTER_SECRET)
#if defined(MBEDTLS_SSL_PROTO_TLS1_2)
#if defined(MBEDTLS_SHA512_C)
#endif
#endif /* MBEDTLS_SSL_PROTO_TLS1_2 */
#endif
#if defined(MBEDTLS_SSL_TRUNCATED_HMAC)
#if defined(MBEDTLS_SSL_TRUNCATED_HMAC_COMPAT)
#endif
#endif /* MBEDTLS_SSL_TRUNCATED_HMAC */
#if defined(MBEDTLS_SSL_ENCRYPT_THEN_MAC)
#endif
#if defined(MBEDTLS_SSL_PROTO_SSL3) || defined(MBEDTLS_SSL_PROTO_TLS1)
#endif
#if defined(MBEDTLS_SSL_PROTO_TLS1_1) || defined(MBEDTLS_SSL_PROTO_TLS1_2)
#endif
#if defined(MBEDTLS_SSL_CLI_C)
#endif /* MBEDTLS_SSL_CLI_C */
#if defined(MBEDTLS_SSL_SRV_C)
#endif /* MBEDTLS_SSL_SRV_C */
#if defined(MBEDTLS_SSL_PROTO_SSL3)
#endif /* MBEDTLS_SSL_PROTO_SSL3 */
#if defined(MBEDTLS_SSL_PROTO_TLS1) || defined(MBEDTLS_SSL_PROTO_TLS1_1) || \
#endif
#if defined(MBEDTLS_SSL_HW_RECORD_ACCEL)
#endif /* MBEDTLS_SSL_HW_RECORD_ACCEL */
#if defined(MBEDTLS_SSL_EXPORT_KEYS)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#if defined(MBEDTLS_ZLIB_SUPPORT)
#endif /* MBEDTLS_ZLIB_SUPPORT */
#if defined(MBEDTLS_SSL_PROTO_SSL3)
#endif /* MBEDTLS_SSL_PROTO_SSL3 */
#if defined(MBEDTLS_SSL_PROTO_TLS1) || defined(MBEDTLS_SSL_PROTO_TLS1_1)
#endif /* MBEDTLS_SSL_PROTO_TLS1 || MBEDTLS_SSL_PROTO_TLS1_1 */
#if defined(MBEDTLS_SSL_PROTO_TLS1_2)
#if defined(MBEDTLS_SHA256_C)
#endif /* MBEDTLS_SHA256_C */
#if defined(MBEDTLS_SHA512_C)
#endif /* MBEDTLS_SHA512_C */
#endif /* MBEDTLS_SSL_PROTO_TLS1_2 */
#if defined(MBEDTLS_KEY_EXCHANGE__SOME__PSK_ENABLED)
#if defined(MBEDTLS_KEY_EXCHANGE_PSK_ENABLED)
#endif /* MBEDTLS_KEY_EXCHANGE_PSK_ENABLED */
#if defined(MBEDTLS_KEY_EXCHANGE_RSA_PSK_ENABLED)
#endif /* MBEDTLS_KEY_EXCHANGE_RSA_PSK_ENABLED */
#if defined(MBEDTLS_KEY_EXCHANGE_DHE_PSK_ENABLED)
#endif /* MBEDTLS_KEY_EXCHANGE_DHE_PSK_ENABLED */
#if defined(MBEDTLS_KEY_EXCHANGE_ECDHE_PSK_ENABLED)
#endif /* MBEDTLS_KEY_EXCHANGE_ECDHE_PSK_ENABLED */
#endif /* MBEDTLS_KEY_EXCHANGE__SOME__PSK_ENABLED */
#if defined(MBEDTLS_SSL_PROTO_SSL3)
#define SSL_MAC_MAX_BYTES   20  /* MD-5 or SHA-1 */
#endif /* MBEDTLS_SSL_PROTO_SSL3 */
#if defined(MBEDTLS_ARC4_C) || defined(MBEDTLS_CIPHER_NULL_CIPHER) ||     \
#define SSL_SOME_MODES_USE_MAC
#endif
#if defined(SSL_SOME_MODES_USE_MAC) && \
#endif /* SSL_SOME_MODES_USE_MAC && ( TLS1 || TLS1_1 || TLS1_2 ) */
#if defined(SSL_SOME_MODES_USE_MAC)
#if defined(MBEDTLS_SSL_ENCRYPT_THEN_MAC)
#endif
#if defined(MBEDTLS_SSL_PROTO_SSL3)
#endif
#if defined(MBEDTLS_SSL_PROTO_TLS1) || defined(MBEDTLS_SSL_PROTO_TLS1_1) || \
#endif
#endif /* AEAD not the only option */
#if defined(MBEDTLS_ARC4_C) || defined(MBEDTLS_CIPHER_NULL_CIPHER)
#endif /* MBEDTLS_ARC4_C || MBEDTLS_CIPHER_NULL_CIPHER */
#if defined(MBEDTLS_GCM_C) || \
#endif /* MBEDTLS_GCM_C || MBEDTLS_CCM_C */
#if defined(MBEDTLS_CIPHER_MODE_CBC) &&                                    \
#if defined(MBEDTLS_SSL_PROTO_TLS1_1) || defined(MBEDTLS_SSL_PROTO_TLS1_2)
#endif /* MBEDTLS_SSL_PROTO_TLS1_1 || MBEDTLS_SSL_PROTO_TLS1_2 */
#if defined(MBEDTLS_SSL_PROTO_SSL3) || defined(MBEDTLS_SSL_PROTO_TLS1)
#endif
#if defined(MBEDTLS_SSL_ENCRYPT_THEN_MAC)
#endif /* MBEDTLS_SSL_ENCRYPT_THEN_MAC */
#endif /* MBEDTLS_CIPHER_MODE_CBC &&
#if defined(SSL_SOME_MODES_USE_MAC)
#endif
#if defined(MBEDTLS_ARC4_C) || defined(MBEDTLS_CIPHER_NULL_CIPHER)
#endif /* MBEDTLS_ARC4_C || MBEDTLS_CIPHER_NULL_CIPHER */
#if defined(MBEDTLS_GCM_C) || \
#endif /* MBEDTLS_GCM_C || MBEDTLS_CCM_C */
#if defined(MBEDTLS_CIPHER_MODE_CBC) &&                                    \
#if defined(MBEDTLS_SSL_PROTO_TLS1_1) || defined(MBEDTLS_SSL_PROTO_TLS1_2)
#endif
#if defined(MBEDTLS_SSL_ENCRYPT_THEN_MAC)
#endif /* MBEDTLS_SSL_ENCRYPT_THEN_MAC */
#if defined(MBEDTLS_SSL_PROTO_TLS1_1) || defined(MBEDTLS_SSL_PROTO_TLS1_2)
#endif /* MBEDTLS_SSL_PROTO_TLS1_1 || MBEDTLS_SSL_PROTO_TLS1_2 */
#if defined(MBEDTLS_SSL_PROTO_SSL3) || defined(MBEDTLS_SSL_PROTO_TLS1)
#endif
#if defined(MBEDTLS_SSL_DEBUG_ALL)
#endif
#if defined(MBEDTLS_SSL_PROTO_SSL3)
#if defined(MBEDTLS_SSL_DEBUG_ALL)
#endif
#endif /* MBEDTLS_SSL_PROTO_SSL3 */
#if defined(MBEDTLS_SSL_PROTO_TLS1) || defined(MBEDTLS_SSL_PROTO_TLS1_1) || \
#if defined(MBEDTLS_SSL_DEBUG_ALL)
#endif
#endif /* MBEDTLS_SSL_PROTO_TLS1 || MBEDTLS_SSL_PROTO_TLS1_1 || \
#endif /* MBEDTLS_CIPHER_MODE_CBC &&
#if defined(MBEDTLS_SSL_DEBUG_ALL)
#endif
#if defined(SSL_SOME_MODES_USE_MAC)
#if defined(MBEDTLS_SSL_PROTO_SSL3)
#endif /* MBEDTLS_SSL_PROTO_SSL3 */
#if defined(MBEDTLS_SSL_PROTO_TLS1) || defined(MBEDTLS_SSL_PROTO_TLS1_1) || \
#if defined(MBEDTLS_MD5_C) || defined(MBEDTLS_SHA1_C) || \
#endif
#if defined(MBEDTLS_SHA512_C)
#endif
#endif /* MBEDTLS_SSL_PROTO_TLS1 || MBEDTLS_SSL_PROTO_TLS1_1 || \
#if defined(MBEDTLS_SSL_DEBUG_ALL)
#endif
#if defined(MBEDTLS_SSL_DEBUG_ALL)
#endif
#endif /* SSL_SOME_MODES_USE_MAC */
#if defined(MBEDTLS_SSL_PROTO_TLS1_2)
#endif /* MBEDTLS_SSL_PROTO_TLS1_2 */
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#endif
#undef MAC_NONE
#undef MAC_PLAINTEXT
#undef MAC_CIPHERTEXT
#if defined(MBEDTLS_ZLIB_SUPPORT)
#endif /* MBEDTLS_ZLIB_SUPPORT */
#if defined(MBEDTLS_SSL_SRV_C) && defined(MBEDTLS_SSL_RENEGOTIATION)
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#endif
#endif /* MBEDTLS_SSL_SRV_C && MBEDTLS_SSL_RENEGOTIATION */
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#if defined(MBEDTLS_SSL_SRV_C) && defined(MBEDTLS_SSL_RENEGOTIATION)
#endif /* MBEDTLS_SSL_SRV_C && MBEDTLS_SSL_RENEGOTIATION */
#endif
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#endif
#if defined(MBEDTLS_SSL_PROTO_DTLS)
static void ssl_flight_free( mbedtls_ssl_flight_item *flight )
{
    mbedtls_ssl_flight_item *cur = flight;
    mbedtls_ssl_flight_item *next;

    while( cur != NULL )
    {
        next = cur->next;

        mbedtls_free( cur->p );
        mbedtls_free( cur );

        cur = next;
    }
}
#if defined(MBEDTLS_SSL_DTLS_ANTI_REPLAY)
#endif
#if defined(MBEDTLS_SSL_HW_RECORD_ACCEL)
#endif /* MBEDTLS_SSL_HW_RECORD_ACCEL */
#if defined(MBEDTLS_SSL_HW_RECORD_ACCEL)
#endif /* MBEDTLS_SSL_HW_RECORD_ACCEL */
#endif /* MBEDTLS_SSL_PROTO_DTLS */
#if defined(MBEDTLS_SSL_PROTO_SSL3) && defined(MBEDTLS_SSL_CLI_C)
#endif /* MBEDTLS_SSL_PROTO_SSL3 && MBEDTLS_SSL_SRV_C */
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#endif
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#endif /* MBEDTLS_SSL_PROTO_DTLS */
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#endif
#if defined(MBEDTLS_ZLIB_SUPPORT)
#endif /*MBEDTLS_ZLIB_SUPPORT */
#if defined(MBEDTLS_SSL_HW_RECORD_ACCEL)
#endif /* MBEDTLS_SSL_HW_RECORD_ACCEL */
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#endif /* MBEDTLS_SSL_PROTO_DTLS */
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#endif /* MBEDTLS_SSL_PROTO_DTLS */
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#endif /* MBEDTLS_SSL_PROTO_DTLS */
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#endif /* MBEDTLS_SSL_PROTO_DTLS */
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#endif
#if defined(MBEDTLS_SSL_DTLS_ANTI_REPLAY)
#endif /* MBEDTLS_SSL_DTLS_ANTI_REPLAY */
#if defined(MBEDTLS_SSL_DTLS_CLIENT_PORT_REUSE) && defined(MBEDTLS_SSL_SRV_C)
#endif /* MBEDTLS_SSL_DTLS_CLIENT_PORT_REUSE && MBEDTLS_SSL_SRV_C */
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#endif /* MBEDTLS_SSL_PROTO_DTLS */
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#if defined(MBEDTLS_SSL_DTLS_CLIENT_PORT_REUSE) && defined(MBEDTLS_SSL_SRV_C)
#endif /* MBEDTLS_SSL_DTLS_CLIENT_PORT_REUSE && MBEDTLS_SSL_SRV_C */
#if defined(MBEDTLS_SSL_DTLS_ANTI_REPLAY)
#endif
#if defined(MBEDTLS_SSL_RENEGOTIATION)
#endif
#endif /* MBEDTLS_SSL_PROTO_DTLS */
#if defined(MBEDTLS_SSL_PROTO_SSL3)
#endif
#if defined(MBEDTLS_SSL_PROTO_TLS1) || defined(MBEDTLS_SSL_PROTO_TLS1_1) || \
#endif
#if defined(MBEDTLS_SSL_HW_RECORD_ACCEL)
#endif /* MBEDTLS_SSL_HW_RECORD_ACCEL */
#if defined(MBEDTLS_ZLIB_SUPPORT)
#endif /* MBEDTLS_ZLIB_SUPPORT */
#if defined(MBEDTLS_SSL_DTLS_ANTI_REPLAY)
#endif
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#endif /* MBEDTLS_SSL_PROTO_DTLS */
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#endif /* MBEDTLS_SSL_PROTO_DTLS */
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#if defined(MBEDTLS_DEBUG_C)
#endif /* MBEDTLS_DEBUG_C */
#endif /* MBEDTLS_SSL_PROTO_DTLS */
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#endif /* MBEDTLS_SSL_PROTO_DTLS */
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#endif /* MBEDTLS_SSL_PROTO_DTLS */
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#endif
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#endif
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#if defined(MBEDTLS_SSL_ALL_ALERT_MESSAGES)
#endif
#if defined(MBEDTLS_SSL_DTLS_BADMAC_LIMIT)
#endif
#endif
#if defined(MBEDTLS_SSL_ALL_ALERT_MESSAGES)
#endif
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#endif
#if defined(MBEDTLS_SSL_RENEGOTIATION_ENABLED)
#endif
#if defined(MBEDTLS_SSL_PROTO_SSL3) && defined(MBEDTLS_SSL_SRV_C)
#endif /* MBEDTLS_SSL_PROTO_SSL3 && MBEDTLS_SSL_SRV_C */
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#endif
#if !defined(MBEDTLS_KEY_EXCHANGE_RSA_ENABLED)         && \
#else
#if defined(MBEDTLS_SSL_CLI_C)
#if defined(MBEDTLS_SSL_PROTO_SSL3)
#endif /* MBEDTLS_SSL_PROTO_SSL3 */
#endif /* MBEDTLS_SSL_CLI_C */
#if defined(MBEDTLS_SSL_SRV_C)
#endif
#if defined(MBEDTLS_SSL_PROTO_SSL3) && defined(MBEDTLS_SSL_CLI_C)
#endif
#if defined(MBEDTLS_SSL_SRV_C)
#if defined(MBEDTLS_SSL_PROTO_SSL3)
#endif /* MBEDTLS_SSL_PROTO_SSL3 */
#if defined(MBEDTLS_SSL_PROTO_TLS1) || defined(MBEDTLS_SSL_PROTO_TLS1_1) || \
#endif /* MBEDTLS_SSL_PROTO_TLS1 || MBEDTLS_SSL_PROTO_TLS1_1 || \
#endif /* MBEDTLS_SSL_SRV_C */
#if defined(MBEDTLS_SSL_RENEGOTIATION) && defined(MBEDTLS_SSL_CLI_C)
#endif /* MBEDTLS_SSL_RENEGOTIATION && MBEDTLS_SSL_CLI_C */
#if defined(MBEDTLS_SSL_SRV_C) && defined(MBEDTLS_SSL_SERVER_NAME_INDICATION)
#else
#endif
#if defined(MBEDTLS_SSL_SRV_C)
#endif
#if defined(MBEDTLS_SSL__ECP_RESTARTABLE)
#endif
#if defined(MBEDTLS_SSL_SRV_C)
#endif
#if defined(MBEDTLS_SSL__ECP_RESTARTABLE)
#endif
#if defined(MBEDTLS_SSL_SERVER_NAME_INDICATION)
#endif
#if defined(MBEDTLS_SSL__ECP_RESTARTABLE)
#endif
#if defined(MBEDTLS_ECP_C)
#endif /* MBEDTLS_ECP_C */
#if defined(MBEDTLS_DEBUG_C)
#endif /* MBEDTLS_DEBUG_C */
#endif /* !MBEDTLS_KEY_EXCHANGE_RSA_ENABLED
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#if defined(MBEDTLS_SSL_DTLS_ANTI_REPLAY)
#endif
#endif /* MBEDTLS_SSL_PROTO_DTLS */
#if defined(MBEDTLS_SSL_HW_RECORD_ACCEL)
#endif
#if defined(MBEDTLS_SSL_PROTO_SSL3) || defined(MBEDTLS_SSL_PROTO_TLS1) || \
#endif
#if defined(MBEDTLS_SSL_PROTO_TLS1_2)
#if defined(MBEDTLS_SHA512_C)
#endif
#if defined(MBEDTLS_SHA256_C)
#endif
#endif /* MBEDTLS_SSL_PROTO_TLS1_2 */
#if defined(MBEDTLS_SSL_PROTO_SSL3) || defined(MBEDTLS_SSL_PROTO_TLS1) || \
#endif
#if defined(MBEDTLS_SSL_PROTO_TLS1_2)
#if defined(MBEDTLS_SHA256_C)
#endif
#if defined(MBEDTLS_SHA512_C)
#endif
#endif /* MBEDTLS_SSL_PROTO_TLS1_2 */
#if defined(MBEDTLS_SSL_PROTO_SSL3) || defined(MBEDTLS_SSL_PROTO_TLS1) || \
#endif
#if defined(MBEDTLS_SSL_PROTO_TLS1_2)
#if defined(MBEDTLS_SHA256_C)
#endif
#if defined(MBEDTLS_SHA512_C)
#endif
#endif /* MBEDTLS_SSL_PROTO_TLS1_2 */
#if defined(MBEDTLS_SSL_PROTO_SSL3) || defined(MBEDTLS_SSL_PROTO_TLS1) || \
#endif
#if defined(MBEDTLS_SSL_PROTO_TLS1_2)
#if defined(MBEDTLS_SHA256_C)
#endif
#if defined(MBEDTLS_SHA512_C)
#endif
#endif /* MBEDTLS_SSL_PROTO_TLS1_2 */
#if defined(MBEDTLS_SSL_PROTO_SSL3)
#if !defined(MBEDTLS_MD5_ALT)
#endif
#if !defined(MBEDTLS_SHA1_ALT)
#endif
#endif /* MBEDTLS_SSL_PROTO_SSL3 */
#if defined(MBEDTLS_SSL_PROTO_TLS1) || defined(MBEDTLS_SSL_PROTO_TLS1_1)
#if !defined(MBEDTLS_MD5_ALT)
#endif
#if !defined(MBEDTLS_SHA1_ALT)
#endif
#endif /* MBEDTLS_SSL_PROTO_TLS1 || MBEDTLS_SSL_PROTO_TLS1_1 */
#if defined(MBEDTLS_SSL_PROTO_TLS1_2)
#if defined(MBEDTLS_SHA256_C)
#if !defined(MBEDTLS_SHA256_ALT)
#endif
#endif /* MBEDTLS_SHA256_C */
#if defined(MBEDTLS_SHA512_C)
#if !defined(MBEDTLS_SHA512_ALT)
#endif
#endif /* MBEDTLS_SHA512_C */
#endif /* MBEDTLS_SSL_PROTO_TLS1_2 */
#if defined(MBEDTLS_SSL_RENEGOTIATION)
#endif
#if defined(MBEDTLS_SSL_ENCRYPT_THEN_MAC)
#endif
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#endif
#if defined(MBEDTLS_SSL_RENEGOTIATION)
#endif
#if defined(MBEDTLS_SSL_CLI_C)
#endif
#if defined(MBEDTLS_SSL_SRV_C)
#endif
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#endif /* MBEDTLS_SSL_PROTO_DTLS */
#if defined(MBEDTLS_SSL_HW_RECORD_ACCEL)
#endif
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#endif
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#endif
#if defined(MBEDTLS_SSL_PROTO_SSL3)
#define SSL_MAX_HASH_LEN 36
#else
#define SSL_MAX_HASH_LEN 12
#endif
#if defined(MBEDTLS_SSL_PROTO_SSL3)
#endif
#if defined(MBEDTLS_SSL_RENEGOTIATION)
#endif
#if defined(MBEDTLS_SSL_CLI_C)
#endif
#if defined(MBEDTLS_SSL_SRV_C)
#endif
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#endif
#if defined(MBEDTLS_SSL_PROTO_SSL3) || defined(MBEDTLS_SSL_PROTO_TLS1) || \
#endif
#if defined(MBEDTLS_SSL_PROTO_TLS1_2)
#if defined(MBEDTLS_SHA256_C)
#endif
#if defined(MBEDTLS_SHA512_C)
#endif
#endif /* MBEDTLS_SSL_PROTO_TLS1_2 */
#if defined(MBEDTLS_SSL_PROTO_TLS1_2) && \
#endif
#if defined(MBEDTLS_DHM_C)
#endif
#if defined(MBEDTLS_ECDH_C)
#endif
#if defined(MBEDTLS_KEY_EXCHANGE_ECJPAKE_ENABLED)
#if defined(MBEDTLS_SSL_CLI_C)
#endif
#endif
#if defined(MBEDTLS_SSL__ECP_RESTARTABLE)
#endif
#if defined(MBEDTLS_SSL_SERVER_NAME_INDICATION)
#endif
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#endif
#if defined(MBEDTLS_SSL_DTLS_HELLO_VERIFY) && defined(MBEDTLS_SSL_SRV_C)
#endif /* MBEDTLS_SSL_DTLS_HELLO_VERIFY && MBEDTLS_SSL_SRV_C */
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#endif
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#endif
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#endif /* MBEDTLS_SSL_PROTO_DTLS */
#if !defined(MBEDTLS_SSL_DTLS_CLIENT_PORT_REUSE) ||     \
#endif
#if defined(MBEDTLS_SSL_RENEGOTIATION)
#endif
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#endif
#if defined(MBEDTLS_SSL_DTLS_ANTI_REPLAY)
#endif
#if defined(MBEDTLS_SSL_CBC_RECORD_SPLITTING)
#endif
#if defined(MBEDTLS_SSL_DTLS_CLIENT_PORT_REUSE) && defined(MBEDTLS_SSL_SRV_C)
#endif /* MBEDTLS_SSL_DTLS_CLIENT_PORT_REUSE && MBEDTLS_SSL_SRV_C */
#if defined(MBEDTLS_SSL_HW_RECORD_ACCEL)
#endif
#if defined(MBEDTLS_SSL_ALPN)
#endif
#if defined(MBEDTLS_SSL_DTLS_HELLO_VERIFY) && defined(MBEDTLS_SSL_SRV_C)
#if defined(MBEDTLS_SSL_DTLS_CLIENT_PORT_REUSE)
#endif
#endif
#if defined(MBEDTLS_SSL_DTLS_ANTI_REPLAY)
#endif
#if defined(MBEDTLS_SSL_DTLS_BADMAC_LIMIT)
#endif
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#endif
#if defined(MBEDTLS_X509_CRT_PARSE_C)
#endif /* MBEDTLS_X509_CRT_PARSE_C */
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#endif
#if defined(MBEDTLS_SSL_SRV_C)
#endif /* MBEDTLS_SSL_SRV_C */
#if defined(MBEDTLS_SSL_CLI_C)
#endif /* MBEDTLS_SSL_CLI_C */
#if defined(MBEDTLS_X509_CRT_PARSE_C)
#endif /* MBEDTLS_X509_CRT_PARSE_C */
#if defined(MBEDTLS_SSL_SERVER_NAME_INDICATION)
#endif /* MBEDTLS_SSL_SERVER_NAME_INDICATION */
#if defined(MBEDTLS_KEY_EXCHANGE_ECJPAKE_ENABLED)
#endif /* MBEDTLS_KEY_EXCHANGE_ECJPAKE_ENABLED */
#if defined(MBEDTLS_KEY_EXCHANGE__SOME__PSK_ENABLED)
#endif /* MBEDTLS_KEY_EXCHANGE__SOME__PSK_ENABLED */
#if defined(MBEDTLS_DHM_C) && defined(MBEDTLS_SSL_SRV_C)
#if !defined(MBEDTLS_DEPRECATED_REMOVED)
#endif /* MBEDTLS_DEPRECATED_REMOVED */
#endif /* MBEDTLS_DHM_C && MBEDTLS_SSL_SRV_C */
#if defined(MBEDTLS_DHM_C) && defined(MBEDTLS_SSL_CLI_C)
#endif /* MBEDTLS_DHM_C && MBEDTLS_SSL_CLI_C */
#if defined(MBEDTLS_KEY_EXCHANGE__WITH_CERT__ENABLED)
#endif /* MBEDTLS_KEY_EXCHANGE__WITH_CERT__ENABLED */
#if defined(MBEDTLS_ECP_C)
#endif /* MBEDTLS_ECP_C */
#if defined(MBEDTLS_X509_CRT_PARSE_C)
#endif /* MBEDTLS_X509_CRT_PARSE_C */
#if defined(MBEDTLS_SSL_SERVER_NAME_INDICATION)
#endif /* MBEDTLS_SSL_SERVER_NAME_INDICATION */
#if defined(MBEDTLS_SSL_ALPN)
#endif /* MBEDTLS_SSL_ALPN */
#if defined(MBEDTLS_SSL_FALLBACK_SCSV) && defined(MBEDTLS_SSL_CLI_C)
#endif
#if defined(MBEDTLS_SSL_SRV_C)
#endif
#if defined(MBEDTLS_SSL_ENCRYPT_THEN_MAC)
#endif
#if defined(MBEDTLS_SSL_EXTENDED_MASTER_SECRET)
#endif
#if defined(MBEDTLS_ARC4_C)
#endif
#if defined(MBEDTLS_SSL_MAX_FRAGMENT_LENGTH)
#endif /* MBEDTLS_SSL_MAX_FRAGMENT_LENGTH */
#if defined(MBEDTLS_SSL_TRUNCATED_HMAC)
#endif /* MBEDTLS_SSL_TRUNCATED_HMAC */
#if defined(MBEDTLS_SSL_CBC_RECORD_SPLITTING)
#endif
#if defined(MBEDTLS_SSL_RENEGOTIATION)
#endif /* MBEDTLS_SSL_RENEGOTIATION */
#if defined(MBEDTLS_SSL_SESSION_TICKETS)
#if defined(MBEDTLS_SSL_CLI_C)
#endif
#if defined(MBEDTLS_SSL_SRV_C)
#endif
#endif /* MBEDTLS_SSL_SESSION_TICKETS */
#if defined(MBEDTLS_SSL_EXPORT_KEYS)
#endif
#if defined(MBEDTLS_SSL_ASYNC_PRIVATE)
#endif /* MBEDTLS_SSL_ASYNC_PRIVATE */
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#endif /* MBEDTLS_SSL_PROTO_DTLS */
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#endif
#if defined(MBEDTLS_ZLIB_SUPPORT)
#endif
#if defined(MBEDTLS_SSL_PROTO_TLS1_1) || defined(MBEDTLS_SSL_PROTO_TLS1_2)
#endif /* MBEDTLS_SSL_PROTO_TLS1_1 || MBEDTLS_SSL_PROTO_TLS1_2 */
#if defined(MBEDTLS_SSL_MAX_FRAGMENT_LENGTH)
#endif /* MBEDTLS_SSL_MAX_FRAGMENT_LENGTH */
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#endif /* MBEDTLS_SSL_PROTO_DTLS */
#if !defined(MBEDTLS_SSL_MAX_FRAGMENT_LENGTH) && \
#endif
#if defined(MBEDTLS_SSL_MAX_FRAGMENT_LENGTH)
#endif
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#endif /* MBEDTLS_SSL_PROTO_DTLS */
#if !defined(MBEDTLS_SSL_MAX_FRAGMENT_LENGTH) &&        \
#endif
#if defined(MBEDTLS_X509_CRT_PARSE_C)
#endif /* MBEDTLS_X509_CRT_PARSE_C */
#if defined(MBEDTLS_SSL_CLI_C)
#endif /* MBEDTLS_SSL_CLI_C */
#if defined(MBEDTLS_SSL_CLI_C)
#endif
#if defined(MBEDTLS_SSL_SRV_C)
#endif
#if defined(MBEDTLS_SSL_RENEGOTIATION)
#if defined(MBEDTLS_SSL_SRV_C)
#endif /* MBEDTLS_SSL_SRV_C */
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#endif
#if defined(MBEDTLS_SSL_SRV_C)
#endif /* MBEDTLS_SSL_SRV_C */
#if defined(MBEDTLS_SSL_CLI_C)
#endif /* MBEDTLS_SSL_CLI_C */
#endif /* MBEDTLS_SSL_RENEGOTIATION */
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#endif
#if defined(MBEDTLS_SSL_RENEGOTIATION)
#endif
#if defined(MBEDTLS_SSL_CLI_C)
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#endif
#endif /* MBEDTLS_SSL_CLI_C */
#if defined(MBEDTLS_SSL_SRV_C)
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#endif
#endif /* MBEDTLS_SSL_SRV_C */
#if defined(MBEDTLS_SSL_RENEGOTIATION)
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#endif
#endif /* MBEDTLS_SSL_RENEGOTIATION */
#if defined(MBEDTLS_SSL_PROTO_SSL3)
#endif /* MBEDTLS_SSL_PROTO_SSL3 */
#if defined(MBEDTLS_SSL_PROTO_TLS1) || defined(MBEDTLS_SSL_PROTO_TLS1_1) || \
#endif /* MBEDTLS_SSL_PROTO_TLS1 || MBEDTLS_SSL_PROTO_TLS1_1 ||
#if defined(MBEDTLS_SSL_RENEGOTIATION)
#endif /* MBEDTLS_SSL_RENEGOTIATION */
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#if defined(MBEDTLS_SSL_SRV_C) && defined(MBEDTLS_SSL_RENEGOTIATION)
#endif /* MBEDTLS_SSL_SRV_C && MBEDTLS_SSL_RENEGOTIATION */
#endif /* MBEDTLS_SSL_PROTO_DTLS */
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#endif
#if defined(MBEDTLS_SSL_CBC_RECORD_SPLITTING)
#endif /* MBEDTLS_SSL_CBC_RECORD_SPLITTING */
#if defined(MBEDTLS_SSL_RENEGOTIATION)
#endif
#if defined(MBEDTLS_SSL_CBC_RECORD_SPLITTING)
#else
#endif
void mbedtls_ssl_transform_free( mbedtls_ssl_transform *transform )
{
    if( transform == NULL )
        return;

#if defined(MBEDTLS_ZLIB_SUPPORT)
    deflateEnd( &transform->ctx_deflate );
    inflateEnd( &transform->ctx_inflate );
#endif

    mbedtls_cipher_free( &transform->cipher_ctx_enc );
    mbedtls_cipher_free( &transform->cipher_ctx_dec );

    mbedtls_md_free( &transform->md_ctx_enc );
    mbedtls_md_free( &transform->md_ctx_dec );

    mbedtls_platform_zeroize( transform, sizeof( mbedtls_ssl_transform ) );
}
#if defined(MBEDTLS_X509_CRT_PARSE_C)
static void ssl_key_cert_free( mbedtls_ssl_key_cert *key_cert )
{
    mbedtls_ssl_key_cert *cur = key_cert, *next;

    while( cur != NULL )
    {
        next = cur->next;
        mbedtls_free( cur );
        cur = next;
    }
}
#endif /* MBEDTLS_X509_CRT_PARSE_C */
#if defined(MBEDTLS_SSL_PROTO_DTLS)
static void ssl_buffering_free( mbedtls_ssl_context *ssl )
{
    unsigned offset;
    mbedtls_ssl_handshake_params * const hs = ssl->handshake;

    if( hs == NULL )
        return;

    ssl_free_buffered_record( ssl );

    for( offset = 0; offset < MBEDTLS_SSL_MAX_BUFFERED_HS; offset++ )
        ssl_buffering_free_slot( ssl, offset );
}
#endif /* MBEDTLS_SSL_PROTO_DTLS */
void mbedtls_ssl_handshake_free( mbedtls_ssl_context *ssl )
{
    mbedtls_ssl_handshake_params *handshake = ssl->handshake;

    if( handshake == NULL )
        return;

#if defined(MBEDTLS_SSL_ASYNC_PRIVATE)
    if( ssl->conf->f_async_cancel != NULL && handshake->async_in_progress != 0 )
    {
        ssl->conf->f_async_cancel( ssl );
        handshake->async_in_progress = 0;
    }
#endif /* MBEDTLS_SSL_ASYNC_PRIVATE */

#if defined(MBEDTLS_SSL_PROTO_SSL3) || defined(MBEDTLS_SSL_PROTO_TLS1) || \
    defined(MBEDTLS_SSL_PROTO_TLS1_1)
    mbedtls_md5_free(    &handshake->fin_md5  );
    mbedtls_sha1_free(   &handshake->fin_sha1 );
#endif
#if defined(MBEDTLS_SSL_PROTO_TLS1_2)
#if defined(MBEDTLS_SHA256_C)
    mbedtls_sha256_free(   &handshake->fin_sha256    );
#endif
#if defined(MBEDTLS_SHA512_C)
    mbedtls_sha512_free(   &handshake->fin_sha512    );
#endif
#endif /* MBEDTLS_SSL_PROTO_TLS1_2 */

#if defined(MBEDTLS_DHM_C)
    mbedtls_dhm_free( &handshake->dhm_ctx );
#endif
#if defined(MBEDTLS_ECDH_C)
    mbedtls_ecdh_free( &handshake->ecdh_ctx );
#endif
#if defined(MBEDTLS_KEY_EXCHANGE_ECJPAKE_ENABLED)
    mbedtls_ecjpake_free( &handshake->ecjpake_ctx );
#if defined(MBEDTLS_SSL_CLI_C)
    mbedtls_free( handshake->ecjpake_cache );
    handshake->ecjpake_cache = NULL;
    handshake->ecjpake_cache_len = 0;
#endif
#endif

#if defined(MBEDTLS_ECDH_C) || defined(MBEDTLS_ECDSA_C) || \
    defined(MBEDTLS_KEY_EXCHANGE_ECJPAKE_ENABLED)
    /* explicit void pointer cast for buggy MS compiler */
    mbedtls_free( (void *) handshake->curves );
#endif

#if defined(MBEDTLS_KEY_EXCHANGE__SOME__PSK_ENABLED)
    if( handshake->psk != NULL )
    {
        mbedtls_platform_zeroize( handshake->psk, handshake->psk_len );
        mbedtls_free( handshake->psk );
    }
#endif

#if defined(MBEDTLS_X509_CRT_PARSE_C) && \
    defined(MBEDTLS_SSL_SERVER_NAME_INDICATION)
    /*
     * Free only the linked list wrapper, not the keys themselves
     * since the belong to the SNI callback
     */
    if( handshake->sni_key_cert != NULL )
    {
        mbedtls_ssl_key_cert *cur = handshake->sni_key_cert, *next;

        while( cur != NULL )
        {
            next = cur->next;
            mbedtls_free( cur );
            cur = next;
        }
    }
#endif /* MBEDTLS_X509_CRT_PARSE_C && MBEDTLS_SSL_SERVER_NAME_INDICATION */

#if defined(MBEDTLS_SSL__ECP_RESTARTABLE)
    mbedtls_x509_crt_restart_free( &handshake->ecrs_ctx );
#endif

#if defined(MBEDTLS_SSL_PROTO_DTLS)
    mbedtls_free( handshake->verify_cookie );
    ssl_flight_free( handshake->flight );
    ssl_buffering_free( ssl );
#endif

    mbedtls_platform_zeroize( handshake,
                              sizeof( mbedtls_ssl_handshake_params ) );
}
void mbedtls_ssl_session_free( mbedtls_ssl_session *session )
{
    if( session == NULL )
        return;

#if defined(MBEDTLS_X509_CRT_PARSE_C)
    if( session->peer_cert != NULL )
    {
        mbedtls_x509_crt_free( session->peer_cert );
        mbedtls_free( session->peer_cert );
    }
#endif

#if defined(MBEDTLS_SSL_SESSION_TICKETS) && defined(MBEDTLS_SSL_CLI_C)
    mbedtls_free( session->ticket );
#endif

    mbedtls_platform_zeroize( session, sizeof( mbedtls_ssl_session ) );
}
void mbedtls_ssl_free( mbedtls_ssl_context *ssl )
{
    if( ssl == NULL )
        return;

    MBEDTLS_SSL_DEBUG_MSG( 2, ( "=> free" ) );

    if( ssl->out_buf != NULL )
    {
        mbedtls_platform_zeroize( ssl->out_buf, MBEDTLS_SSL_OUT_BUFFER_LEN );
        mbedtls_free( ssl->out_buf );
    }

    if( ssl->in_buf != NULL )
    {
        mbedtls_platform_zeroize( ssl->in_buf, MBEDTLS_SSL_IN_BUFFER_LEN );
        mbedtls_free( ssl->in_buf );
    }

#if defined(MBEDTLS_ZLIB_SUPPORT)
    if( ssl->compress_buf != NULL )
    {
        mbedtls_platform_zeroize( ssl->compress_buf, MBEDTLS_SSL_COMPRESS_BUFFER_LEN );
        mbedtls_free( ssl->compress_buf );
    }
#endif

    if( ssl->transform )
    {
        mbedtls_ssl_transform_free( ssl->transform );
        mbedtls_free( ssl->transform );
    }

    if( ssl->handshake )
    {
        mbedtls_ssl_handshake_free( ssl );
        mbedtls_ssl_transform_free( ssl->transform_negotiate );
        mbedtls_ssl_session_free( ssl->session_negotiate );

        mbedtls_free( ssl->handshake );
        mbedtls_free( ssl->transform_negotiate );
        mbedtls_free( ssl->session_negotiate );
    }

    if( ssl->session )
    {
        mbedtls_ssl_session_free( ssl->session );
        mbedtls_free( ssl->session );
    }

#if defined(MBEDTLS_X509_CRT_PARSE_C)
    if( ssl->hostname != NULL )
    {
        mbedtls_platform_zeroize( ssl->hostname, strlen( ssl->hostname ) );
        mbedtls_free( ssl->hostname );
    }
#endif

#if defined(MBEDTLS_SSL_HW_RECORD_ACCEL)
    if( mbedtls_ssl_hw_record_finish != NULL )
    {
        MBEDTLS_SSL_DEBUG_MSG( 2, ( "going for mbedtls_ssl_hw_record_finish()" ) );
        mbedtls_ssl_hw_record_finish( ssl );
    }
#endif

#if defined(MBEDTLS_SSL_DTLS_HELLO_VERIFY) && defined(MBEDTLS_SSL_SRV_C)
    mbedtls_free( ssl->cli_id );
#endif

    MBEDTLS_SSL_DEBUG_MSG( 2, ( "<= free" ) );

    /* Actually clear after last debug message */
    mbedtls_platform_zeroize( ssl, sizeof( mbedtls_ssl_context ) );
}
#if defined(MBEDTLS_KEY_EXCHANGE__WITH_CERT__ENABLED)
#if defined(MBEDTLS_SHA512_C)
#endif
#if defined(MBEDTLS_SHA256_C)
#endif
#if defined(MBEDTLS_SHA1_C) && defined(MBEDTLS_TLS_DEFAULT_ALLOW_SHA1_IN_KEY_EXCHANGE)
#endif
#endif
#if defined(MBEDTLS_KEY_EXCHANGE__WITH_CERT__ENABLED)
#endif
#if defined(MBEDTLS_ECP_C)
#if defined(MBEDTLS_ECP_DP_SECP256R1_ENABLED)
#endif
#if defined(MBEDTLS_ECP_DP_SECP384R1_ENABLED)
#endif
#endif
#if defined(MBEDTLS_DHM_C) && defined(MBEDTLS_SSL_SRV_C)
#endif
#if defined(MBEDTLS_SSL_CLI_C)
#if defined(MBEDTLS_SSL_SESSION_TICKETS)
#endif
#endif
#if defined(MBEDTLS_ARC4_C)
#endif
#if defined(MBEDTLS_SSL_ENCRYPT_THEN_MAC)
#endif
#if defined(MBEDTLS_SSL_EXTENDED_MASTER_SECRET)
#endif
#if defined(MBEDTLS_SSL_CBC_RECORD_SPLITTING)
#endif
#if defined(MBEDTLS_SSL_DTLS_HELLO_VERIFY) && defined(MBEDTLS_SSL_SRV_C)
#endif
#if defined(MBEDTLS_SSL_DTLS_ANTI_REPLAY)
#endif
#if defined(MBEDTLS_SSL_SRV_C)
#endif
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#endif
#if defined(MBEDTLS_SSL_RENEGOTIATION)
#endif
#if defined(MBEDTLS_DHM_C) && defined(MBEDTLS_SSL_SRV_C)
#endif
#if defined(MBEDTLS_X509_CRT_PARSE_C)
#endif
#if defined(MBEDTLS_KEY_EXCHANGE__WITH_CERT__ENABLED)
#endif
#if defined(MBEDTLS_ECP_C)
#endif
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#endif
#if defined(MBEDTLS_X509_CRT_PARSE_C)
#endif
#if defined(MBEDTLS_KEY_EXCHANGE__WITH_CERT__ENABLED)
#endif
#if defined(MBEDTLS_ECP_C)
#endif
#if defined(MBEDTLS_DHM_C) && defined(MBEDTLS_SSL_CLI_C)
#endif
void mbedtls_ssl_config_free( mbedtls_ssl_config *conf )
{
#if defined(MBEDTLS_DHM_C)
    mbedtls_mpi_free( &conf->dhm_P );
    mbedtls_mpi_free( &conf->dhm_G );
#endif

#if defined(MBEDTLS_KEY_EXCHANGE__SOME__PSK_ENABLED)
    if( conf->psk != NULL )
    {
        mbedtls_platform_zeroize( conf->psk, conf->psk_len );
        mbedtls_free( conf->psk );
        conf->psk = NULL;
        conf->psk_len = 0;
    }

    if( conf->psk_identity != NULL )
    {
        mbedtls_platform_zeroize( conf->psk_identity, conf->psk_identity_len );
        mbedtls_free( conf->psk_identity );
        conf->psk_identity = NULL;
        conf->psk_identity_len = 0;
    }
#endif

#if defined(MBEDTLS_X509_CRT_PARSE_C)
    ssl_key_cert_free( conf->key_cert );
#endif

    mbedtls_platform_zeroize( conf, sizeof( mbedtls_ssl_config ) );
}
#if defined(MBEDTLS_PK_C) && \
#if defined(MBEDTLS_RSA_C)
#endif
#if defined(MBEDTLS_ECDSA_C)
#endif
#if defined(MBEDTLS_RSA_C)
#endif
#if defined(MBEDTLS_ECDSA_C)
#endif
#endif /* MBEDTLS_PK_C && ( MBEDTLS_RSA_C || MBEDTLS_ECDSA_C ) */
#if defined(MBEDTLS_SSL_PROTO_TLS1_2) && \
#endif /* MBEDTLS_SSL_PROTO_TLS1_2) &&
#if defined(MBEDTLS_MD5_C)
#endif
#if defined(MBEDTLS_SHA1_C)
#endif
#if defined(MBEDTLS_SHA256_C)
#endif
#if defined(MBEDTLS_SHA512_C)
#endif
#if defined(MBEDTLS_MD5_C)
#endif
#if defined(MBEDTLS_SHA1_C)
#endif
#if defined(MBEDTLS_SHA256_C)
#endif
#if defined(MBEDTLS_SHA512_C)
#endif
#if defined(MBEDTLS_ECP_C)
#endif /* MBEDTLS_ECP_C */
#if defined(MBEDTLS_KEY_EXCHANGE__WITH_CERT__ENABLED)
#endif /* MBEDTLS_KEY_EXCHANGE__WITH_CERT__ENABLED */
#if defined(MBEDTLS_X509_CRT_PARSE_C)
#if defined(MBEDTLS_X509_CHECK_KEY_USAGE)
#endif
#if defined(MBEDTLS_X509_CHECK_EXTENDED_KEY_USAGE)
#endif
#if !defined(MBEDTLS_X509_CHECK_KEY_USAGE) &&          \
#endif
#if defined(MBEDTLS_X509_CHECK_KEY_USAGE)
#else
#endif /* MBEDTLS_X509_CHECK_KEY_USAGE */
#if defined(MBEDTLS_X509_CHECK_EXTENDED_KEY_USAGE)
#endif /* MBEDTLS_X509_CHECK_EXTENDED_KEY_USAGE */
#endif /* MBEDTLS_X509_CRT_PARSE_C */
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#else
#endif
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#else
#endif
#if defined(MBEDTLS_SSL_PROTO_TLS1_2)
#if defined(MBEDTLS_SSL_PROTO_TLS1) || defined(MBEDTLS_SSL_PROTO_TLS1_1)
#if defined(MBEDTLS_MD5_C)
#endif
#if defined(MBEDTLS_SHA1_C)
#endif
#endif /* MBEDTLS_SSL_PROTO_TLS1 || MBEDTLS_SSL_PROTO_TLS1_1 */
#if defined(MBEDTLS_SHA512_C)
#endif
#if defined(MBEDTLS_SHA256_C)
#endif
#else /* !MBEDTLS_SSL_PROTO_TLS1_2 */
#endif /* MBEDTLS_SSL_PROTO_TLS1_2 */
#if defined(MBEDTLS_SSL_PROTO_SSL3) || defined(MBEDTLS_SSL_PROTO_TLS1) || \
#endif /* MBEDTLS_SSL_PROTO_SSL3 || MBEDTLS_SSL_PROTO_TLS1 || \
#if defined(MBEDTLS_SSL_PROTO_TLS1) || defined(MBEDTLS_SSL_PROTO_TLS1_1) || \
#endif /* MBEDTLS_SSL_PROTO_TLS1 || MBEDTLS_SSL_PROTO_TLS1_1 || \
#endif /* MBEDTLS_SSL_TLS_C */
