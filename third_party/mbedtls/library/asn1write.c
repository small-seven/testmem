#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_ASN1_WRITE_C)
#include "mbedtls/asn1write.h"
#include <string.h>
#if defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#else
#include <stdlib.h>
#define mbedtls_calloc    calloc
#define mbedtls_free       free
#endif
#if SIZE_MAX > 0xFFFFFFFF
#endif
#if SIZE_MAX > 0xFFFFFFFF
#endif
#if defined(MBEDTLS_BIGNUM_C)
#endif /* MBEDTLS_BIGNUM_C */
#endif /* MBEDTLS_ASN1_WRITE_C */
