#include <openssl/e_os2.h>
#include <string.h>
#include <assert.h>
#if !defined(KECCAK1600_ASM) || !defined(SELFTEST)
#if !defined(KECCAK_REF) && !defined(KECCAK_1X) && !defined(KECCAK_1X_ALT) && \
# define KECCAK_2X      /* default to KECCAK_2X variant */
#endif
#if defined(__i386) || defined(__i386__) || defined(_M_IX86)
# define KECCAK_COMPLEMENTING_TRANSFORM
#endif
#if defined(__x86_64__) || defined(__aarch64__) || \
# define BIT_INTERLEAVE (0)
#else
# define BIT_INTERLEAVE (sizeof(void *) < 8)
#endif
#define ROL32(a, offset) (((a) << (offset)) | ((a) >> ((32 - (offset)) & 31)))
#if defined(KECCAK_REF)
#elif defined(KECCAK_1X)
#if defined(__arm__)
#else
#endif
#elif defined(KECCAK_1X_ALT)
#elif defined(KECCAK_2X)
#ifdef KECCAK_COMPLEMENTING_TRANSFORM
#else
#endif
#ifdef KECCAK_COMPLEMENTING_TRANSFORM
#else
#endif
#ifdef KECCAK_COMPLEMENTING_TRANSFORM
#else
#endif
#ifdef KECCAK_COMPLEMENTING_TRANSFORM
#else
#endif
#ifdef KECCAK_COMPLEMENTING_TRANSFORM
#else
#endif
#ifdef KECCAK_COMPLEMENTING_TRANSFORM
#endif
#ifdef KECCAK_COMPLEMENTING_TRANSFORM
#endif
#else   /* define KECCAK_INPLACE to compile this code path */
#endif
#endif
#ifdef SELFTEST
# include <stdio.h>
#endif
