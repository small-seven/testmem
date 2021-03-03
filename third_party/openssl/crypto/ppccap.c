#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>
#include <signal.h>
#include <unistd.h>
#if defined(__linux) || defined(_AIX)
# include <sys/utsname.h>
#endif
#if defined(_AIX53)     /* defined even on post-5.3 */
# include <sys/systemcfg.h>
# if !defined(__power_set)
#  define __power_set(a) (_system_configuration.implementation & (a))
# endif
#endif
#if defined(__APPLE__) && defined(__MACH__)
# include <sys/types.h>
# include <sys/sysctl.h>
#endif
#include <openssl/crypto.h>
#include <openssl/bn.h>
#include <internal/cryptlib.h>
#include <crypto/chacha.h>
#include "bn/bn_local.h"
#include "ppc_arch.h"
#ifdef OPENSSL_BN_ASM_MONT
#endif
#ifndef OPENSSL_NO_CHACHA
#endif
#ifndef OPENSSL_NO_POLY1305
#endif
#ifdef ECP_NISTZ256_ASM
#endif
#if defined(__GLIBC__) && defined(__GLIBC_PREREQ)
# if __GLIBC_PREREQ(2, 16)
#  include <sys/auxv.h>
#  define OSSL_IMPLEMENT_GETAUXVAL
# endif
#endif
#define HWCAP                   16      /* AT_HWCAP */
#define HWCAP_PPC64             (1U << 30)
#define HWCAP_ALTIVEC           (1U << 28)
#define HWCAP_FPU               (1U << 27)
#define HWCAP_POWER6_EXT        (1U << 9)
#define HWCAP_VSX               (1U << 7)
#define HWCAP2                  26      /* AT_HWCAP2 */
#define HWCAP_VEC_CRYPTO        (1U << 25)
#define HWCAP_ARCH_3_00         (1U << 23)
# if defined(__GNUC__) && __GNUC__>=2
# endif
#if defined(_AIX)
# if defined(_SC_AIX_KERNEL_BITMODE)
# endif
# if defined(__power_set)
# endif
#endif
#if defined(__APPLE__) && defined(__MACH__)
#endif
#ifdef OSSL_IMPLEMENT_GETAUXVAL
#endif
#ifdef SIGEMT
#endif
#ifndef OSSL_IMPLEMENT_GETAUXVAL
# ifdef __linux
# endif
#endif
