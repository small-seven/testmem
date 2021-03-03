#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#else
#include <stdlib.h>
#include <stdio.h>
#define mbedtls_printf       printf
#define mbedtls_exit         exit
#define MBEDTLS_EXIT_SUCCESS EXIT_SUCCESS
#define MBEDTLS_EXIT_FAILURE EXIT_FAILURE
#endif
#if defined(MBEDTLS_MD5_C)
#include "mbedtls/md5.h"
#endif
#if !defined(MBEDTLS_MD5_C)
#else
#if defined(_WIN32)
#endif
#endif /* MBEDTLS_MD5_C */
