#include <assert.h>
#include <openssl/crypto.h>
#include "internal/cryptlib.h"
#include "bn_local.h"
#if defined(BN_LLONG) || defined(BN_UMULT_HIGH)
# ifndef OPENSSL_SMALL_FOOTPRINT
# endif
# ifndef OPENSSL_SMALL_FOOTPRINT
# endif
# ifndef OPENSSL_SMALL_FOOTPRINT
# endif
#else                           /* !(defined(BN_LLONG) ||
# ifndef OPENSSL_SMALL_FOOTPRINT
# endif
# ifndef OPENSSL_SMALL_FOOTPRINT
# endif
# ifndef OPENSSL_SMALL_FOOTPRINT
# endif
#endif                          /* !(defined(BN_LLONG) ||
#if defined(BN_LLONG) && defined(BN_DIV2W)
#else
#endif                          /* !defined(BN_LLONG) && defined(BN_DIV2W) */
#ifdef BN_LLONG
# ifndef OPENSSL_SMALL_FOOTPRINT
# endif
#else                           /* !BN_LLONG */
# ifndef OPENSSL_SMALL_FOOTPRINT
# endif
#endif                          /* !BN_LLONG */
#ifndef OPENSSL_SMALL_FOOTPRINT
#endif
#if defined(BN_MUL_COMBA) && !defined(OPENSSL_SMALL_FOOTPRINT)
# undef bn_mul_comba8
# undef bn_mul_comba4
# undef bn_sqr_comba8
# undef bn_sqr_comba4
# ifdef BN_LLONG
#  define mul_add_c(a,b,c0,c1,c2)       do {    \
#  define mul_add_c2(a,b,c0,c1,c2)      do {    \
#  define sqr_add_c(a,i,c0,c1,c2)       do {    \
#  define sqr_add_c2(a,i,j,c0,c1,c2) \
# elif defined(BN_UMULT_LOHI)
#  define mul_add_c(a,b,c0,c1,c2)       do {    \
#  define mul_add_c2(a,b,c0,c1,c2)      do {    \
#  define sqr_add_c(a,i,c0,c1,c2)       do {    \
#  define sqr_add_c2(a,i,j,c0,c1,c2)    \
# elif defined(BN_UMULT_HIGH)
#  define mul_add_c(a,b,c0,c1,c2)       do {    \
#  define mul_add_c2(a,b,c0,c1,c2)      do {    \
#  define sqr_add_c(a,i,c0,c1,c2)       do {    \
#  define sqr_add_c2(a,i,j,c0,c1,c2)      \
# else                          /* !BN_LLONG */
#  define mul_add_c(a,b,c0,c1,c2)       do {    \
#  define mul_add_c2(a,b,c0,c1,c2)      do {    \
#  define sqr_add_c(a,i,c0,c1,c2)       do {    \
#  define sqr_add_c2(a,i,j,c0,c1,c2) \
# endif                         /* !BN_LLONG */
# ifdef OPENSSL_NO_ASM
#  ifdef OPENSSL_BN_ASM_MONT
#   include <alloca.h>
#   ifdef mul64
#   endif
#   if 0                        /* template for platform-specific
#   endif
#   ifdef mul64
#   else
#   endif
#   ifdef mul64
#   else
#   endif
#   ifdef mul64
#   else
#   endif
#   ifdef mul64
#   else
#   endif
#  else
#  endif                        /* OPENSSL_BN_ASM_MONT */
# endif
#else                           /* !BN_MUL_COMBA */
# undef bn_sqr_comba4
# undef bn_sqr_comba8
# ifdef OPENSSL_NO_ASM
#  ifdef OPENSSL_BN_ASM_MONT
#   include <alloca.h>
#  else
#  endif                        /* OPENSSL_BN_ASM_MONT */
# endif
#endif                          /* !BN_MUL_COMBA */
