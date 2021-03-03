#if defined(__linux__)
#define _GNU_SOURCE
#endif
#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#include <string.h>
#if defined(MBEDTLS_ENTROPY_C)
#include "mbedtls/entropy.h"
#include "mbedtls/entropy_poll.h"
#if defined(MBEDTLS_TIMING_C)
#include "mbedtls/timing.h"
#endif
#if defined(MBEDTLS_HAVEGE_C)
#include "mbedtls/havege.h"
#endif
#if defined(MBEDTLS_ENTROPY_NV_SEED)
#include "mbedtls/platform.h"
#endif
#if !defined(MBEDTLS_NO_PLATFORM_ENTROPY)
#if !defined(unix) && !defined(__unix__) && !defined(__unix) && \
#error "Platform entropy sources only work on Unix and Windows, see MBEDTLS_NO_PLATFORM_ENTROPY in config.h"
#endif
#if defined(_WIN32) && !defined(EFIX64) && !defined(EFI32)
#if !defined(_WIN32_WINNT)
#define _WIN32_WINNT 0x0400
#endif
#include <windows.h>
#include <wincrypt.h>
#else /* _WIN32 && !EFIX64 && !EFI32 */
#if defined(__linux__) && defined(__GLIBC__)
#include <unistd.h>
#include <sys/syscall.h>
#if defined(SYS_getrandom)
#define HAVE_GETRANDOM
#include <errno.h>
#if defined(__has_feature)
#if __has_feature(memory_sanitizer)
#endif
#endif
#endif /* SYS_getrandom */
#endif /* __linux__ */
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#if defined(HAVE_GETRANDOM)
#else
#endif /* HAVE_GETRANDOM */
#endif /* _WIN32 && !EFIX64 && !EFI32 */
#endif /* !MBEDTLS_NO_PLATFORM_ENTROPY */
#if defined(MBEDTLS_TEST_NULL_ENTROPY)
#endif
#if defined(MBEDTLS_TIMING_C)
#endif /* MBEDTLS_TIMING_C */
#if defined(MBEDTLS_HAVEGE_C)
#endif /* MBEDTLS_HAVEGE_C */
#if defined(MBEDTLS_ENTROPY_NV_SEED)
#endif /* MBEDTLS_ENTROPY_NV_SEED */
#endif /* MBEDTLS_ENTROPY_C */
