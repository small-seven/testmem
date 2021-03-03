#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_SELF_TEST) && defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#else
#include <stdio.h>
#define mbedtls_printf     printf
#endif
#if defined(MBEDTLS_TIMING_C)
#include "mbedtls/timing.h"
#if !defined(MBEDTLS_TIMING_ALT)
#if !defined(unix) && !defined(__unix__) && !defined(__unix) && \
#error "This module only works on Unix and Windows, see MBEDTLS_TIMING_C in config.h"
#endif
#ifndef asm
#define asm __asm
#endif
#if defined(_WIN32) && !defined(EFIX64) && !defined(EFI32)
#include <windows.h>
#include <process.h>
#else
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <signal.h>
#include <time.h>
#endif /* _WIN32 && !EFIX64 && !EFI32 */
#if !defined(HAVE_HARDCLOCK) && defined(MBEDTLS_HAVE_ASM) &&  \
#define HAVE_HARDCLOCK
#endif /* !HAVE_HARDCLOCK && MBEDTLS_HAVE_ASM &&
#if !defined(HAVE_HARDCLOCK) && defined(MBEDTLS_HAVE_ASM) &&  \
#define HAVE_HARDCLOCK
#endif /* !HAVE_HARDCLOCK && MBEDTLS_HAVE_ASM &&
#if !defined(HAVE_HARDCLOCK) && defined(MBEDTLS_HAVE_ASM) &&  \
#define HAVE_HARDCLOCK
#endif /* !HAVE_HARDCLOCK && MBEDTLS_HAVE_ASM &&
#if !defined(HAVE_HARDCLOCK) && defined(MBEDTLS_HAVE_ASM) &&  \
#define HAVE_HARDCLOCK
#endif /* !HAVE_HARDCLOCK && MBEDTLS_HAVE_ASM &&
#if !defined(HAVE_HARDCLOCK) && defined(MBEDTLS_HAVE_ASM) &&  \
#if defined(__OpenBSD__)
#warning OpenBSD does not allow access to tick register using software version instead
#else
#define HAVE_HARDCLOCK
#endif /* __OpenBSD__ */
#endif /* !HAVE_HARDCLOCK && MBEDTLS_HAVE_ASM &&
#if !defined(HAVE_HARDCLOCK) && defined(MBEDTLS_HAVE_ASM) &&  \
#define HAVE_HARDCLOCK
#endif /* !HAVE_HARDCLOCK && MBEDTLS_HAVE_ASM &&
#if !defined(HAVE_HARDCLOCK) && defined(MBEDTLS_HAVE_ASM) &&      \
#define HAVE_HARDCLOCK
#endif /* !HAVE_HARDCLOCK && MBEDTLS_HAVE_ASM &&
#if !defined(HAVE_HARDCLOCK) && defined(MBEDTLS_HAVE_ASM) &&      \
#define HAVE_HARDCLOCK
#endif /* !HAVE_HARDCLOCK && MBEDTLS_HAVE_ASM &&
#if !defined(HAVE_HARDCLOCK) && defined(_MSC_VER) && \
#define HAVE_HARDCLOCK
#endif /* !HAVE_HARDCLOCK && _MSC_VER && !EFIX64 && !EFI32 */
#if !defined(HAVE_HARDCLOCK)
#define HAVE_HARDCLOCK
#endif /* !HAVE_HARDCLOCK */
#if defined(_WIN32) && !defined(EFIX64) && !defined(EFI32)
#else /* _WIN32 && !EFIX64 && !EFI32 */
#endif /* _WIN32 && !EFIX64 && !EFI32 */
#endif /* !MBEDTLS_TIMING_ALT */
#if defined(MBEDTLS_SELF_TEST)
#define FAIL    do                                                      \
#endif /* MBEDTLS_SELF_TEST */
#endif /* MBEDTLS_TIMING_C */
