#define USE_crypto           0x01    /* OpenSSL's libcrypto */
#define USE_gcrypt           0x02    /* GnuTLS's libgcrypt */
#define USE_tomcrypt         0x04    /* LibTomCrypt */
#define USE_mbedcrypto       0x08    /* mbed TLS */
#include <stdlib.h>
#include <math.h>
#include "libavutil/avutil.h"
#include "libavutil/avstring.h"
#include "libavutil/crc.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/timer.h"
#ifndef AV_READ_TIME
#define AV_READ_TIME(x) 0
#endif
#if HAVE_UNISTD_H
#include <unistd.h> /* for getopt */
#endif
#if !HAVE_GETOPT
#include "compat/getopt.c"
#endif
#define MAX_INPUT_SIZE 1048576
#define MAX_OUTPUT_SIZE 128
#include "libavutil/md5.h"
#include "libavutil/sha.h"
#include "libavutil/sha512.h"
#include "libavutil/ripemd.h"
#include "libavutil/aes.h"
#include "libavutil/blowfish.h"
#include "libavutil/camellia.h"
#include "libavutil/cast5.h"
#include "libavutil/des.h"
#include "libavutil/twofish.h"
#include "libavutil/rc4.h"
#include "libavutil/xtea.h"
#define IMPL_USE_lavu IMPL_USE
#define DEFINE_LAVU_MD(suffix, type, namespace, hsize)                       \
#if (USE_EXT_LIBS) & USE_crypto
#define OPENSSL_DISABLE_OLD_DES_SUPPORT
#include <openssl/md5.h>
#include <openssl/sha.h>
#include <openssl/ripemd.h>
#include <openssl/aes.h>
#include <openssl/blowfish.h>
#include <openssl/camellia.h>
#include <openssl/cast.h>
#include <openssl/des.h>
#include <openssl/rc4.h>
#define DEFINE_CRYPTO_WRAPPER(suffix, function)                              \
#define IMPL_USE_crypto(...) IMPL_USE(__VA_ARGS__)
#else
#define IMPL_USE_crypto(...) /* ignore */
#endif
#if (USE_EXT_LIBS) & USE_gcrypt
#include <gcrypt.h>
#define DEFINE_GCRYPT_WRAPPER(suffix, algo)                                  \
#define DEFINE_GCRYPT_CYPHER_WRAPPER(suffix, cypher, mode, sz)                      \
#define IMPL_USE_gcrypt(...) IMPL_USE(__VA_ARGS__)
#else
#define IMPL_USE_gcrypt(...) /* ignore */
#endif
#if (USE_EXT_LIBS) & USE_mbedcrypto
#include <mbedtls/aes.h>
#include <mbedtls/arc4.h>
#include <mbedtls/blowfish.h>
#include <mbedtls/camellia.h>
#include <mbedtls/des.h>
#include <mbedtls/md5.h>
#include <mbedtls/ripemd160.h>
#include <mbedtls/sha1.h>
#include <mbedtls/sha256.h>
#include <mbedtls/sha512.h>
#include <mbedtls/xtea.h>
#define DEFINE_MBEDCRYPTO_WRAPPER(suffix)                                  \
#define DEFINE_MBEDCRYPTO_WRAPPER_SHA2(suffix)                             \
#define DEFINE_MBEDCRYPTO_CYPHER_WRAPPER(suffix, cypher, algo)                  \
#define IMPL_USE_mbedcrypto(...) IMPL_USE(__VA_ARGS__)
#else
#define IMPL_USE_mbedcrypto(...) /* ignore */
#endif
#if (USE_EXT_LIBS) & USE_tomcrypt
#include <tomcrypt.h>
#define DEFINE_TOMCRYPT_WRAPPER(suffix, namespace, algo)                     \
#define IMPL_USE_tomcrypt(...) IMPL_USE(__VA_ARGS__)
#else
#define IMPL_USE_tomcrypt(...) /* ignore */
#endif
#define IMPL_USE(lib, name, symbol, output) \
#define IMPL(lib, ...) IMPL_USE_ ## lib(lib, __VA_ARGS__)
#define IMPL_ALL(...) \
