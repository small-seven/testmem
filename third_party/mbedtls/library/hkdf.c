#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_HKDF_C)
#include <string.h>
#include "mbedtls/hkdf.h"
#include "mbedtls/platform_util.h"
#endif /* MBEDTLS_HKDF_C */
