#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_PKCS5_C)
#include "mbedtls/pkcs5.h"
#if defined(MBEDTLS_ASN1_PARSE_C)
#include "mbedtls/asn1.h"
#include "mbedtls/cipher.h"
#include "mbedtls/oid.h"
#endif /* MBEDTLS_ASN1_PARSE_C */
#include <string.h>
#if defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#else
#include <stdio.h>
#define mbedtls_printf printf
#endif
#if defined(MBEDTLS_ASN1_PARSE_C)
#endif /* MBEDTLS_ASN1_PARSE_C */
#if UINT_MAX > 0xFFFFFFFF
#endif
#if defined(MBEDTLS_SELF_TEST)
#if !defined(MBEDTLS_SHA1_C)
#else
#define MAX_TESTS   6
#endif /* MBEDTLS_SHA1_C */
#endif /* MBEDTLS_SELF_TEST */
#endif /* MBEDTLS_PKCS5_C */
