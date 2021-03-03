#include <openssl/opensslconf.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/crypto.h>
#include <openssl/sha.h>
#include <openssl/opensslv.h>
#include "internal/cryptlib.h"
#include "crypto/sha.h"
#if defined(__i386) || defined(__i386__) || defined(_M_IX86) || \
# define SHA512_BLOCK_CAN_MANAGE_UNALIGNED_DATA
#endif
#ifndef SHA512_ASM
#endif
#ifdef  B_ENDIAN
#else
#endif
#ifndef SHA512_BLOCK_CAN_MANAGE_UNALIGNED_DATA
#endif
#ifndef SHA512_BLOCK_CAN_MANAGE_UNALIGNED_DATA
#endif
#ifndef SHA512_ASM
# ifndef PEDANTIC
#  if defined(__GNUC__) && __GNUC__>=2 && \
#   if defined(__x86_64) || defined(__x86_64__)
#    define ROTR(a,n)    ({ SHA_LONG64 ret;             \
#    if !defined(B_ENDIAN)
#     define PULL64(x) ({ SHA_LONG64 ret=*((const SHA_LONG64 *)(&(x)));  \
#    endif
#   elif (defined(__i386) || defined(__i386__)) && !defined(B_ENDIAN)
#    if defined(I386_ONLY)
#     define PULL64(x) ({ const unsigned int *p=(const unsigned int *)(&(x));\
#    else
#     define PULL64(x) ({ const unsigned int *p=(const unsigned int *)(&(x));\
#    endif
#   elif (defined(_ARCH_PPC) && defined(__64BIT__)) || defined(_ARCH_PPC64)
#    define ROTR(a,n)    ({ SHA_LONG64 ret;             \
#   elif defined(__aarch64__)
#    define ROTR(a,n)    ({ SHA_LONG64 ret;             \
#    if  defined(__BYTE_ORDER__) && defined(__ORDER_LITTLE_ENDIAN__) && \
#     define PULL64(x)   ({ SHA_LONG64 ret;                     \
#    endif
#   endif
#  elif defined(_MSC_VER)
#   if defined(_WIN64)         /* applies to both IA-64 and AMD64 */
#    pragma intrinsic(_rotr64)
#    define ROTR(a,n)    _rotr64((a),n)
#   endif
#   if defined(_M_IX86) && !defined(OPENSSL_NO_ASM) && \
#    if defined(I386_ONLY)
#    else
#    endif
#    define PULL64(x) __pull64be(&(x))
#   endif
#  endif
# endif
# ifndef PULL64
#  define B(x,j)    (((SHA_LONG64)(*(((const unsigned char *)(&x))+j)))<<((7-j)*8))
#  define PULL64(x) (B(x,0)|B(x,1)|B(x,2)|B(x,3)|B(x,4)|B(x,5)|B(x,6)|B(x,7))
# endif
# ifndef ROTR
#  define ROTR(x,s)       (((x)>>s) | (x)<<(64-s))
# endif
# define Sigma0(x)       (ROTR((x),28) ^ ROTR((x),34) ^ ROTR((x),39))
# define Sigma1(x)       (ROTR((x),14) ^ ROTR((x),18) ^ ROTR((x),41))
# define sigma0(x)       (ROTR((x),1)  ^ ROTR((x),8)  ^ ((x)>>7))
# define sigma1(x)       (ROTR((x),19) ^ ROTR((x),61) ^ ((x)>>6))
# define Ch(x,y,z)       (((x) & (y)) ^ ((~(x)) & (z)))
# define Maj(x,y,z)      (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
# if defined(__i386) || defined(__i386__) || defined(_M_IX86)
#  ifdef B_ENDIAN
#  else
#  endif
# elif defined(OPENSSL_SMALL_FOOTPRINT)
#  ifdef B_ENDIAN
#  else
#  endif
# else
#  define ROUND_00_15(i,a,b,c,d,e,f,g,h)        do {    \
#  define ROUND_16_80(i,j,a,b,c,d,e,f,g,h,X)    do {    \
#  ifdef B_ENDIAN
#  else
#  endif
# endif
#endif                         /* SHA512_ASM */
