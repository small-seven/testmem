#include "lwip/opt.h"
#if LWIP_ALTCP /* don't build if not configured for use in lwipopts.h */
#include "lwip/apps/altcp_tls_mbedtls_opts.h"
#if LWIP_ALTCP_TLS && LWIP_ALTCP_TLS_MBEDTLS
#include "lwip/altcp.h"
#include "lwip/altcp_tls.h"
#include "lwip/priv/altcp_priv.h"
#include "altcp_tls_mbedtls_structs.h"
#include "altcp_tls_mbedtls_mem.h"
#include "mbedtls/entropy.h"
#include "mbedtls/ctr_drbg.h"
#include "mbedtls/certs.h"
#include "mbedtls/x509.h"
#include "mbedtls/ssl.h"
#include "mbedtls/net.h"
#include "mbedtls/error.h"
#include "mbedtls/debug.h"
#include "mbedtls/platform.h"
#include "mbedtls/memory_buffer_alloc.h"
#include "mbedtls/ssl_cache.h"
#include "mbedtls/ssl_internal.h" /* to call mbedtls_flush_output after ERR_MEM */
#include <string.h>
#ifndef ALTCP_MBEDTLS_ENTROPY_PTR
#define ALTCP_MBEDTLS_ENTROPY_PTR   NULL
#endif
#ifndef ALTCP_MBEDTLS_ENTROPY_LEN
#define ALTCP_MBEDTLS_ENTROPY_LEN   0
#endif
#if defined(MBEDTLS_SSL_CACHE_C) && ALTCP_MBEDTLS_SESSION_CACHE_TIMEOUT_SECONDS
#endif
#if ALTCP_MBEDTLS_DEBUG != LWIP_DBG_OFF
#endif
#ifndef ALTCP_MBEDTLS_RNG_FN
#define ALTCP_MBEDTLS_RNG_FN dummy_rng
#endif /* ALTCP_MBEDTLS_RNG_FN */
#if ALTCP_MBEDTLS_DEBUG != LWIP_DBG_OFF
#endif
#if defined(MBEDTLS_SSL_CACHE_C) && ALTCP_MBEDTLS_SESSION_CACHE_TIMEOUT_SECONDS
#endif
#if defined(MBEDTLS_SSL_MAX_FRAGMENT_LENGTH)
#endif
#ifdef LWIP_DEBUG
#endif
#endif /* LWIP_ALTCP_TLS && LWIP_ALTCP_TLS_MBEDTLS */
#endif /* LWIP_ALTCP */
