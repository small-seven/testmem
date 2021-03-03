#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_RSA_C)
#include "mbedtls/rsa.h"
#include "mbedtls/bignum.h"
#include "mbedtls/rsa_internal.h"
#if defined(MBEDTLS_GENPRIME)
#else
#endif /* MBEDTLS_GENPRIME */
#endif /* MBEDTLS_RSA_C */
