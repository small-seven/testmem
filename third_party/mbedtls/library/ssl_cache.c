#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_SSL_CACHE_C)
#if defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#else
#include <stdlib.h>
#define mbedtls_calloc    calloc
#define mbedtls_free      free
#endif
#include "mbedtls/ssl_cache.h"
#include <string.h>
#if defined(MBEDTLS_THREADING_C)
#endif
#if defined(MBEDTLS_HAVE_TIME)
#endif
#if defined(MBEDTLS_THREADING_C)
#endif
#if defined(MBEDTLS_HAVE_TIME)
#endif
#if defined(MBEDTLS_X509_CRT_PARSE_C)
#endif /* MBEDTLS_X509_CRT_PARSE_C */
#if defined(MBEDTLS_THREADING_C)
#endif
#if defined(MBEDTLS_HAVE_TIME)
#endif
#if defined(MBEDTLS_THREADING_C)
#endif
#if defined(MBEDTLS_HAVE_TIME)
#endif
#if defined(MBEDTLS_HAVE_TIME)
#endif
#if defined(MBEDTLS_HAVE_TIME)
#else /* MBEDTLS_HAVE_TIME */
#endif /* MBEDTLS_HAVE_TIME */
#if defined(MBEDTLS_HAVE_TIME)
#endif
#if defined(MBEDTLS_X509_CRT_PARSE_C)
#endif /* MBEDTLS_X509_CRT_PARSE_C */
#if defined(MBEDTLS_THREADING_C)
#endif
#if defined(MBEDTLS_HAVE_TIME)
#endif /* MBEDTLS_HAVE_TIME */
void mbedtls_ssl_cache_free( mbedtls_ssl_cache_context *cache )
{
    mbedtls_ssl_cache_entry *cur, *prv;

    cur = cache->chain;

    while( cur != NULL )
    {
        prv = cur;
        cur = cur->next;

        mbedtls_ssl_session_free( &prv->session );

#if defined(MBEDTLS_X509_CRT_PARSE_C)
        mbedtls_free( prv->peer_cert.p );
#endif /* MBEDTLS_X509_CRT_PARSE_C */

        mbedtls_free( prv );
    }

#if defined(MBEDTLS_THREADING_C)
    mbedtls_mutex_free( &cache->mutex );
#endif
    cache->chain = NULL;
}
#endif /* MBEDTLS_SSL_CACHE_C */
