#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_PK_WRITE_C)
#include "mbedtls/pk.h"
#include "mbedtls/asn1write.h"
#include "mbedtls/oid.h"
#include "mbedtls/platform_util.h"
#include <string.h>
#if defined(MBEDTLS_RSA_C)
#include "mbedtls/rsa.h"
#endif
#if defined(MBEDTLS_ECP_C)
#include "mbedtls/bignum.h"
#include "mbedtls/ecp.h"
#include "mbedtls/platform_util.h"
#endif
#if defined(MBEDTLS_ECDSA_C)
#include "mbedtls/ecdsa.h"
#endif
#if defined(MBEDTLS_PEM_WRITE_C)
#include "mbedtls/pem.h"
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
#if defined(MBEDTLS_RSA_C)
#endif /* MBEDTLS_RSA_C */
#if defined(MBEDTLS_ECP_C)
#endif /* MBEDTLS_ECP_C */
#if defined(MBEDTLS_RSA_C)
#endif
#if defined(MBEDTLS_ECP_C)
#endif
#if defined(MBEDTLS_ECP_C)
#endif
#if defined(MBEDTLS_RSA_C)
#endif /* MBEDTLS_RSA_C */
#if defined(MBEDTLS_ECP_C)
#endif /* MBEDTLS_ECP_C */
#if defined(MBEDTLS_PEM_WRITE_C)
#define PEM_BEGIN_PUBLIC_KEY    "-----BEGIN PUBLIC KEY-----\n"
#define PEM_END_PUBLIC_KEY      "-----END PUBLIC KEY-----\n"
#define PEM_BEGIN_PRIVATE_KEY_RSA   "-----BEGIN RSA PRIVATE KEY-----\n"
#define PEM_END_PRIVATE_KEY_RSA     "-----END RSA PRIVATE KEY-----\n"
#define PEM_BEGIN_PRIVATE_KEY_EC    "-----BEGIN EC PRIVATE KEY-----\n"
#define PEM_END_PRIVATE_KEY_EC      "-----END EC PRIVATE KEY-----\n"
#if defined(MBEDTLS_RSA_C)
#define RSA_PUB_DER_MAX_BYTES   38 + 2 * MBEDTLS_MPI_MAX_SIZE
#define MPI_MAX_SIZE_2          MBEDTLS_MPI_MAX_SIZE / 2 + \
#define RSA_PRV_DER_MAX_BYTES   47 + 3 * MBEDTLS_MPI_MAX_SIZE \
#else /* MBEDTLS_RSA_C */
#define RSA_PUB_DER_MAX_BYTES   0
#define RSA_PRV_DER_MAX_BYTES   0
#endif /* MBEDTLS_RSA_C */
#if defined(MBEDTLS_ECP_C)
#define ECP_PUB_DER_MAX_BYTES   30 + 2 * MBEDTLS_ECP_MAX_BYTES
#define ECP_PRV_DER_MAX_BYTES   29 + 3 * MBEDTLS_ECP_MAX_BYTES
#else /* MBEDTLS_ECP_C */
#define ECP_PUB_DER_MAX_BYTES   0
#define ECP_PRV_DER_MAX_BYTES   0
#endif /* MBEDTLS_ECP_C */
#define PUB_DER_MAX_BYTES   RSA_PUB_DER_MAX_BYTES > ECP_PUB_DER_MAX_BYTES ? \
#define PRV_DER_MAX_BYTES   RSA_PRV_DER_MAX_BYTES > ECP_PRV_DER_MAX_BYTES ? \
#if defined(MBEDTLS_RSA_C)
#endif
#if defined(MBEDTLS_ECP_C)
#endif
#endif /* MBEDTLS_PEM_WRITE_C */
#endif /* MBEDTLS_PK_WRITE_C */
