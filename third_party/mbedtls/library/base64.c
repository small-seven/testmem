#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_BASE64_C)
#include "mbedtls/base64.h"
#include <stdint.h>
#if defined(MBEDTLS_SELF_TEST)
#include <string.h>
#if defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#else
#include <stdio.h>
#define mbedtls_printf printf
#endif /* MBEDTLS_PLATFORM_C */
#endif /* MBEDTLS_SELF_TEST */
#define BASE64_SIZE_T_MAX   ( (size_t) -1 ) /* SIZE_T_MAX is not standard */
#if defined(MBEDTLS_SELF_TEST)
#endif /* MBEDTLS_SELF_TEST */
#endif /* MBEDTLS_BASE64_C */
