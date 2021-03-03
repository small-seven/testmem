#ifndef _GNU_SOURCE
# define _GNU_SOURCE
#endif
#include "e_os.h"
#include <stdio.h>
#include "internal/cryptlib.h"
#include <openssl/rand.h>
#include <openssl/crypto.h>
#include "rand_local.h"
#include "crypto/rand.h"
#include <stdio.h>
#include "internal/dso.h"
#ifdef __linux
# include <sys/syscall.h>
# ifdef DEVRANDOM_WAIT
#  include <sys/shm.h>
#  include <sys/utsname.h>
# endif
#endif
#if defined(__FreeBSD__) && !defined(OPENSSL_SYS_UEFI)
# include <sys/types.h>
# include <sys/sysctl.h>
# include <sys/param.h>
#endif
#if defined(__OpenBSD__) || defined(__NetBSD__)
# include <sys/param.h>
#endif
#if defined(OPENSSL_SYS_UNIX) || defined(__DJGPP__)
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/time.h>
# define TWO32TO64(a, b) ((((uint64_t)(a)) << 32) + (b))
# undef OSSL_POSIX_TIMER_OKAY
# if defined(_POSIX_TIMERS) && _POSIX_TIMERS > 0
#  if defined(__GLIBC__)
#   if defined(__GLIBC_PREREQ)
#    if __GLIBC_PREREQ(2, 17)
#     define OSSL_POSIX_TIMER_OKAY
#    endif
#   endif
#  else
#   define OSSL_POSIX_TIMER_OKAY
#  endif
# endif
#endif /* (defined(OPENSSL_SYS_UNIX) && !defined(OPENSSL_SYS_VXWORKS))
#if defined(OPENSSL_RAND_SEED_NONE)
# undef OPENSSL_RAND_SEED_OS
# undef OPENSSL_RAND_SEED_GETRANDOM
# undef OPENSSL_RAND_SEED_LIBRANDOM
# undef OPENSSL_RAND_SEED_DEVRANDOM
# undef OPENSSL_RAND_SEED_RDTSC
# undef OPENSSL_RAND_SEED_RDCPU
# undef OPENSSL_RAND_SEED_EGD
#endif
#if (defined(OPENSSL_SYS_VXWORKS) || defined(OPENSSL_SYS_UEFI)) && \
# error "UEFI and VXWorks only support seeding NONE"
#endif
#if defined(OPENSSL_SYS_VXWORKS)
#endif
#if !(defined(OPENSSL_SYS_WINDOWS) || defined(OPENSSL_SYS_WIN32) \
# if defined(OPENSSL_SYS_VOS)
#  ifndef OPENSSL_RAND_SEED_OS
#   error "Unsupported seeding method configured; must be os"
#  endif
#  if defined(OPENSSL_SYS_VOS_HPPA) && defined(OPENSSL_SYS_VOS_IA32)
#   error "Unsupported HP-PA and IA32 at the same time."
#  endif
#  if !defined(OPENSSL_SYS_VOS_HPPA) && !defined(OPENSSL_SYS_VOS_IA32)
#   error "Must have one of HP-PA or IA32"
#  endif
#  ifdef OPENSSL_SYS_VOS_HPPA
#  else
#  endif
#  ifdef OPENSSL_SYS_VOS_HPPA
#  else
#  endif
# else
#  if defined(OPENSSL_RAND_SEED_EGD) && \
#   error "Seeding uses EGD but EGD is turned off or no device given"
#  endif
#  if defined(OPENSSL_RAND_SEED_DEVRANDOM) && !defined(DEVRANDOM)
#   error "Seeding uses urandom but DEVRANDOM is not configured"
#  endif
#  if defined(OPENSSL_RAND_SEED_OS)
#   if !defined(DEVRANDOM)
#    error "OS seeding requires DEVRANDOM to be configured"
#   endif
#   define OPENSSL_RAND_SEED_GETRANDOM
#   define OPENSSL_RAND_SEED_DEVRANDOM
#  endif
#  if defined(OPENSSL_RAND_SEED_LIBRANDOM)
#   error "librandom not (yet) supported"
#  endif
#  if (defined(__FreeBSD__) || defined(__NetBSD__)) && defined(KERN_ARND)
#if   defined(__NetBSD__) && __NetBSD_Version__ < 400000000
#endif
#  endif
#  if defined(OPENSSL_RAND_SEED_GETRANDOM)
#   if defined(__linux) && !defined(__NR_getrandom)
#    if defined(__arm__)
#     define __NR_getrandom    (__NR_SYSCALL_BASE+384)
#    elif defined(__i386__)
#     define __NR_getrandom    355
#    elif defined(__x86_64__)
#     if defined(__ILP32__)
#      define __NR_getrandom   (__X32_SYSCALL_BIT + 318)
#     else
#      define __NR_getrandom   318
#     endif
#    elif defined(__xtensa__)
#     define __NR_getrandom    338
#    elif defined(__s390__) || defined(__s390x__)
#     define __NR_getrandom    349
#    elif defined(__bfin__)
#     define __NR_getrandom    389
#    elif defined(__powerpc__)
#     define __NR_getrandom    359
#    elif defined(__mips__) || defined(__mips64)
#     if _MIPS_SIM == _MIPS_SIM_ABI32
#      define __NR_getrandom   (__NR_Linux + 353)
#     elif _MIPS_SIM == _MIPS_SIM_ABI64
#      define __NR_getrandom   (__NR_Linux + 313)
#     elif _MIPS_SIM == _MIPS_SIM_NABI32
#      define __NR_getrandom   (__NR_Linux + 317)
#     endif
#    elif defined(__hppa__)
#     define __NR_getrandom    (__NR_Linux + 339)
#    elif defined(__sparc__)
#     define __NR_getrandom    347
#    elif defined(__ia64__)
#     define __NR_getrandom    1339
#    elif defined(__alpha__)
#     define __NR_getrandom    511
#    elif defined(__sh__)
#     if defined(__SH5__)
#      define __NR_getrandom   373
#     else
#      define __NR_getrandom   384
#     endif
#    elif defined(__avr32__)
#     define __NR_getrandom    317
#    elif defined(__microblaze__)
#     define __NR_getrandom    385
#    elif defined(__m68k__)
#     define __NR_getrandom    352
#    elif defined(__cris__)
#     define __NR_getrandom    356
#    elif defined(__aarch64__)
#     define __NR_getrandom    278
#    else /* generic */
#     define __NR_getrandom    278
#    endif
#   endif
#  if defined(__GNUC__) && __GNUC__>=2 && defined(__ELF__) && !defined(__hpux)
#  else
#  endif
#  if defined(__linux) && defined(__NR_getrandom)
#  elif (defined(__FreeBSD__) || defined(__NetBSD__)) && defined(KERN_ARND)
#  else
#  endif
#  endif    /* defined(OPENSSL_RAND_SEED_GETRANDOM) */
#  if defined(OPENSSL_RAND_SEED_DEVRANDOM)
#   if defined(__linux) && defined(DEVRANDOM_WAIT)
#   else /* defined __linux */
#   endif
#  else     /* !defined(OPENSSL_RAND_SEED_DEVRANDOM) */
#  endif    /* defined(OPENSSL_RAND_SEED_DEVRANDOM) */
#  if defined(OPENSSL_RAND_SEED_NONE)
#  else
#   if defined(OPENSSL_RAND_SEED_GETRANDOM)
#   endif
#   if defined(OPENSSL_RAND_SEED_LIBRANDOM)
#   endif
#   if defined(OPENSSL_RAND_SEED_DEVRANDOM)
#   endif
#   if defined(OPENSSL_RAND_SEED_RDTSC)
#   endif
#   if defined(OPENSSL_RAND_SEED_RDCPU)
#   endif
#   if defined(OPENSSL_RAND_SEED_EGD)
#   endif
#  endif
# endif
#endif
#if defined(OPENSSL_SYS_UNIX) || defined(__DJGPP__)
# if defined(OSSL_POSIX_TIMER_OKAY)
# endif
# if defined(__unix__) \
# endif
# if defined(__sun) || defined(__hpux)
# elif defined(_AIX)
# elif defined(OSSL_POSIX_TIMER_OKAY)
#  ifdef CLOCK_BOOTTIME
#   define CLOCK_TYPE CLOCK_BOOTTIME
#  elif defined(_POSIX_MONOTONIC_CLOCK)
#   define CLOCK_TYPE CLOCK_MONOTONIC
#  else
#   define CLOCK_TYPE CLOCK_REALTIME
#  endif
# endif
# if defined(__unix__) \
# endif
#endif /* (defined(OPENSSL_SYS_UNIX) && !defined(OPENSSL_SYS_VXWORKS))
