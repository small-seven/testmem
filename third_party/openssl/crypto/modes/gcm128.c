#include <openssl/crypto.h>
#include "modes_local.h"
#include <string.h>
#if defined(BSWAP4) && defined(STRICT_ALIGNMENT)
# undef  GETU32
# define GETU32(p)       BSWAP4(*(const u32 *)(p))
# undef  PUTU32
# define PUTU32(p,v)     *(u32 *)(p) = BSWAP4(v)
#endif
#define PACK(s)         ((size_t)(s)<<(sizeof(size_t)*8-16))
#define REDUCE1BIT(V)   do { \
#if     TABLE_BITS==8
# ifdef BSWAP8
# else
# endif
# define GCM_MUL(ctx)      gcm_gmult_8bit(ctx->Xi.u,ctx->Htable)
#elif   TABLE_BITS==4
# if defined(OPENSSL_SMALL_FOOTPRINT)
# endif
# if defined(OPENSSL_SMALL_FOOTPRINT)
# else
# endif
# if defined(GHASH_ASM) && (defined(__arm__) || defined(__arm))
# endif
# ifndef GHASH_ASM
#  ifdef BSWAP8
#  else
#  endif
#  if !defined(OPENSSL_SMALL_FOOTPRINT)
#   if 1
#   else
#   endif
#   ifdef BSWAP8
#   else
#   endif
#  endif
# else
# endif
# define GCM_MUL(ctx)      gcm_gmult_4bit(ctx->Xi.u,ctx->Htable)
# if defined(GHASH_ASM) || !defined(OPENSSL_SMALL_FOOTPRINT)
#  define GHASH(ctx,in,len) gcm_ghash_4bit((ctx)->Xi.u,(ctx)->Htable,in,len)
#  define GHASH_CHUNK       (3*1024)
# endif
#else                           /* TABLE_BITS */
# ifdef BSWAP8
# else
# endif
# ifdef BSWAP8
# else
# endif
# define GCM_MUL(ctx)      gcm_gmult_1bit(ctx->Xi.u,ctx->H.u)
#endif
#if     TABLE_BITS==4 && (defined(GHASH_ASM) || defined(OPENSSL_CPUID_OBJ))
# if    !defined(I386_ONLY) && \
#  define GHASH_ASM_X86_OR_64
#  define GCM_FUNCREF_4BIT
#  if defined(__i386) || defined(__i386__) || defined(_M_IX86)
#   define gcm_init_avx   gcm_init_clmul
#   define gcm_gmult_avx  gcm_gmult_clmul
#   define gcm_ghash_avx  gcm_ghash_clmul
#  else
#  endif
#  if   defined(__i386) || defined(__i386__) || defined(_M_IX86)
#   define GHASH_ASM_X86
#  endif
# elif defined(__arm__) || defined(__arm) || defined(__aarch64__)
#  include "arm_arch.h"
#  if __ARM_MAX_ARCH__>=7
#   define GHASH_ASM_ARM
#   define GCM_FUNCREF_4BIT
#   define PMULL_CAPABLE        (OPENSSL_armcap_P & ARMV8_PMULL)
#   if defined(__arm__) || defined(__arm)
#    define NEON_CAPABLE        (OPENSSL_armcap_P & ARMV7_NEON)
#   endif
#  endif
# elif defined(__sparc__) || defined(__sparc)
#  include "sparc_arch.h"
#  define GHASH_ASM_SPARC
#  define GCM_FUNCREF_4BIT
# elif defined(OPENSSL_CPUID_OBJ) && (defined(__powerpc__) || defined(__ppc__) || defined(_ARCH_PPC))
#  include "ppc_arch.h"
#  define GHASH_ASM_PPC
#  define GCM_FUNCREF_4BIT
# endif
#endif
#ifdef GCM_FUNCREF_4BIT
# undef  GCM_MUL
# define GCM_MUL(ctx)           (*gcm_gmult_p)(ctx->Xi.u,ctx->Htable)
# ifdef GHASH
#  undef  GHASH
#  define GHASH(ctx,in,len)     (*gcm_ghash_p)(ctx->Xi.u,ctx->Htable,in,len)
# endif
#endif
#ifdef BSWAP8
#else
#endif
#if     TABLE_BITS==8
#elif   TABLE_BITS==4
# if    defined(GHASH)
#  define CTX__GHASH(f) (ctx->ghash = (f))
# else
#  define CTX__GHASH(f) (ctx->ghash = NULL)
# endif
# if    defined(GHASH_ASM_X86_OR_64)
#  if   !defined(GHASH_ASM_X86) || defined(OPENSSL_IA32_SSE2)
#  endif
#  if   defined(GHASH_ASM_X86)  /* x86 only */
#   if  defined(OPENSSL_IA32_SSE2)
#   else
#   endif
#  else
#  endif
# elif  defined(GHASH_ASM_ARM)
#  ifdef PMULL_CAPABLE
#  endif
#  ifdef NEON_CAPABLE
#  endif
# elif  defined(GHASH_ASM_SPARC)
# elif  defined(GHASH_ASM_PPC)
# else
# endif
# undef CTX__GHASH
#endif
#ifdef GCM_FUNCREF_4BIT
#endif
#ifdef BSWAP8
#else
#endif
#ifdef BSWAP4
#else
#endif
#ifdef BSWAP4
#else
#endif
#ifdef GCM_FUNCREF_4BIT
# ifdef GHASH
# endif
#endif
#ifdef GHASH
#else
#endif
#ifdef GCM_FUNCREF_4BIT
# if defined(GHASH) && !defined(OPENSSL_SMALL_FOOTPRINT)
# endif
#endif
#if defined(GHASH) && !defined(OPENSSL_SMALL_FOOTPRINT)
#else
#endif
#ifdef BSWAP4
#else
#endif
#if !defined(OPENSSL_SMALL_FOOTPRINT)
# if defined(GHASH)
# else
# endif
# if defined(STRICT_ALIGNMENT)
# endif
# if defined(GHASH)
#  if defined(GHASH_CHUNK)
#   ifdef BSWAP4
#   else
#   endif
#  endif
#  ifdef BSWAP4
#  else
#  endif
# else
#  ifdef BSWAP4
#  else
#  endif
# endif
# ifdef BSWAP4
# else
# endif
# if defined(GHASH)
# else
# endif
#endif
#ifdef BSWAP4
#else
#endif
#if defined(GHASH) && !defined(OPENSSL_SMALL_FOOTPRINT)
#else
#endif
#ifdef GCM_FUNCREF_4BIT
# if defined(GHASH) && !defined(OPENSSL_SMALL_FOOTPRINT)
# endif
#endif
#if defined(GHASH) && !defined(OPENSSL_SMALL_FOOTPRINT)
#else
#endif
#ifdef BSWAP4
#else
#endif
#if !defined(OPENSSL_SMALL_FOOTPRINT)
# if defined(GHASH)
# else
# endif
# if defined(STRICT_ALIGNMENT)
# endif
# if defined(GHASH)
#  if defined(GHASH_CHUNK)
#   ifdef BSWAP4
#   else
#   endif
#  endif
#  ifdef BSWAP4
#  else
#  endif
# else
#  ifdef BSWAP4
#  else
#  endif
# endif
# ifdef BSWAP4
# else
# endif
# if defined(GHASH)
# else
# endif
#endif
#ifdef BSWAP4
#else
#endif
#if defined(GHASH) && !defined(OPENSSL_SMALL_FOOTPRINT)
#else
#endif
#if defined(OPENSSL_SMALL_FOOTPRINT)
#else
# ifdef GCM_FUNCREF_4BIT
#  ifdef GHASH
#  endif
# endif
#if defined(GHASH)
#else
#endif
# ifdef BSWAP4
# else
# endif
# if defined(GHASH)
# else
# endif
# if defined(GHASH)
#  if defined(GHASH_CHUNK)
#   ifdef BSWAP4
#   else
#   endif
#  endif
# endif
# ifdef BSWAP4
# else
# endif
# if defined(GHASH)
# else
# endif
# ifdef BSWAP4
# else
# endif
# if defined(GHASH)
# else
# endif
#endif
#if defined(OPENSSL_SMALL_FOOTPRINT)
#else
# ifdef GCM_FUNCREF_4BIT
#  ifdef GHASH
#  endif
# endif
# if defined(GHASH)
# else
# endif
# ifdef BSWAP4
# else
# endif
# if defined(GHASH)
# else
# endif
# if defined(GHASH)
#  if defined(GHASH_CHUNK)
#   ifdef BSWAP4
#   else
#   endif
#  endif
# endif
# if defined(GHASH)
# else
# endif
# ifdef BSWAP4
# else
# endif
# ifdef BSWAP4
# else
# endif
# if defined(GHASH)
# else
# endif
#endif
#ifdef GCM_FUNCREF_4BIT
# if defined(GHASH) && !defined(OPENSSL_SMALL_FOOTPRINT)
# endif
#endif
#if defined(GHASH) && !defined(OPENSSL_SMALL_FOOTPRINT)
#else
#endif
#ifdef BSWAP8
#else
#endif
#if defined(GHASH) && !defined(OPENSSL_SMALL_FOOTPRINT)
#else
#endif
