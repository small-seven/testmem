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
#define mbedtls_exit       exit
#define mbedtls_printf     printf
#define mbedtls_snprintf   snprintf
#define mbedtls_free       free
#define mbedtls_exit            exit
#define MBEDTLS_EXIT_SUCCESS    EXIT_SUCCESS
#define MBEDTLS_EXIT_FAILURE    EXIT_FAILURE
#endif
#if !defined(MBEDTLS_TIMING_C)
#else
#include <string.h>
#include <stdlib.h>
#include "mbedtls/timing.h"
#include "mbedtls/md4.h"
#include "mbedtls/md5.h"
#include "mbedtls/ripemd160.h"
#include "mbedtls/sha1.h"
#include "mbedtls/sha256.h"
#include "mbedtls/sha512.h"
#include "mbedtls/arc4.h"
#include "mbedtls/des.h"
#include "mbedtls/aes.h"
#include "mbedtls/aria.h"
#include "mbedtls/blowfish.h"
#include "mbedtls/camellia.h"
#include "mbedtls/chacha20.h"
#include "mbedtls/gcm.h"
#include "mbedtls/ccm.h"
#include "mbedtls/chachapoly.h"
#include "mbedtls/cmac.h"
#include "mbedtls/poly1305.h"
#include "mbedtls/havege.h"
#include "mbedtls/ctr_drbg.h"
#include "mbedtls/hmac_drbg.h"
#include "mbedtls/rsa.h"
#include "mbedtls/dhm.h"
#include "mbedtls/ecdsa.h"
#include "mbedtls/ecdh.h"
#include "mbedtls/error.h"
#if defined(MBEDTLS_MEMORY_BUFFER_ALLOC_C)
#include "mbedtls/memory_buffer_alloc.h"
#endif
#define MEM_BLOCK_OVERHEAD  ( 2 * sizeof( size_t ) )
#define HEAP_SIZE       (1u << 16)  // 64k
#define BUFSIZE         1024
#define HEADER_FORMAT   "  %-24s :  "
#define TITLE_LEN       25
#define OPTIONS                                                         \
#if defined(MBEDTLS_ERROR_C)
#define PRINT_ERROR                                                     \
#else
#define PRINT_ERROR                                                     \
#endif
#define TIME_AND_TSC( TITLE, CODE )                                     \
#if defined(MBEDTLS_MEMORY_BUFFER_ALLOC_C) && defined(MBEDTLS_MEMORY_DEBUG)
#define MEMORY_MEASURE_INIT                                             \
#define MEMORY_MEASURE_PRINT( title_len )                               \
#else
#define MEMORY_MEASURE_INIT
#define MEMORY_MEASURE_PRINT( title_len )
#endif
#define TIME_PUBLIC( TITLE, TYPE, CODE )                                \
#if defined(MBEDTLS_ECP_C)
#else
#define ecp_clear_precomputed( g )
#endif
typedef struct {
    char md4, md5, ripemd160, sha1, sha256, sha512,
         arc4, des3, des,
         aes_cbc, aes_gcm, aes_ccm, aes_xts, chachapoly,
         aes_cmac, des3_cmac,
         aria, camellia, blowfish, chacha20,
         poly1305,
         havege, ctr_drbg, hmac_drbg,
         rsa, dhm, ecdsa, ecdh;
} todo_list;
#if defined(MBEDTLS_MEMORY_BUFFER_ALLOC_C)
#endif
#if defined(MBEDTLS_MEMORY_BUFFER_ALLOC_C)
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
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#if defined(MBEDTLS_CMAC_C)
#endif /* MBEDTLS_CMAC_C */
#endif /* MBEDTLS_DES_C */
#if defined(MBEDTLS_AES_C)
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif
#if defined(MBEDTLS_CIPHER_MODE_XTS)
#endif
#if defined(MBEDTLS_GCM_C)
#endif
#if defined(MBEDTLS_CCM_C)
#endif
#if defined(MBEDTLS_CHACHAPOLY_C)
#endif
#if defined(MBEDTLS_CMAC_C)
#endif /* MBEDTLS_CMAC_C */
#endif /* MBEDTLS_AES_C */
#if defined(MBEDTLS_ARIA_C) && defined(MBEDTLS_CIPHER_MODE_CBC)
#endif
#if defined(MBEDTLS_CAMELLIA_C) && defined(MBEDTLS_CIPHER_MODE_CBC)
#endif
#if defined(MBEDTLS_CHACHA20_C)
#endif
#if defined(MBEDTLS_POLY1305_C)
#endif
#if defined(MBEDTLS_BLOWFISH_C) && defined(MBEDTLS_CIPHER_MODE_CBC)
#endif
#if defined(MBEDTLS_HAVEGE_C)
#endif
#if defined(MBEDTLS_CTR_DRBG_C)
#endif
#if defined(MBEDTLS_HMAC_DRBG_C)
#if defined(MBEDTLS_SHA1_C)
#endif
#if defined(MBEDTLS_SHA256_C)
#endif
#endif
#if defined(MBEDTLS_RSA_C) && defined(MBEDTLS_GENPRIME)
#endif
#if defined(MBEDTLS_DHM_C) && defined(MBEDTLS_BIGNUM_C)
#endif
#if defined(MBEDTLS_ECDSA_C) && defined(MBEDTLS_SHA256_C)
#endif
#if defined(MBEDTLS_ECDH_C) && defined(MBEDTLS_ECDH_LEGACY_CONTEXT)
#if defined(MBEDTLS_ECP_DP_CURVE25519_ENABLED)
#endif
#if defined(MBEDTLS_ECP_DP_CURVE448_ENABLED)
#endif
#endif
#if defined(MBEDTLS_MEMORY_BUFFER_ALLOC_C)
#endif
#if defined(_WIN32)
#endif
#endif /* MBEDTLS_TIMING_C */
