#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_PKCS12_C)
#include "mbedtls/pkcs12.h"
#include "mbedtls/asn1.h"
#include "mbedtls/cipher.h"
#include "mbedtls/platform_util.h"
#include <string.h>
#if defined(MBEDTLS_ARC4_C)
#include "mbedtls/arc4.h"
#endif
#if defined(MBEDTLS_DES_C)
#include "mbedtls/des.h"
#endif
#if defined(MBEDTLS_ASN1_PARSE_C)
#define PKCS12_MAX_PWDLEN 128
#undef PKCS12_MAX_PWDLEN
#if !defined(MBEDTLS_ARC4_C)
#else
#endif /* MBEDTLS_ARC4_C */
#endif /* MBEDTLS_ASN1_PARSE_C */
#endif /* MBEDTLS_PKCS12_C */
