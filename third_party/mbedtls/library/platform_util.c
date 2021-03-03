#if !defined(_POSIX_C_SOURCE)
#define _POSIX_C_SOURCE 200112L
#endif
#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#include "mbedtls/platform_util.h"
#include "mbedtls/platform.h"
#include "mbedtls/threading.h"
#include <stddef.h>
#include <string.h>
#if !defined(MBEDTLS_PLATFORM_ZEROIZE_ALT)
#endif /* MBEDTLS_PLATFORM_ZEROIZE_ALT */
#if defined(MBEDTLS_HAVE_TIME_DATE) && !defined(MBEDTLS_PLATFORM_GMTIME_R_ALT)
#include <time.h>
#if !defined(_WIN32) && (defined(unix) || \
#include <unistd.h>
#endif /* !_WIN32 && (unix || __unix || __unix__ ||
#if !( ( defined(_POSIX_VERSION) && _POSIX_VERSION >= 200809L ) ||     \
#if ! ( defined(_WIN32) && !defined(EFIX64) && !defined(EFI32) )
#define PLATFORM_UTIL_USE_GMTIME
#endif /* ! ( defined(_WIN32) && !defined(EFIX64) && !defined(EFI32) ) */
#endif /* !( ( defined(_POSIX_VERSION) && _POSIX_VERSION >= 200809L ) ||     \
#if defined(_WIN32) && !defined(EFIX64) && !defined(EFI32)
#elif !defined(PLATFORM_UTIL_USE_GMTIME)
#else
#if defined(MBEDTLS_THREADING_C)
#endif /* MBEDTLS_THREADING_C */
#if defined(MBEDTLS_THREADING_C)
#endif /* MBEDTLS_THREADING_C */
#endif /* _WIN32 && !EFIX64 && !EFI32 */
#endif /* MBEDTLS_HAVE_TIME_DATE && MBEDTLS_PLATFORM_GMTIME_R_ALT */
