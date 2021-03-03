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
#if defined(MBEDTLS_HAVEGE_C) && defined(MBEDTLS_FS_IO)
#include "mbedtls/havege.h"
#include <stdio.h>
#include <time.h>
#endif
#if !defined(MBEDTLS_HAVEGE_C) || !defined(MBEDTLS_FS_IO)
#else
#endif /* MBEDTLS_HAVEGE_C */
