#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_ENTROPY_C)
#if defined(MBEDTLS_TEST_NULL_ENTROPY)
#warning "**** WARNING!  MBEDTLS_TEST_NULL_ENTROPY defined! "
#warning "**** THIS BUILD HAS NO DEFINED ENTROPY SOURCES "
#warning "**** THIS BUILD IS *NOT* SUITABLE FOR PRODUCTION USE "
#endif
#include "mbedtls/entropy.h"
#include "mbedtls/entropy_poll.h"
#include "mbedtls/platform_util.h"
#include <string.h>
#if defined(MBEDTLS_FS_IO)
#include <stdio.h>
#endif
#if defined(MBEDTLS_ENTROPY_NV_SEED)
#include "mbedtls/platform.h"
#endif
#if defined(MBEDTLS_SELF_TEST)
#if defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#else
#include <stdio.h>
#define mbedtls_printf     printf
#endif /* MBEDTLS_PLATFORM_C */
#endif /* MBEDTLS_SELF_TEST */
#if defined(MBEDTLS_HAVEGE_C)
#include "mbedtls/havege.h"
#endif
#define ENTROPY_MAX_LOOP    256     /**< Maximum amount to loop before error */
#if defined(MBEDTLS_THREADING_C)
#endif
#if defined(MBEDTLS_ENTROPY_SHA512_ACCUMULATOR)
#else
#endif
#if defined(MBEDTLS_HAVEGE_C)
#endif
#if defined(MBEDTLS_TEST_NULL_ENTROPY)
#endif
#if !defined(MBEDTLS_NO_DEFAULT_ENTROPY_SOURCES)
#if !defined(MBEDTLS_NO_PLATFORM_ENTROPY)
#endif
#if defined(MBEDTLS_TIMING_C)
#endif
#if defined(MBEDTLS_HAVEGE_C)
#endif
#if defined(MBEDTLS_ENTROPY_HARDWARE_ALT)
#endif
#if defined(MBEDTLS_ENTROPY_NV_SEED)
#endif
#endif /* MBEDTLS_NO_DEFAULT_ENTROPY_SOURCES */
void mbedtls_entropy_free( mbedtls_entropy_context *ctx )
{
#if defined(MBEDTLS_HAVEGE_C)
    mbedtls_havege_free( &ctx->havege_data );
#endif
#if defined(MBEDTLS_THREADING_C)
    mbedtls_mutex_free( &ctx->mutex );
#endif
#if defined(MBEDTLS_ENTROPY_SHA512_ACCUMULATOR)
    mbedtls_sha512_free( &ctx->accumulator );
#else
    mbedtls_sha256_free( &ctx->accumulator );
#endif
#if defined(MBEDTLS_ENTROPY_NV_SEED)
    ctx->initial_entropy_run = 0;
#endif
    ctx->source_count = 0;
    mbedtls_platform_zeroize( ctx->source, sizeof( ctx->source ) );
    ctx->accumulator_started = 0;
}
#if defined(MBEDTLS_THREADING_C)
#endif
#if defined(MBEDTLS_THREADING_C)
#endif
#if defined(MBEDTLS_ENTROPY_SHA512_ACCUMULATOR)
#else
#endif
#if defined(MBEDTLS_ENTROPY_SHA512_ACCUMULATOR)
#else
#endif
#if defined(MBEDTLS_THREADING_C)
#endif
#if defined(MBEDTLS_THREADING_C)
#endif
#if defined(MBEDTLS_THREADING_C)
#endif
#if defined(MBEDTLS_THREADING_C)
#endif
#if defined(MBEDTLS_ENTROPY_NV_SEED)
#endif
#if defined(MBEDTLS_THREADING_C)
#endif
#if defined(MBEDTLS_ENTROPY_SHA512_ACCUMULATOR)
#else /* MBEDTLS_ENTROPY_SHA512_ACCUMULATOR */
#endif /* MBEDTLS_ENTROPY_SHA512_ACCUMULATOR */
#if defined(MBEDTLS_THREADING_C)
#endif
#if defined(MBEDTLS_ENTROPY_NV_SEED)
#endif /* MBEDTLS_ENTROPY_NV_SEED */
#if defined(MBEDTLS_FS_IO)
#endif /* MBEDTLS_FS_IO */
#if defined(MBEDTLS_SELF_TEST)
#if !defined(MBEDTLS_TEST_NULL_ENTROPY)
#endif /* !MBEDTLS_TEST_NULL_ENTROPY */
#if defined(MBEDTLS_ENTROPY_HARDWARE_ALT)
#endif /* MBEDTLS_ENTROPY_HARDWARE_ALT */
#if !defined(MBEDTLS_TEST_NULL_ENTROPY)
#endif /* !MBEDTLS_TEST_NULL_ENTROPY */
#if !defined(MBEDTLS_TEST_NULL_ENTROPY)
#if defined(MBEDTLS_ENTROPY_HARDWARE_ALT)
#endif
#endif /* !MBEDTLS_TEST_NULL_ENTROPY */
#endif /* MBEDTLS_SELF_TEST */
#endif /* MBEDTLS_ENTROPY_C */
