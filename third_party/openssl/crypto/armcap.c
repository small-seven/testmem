#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>
#include <signal.h>
#include <openssl/crypto.h>
#include "internal/cryptlib.h"
#include "arm_arch.h"
#if __ARM_MAX_ARCH__<7
#else
# ifdef __aarch64__
# endif
# if defined(__GNUC__) && __GNUC__>=2
# endif
# if defined(__GLIBC__) && defined(__GLIBC_PREREQ)
#  if __GLIBC_PREREQ(2, 16)
#   include <sys/auxv.h>
#   define OSSL_IMPLEMENT_GETAUXVAL
#  endif
# endif
# if defined(__arm__) || defined (__arm)
#  define HWCAP                  16
#  define HWCAP_NEON             (1 << 12)
#  define HWCAP_CE               26
#  define HWCAP_CE_AES           (1 << 0)
#  define HWCAP_CE_PMULL         (1 << 1)
#  define HWCAP_CE_SHA1          (1 << 2)
#  define HWCAP_CE_SHA256        (1 << 3)
# elif defined(__aarch64__)
#  define HWCAP                  16
#  define HWCAP_NEON             (1 << 1)
#  define HWCAP_CE               HWCAP
#  define HWCAP_CE_AES           (1 << 3)
#  define HWCAP_CE_PMULL         (1 << 4)
#  define HWCAP_CE_SHA1          (1 << 5)
#  define HWCAP_CE_SHA256        (1 << 6)
#  define HWCAP_CE_SHA512        (1 << 21)
# endif
# if defined(__APPLE__) && !defined(__aarch64__)
# endif
# ifdef OSSL_IMPLEMENT_GETAUXVAL
#  ifdef __aarch64__
#  endif
# endif
# ifndef OSSL_IMPLEMENT_GETAUXVAL
#  if defined(__aarch64__) && !defined(__APPLE__)
#  endif
# endif
#endif
