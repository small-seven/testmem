#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_CMAC_C)
#include "mbedtls/cmac.h"
#include "mbedtls/platform_util.h"
#include <string.h>
#if defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#else
#include <stdlib.h>
#define mbedtls_calloc     calloc
#define mbedtls_free       free
#if defined(MBEDTLS_SELF_TEST)
#include <stdio.h>
#define mbedtls_printf     printf
#endif /* MBEDTLS_SELF_TEST */
#endif /* MBEDTLS_PLATFORM_C */
#if !defined(MBEDTLS_CMAC_ALT) || defined(MBEDTLS_SELF_TEST)
#if defined(_MSC_VER)
#pragma warning( push )
#pragma warning( disable : 4146 )
#endif
#if defined(_MSC_VER)
#pragma warning( pop )
#endif
#endif /* !defined(MBEDTLS_CMAC_ALT) || defined(MBEDTLS_SELF_TEST) */
#if !defined(MBEDTLS_CMAC_ALT)
#if defined(MBEDTLS_AES_C)
#endif /* MBEDTLS_AES_C */
#endif /* !MBEDTLS_CMAC_ALT */
#if defined(MBEDTLS_SELF_TEST)
#define NB_CMAC_TESTS_PER_KEY 4
#define NB_PRF_TESTS 3
#if defined(MBEDTLS_AES_C) || defined(MBEDTLS_DES_C)
#endif /* MBEDTLS_AES_C || MBEDTLS_DES_C */
#if defined(MBEDTLS_AES_C)
#endif /* MBEDTLS_AES_C */
#if defined(MBEDTLS_DES_C)
#endif /* MBEDTLS_DES_C */
#if defined(MBEDTLS_AES_C)
#endif /* MBEDTLS_AES_C */
#if defined(MBEDTLS_AES_C)
#endif /* MBEDTLS_AES_C */
#if defined(MBEDTLS_AES_C)
#endif /* MBEDTLS_AES_C */
#if defined(MBEDTLS_DES_C)
#endif /* MBEDTLS_DES_C */
#if defined(MBEDTLS_AES_C)
#endif /* MBEDTLS_AES_C */
#endif /* MBEDTLS_SELF_TEST */
#endif /* MBEDTLS_CMAC_C */
