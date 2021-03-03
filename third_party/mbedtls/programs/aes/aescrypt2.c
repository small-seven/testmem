#define _POSIX_C_SOURCE 1
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
#define mbedtls_fprintf         fprintf
#define mbedtls_printf          printf
#define mbedtls_exit            exit
#define MBEDTLS_EXIT_SUCCESS    EXIT_SUCCESS
#define MBEDTLS_EXIT_FAILURE    EXIT_FAILURE
#endif /* MBEDTLS_PLATFORM_C */
#include "mbedtls/aes.h"
#include "mbedtls/md.h"
#include "mbedtls/platform_util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if defined(_WIN32)
#include <windows.h>
#if !defined(_WIN32_WCE)
#include <io.h>
#endif
#else
#include <sys/types.h>
#include <unistd.h>
#endif
#define MODE_ENCRYPT    0
#define MODE_DECRYPT    1
#define USAGE   \
#if !defined(MBEDTLS_AES_C) || !defined(MBEDTLS_SHA256_C) || \
#else
#if defined(_WIN32_WCE)
#elif defined(_WIN32)
#else
#endif
#if defined(_WIN32)
#endif
#if defined(_WIN32_WCE)
#else
#if defined(_WIN32)
#else
#endif
#endif
#endif /* MBEDTLS_AES_C && MBEDTLS_SHA256_C && MBEDTLS_FS_IO */
