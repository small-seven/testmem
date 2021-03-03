#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_PK_PARSE_C)
#include "mbedtls/pk.h"
#include "mbedtls/asn1.h"
#include "mbedtls/oid.h"
#include "mbedtls/platform_util.h"
#include <string.h>
#if defined(MBEDTLS_RSA_C)
#include "mbedtls/rsa.h"
#endif
#if defined(MBEDTLS_ECP_C)
#include "mbedtls/ecp.h"
#endif
#if defined(MBEDTLS_ECDSA_C)
#include "mbedtls/ecdsa.h"
#endif
#if defined(MBEDTLS_PEM_PARSE_C)
#include "mbedtls/pem.h"
#endif
#if defined(MBEDTLS_PKCS5_C)
#include "mbedtls/pkcs5.h"
#endif
#if defined(MBEDTLS_PKCS12_C)
#include "mbedtls/pkcs12.h"
#endif
#if defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#else
#include <stdlib.h>
#define mbedtls_calloc    calloc
#define mbedtls_free       free
#endif
#define PK_VALIDATE_RET( cond )    \
#define PK_VALIDATE( cond )        \
#if defined(MBEDTLS_FS_IO)
#endif /* MBEDTLS_FS_IO */
#if defined(MBEDTLS_ECP_C)
#if defined(MBEDTLS_PK_PARSE_EC_EXTENDED)
#endif
#if defined(MBEDTLS_PK_PARSE_EC_EXTENDED)
#endif /* MBEDTLS_PK_PARSE_EC_EXTENDED */
#if defined(MBEDTLS_PK_PARSE_EC_EXTENDED)
#else
#endif
#endif /* MBEDTLS_ECP_C */
#if defined(MBEDTLS_RSA_C)
#endif /* MBEDTLS_RSA_C */
#if defined(MBEDTLS_RSA_C)
#endif /* MBEDTLS_RSA_C */
#if defined(MBEDTLS_ECP_C)
#endif /* MBEDTLS_ECP_C */
#if defined(MBEDTLS_RSA_C)
#if !defined(MBEDTLS_RSA_NO_CRT) && !defined(MBEDTLS_RSA_ALT)
#else
#endif
#endif /* MBEDTLS_RSA_C */
#if defined(MBEDTLS_ECP_C)
#endif /* MBEDTLS_ECP_C */
#if defined(MBEDTLS_RSA_C)
#endif /* MBEDTLS_RSA_C */
#if defined(MBEDTLS_ECP_C)
#endif /* MBEDTLS_ECP_C */
#if defined(MBEDTLS_PKCS12_C) || defined(MBEDTLS_PKCS5_C)
#if defined(MBEDTLS_PKCS12_C)
#endif
#if defined(MBEDTLS_PKCS12_C)
#endif /* MBEDTLS_PKCS12_C */
#if defined(MBEDTLS_PKCS5_C)
#endif /* MBEDTLS_PKCS5_C */
#endif /* MBEDTLS_PKCS12_C || MBEDTLS_PKCS5_C */
#if defined(MBEDTLS_PEM_PARSE_C)
#endif
#if defined(MBEDTLS_PEM_PARSE_C)
#if defined(MBEDTLS_RSA_C)
#endif /* MBEDTLS_RSA_C */
#if defined(MBEDTLS_ECP_C)
#endif /* MBEDTLS_ECP_C */
#if defined(MBEDTLS_PKCS12_C) || defined(MBEDTLS_PKCS5_C)
#endif /* MBEDTLS_PKCS12_C || MBEDTLS_PKCS5_C */
#else
#endif /* MBEDTLS_PEM_PARSE_C */
#if defined(MBEDTLS_PKCS12_C) || defined(MBEDTLS_PKCS5_C)
#endif /* MBEDTLS_PKCS12_C || MBEDTLS_PKCS5_C */
#if defined(MBEDTLS_RSA_C)
#endif /* MBEDTLS_RSA_C */
#if defined(MBEDTLS_ECP_C)
#endif /* MBEDTLS_ECP_C */
#if defined(MBEDTLS_RSA_C)
#endif
#if defined(MBEDTLS_PEM_PARSE_C)
#endif
#if defined(MBEDTLS_PEM_PARSE_C)
#if defined(MBEDTLS_RSA_C)
#endif /* MBEDTLS_RSA_C */
#endif /* MBEDTLS_PEM_PARSE_C */
#if defined(MBEDTLS_RSA_C)
#endif /* MBEDTLS_RSA_C */
#endif /* MBEDTLS_PK_PARSE_C */
