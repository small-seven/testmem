#include <stdio.h>
#include <string.h>
#include <openssl/opensslconf.h>
#include <openssl/crypto.h>
#include <openssl/engine.h>
#include <openssl/evp.h>
#include <openssl/aes.h>
#include <openssl/rand.h>
#include <openssl/err.h>
#include <openssl/modes.h>
#ifndef OPENSSL_NO_HW
# ifndef OPENSSL_NO_HW_PADLOCK
#  if (OPENSSL_VERSION_NUMBER >= 0x00908000L)
#   ifndef OPENSSL_NO_DYNAMIC_ENGINE
#    define DYNAMIC_ENGINE
#   endif
#  elif (OPENSSL_VERSION_NUMBER >= 0x00907000L)
#   ifdef ENGINE_DYNAMIC_SUPPORT
#    define DYNAMIC_ENGINE
#   endif
#  else
#   error "Only OpenSSL >= 0.9.7 is supported"
#  endif
#  undef COMPILE_HW_PADLOCK
#  if defined(PADLOCK_ASM)
#   define COMPILE_HW_PADLOCK
#   ifdef OPENSSL_NO_DYNAMIC_ENGINE
#   endif
#  endif
#  ifdef OPENSSL_NO_DYNAMIC_ENGINE
#   ifdef COMPILE_HW_PADLOCK
#   endif
#  endif
#  ifdef COMPILE_HW_PADLOCK
#   ifdef OPENSSL_NO_DYNAMIC_ENGINE
#   endif
#   ifndef OPENSSL_NO_DYNAMIC_ENGINE
#   endif                       /* !OPENSSL_NO_DYNAMIC_ENGINE */
#   define AES_BLOCK_SIZE          16
#   define AES_KEY_SIZE_128        16
#   define AES_KEY_SIZE_192        24
#   define AES_KEY_SIZE_256        32
#   if defined(NID_aes_128_cfb128) && ! defined (NID_aes_128_cfb)
#    define NID_aes_128_cfb NID_aes_128_cfb128
#   endif
#   if defined(NID_aes_128_ofb128) && ! defined (NID_aes_128_ofb)
#    define NID_aes_128_ofb NID_aes_128_ofb128
#   endif
#   if defined(NID_aes_192_cfb128) && ! defined (NID_aes_192_cfb)
#    define NID_aes_192_cfb NID_aes_192_cfb128
#   endif
#   if defined(NID_aes_192_ofb128) && ! defined (NID_aes_192_ofb)
#    define NID_aes_192_ofb NID_aes_192_ofb128
#   endif
#   if defined(NID_aes_256_cfb128) && ! defined (NID_aes_256_cfb)
#    define NID_aes_256_cfb NID_aes_256_cfb128
#   endif
#   if defined(NID_aes_256_ofb128) && ! defined (NID_aes_256_ofb)
#    define NID_aes_256_ofb NID_aes_256_ofb128
#   endif
#   define NEAREST_ALIGNED(ptr) ( (unsigned char *)(ptr) +         \
#   define ALIGNED_CIPHER_DATA(ctx) ((struct padlock_cipher_data *)\
#   define EVP_CIPHER_block_size_ECB       AES_BLOCK_SIZE
#   define EVP_CIPHER_block_size_CBC       AES_BLOCK_SIZE
#   define EVP_CIPHER_block_size_OFB       1
#   define EVP_CIPHER_block_size_CFB       1
#   define EVP_CIPHER_block_size_CTR       1
#   define DECLARE_AES_EVP(ksize,lmode,umode)      \
#   ifndef AES_ASM
#   endif
#  endif                        /* COMPILE_HW_PADLOCK */
# endif                         /* !OPENSSL_NO_HW_PADLOCK */
#endif                          /* !OPENSSL_NO_HW */
#if defined(OPENSSL_NO_HW) || defined(OPENSSL_NO_HW_PADLOCK) \
# ifndef OPENSSL_NO_DYNAMIC_ENGINE
# endif
#endif
