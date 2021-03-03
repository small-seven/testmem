#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#include "mbedtls/platform_util.h"
#if defined(MBEDTLS_PLATFORM_MEMORY) &&                 \
#if !defined(MBEDTLS_PLATFORM_STD_CALLOC)
#define MBEDTLS_PLATFORM_STD_CALLOC   platform_calloc_uninit
#endif /* !MBEDTLS_PLATFORM_STD_CALLOC */
#if !defined(MBEDTLS_PLATFORM_STD_FREE)
#define MBEDTLS_PLATFORM_STD_FREE     platform_free_uninit
#endif /* !MBEDTLS_PLATFORM_STD_FREE */
void * mbedtls_calloc( size_t nmemb, size_t size )
{
    return (*mbedtls_calloc_func)( nmemb, size );
}
void mbedtls_free( void * ptr )
{
    (*mbedtls_free_func)( ptr );
}
int mbedtls_platform_set_calloc_free( void * (*calloc_func)( size_t, size_t ),
                              void (*free_func)( void * ) )
{
    mbedtls_calloc_func = calloc_func;
    mbedtls_free_func = free_func;
    return( 0 );
}
#endif /* MBEDTLS_PLATFORM_MEMORY &&
#if defined(_WIN32)
#include <stdarg.h>
#if defined(_TRUNCATE) && !defined(__MINGW32__)
#else
#endif
#endif
#if defined(MBEDTLS_PLATFORM_SNPRINTF_ALT)
#if !defined(MBEDTLS_PLATFORM_STD_SNPRINTF)
#define MBEDTLS_PLATFORM_STD_SNPRINTF    platform_snprintf_uninit
#endif /* !MBEDTLS_PLATFORM_STD_SNPRINTF */
#endif /* MBEDTLS_PLATFORM_SNPRINTF_ALT */
#if defined(MBEDTLS_PLATFORM_PRINTF_ALT)
#if !defined(MBEDTLS_PLATFORM_STD_PRINTF)
#define MBEDTLS_PLATFORM_STD_PRINTF    platform_printf_uninit
#endif /* !MBEDTLS_PLATFORM_STD_PRINTF */
#endif /* MBEDTLS_PLATFORM_PRINTF_ALT */
#if defined(MBEDTLS_PLATFORM_FPRINTF_ALT)
#if !defined(MBEDTLS_PLATFORM_STD_FPRINTF)
#define MBEDTLS_PLATFORM_STD_FPRINTF   platform_fprintf_uninit
#endif /* !MBEDTLS_PLATFORM_STD_FPRINTF */
#endif /* MBEDTLS_PLATFORM_FPRINTF_ALT */
#if defined(MBEDTLS_PLATFORM_EXIT_ALT)
#if !defined(MBEDTLS_PLATFORM_STD_EXIT)
#define MBEDTLS_PLATFORM_STD_EXIT   platform_exit_uninit
#endif /* !MBEDTLS_PLATFORM_STD_EXIT */
#endif /* MBEDTLS_PLATFORM_EXIT_ALT */
#if defined(MBEDTLS_HAVE_TIME)
#if defined(MBEDTLS_PLATFORM_TIME_ALT)
#if !defined(MBEDTLS_PLATFORM_STD_TIME)
static mbedtls_time_t platform_time_uninit( mbedtls_time_t* timer )
{
    ((void) timer);
    return( 0 );
}
#define MBEDTLS_PLATFORM_STD_TIME   platform_time_uninit
#endif /* !MBEDTLS_PLATFORM_STD_TIME */
#endif /* MBEDTLS_PLATFORM_TIME_ALT */
#endif /* MBEDTLS_HAVE_TIME */
#if defined(MBEDTLS_ENTROPY_NV_SEED)
#if !defined(MBEDTLS_PLATFORM_NO_STD_FUNCTIONS) && defined(MBEDTLS_FS_IO)
#endif /* MBEDTLS_PLATFORM_NO_STD_FUNCTIONS */
#if defined(MBEDTLS_PLATFORM_NV_SEED_ALT)
#if !defined(MBEDTLS_PLATFORM_STD_NV_SEED_READ)
#define MBEDTLS_PLATFORM_STD_NV_SEED_READ   platform_nv_seed_read_uninit
#endif /* !MBEDTLS_PLATFORM_STD_NV_SEED_READ */
#if !defined(MBEDTLS_PLATFORM_STD_NV_SEED_WRITE)
#define MBEDTLS_PLATFORM_STD_NV_SEED_WRITE   platform_nv_seed_write_uninit
#endif /* !MBEDTLS_PLATFORM_STD_NV_SEED_WRITE */
#endif /* MBEDTLS_PLATFORM_NV_SEED_ALT */
#endif /* MBEDTLS_ENTROPY_NV_SEED */
#if !defined(MBEDTLS_PLATFORM_SETUP_TEARDOWN_ALT)
#endif /* MBEDTLS_PLATFORM_SETUP_TEARDOWN_ALT */
#endif /* MBEDTLS_PLATFORM_C */
