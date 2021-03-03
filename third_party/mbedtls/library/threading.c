#if !defined(_POSIX_C_SOURCE)
#define _POSIX_C_SOURCE 200112L
#endif
#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_THREADING_C)
#include "mbedtls/threading.h"
#if defined(MBEDTLS_HAVE_TIME_DATE) && !defined(MBEDTLS_PLATFORM_GMTIME_R_ALT)
#if !defined(_WIN32) && (defined(unix) || \
#include <unistd.h>
#endif /* !_WIN32 && (unix || __unix || __unix__ ||
#if !( ( defined(_POSIX_VERSION) && _POSIX_VERSION >= 200809L ) ||     \
#if ! ( defined(_WIN32) && !defined(EFIX64) && !defined(EFI32) )
#define THREADING_USE_GMTIME
#endif /* ! ( defined(_WIN32) && !defined(EFIX64) && !defined(EFI32) ) */
#endif /* !( ( defined(_POSIX_VERSION) && _POSIX_VERSION >= 200809L ) ||     \
#endif /* MBEDTLS_HAVE_TIME_DATE && !MBEDTLS_PLATFORM_GMTIME_R_ALT */
#if defined(MBEDTLS_THREADING_PTHREAD)
#define MUTEX_INIT  = { PTHREAD_MUTEX_INITIALIZER, 1 }
#endif /* MBEDTLS_THREADING_PTHREAD */
#if defined(MBEDTLS_THREADING_ALT)
#if defined(MBEDTLS_FS_IO)
#endif
#if defined(THREADING_USE_GMTIME)
#endif
#if defined(MBEDTLS_FS_IO)
#endif
#if defined(THREADING_USE_GMTIME)
#endif
#endif /* MBEDTLS_THREADING_ALT */
#ifndef MUTEX_INIT
#define MUTEX_INIT
#endif
#if defined(MBEDTLS_FS_IO)
#endif
#if defined(THREADING_USE_GMTIME)
#endif
#endif /* MBEDTLS_THREADING_C */
