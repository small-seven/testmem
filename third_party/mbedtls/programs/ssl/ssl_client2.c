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
#define mbedtls_time       time
#define mbedtls_time_t     time_t
#define mbedtls_printf     printf
#define mbedtls_fprintf    fprintf
#define mbedtls_snprintf   snprintf
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
#define MAX_REQUEST_SIZE      20000
#define MAX_REQUEST_SIZE_STR "20000"
#define DFL_SERVER_NAME         "localhost"
#define DFL_SERVER_ADDR         NULL
#define DFL_SERVER_PORT         "4433"
#define DFL_REQUEST_PAGE        "/"
#define DFL_REQUEST_SIZE        -1
#define DFL_DEBUG_LEVEL         0
#define DFL_NBIO                0
#define DFL_EVENT               0
#define DFL_READ_TIMEOUT        0
#define DFL_MAX_RESEND          0
#define DFL_CA_FILE             ""
#define DFL_CA_PATH             ""
#define DFL_CRT_FILE            ""
#define DFL_KEY_FILE            ""
#define DFL_PSK                 ""
#define DFL_PSK_IDENTITY        "Client_identity"
#define DFL_ECJPAKE_PW          NULL
#define DFL_EC_MAX_OPS          -1
#define DFL_FORCE_CIPHER        0
#define DFL_RENEGOTIATION       MBEDTLS_SSL_RENEGOTIATION_DISABLED
#define DFL_ALLOW_LEGACY        -2
#define DFL_RENEGOTIATE         0
#define DFL_EXCHANGES           1
#define DFL_MIN_VERSION         -1
#define DFL_MAX_VERSION         -1
#define DFL_ARC4                -1
#define DFL_SHA1                -1
#define DFL_AUTH_MODE           -1
#define DFL_MFL_CODE            MBEDTLS_SSL_MAX_FRAG_LEN_NONE
#define DFL_TRUNC_HMAC          -1
#define DFL_RECSPLIT            -1
#define DFL_DHMLEN              -1
#define DFL_RECONNECT           0
#define DFL_RECO_DELAY          0
#define DFL_RECONNECT_HARD      0
#define DFL_TICKETS             MBEDTLS_SSL_SESSION_TICKETS_ENABLED
#define DFL_ALPN_STRING         NULL
#define DFL_CURVES              NULL
#define DFL_TRANSPORT           MBEDTLS_SSL_TRANSPORT_STREAM
#define DFL_HS_TO_MIN           0
#define DFL_HS_TO_MAX           0
#define DFL_DTLS_MTU            -1
#define DFL_DGRAM_PACKING        1
#define DFL_FALLBACK            -1
#define DFL_EXTENDED_MS         -1
#define DFL_ETM                 -1
#define DFL_SKIP_CLOSE_NOTIFY   0
#define GET_REQUEST "GET %s HTTP/1.0\r\nExtra-header: "
#define GET_REQUEST_END "\r\n\r\n"
#if defined(MBEDTLS_X509_CRT_PARSE_C)
#if defined(MBEDTLS_FS_IO)
#define USAGE_IO \
#else
#define USAGE_IO \
#endif /* MBEDTLS_FS_IO */
#else
#define USAGE_IO ""
#endif /* MBEDTLS_X509_CRT_PARSE_C */
#if defined(MBEDTLS_KEY_EXCHANGE__SOME__PSK_ENABLED)
#define USAGE_PSK                                                   \
#else
#define USAGE_PSK ""
#endif /* MBEDTLS_KEY_EXCHANGE__SOME__PSK_ENABLED */
#if defined(MBEDTLS_SSL_SESSION_TICKETS)
#define USAGE_TICKETS                                       \
#else
#define USAGE_TICKETS ""
#endif /* MBEDTLS_SSL_SESSION_TICKETS */
#if defined(MBEDTLS_SSL_TRUNCATED_HMAC)
#define USAGE_TRUNC_HMAC                                    \
#else
#define USAGE_TRUNC_HMAC ""
#endif /* MBEDTLS_SSL_TRUNCATED_HMAC */
#if defined(MBEDTLS_SSL_MAX_FRAGMENT_LENGTH)
#define USAGE_MAX_FRAG_LEN                                      \
#else
#define USAGE_MAX_FRAG_LEN ""
#endif /* MBEDTLS_SSL_MAX_FRAGMENT_LENGTH */
#if defined(MBEDTLS_SSL_CBC_RECORD_SPLITTING)
#define USAGE_RECSPLIT \
#else
#define USAGE_RECSPLIT
#endif
#if defined(MBEDTLS_DHM_C)
#define USAGE_DHMLEN \
#else
#define USAGE_DHMLEN
#endif
#if defined(MBEDTLS_SSL_ALPN)
#define USAGE_ALPN \
#else
#define USAGE_ALPN ""
#endif /* MBEDTLS_SSL_ALPN */
#if defined(MBEDTLS_ECP_C)
#define USAGE_CURVES \
#else
#define USAGE_CURVES ""
#endif
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#define USAGE_DTLS \
#else
#define USAGE_DTLS ""
#endif
#if defined(MBEDTLS_SSL_FALLBACK_SCSV)
#define USAGE_FALLBACK \
#else
#define USAGE_FALLBACK ""
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
#if defined(MBEDTLS_ECP_RESTARTABLE)
#define USAGE_ECRESTART \
#else
#define USAGE_ECRESTART ""
#endif
#define USAGE \
#define ALPN_LIST_SIZE  10
#define CURVE_LIST_SIZE 20
#if defined(MBEDTLS_X509_CRT_PARSE_C)
#if defined(MBEDTLS_SHA512_C)
#endif
#if defined(MBEDTLS_SHA256_C)
#endif
#if defined(MBEDTLS_SHA1_C)
#endif
#endif /* MBEDTLS_X509_CRT_PARSE_C */
#if !defined(MBEDTLS_TIMING_C)
#else
#endif
#if !defined(MBEDTLS_TIMING_C)
#endif
#if defined(MBEDTLS_TIMING_C)
#endif /* MBEDTLS_TIMING_C */
#if defined(MBEDTLS_KEY_EXCHANGE__SOME__PSK_ENABLED)
#endif
#if defined(MBEDTLS_SSL_ALPN)
#endif
#if defined(MBEDTLS_ECP_C)
#endif
#if defined(MBEDTLS_X509_CRT_PARSE_C)
#endif
#if defined(MBEDTLS_TIMING_C)
#endif
#if defined(MBEDTLS_X509_CRT_PARSE_C)
#endif
#if defined(MBEDTLS_X509_CRT_PARSE_C)
#endif
#if defined(MBEDTLS_SSL_ALPN)
#endif
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
#if defined(MBEDTLS_CERTS_C)
#else
#endif
#if defined(MBEDTLS_FS_IO)
#endif
#if defined(MBEDTLS_CERTS_C)
#else
#endif
#endif /* MBEDTLS_X509_CRT_PARSE_C */
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
#if defined(MBEDTLS_SSL_CBC_RECORD_SPLITTING)
#endif
#if defined(MBEDTLS_DHM_C)
#endif
#if defined(MBEDTLS_SSL_ALPN)
#endif
#if defined(MBEDTLS_SSL_SESSION_TICKETS)
#endif
#if defined(MBEDTLS_ARC4_C)
#endif
#if defined(MBEDTLS_SSL_RENEGOTIATION)
#endif
#if defined(MBEDTLS_X509_CRT_PARSE_C)
#endif
#if defined(MBEDTLS_ECP_C)
#endif
#if defined(MBEDTLS_KEY_EXCHANGE__SOME__PSK_ENABLED)
#endif
#if defined(MBEDTLS_SSL_FALLBACK_SCSV)
#endif
#if defined(MBEDTLS_X509_CRT_PARSE_C)
#endif
#if defined(MBEDTLS_KEY_EXCHANGE_ECJPAKE_ENABLED)
#endif
#if defined(MBEDTLS_SSL_PROTO_DTLS)
#endif
#if defined(MBEDTLS_TIMING_C)
#endif
#if defined(MBEDTLS_ECP_RESTARTABLE)
#endif
#if defined(MBEDTLS_ECP_RESTARTABLE)
#endif
#if defined(MBEDTLS_TIMING_C)
#else
#endif
#if defined(MBEDTLS_SSL_MAX_FRAGMENT_LENGTH)
#endif
#if defined(MBEDTLS_SSL_ALPN)
#endif
#if defined(MBEDTLS_X509_CRT_PARSE_C)
#endif /* MBEDTLS_X509_CRT_PARSE_C */
#if defined(MBEDTLS_SSL_RENEGOTIATION)
#if defined(MBEDTLS_ECP_RESTARTABLE)
#endif
#if defined(MBEDTLS_TIMING_C)
#else
#endif
#endif /* MBEDTLS_SSL_RENEGOTIATION */
#if defined(MBEDTLS_TIMING_C)
#else
#endif
#if defined(MBEDTLS_ECP_RESTARTABLE)
#endif
#if defined(MBEDTLS_TIMING_C)
#else
#endif
#if defined(MBEDTLS_ECP_RESTARTABLE)
#endif
#if defined(MBEDTLS_TIMING_C)
#else
#endif
#if defined(MBEDTLS_ECP_RESTARTABLE)
#endif
#if defined(MBEDTLS_TIMING_C)
#else
#endif
#if defined(MBEDTLS_TIMING_C)
#else
#endif
#if defined(MBEDTLS_TIMING_C)
#endif
#ifdef MBEDTLS_ERROR_C
#endif
#if defined(MBEDTLS_X509_CRT_PARSE_C)
#endif
#if defined(_WIN32)
#endif
#endif /* MBEDTLS_BIGNUM_C && MBEDTLS_ENTROPY_C && MBEDTLS_SSL_TLS_C &&
