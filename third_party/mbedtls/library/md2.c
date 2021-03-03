#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_MD2_C)
#include "mbedtls/md2.h"
#include "mbedtls/platform_util.h"
#include <string.h>
#if defined(MBEDTLS_SELF_TEST)
#if defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#else
#include <stdio.h>
#define mbedtls_printf printf
#endif /* MBEDTLS_PLATFORM_C */
#endif /* MBEDTLS_SELF_TEST */
#if !defined(MBEDTLS_MD2_ALT)
void mbedtls_md2_free( mbedtls_md2_context *ctx )
{
    if( ctx == NULL )
        return;

    mbedtls_platform_zeroize( ctx, sizeof( mbedtls_md2_context ) );
}
#if !defined(MBEDTLS_DEPRECATED_REMOVED)
#endif
#if !defined(MBEDTLS_MD2_PROCESS_ALT)
#if !defined(MBEDTLS_DEPRECATED_REMOVED)
#endif
#endif /* !MBEDTLS_MD2_PROCESS_ALT */
#if !defined(MBEDTLS_DEPRECATED_REMOVED)
#endif
#if !defined(MBEDTLS_DEPRECATED_REMOVED)
#endif
#endif /* !MBEDTLS_MD2_ALT */
#if !defined(MBEDTLS_DEPRECATED_REMOVED)
#endif
#if defined(MBEDTLS_SELF_TEST)
#endif /* MBEDTLS_SELF_TEST */
#endif /* MBEDTLS_MD2_C */
