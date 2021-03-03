#include <openssl/opensslconf.h>
#include <openssl/crypto.h>
#include <openssl/evp.h>
#include <openssl/err.h>
#include <string.h>
#include <assert.h>
#include <openssl/aes.h>
#include "crypto/evp.h"
#include "modes_local.h"
#include <openssl/rand.h>
#include "evp_local.h"
typedef struct {
    union {
        double align;
        AES_KEY ks;
    } ks;
typedef struct {
    union {
        double align;
        AES_KEY ks;
    } ks;                       /* AES key schedule to use */
typedef struct {
    union {
        double align;
        AES_KEY ks;
    } ks1, ks2;                 /* AES key schedules to use */
typedef struct {
    union {
        double align;
        AES_KEY ks;
    } ks;                       /* AES key schedule to use */
#ifndef OPENSSL_NO_OCB
typedef struct {
    union {
        double align;
        AES_KEY ks;
    } ksenc;                    /* AES key schedule to use for encryption */
#endif
#define MAXBITCHUNK     ((size_t)1<<(sizeof(size_t)*8-4))
#ifdef VPAES_ASM
#endif
#ifdef BSAES_ASM
#endif
#ifdef AES_CTR_ASM
#endif
#ifdef AES_XTS_ASM
#endif
#if defined(OPENSSL_CPUID_OBJ) && (defined(__powerpc__) || defined(__ppc__) || defined(_ARCH_PPC))
# include "ppc_arch.h"
# ifdef VPAES_ASM
#  define VPAES_CAPABLE (OPENSSL_ppccap_P & PPC_ALTIVEC)
# endif
# define HWAES_CAPABLE  (OPENSSL_ppccap_P & PPC_CRYPTO207)
# define HWAES_set_encrypt_key aes_p8_set_encrypt_key
# define HWAES_set_decrypt_key aes_p8_set_decrypt_key
# define HWAES_encrypt aes_p8_encrypt
# define HWAES_decrypt aes_p8_decrypt
# define HWAES_cbc_encrypt aes_p8_cbc_encrypt
# define HWAES_ctr32_encrypt_blocks aes_p8_ctr32_encrypt_blocks
# define HWAES_xts_encrypt aes_p8_xts_encrypt
# define HWAES_xts_decrypt aes_p8_xts_decrypt
#endif
#if     defined(OPENSSL_CPUID_OBJ) &&                   (  \
# ifdef VPAES_ASM
#  define VPAES_CAPABLE   (OPENSSL_ia32cap_P[1]&(1<<(41-32)))
# endif
# ifdef BSAES_ASM
#  define BSAES_CAPABLE   (OPENSSL_ia32cap_P[1]&(1<<(41-32)))
# endif
# define AESNI_CAPABLE   (OPENSSL_ia32cap_P[1]&(1<<(57-32)))
# if defined(__x86_64) || defined(__x86_64__) || defined(_M_AMD64) || defined(_M_X64)
#  define AES_gcm_encrypt aesni_gcm_encrypt
#  define AES_gcm_decrypt aesni_gcm_decrypt
#  define AES_GCM_ASM(gctx)       (gctx->ctr==aesni_ctr32_encrypt_blocks && \
#  define AES_GCM_ASM2(gctx)      (gctx->gcm.block==(block128_f)aesni_encrypt && \
#  undef AES_GCM_ASM2          /* minor size optimization */
# endif
# define aesni_ofb_cipher aes_ofb_cipher
# define aesni_cfb_cipher aes_cfb_cipher
# define aesni_cfb8_cipher aes_cfb8_cipher
# define aesni_cfb1_cipher aes_cfb1_cipher
# define aesni_ctr_cipher aes_ctr_cipher
# define aesni_gcm_cipher aes_gcm_cipher
# define aesni_xts_cipher aes_xts_cipher
# define aesni_ccm_cipher aes_ccm_cipher
# ifndef OPENSSL_NO_OCB
#  define aesni_ocb_cipher aes_ocb_cipher
# endif                        /* OPENSSL_NO_OCB */
# define BLOCK_CIPHER_generic(nid,keylen,blocksize,ivlen,nmode,mode,MODE,flags) \
# define BLOCK_CIPHER_custom(nid,keylen,blocksize,ivlen,mode,MODE,flags) \
#elif   defined(AES_ASM) && (defined(__sparc) || defined(__sparc__))
# include "sparc_arch.h"
# define HWAES_CAPABLE           (OPENSSL_sparcv9cap_P[0] & SPARCV9_FJAESX)
# define HWAES_set_encrypt_key aes_fx_set_encrypt_key
# define HWAES_set_decrypt_key aes_fx_set_decrypt_key
# define HWAES_encrypt aes_fx_encrypt
# define HWAES_decrypt aes_fx_decrypt
# define HWAES_cbc_encrypt aes_fx_cbc_encrypt
# define HWAES_ctr32_encrypt_blocks aes_fx_ctr32_encrypt_blocks
# define SPARC_AES_CAPABLE       (OPENSSL_sparcv9cap_P[1] & CFR_AES)
# define aes_t4_cbc_cipher aes_cbc_cipher
# define aes_t4_ecb_cipher aes_ecb_cipher
# define aes_t4_ofb_cipher aes_ofb_cipher
# define aes_t4_cfb_cipher aes_cfb_cipher
# define aes_t4_cfb8_cipher aes_cfb8_cipher
# define aes_t4_cfb1_cipher aes_cfb1_cipher
# define aes_t4_ctr_cipher aes_ctr_cipher
# define aes_t4_gcm_cipher aes_gcm_cipher
# define aes_t4_xts_cipher aes_xts_cipher
# define aes_t4_ccm_cipher aes_ccm_cipher
# ifndef OPENSSL_NO_OCB
#  define aes_t4_ocb_cipher aes_ocb_cipher
# endif                        /* OPENSSL_NO_OCB */
# define BLOCK_CIPHER_generic(nid,keylen,blocksize,ivlen,nmode,mode,MODE,flags) \
# define BLOCK_CIPHER_custom(nid,keylen,blocksize,ivlen,mode,MODE,flags) \
#elif defined(OPENSSL_CPUID_OBJ) && defined(__s390__)
# include "s390x_arch.h"
typedef struct {
    union {
        double align;
        /*-
         * KM-AES parameter block - begin
         * (see z/Architecture Principles of Operation >= SA22-7832-06)
         */
        struct {
            unsigned char k[32];
        } param;
typedef struct {
    union {
        double align;
        /*-
         * KMO-AES parameter block - begin
         * (see z/Architecture Principles of Operation >= SA22-7832-08)
         */
        struct {
            unsigned char cv[16];
            unsigned char k[32];
        } param;
typedef struct {
    union {
        double align;
        /*-
         * KMF-AES parameter block - begin
         * (see z/Architecture Principles of Operation >= SA22-7832-08)
         */
        struct {
            unsigned char cv[16];
            unsigned char k[32];
        } param;
typedef struct {
    union {
        double align;
        /*-
         * KMA-GCM-AES parameter block - begin
         * (see z/Architecture Principles of Operation >= SA22-7832-11)
         */
        struct {
            unsigned char reserved[12];
            union {
                unsigned int w;
                unsigned char b[4];
            } cv;
typedef struct {
    union {
        double align;
        /*-
         * Padding is chosen so that ccm.kmac_param.k overlaps with key.k and
         * ccm.fc with key.k.rounds. Remember that on s390x, an AES_KEY's
         * rounds field is used to store the function code and that the key
         * schedule is not stored (if aes hardware support is detected).
         */
        struct {
            unsigned char pad[16];
            AES_KEY k;
        } key;
# define S390X_AES_FC(keylen)  (S390X_AES_128 + ((((keylen) << 3) - 128) >> 6))
# define S390X_aes_128_CAPABLE (OPENSSL_s390xcap_P.km[0] &	\
# define S390X_aes_192_CAPABLE (OPENSSL_s390xcap_P.km[0] &	\
# define S390X_aes_256_CAPABLE (OPENSSL_s390xcap_P.km[0] &	\
# define s390x_aes_init_key aes_init_key
# define S390X_aes_128_cbc_CAPABLE	1	/* checked by callee */
# define S390X_aes_192_cbc_CAPABLE	1
# define S390X_aes_256_cbc_CAPABLE	1
# define S390X_AES_CBC_CTX		EVP_AES_KEY
# define s390x_aes_cbc_init_key aes_init_key
# define s390x_aes_cbc_cipher aes_cbc_cipher
# define S390X_aes_128_ecb_CAPABLE	S390X_aes_128_CAPABLE
# define S390X_aes_192_ecb_CAPABLE	S390X_aes_192_CAPABLE
# define S390X_aes_256_ecb_CAPABLE	S390X_aes_256_CAPABLE
# define S390X_aes_128_ofb_CAPABLE (S390X_aes_128_CAPABLE &&		\
# define S390X_aes_192_ofb_CAPABLE (S390X_aes_192_CAPABLE &&		\
# define S390X_aes_256_ofb_CAPABLE (S390X_aes_256_CAPABLE &&		\
# define S390X_aes_128_cfb_CAPABLE (S390X_aes_128_CAPABLE &&		\
# define S390X_aes_192_cfb_CAPABLE (S390X_aes_192_CAPABLE &&		\
# define S390X_aes_256_cfb_CAPABLE (S390X_aes_256_CAPABLE &&		\
# define S390X_aes_128_cfb8_CAPABLE (OPENSSL_s390xcap_P.kmf[0] &	\
# define S390X_aes_192_cfb8_CAPABLE (OPENSSL_s390xcap_P.kmf[0] &	\
# define S390X_aes_256_cfb8_CAPABLE (OPENSSL_s390xcap_P.kmf[0] &	\
# define S390X_aes_128_cfb1_CAPABLE	0
# define S390X_aes_192_cfb1_CAPABLE	0
# define S390X_aes_256_cfb1_CAPABLE	0
# define s390x_aes_cfb1_init_key aes_init_key
# define s390x_aes_cfb1_cipher aes_cfb1_cipher
# define S390X_aes_128_ctr_CAPABLE	1	/* checked by callee */
# define S390X_aes_192_ctr_CAPABLE	1
# define S390X_aes_256_ctr_CAPABLE	1
# define S390X_AES_CTR_CTX		EVP_AES_KEY
# define s390x_aes_ctr_init_key aes_init_key
# define s390x_aes_ctr_cipher aes_ctr_cipher
# define S390X_aes_128_gcm_CAPABLE (S390X_aes_128_CAPABLE &&		\
# define S390X_aes_192_gcm_CAPABLE (S390X_aes_192_CAPABLE &&		\
# define S390X_aes_256_gcm_CAPABLE (S390X_aes_256_CAPABLE &&		\
# define S390X_gcm_ivpadlen(i)	((((i) + 15) >> 4 << 4) + 16)
# define S390X_AES_XTS_CTX		EVP_AES_XTS_CTX
# define S390X_aes_128_xts_CAPABLE	1	/* checked by callee */
# define S390X_aes_256_xts_CAPABLE	1
# define s390x_aes_xts_init_key aes_xts_init_key
# define s390x_aes_xts_cipher aes_xts_cipher
# define s390x_aes_xts_ctrl aes_xts_ctrl
# define s390x_aes_xts_cleanup aes_xts_cleanup
# define S390X_aes_128_ccm_CAPABLE (S390X_aes_128_CAPABLE &&		\
# define S390X_aes_192_ccm_CAPABLE (S390X_aes_192_CAPABLE &&		\
# define S390X_aes_256_ccm_CAPABLE (S390X_aes_256_CAPABLE &&		\
# define S390X_CCM_AAD_FLAG	0x40
# define s390x_aes_ccm_cleanup aes_ccm_cleanup
# ifndef OPENSSL_NO_OCB
#  define S390X_AES_OCB_CTX		EVP_AES_OCB_CTX
#  define S390X_aes_128_ocb_CAPABLE	0
#  define S390X_aes_192_ocb_CAPABLE	0
#  define S390X_aes_256_ocb_CAPABLE	0
#  define s390x_aes_ocb_init_key aes_ocb_init_key
#  define s390x_aes_ocb_cipher aes_ocb_cipher
#  define s390x_aes_ocb_cleanup aes_ocb_cleanup
#  define s390x_aes_ocb_ctrl aes_ocb_ctrl
# endif
# define BLOCK_CIPHER_generic(nid,keylen,blocksize,ivlen,nmode,mode,	\
# define BLOCK_CIPHER_custom(nid,keylen,blocksize,ivlen,mode,MODE,flags)\
#else
# define BLOCK_CIPHER_generic(nid,keylen,blocksize,ivlen,nmode,mode,MODE,flags) \
# define BLOCK_CIPHER_custom(nid,keylen,blocksize,ivlen,mode,MODE,flags) \
#endif
#if defined(OPENSSL_CPUID_OBJ) && (defined(__arm__) || defined(__arm) || defined(__aarch64__))
# include "arm_arch.h"
# if __ARM_MAX_ARCH__>=7
#  if defined(BSAES_ASM)
#   define BSAES_CAPABLE (OPENSSL_armcap_P & ARMV7_NEON)
#  endif
#  if defined(VPAES_ASM)
#   define VPAES_CAPABLE (OPENSSL_armcap_P & ARMV7_NEON)
#  endif
#  define HWAES_CAPABLE (OPENSSL_armcap_P & ARMV8_AES)
#  define HWAES_set_encrypt_key aes_v8_set_encrypt_key
#  define HWAES_set_decrypt_key aes_v8_set_decrypt_key
#  define HWAES_encrypt aes_v8_encrypt
#  define HWAES_decrypt aes_v8_decrypt
#  define HWAES_cbc_encrypt aes_v8_cbc_encrypt
#  define HWAES_ctr32_encrypt_blocks aes_v8_ctr32_encrypt_blocks
# endif
#endif
#if defined(HWAES_CAPABLE)
#endif
#define BLOCK_CIPHER_generic_pack(nid,keylen,flags)             \
#ifdef HWAES_CAPABLE
# ifdef HWAES_cbc_encrypt
# endif
#endif
#ifdef BSAES_CAPABLE
#endif
#ifdef VPAES_CAPABLE
#endif
#ifdef HWAES_CAPABLE
# ifdef HWAES_cbc_encrypt
# endif
# ifdef HWAES_ctr32_encrypt_blocks
# endif
#endif
#ifdef BSAES_CAPABLE
#endif
#ifdef VPAES_CAPABLE
#endif
#ifdef AES_CTR_ASM
#endif
#ifdef HWAES_CAPABLE
# ifdef HWAES_ctr32_encrypt_blocks
# else
# endif
#endif
#ifdef BSAES_CAPABLE
#endif
#ifdef VPAES_CAPABLE
#endif
#ifdef AES_CTR_ASM
#else
#endif
#if defined(AES_GCM_ASM)
#endif
#if defined(AES_GCM_ASM2)
#endif
#if defined(AES_GCM_ASM)
#endif
#if defined(AES_GCM_ASM2)
#endif
#if defined(AES_GCM_ASM)
#endif
#if defined(AES_GCM_ASM2)
#endif
#if defined(AES_GCM_ASM)
#endif
#if defined(AES_GCM_ASM2)
#endif
#define CUSTOM_FLAGS    (EVP_CIPH_FLAG_DEFAULT_ASN1 \
#ifdef AES_XTS_ASM
#else
#endif
#ifdef HWAES_CAPABLE
# ifdef HWAES_xts_encrypt
# endif
# ifdef HWAES_xts_decrypt
#endif
#endif
#ifdef BSAES_CAPABLE
#endif
#ifdef VPAES_CAPABLE
#endif
#define aes_xts_cleanup NULL
#define XTS_FLAGS       (EVP_CIPH_FLAG_DEFAULT_ASN1 | EVP_CIPH_CUSTOM_IV \
#ifdef HWAES_CAPABLE
#endif
#ifdef VPAES_CAPABLE
#endif
#define aes_ccm_cleanup NULL
typedef struct {
    union {
        double align;
        AES_KEY ks;
    } ks;
#define WRAP_FLAGS      (EVP_CIPH_WRAP_MODE \
#ifndef OPENSSL_NO_OCB
# ifdef HWAES_CAPABLE
#  ifdef HWAES_ocb_encrypt
#  else
#    define HWAES_ocb_encrypt ((ocb128_f)NULL)
#  endif
#  ifdef HWAES_ocb_decrypt
#  else
#    define HWAES_ocb_decrypt ((ocb128_f)NULL)
#  endif
# endif
# ifdef HWAES_CAPABLE
# endif
# ifdef VPAES_CAPABLE
# endif
#endif                         /* OPENSSL_NO_OCB */
