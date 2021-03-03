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
#define mbedtls_printf          printf
#define mbedtls_exit            exit
#define MBEDTLS_EXIT_SUCCESS    EXIT_SUCCESS
#define MBEDTLS_EXIT_FAILURE    EXIT_FAILURE
#endif /* MBEDTLS_PLATFORM_C */
#if defined(MBEDTLS_PK_WRITE_C) && defined(MBEDTLS_FS_IO) && \
#include "mbedtls/error.h"
#include "mbedtls/pk.h"
#include "mbedtls/ecdsa.h"
#include "mbedtls/rsa.h"
#include "mbedtls/error.h"
#include "mbedtls/entropy.h"
#include "mbedtls/ctr_drbg.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if !defined(_WIN32)
#include <unistd.h>
#define DEV_RANDOM_THRESHOLD        32
#endif /* !_WIN32 */
#endif
#if defined(MBEDTLS_ECP_C)
#define DFL_EC_CURVE            mbedtls_ecp_curve_list()->grp_id
#else
#define DFL_EC_CURVE            0
#endif
#if !defined(_WIN32) && defined(MBEDTLS_FS_IO)
#define USAGE_DEV_RANDOM \
#else
#define USAGE_DEV_RANDOM ""
#endif /* !_WIN32 && MBEDTLS_FS_IO */
#define FORMAT_PEM              0
#define FORMAT_DER              1
#define DFL_TYPE                MBEDTLS_PK_RSA
#define DFL_RSA_KEYSIZE         4096
#define DFL_FILENAME            "keyfile.key"
#define DFL_FORMAT              FORMAT_PEM
#define DFL_USE_DEV_RANDOM      0
#define USAGE \
#if !defined(MBEDTLS_PK_WRITE_C) || !defined(MBEDTLS_PEM_WRITE_C) || \
#else
#if defined(MBEDTLS_ECP_C)
#endif
#if defined(MBEDTLS_ECP_C)
#endif /* MBEDTLS_ECP_C */
#if defined(MBEDTLS_ECP_C)
#endif
#if !defined(_WIN32) && defined(MBEDTLS_FS_IO)
#endif /* !_WIN32 && MBEDTLS_FS_IO */
#if defined(MBEDTLS_RSA_C) && defined(MBEDTLS_GENPRIME)
#endif /* MBEDTLS_RSA_C */
#if defined(MBEDTLS_ECP_C)
#endif /* MBEDTLS_ECP_C */
#if defined(MBEDTLS_RSA_C)
#endif
#if defined(MBEDTLS_ECP_C)
#endif
#ifdef MBEDTLS_ERROR_C
#else
#endif
#if defined(_WIN32)
#endif
#endif /* MBEDTLS_PK_WRITE_C && MBEDTLS_PEM_WRITE_C && MBEDTLS_FS_IO &&
