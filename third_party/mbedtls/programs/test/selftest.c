#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#include "mbedtls/entropy.h"
#include "mbedtls/entropy_poll.h"
#include "mbedtls/hmac_drbg.h"
#include "mbedtls/ctr_drbg.h"
#include "mbedtls/dhm.h"
#include "mbedtls/gcm.h"
#include "mbedtls/ccm.h"
#include "mbedtls/cmac.h"
#include "mbedtls/md2.h"
#include "mbedtls/md4.h"
#include "mbedtls/md5.h"
#include "mbedtls/ripemd160.h"
#include "mbedtls/sha1.h"
#include "mbedtls/sha256.h"
#include "mbedtls/sha512.h"
#include "mbedtls/arc4.h"
#include "mbedtls/des.h"
#include "mbedtls/aes.h"
#include "mbedtls/camellia.h"
#include "mbedtls/aria.h"
#include "mbedtls/chacha20.h"
#include "mbedtls/poly1305.h"
#include "mbedtls/chachapoly.h"
#include "mbedtls/base64.h"
#include "mbedtls/bignum.h"
#include "mbedtls/rsa.h"
#include "mbedtls/x509.h"
#include "mbedtls/xtea.h"
#include "mbedtls/pkcs5.h"
#include "mbedtls/ecp.h"
#include "mbedtls/ecjpake.h"
#include "mbedtls/timing.h"
#include "mbedtls/nist_kw.h"
#include <string.h>
#if defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#else
#include <stdio.h>
#include <stdlib.h>
#define mbedtls_calloc     calloc
#define mbedtls_free       free
#define mbedtls_printf     printf
#define mbedtls_snprintf   snprintf
#define mbedtls_exit       exit
#define MBEDTLS_EXIT_SUCCESS EXIT_SUCCESS
#define MBEDTLS_EXIT_FAILURE EXIT_FAILURE
#endif
#if defined(MBEDTLS_MEMORY_BUFFER_ALLOC_C)
#include "mbedtls/memory_buffer_alloc.h"
#endif
#if defined MBEDTLS_SELF_TEST
#endif /* MBEDTLS_SELF_TEST */
#if defined(MBEDTLS_SELF_TEST) && defined(MBEDTLS_ENTROPY_C)
#if defined(MBEDTLS_ENTROPY_NV_SEED) && !defined(MBEDTLS_NO_PLATFORM_ENTROPY)
#endif
#if defined(MBEDTLS_ENTROPY_NV_SEED) && !defined(MBEDTLS_NO_PLATFORM_ENTROPY)
#endif
#endif
#if defined(MBEDTLS_SELF_TEST)
#if defined(MBEDTLS_MEMORY_BUFFER_ALLOC_C)
#if defined(MBEDTLS_MEMORY_DEBUG)
#endif
#endif
typedef struct
{
    const char *name;
    int ( *function )( int );
} selftest_t;
#if defined(MBEDTLS_MD2_C)
#endif
#if defined(MBEDTLS_MD4_C)
#endif
#if defined(MBEDTLS_MD5_C)
#endif
#if defined(MBEDTLS_RIPEMD160_C)
#endif
#if defined(MBEDTLS_SHA1_C)
#endif
#if defined(MBEDTLS_SHA256_C)
#endif
#if defined(MBEDTLS_SHA512_C)
#endif
#if defined(MBEDTLS_ARC4_C)
#endif
#if defined(MBEDTLS_DES_C)
#endif
#if defined(MBEDTLS_AES_C)
#endif
#if defined(MBEDTLS_GCM_C) && defined(MBEDTLS_AES_C)
#endif
#if defined(MBEDTLS_CCM_C) && defined(MBEDTLS_AES_C)
#endif
#if defined(MBEDTLS_NIST_KW_C) && defined(MBEDTLS_AES_C)
#endif
#if defined(MBEDTLS_CMAC_C)
#endif
#if defined(MBEDTLS_CHACHA20_C)
#endif
#if defined(MBEDTLS_POLY1305_C)
#endif
#if defined(MBEDTLS_CHACHAPOLY_C)
#endif
#if defined(MBEDTLS_BASE64_C)
#endif
#if defined(MBEDTLS_BIGNUM_C)
#endif
#if defined(MBEDTLS_RSA_C)
#endif
#if defined(MBEDTLS_X509_USE_C)
#endif
#if defined(MBEDTLS_XTEA_C)
#endif
#if defined(MBEDTLS_CAMELLIA_C)
#endif
#if defined(MBEDTLS_ARIA_C)
#endif
#if defined(MBEDTLS_CTR_DRBG_C)
#endif
#if defined(MBEDTLS_HMAC_DRBG_C)
#endif
#if defined(MBEDTLS_ECP_C)
#endif
#if defined(MBEDTLS_ECJPAKE_C)
#endif
#if defined(MBEDTLS_DHM_C)
#endif
#if defined(MBEDTLS_ENTROPY_C)
#endif
#if defined(MBEDTLS_PKCS5_C)
#endif
#if defined(MBEDTLS_TIMING_C)
#endif
#if defined(MBEDTLS_MEMORY_BUFFER_ALLOC_C)
#endif
#endif /* MBEDTLS_SELF_TEST */
#if defined(MBEDTLS_SELF_TEST)
#endif /* MBEDTLS_SELF_TEST */
#if defined(MBEDTLS_MEMORY_BUFFER_ALLOC_C) && defined(MBEDTLS_SELF_TEST)
#endif
#if defined(MBEDTLS_SELF_TEST)
#if defined(MBEDTLS_MEMORY_BUFFER_ALLOC_C)
#endif
#else
#endif
#if defined(_WIN32)
#endif
