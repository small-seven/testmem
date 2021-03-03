#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#else
#include <stdio.h>
#include <stdlib.h>
#define mbedtls_free       free
#define mbedtls_time       time
#define mbedtls_time_t     time_t
#define mbedtls_calloc    calloc
#define mbedtls_fprintf    fprintf
#define mbedtls_printf     printf
#define mbedtls_exit            exit
#define MBEDTLS_EXIT_SUCCESS    EXIT_SUCCESS
#define MBEDTLS_EXIT_FAILURE    EXIT_FAILURE
#endif
#if !defined(MBEDTLS_ENTROPY_C) || \
#else
#include "mbedtls/net_sockets.h"
#include "mbedtls/ssl.h"
#include "mbedtls/entropy.h"
#include "mbedtls/ctr_drbg.h"
#include "mbedtls/certs.h"
#include "mbedtls/x509.h"
#include "mbedtls/error.h"
#include "mbedtls/debug.h"
#include "mbedtls/timing.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#if !defined(_MSC_VER)
#include <inttypes.h>
#endif
#if !defined(_WIN32)
#include <signal.h>
#endif
#if defined(MBEDTLS_SSL_CACHE_C)
#include "mbedtls/ssl_cache.h"
#endif
#if defined(MBEDTLS_SSL_TICKET_C)
#include "mbedtls/ssl_ticket.h"
#endif
#if defined(MBEDTLS_SSL_COOKIE_C)
#include "mbedtls/ssl_cookie.h"
#endif
#if defined(MBEDTLS_MEMORY_BUFFER_ALLOC_C)
#include "mbedtls/memory_buffer_alloc.h"
#endif
#if defined(MBEDTLS_SSL_SERVER_NAME_INDICATION) && defined(MBEDTLS_FS_IO)
#define SNI_OPTION
#endif
#if defined(_WIN32)
#include <windows.h>
#endif
#define MEMORY_HEAP_SIZE        120000
#define DFL_SERVER_ADDR         NULL
#define DFL_SERVER_PORT         "4433"
#define DFL_RESPONSE_SIZE       -1
#define DFL_DEBUG_LEVEL         0
#define DFL_NBIO                0
#define DFL_EVENT               0
#define DFL_READ_TIMEOUT        0
#define DFL_CA_FILE             ""
#define DFL_CA_PATH             ""
#define DFL_CRT_FILE            ""
#define DFL_KEY_FILE            ""
#define DFL_CRT_FILE2           ""
#define DFL_KEY_FILE2           ""
#define DFL_ASYNC_OPERATIONS    "-"
#define DFL_ASYNC_PRIVATE_DELAY1 ( -1 )
#define DFL_ASYNC_PRIVATE_DELAY2 ( -1 )
#define DFL_ASYNC_PRIVATE_ERROR  ( 0 )
#define DFL_PSK                 ""
#define DFL_PSK_IDENTITY        "Client_identity"
#define DFL_ECJPAKE_PW          NULL
#define DFL_PSK_LIST            NULL
#define DFL_FORCE_CIPHER        0
#define DFL_VERSION_SUITES      NULL
#define DFL_RENEGOTIATION       MBEDTLS_SSL_RENEGOTIATION_DISABLED
#define DFL_ALLOW_LEGACY        -2
#define DFL_RENEGOTIATE         0
#define DFL_RENEGO_DELAY        -2
#define DFL_RENEGO_PERIOD       ( (uint64_t)-1 )
#define DFL_EXCHANGES           1
#define DFL_MIN_VERSION         -1
#define DFL_MAX_VERSION         -1
#define DFL_ARC4                -1
#define DFL_SHA1                -1
#define DFL_AUTH_MODE           -1
#define DFL_CERT_REQ_CA_LIST    MBEDTLS_SSL_CERT_REQ_CA_LIST_ENABLED
#define DFL_MFL_CODE            MBEDTLS_SSL_MAX_FRAG_LEN_NONE
#define DFL_TRUNC_HMAC          -1
#define DFL_TICKETS             MBEDTLS_SSL_SESSION_TICKETS_ENABLED
#define DFL_TICKET_TIMEOUT      86400
#define DFL_CACHE_MAX           -1
#define DFL_CACHE_TIMEOUT       -1
#define DFL_SNI                 NULL
#define DFL_ALPN_STRING         NULL
#define DFL_CURVES              NULL
#define DFL_DHM_FILE            NULL
#define DFL_TRANSPORT           MBEDTLS_SSL_TRANSPORT_STREAM
#define DFL_COOKIES             1
#define DFL_ANTI_REPLAY         -1
#define DFL_HS_TO_MIN           0
#define DFL_HS_TO_MAX           0
#define DFL_DTLS_MTU            -1
#define DFL_BADMAC_LIMIT        -1
#define DFL_DGRAM_PACKING        1
#define DFL_EXTENDED_MS         -1
#define DFL_ETM                 -1
#define LONG_RESPONSE "<p>01-blah-blah-blah-blah-blah-blah-blah-blah-blah\r\n" \
#define HTTP_RESPONSE \
#define DFL_IO_BUF_LEN      200
#if defined(MBEDTLS_X509_CRT_PARSE_C)
#if defined(MBEDTLS_FS_IO)
#define USAGE_IO \
#else
#define USAGE_IO \
#endif /* MBEDTLS_FS_IO */
#else
#define USAGE_IO ""
#endif /* MBEDTLS_X509_CRT_PARSE_C */
#if defined(MBEDTLS_SSL_ASYNC_PRIVATE)
#define USAGE_SSL_ASYNC \
#else
#define USAGE_SSL_ASYNC ""
#endif /* MBEDTLS_SSL_ASYNC_PRIVATE */
#if defined(MBEDTLS_KEY_EXCHANGE__SOME__PSK_ENABLED)
#define USAGE_PSK                                                       \
#else
#define USAGE_PSK ""
#endif /* MBEDTLS_KEY_EXCHANGE__SOME__PSK_ENABLED */
#if defined(MBEDTLS_SSL_SESSION_TICKETS)
#define USAGE_TICKETS                                       \
#else
#define USAGE_TICKETS ""
#endif /* MBEDTLS_SSL_SESSION_TICKETS */
#if defined(MBEDTLS_SSL_CACHE_C)
#define USAGE_CACHE                                             \
#else
#define USAGE_CACHE ""
#endif /* MBEDTLS_SSL_CACHE_C */
#if defined(SNI_OPTION)
#if defined(MBEDTLS_X509_CRL_PARSE_C)
#define SNI_CRL              ",crl"
#else
#define SNI_CRL              ""
#endif
#define USAGE_SNI                                                           \
#else
#define USAGE_SNI ""
#endif /* SNI_OPTION */
#if defined(MBEDTLS_SSL_MAX_FRAGMENT_LENGTH)
#define USAGE_MAX_FRAG_LEN                                      \
#else
#define USAGE_MAX_FRAG_LEN ""
#endif /* MBEDTLS_SSL_MAX_FRAGMENT_LENGTH */
#if defined(MBEDTLS_SSL_TRUNCATED_HMAC)
#define USAGE_TRUNC_HMAC \
#else
#define USAGE_TRUNC_HMAC ""
#endif
#if defined(MBEDTLS_SSL_ALPN)
#define USAGE_ALPN \
#else
#define USAGE_ALPN ""
#endif /* MBEDTLS_SSL_ALPN */
#if defined(MBEDTLS_SSL_DTLS_HELLO_VERIFY)
#define USAGE_COOKIES \
#else
#define USAGE_COOKIES ""
#endif
#if defined(MBEDTLS_SSL_DTLS_ANTI_REPLAY)
#define USAGE_ANTI_REPLAY \
#else
#define USAGE_ANTI_REPLAY ""
#endif
#if defined(MBEDTLS_SSL_DTLS_BADMAC_LIMIT)
#define USAGE_BADMAC_LIMIT \
#else
#define USAGE_BADMAC_LIMIT ""
#endif
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#define USAGE_DTLS \
#else
#define USAGE_DTLS ""
#endif
#if defined(MBEDTLS_SSL_EXTENDED_MASTER_SECRET)
#define USAGE_EMS \
#else
#define USAGE_EMS ""
#endif
#if defined(MBEDTLS_SSL_ENCRYPT_THEN_MAC)
#define USAGE_ETM \
#else
#define USAGE_ETM ""
#endif
#if defined(MBEDTLS_SSL_RENEGOTIATION)
#define USAGE_RENEGO \
#else
#define USAGE_RENEGO ""
#endif
#if defined(MBEDTLS_KEY_EXCHANGE_ECJPAKE_ENABLED)
#define USAGE_ECJPAKE \
#else
#define USAGE_ECJPAKE ""
#endif
#if defined(MBEDTLS_ECP_C)
#define USAGE_CURVES \
#else
#define USAGE_CURVES ""
#endif
#define USAGE \
#define ALPN_LIST_SIZE  10
#define CURVE_LIST_SIZE 20
#define PUT_UINT64_BE(out_be,in_le,i)                                   \
#define GET_ITEM( dst )         \
#if defined(SNI_OPTION)
typedef struct _sni_entry sni_entry;

struct _sni_entry {
    const char *name;
    mbedtls_x509_crt *cert;
    mbedtls_pk_context *key;
    mbedtls_x509_crt* ca;
    mbedtls_x509_crl* crl;
    int authmode;
    sni_entry *next;
};
void sni_free( sni_entry *head )
{
    sni_entry *cur = head, *next;

    while( cur != NULL )
    {
        mbedtls_x509_crt_free( cur->cert );
        mbedtls_free( cur->cert );

        mbedtls_pk_free( cur->key );
        mbedtls_free( cur->key );

        mbedtls_x509_crt_free( cur->ca );
        mbedtls_free( cur->ca );
#if defined(MBEDTLS_X509_CRL_PARSE_C)
        mbedtls_x509_crl_free( cur->crl );
        mbedtls_free( cur->crl );
#endif
        next = cur->next;
        mbedtls_free( cur );
        cur = next;
    }
}
#if defined(MBEDTLS_X509_CRL_PARSE_C)
#endif
#if defined(MBEDTLS_X509_CRL_PARSE_C)
#endif
#if defined(MBEDTLS_X509_CRL_PARSE_C)
#endif
#endif /* SNI_OPTION */
#if defined(MBEDTLS_KEY_EXCHANGE__SOME__PSK_ENABLED)
#define HEX2NUM( c )                        \
typedef struct _psk_entry psk_entry;

struct _psk_entry
{
    const char *name;
    size_t key_len;
    unsigned char key[MBEDTLS_PSK_MAX_LEN];
    psk_entry *next;
};
void psk_free( psk_entry *head )
{
    psk_entry *next;

    while( head != NULL )
    {
        next = head->next;
        mbedtls_free( head );
        head = next;
    }
}
#endif /* MBEDTLS_KEY_EXCHANGE__SOME__PSK_ENABLED */
#if !defined(_WIN32)
#endif
#if defined(MBEDTLS_X509_CRT_PARSE_C)
#if defined(MBEDTLS_SHA512_C)
#endif
#if defined(MBEDTLS_SHA256_C)
#endif
#if defined(MBEDTLS_SHA1_C)
#endif
#endif /* MBEDTLS_X509_CRT_PARSE_C */
#if defined(MBEDTLS_SSL_ASYNC_PRIVATE)
typedef struct
{
    mbedtls_x509_crt *cert; /*!< Certificate corresponding to the key */
    mbedtls_pk_context *pk; /*!< Private key */
    unsigned delay; /*!< Number of resume steps to go through */
    unsigned pk_owned : 1; /*!< Whether to free the pk object on exit */
} ssl_async_key_slot_t;
typedef enum {
    SSL_ASYNC_INJECT_ERROR_NONE = 0, /*!< Let the callbacks succeed */
    SSL_ASYNC_INJECT_ERROR_START, /*!< Inject error during start */
    SSL_ASYNC_INJECT_ERROR_CANCEL, /*!< Close the connection after async start */
    SSL_ASYNC_INJECT_ERROR_RESUME, /*!< Inject error during resume */
#define SSL_ASYNC_INJECT_ERROR_MAX SSL_ASYNC_INJECT_ERROR_RESUME
} ssl_async_inject_error_t;
typedef struct
{
    ssl_async_key_slot_t slots[4]; /* key, key2, sni1, sni2 */
    size_t slots_used;
    ssl_async_inject_error_t inject_error;
    int (*f_rng)(void *, unsigned char *, size_t);
    void *p_rng;
} ssl_async_key_context_t;
#define SSL_ASYNC_INPUT_MAX_SIZE 512
typedef enum
{
    ASYNC_OP_SIGN,
    ASYNC_OP_DECRYPT,
} ssl_async_operation_type_t;
typedef struct
{
    unsigned slot;
    ssl_async_operation_type_t operation_type;
    mbedtls_md_type_t md_alg;
    unsigned char input[SSL_ASYNC_INPUT_MAX_SIZE];
    size_t input_len;
    unsigned remaining_delay;
} ssl_async_operation_context_t;
#endif /* MBEDTLS_SSL_ASYNC_PRIVATE */
#if !defined(MBEDTLS_TIMING_C)
#else
#endif
#if !defined(MBEDTLS_TIMING_C)
#endif
#if defined(MBEDTLS_TIMING_C)
#endif /* MBEDTLS_TIMING_C */
#if defined(MBEDTLS_KEY_EXCHANGE__SOME__PSK_ENABLED)
#endif
#if defined(MBEDTLS_SSL_COOKIE_C)
#endif
#if defined(MBEDTLS_X509_CRT_PARSE_C)
#endif
#if defined(MBEDTLS_TIMING_C)
#endif
#if defined(MBEDTLS_SSL_RENEGOTIATION)
#endif
#if defined(MBEDTLS_X509_CRT_PARSE_C)
#if defined(MBEDTLS_SSL_ASYNC_PRIVATE)
#endif /* MBEDTLS_SSL_ASYNC_PRIVATE */
#endif /* MBEDTLS_X509_CRT_PARSE_C */
#if defined(MBEDTLS_DHM_C) && defined(MBEDTLS_FS_IO)
#endif
#if defined(MBEDTLS_SSL_CACHE_C)
#endif
#if defined(MBEDTLS_SSL_SESSION_TICKETS)
#endif
#if defined(SNI_OPTION)
#endif
#if defined(MBEDTLS_ECP_C)
#endif
#if defined(MBEDTLS_SSL_ALPN)
#endif
#if defined(MBEDTLS_MEMORY_BUFFER_ALLOC_C)
#endif
#if defined(MBEDTLS_MEMORY_BUFFER_ALLOC_C)
#endif
#if defined(MBEDTLS_X509_CRT_PARSE_C)
#if defined(MBEDTLS_SSL_ASYNC_PRIVATE)
#endif
#endif
#if defined(MBEDTLS_DHM_C) && defined(MBEDTLS_FS_IO)
#endif
#if defined(MBEDTLS_SSL_CACHE_C)
#endif
#if defined(MBEDTLS_SSL_SESSION_TICKETS)
#endif
#if defined(MBEDTLS_SSL_ALPN)
#endif
#if defined(MBEDTLS_SSL_COOKIE_C)
#endif
#if !defined(_WIN32)
#endif
#if defined(MBEDTLS_SSL_ASYNC_PRIVATE)
#endif /* MBEDTLS_SSL_ASYNC_PRIVATE */
#if defined(_MSC_VER)
#else
#endif /* _MSC_VER */
#if defined(MBEDTLS_DEBUG_C)
#endif
#if defined(MBEDTLS_KEY_EXCHANGE__SOME__PSK_ENABLED)
#endif /* MBEDTLS_KEY_EXCHANGE__SOME__PSK_ENABLED */
#if defined(MBEDTLS_ECP_C)
#endif /* MBEDTLS_ECP_C */
#if defined(MBEDTLS_SSL_ALPN)
#endif /* MBEDTLS_SSL_ALPN */
#if defined(MBEDTLS_X509_CRT_PARSE_C)
#if defined(MBEDTLS_FS_IO)
#endif
#if defined(MBEDTLS_CERTS_C)
#if defined(MBEDTLS_PEM_PARSE_C)
#endif /* MBEDTLS_PEM_PARSE_C */
#else
#endif /* MBEDTLS_CERTS_C */
#if defined(MBEDTLS_FS_IO)
#endif
#if !defined(MBEDTLS_CERTS_C)
#else
#if defined(MBEDTLS_RSA_C)
#endif /* MBEDTLS_RSA_C */
#if defined(MBEDTLS_ECDSA_C)
#endif /* MBEDTLS_ECDSA_C */
#endif /* MBEDTLS_CERTS_C */
#endif /* MBEDTLS_X509_CRT_PARSE_C */
#if defined(MBEDTLS_DHM_C) && defined(MBEDTLS_FS_IO)
#endif
#if defined(SNI_OPTION)
#endif /* SNI_OPTION */
#if defined(MBEDTLS_X509_CRT_PARSE_C)
#endif /* MBEDTLS_X509_CRT_PARSE_C */
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#endif /* MBEDTLS_SSL_PROTO_DTLS */
#if defined(MBEDTLS_SSL_MAX_FRAGMENT_LENGTH)
#endif
#if defined(MBEDTLS_SSL_TRUNCATED_HMAC)
#endif
#if defined(MBEDTLS_SSL_EXTENDED_MASTER_SECRET)
#endif
#if defined(MBEDTLS_SSL_ENCRYPT_THEN_MAC)
#endif
#if defined(MBEDTLS_SSL_ALPN)
#endif
#if defined(MBEDTLS_SSL_CACHE_C)
#endif
#if defined(MBEDTLS_SSL_SESSION_TICKETS)
#endif
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#if defined(MBEDTLS_SSL_COOKIE_C)
#endif /* MBEDTLS_SSL_COOKIE_C */
#if defined(MBEDTLS_SSL_DTLS_HELLO_VERIFY)
#endif /* MBEDTLS_SSL_DTLS_HELLO_VERIFY */
#if defined(MBEDTLS_SSL_DTLS_ANTI_REPLAY)
#endif
#if defined(MBEDTLS_SSL_DTLS_BADMAC_LIMIT)
#endif
#endif /* MBEDTLS_SSL_PROTO_DTLS */
#if defined(MBEDTLS_ARC4_C)
#endif
#if defined(MBEDTLS_SSL_RENEGOTIATION)
#endif
#if defined(MBEDTLS_X509_CRT_PARSE_C)
#if defined(MBEDTLS_SSL_ASYNC_PRIVATE)
#endif /* MBEDTLS_SSL_ASYNC_PRIVATE */
#if defined(MBEDTLS_SSL_ASYNC_PRIVATE)
#endif /* MBEDTLS_SSL_ASYNC_PRIVATE */
#if defined(MBEDTLS_SSL_ASYNC_PRIVATE)
#endif /* MBEDTLS_SSL_ASYNC_PRIVATE */
#endif /* MBEDTLS_X509_CRT_PARSE_C */
#if defined(SNI_OPTION)
#if defined(MBEDTLS_SSL_ASYNC_PRIVATE)
#endif /* MBEDTLS_SSL_ASYNC_PRIVATE */
#endif
#if defined(MBEDTLS_ECP_C)
#endif
#if defined(MBEDTLS_KEY_EXCHANGE__SOME__PSK_ENABLED)
#endif
#if defined(MBEDTLS_DHM_C)
#if defined(MBEDTLS_FS_IO)
#endif
#endif
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#endif
#if defined(MBEDTLS_TIMING_C)
#endif
#if !defined(_WIN32)
#endif
#ifdef MBEDTLS_ERROR_C
#endif
#if !defined(_WIN32)
#endif
#if defined(MBEDTLS_SSL_DTLS_HELLO_VERIFY)
#endif /* MBEDTLS_SSL_DTLS_HELLO_VERIFY */
#if defined(MBEDTLS_KEY_EXCHANGE_ECJPAKE_ENABLED)
#endif
#if defined(MBEDTLS_SSL_ASYNC_PRIVATE)
#endif /* MBEDTLS_SSL_ASYNC_PRIVATE */
#if defined(MBEDTLS_TIMING_C)
#else
#endif
#if defined(MBEDTLS_X509_CRT_PARSE_C)
#endif
#if defined(MBEDTLS_SSL_ASYNC_PRIVATE)
#endif
#if defined(MBEDTLS_SSL_MAX_FRAGMENT_LENGTH)
#endif
#if defined(MBEDTLS_SSL_ALPN)
#endif
#if defined(MBEDTLS_X509_CRT_PARSE_C)
#endif /* MBEDTLS_X509_CRT_PARSE_C */
#if defined(MBEDTLS_TIMING_C)
#else
#endif
#if defined(MBEDTLS_TIMING_C)
#else
#endif
#if defined(MBEDTLS_SSL_RENEGOTIATION)
#if defined(MBEDTLS_TIMING_C)
#else
#endif
#endif /* MBEDTLS_SSL_RENEGOTIATION */
#if defined(MBEDTLS_TIMING_C)
#else
#endif
#if defined(MBEDTLS_TIMING_C)
#else
#endif
#ifdef MBEDTLS_ERROR_C
#endif
#if defined(MBEDTLS_DHM_C) && defined(MBEDTLS_FS_IO)
#endif
#if defined(MBEDTLS_X509_CRT_PARSE_C)
#endif
#if defined(MBEDTLS_SSL_ASYNC_PRIVATE)
#endif
#if defined(SNI_OPTION)
#endif
#if defined(MBEDTLS_KEY_EXCHANGE__SOME__PSK_ENABLED)
#endif
#if defined(MBEDTLS_DHM_C) && defined(MBEDTLS_FS_IO)
#endif
#if defined(MBEDTLS_SSL_CACHE_C)
#endif
#if defined(MBEDTLS_SSL_SESSION_TICKETS)
#endif
#if defined(MBEDTLS_SSL_COOKIE_C)
#endif
#if defined(MBEDTLS_MEMORY_BUFFER_ALLOC_C)
#if defined(MBEDTLS_MEMORY_DEBUG)
#endif
#endif
#if defined(_WIN32)
#endif
#endif /* MBEDTLS_BIGNUM_C && MBEDTLS_ENTROPY_C && MBEDTLS_SSL_TLS_C &&
