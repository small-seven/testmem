#include <stddef.h>
#include <stdint.h>
#include <stdatomic.h>
#include "attributes.h"
#include "cpu.h"
#include "cpu_internal.h"
#include "config.h"
#include "opt.h"
#include "common.h"
#if HAVE_SCHED_GETAFFINITY
#ifndef _GNU_SOURCE
# define _GNU_SOURCE
#endif
#include <sched.h>
#endif
#if HAVE_GETPROCESSAFFINITYMASK || HAVE_WINRT
#include <windows.h>
#endif
#if HAVE_SYSCTL
#if HAVE_SYS_PARAM_H
#include <sys/param.h>
#endif
#include <sys/types.h>
#include <sys/sysctl.h>
#endif
#if HAVE_UNISTD_H
#include <unistd.h>
#endif
#define CPUFLAG_MMXEXT   (AV_CPU_FLAG_MMX      | AV_CPU_FLAG_MMXEXT | AV_CPU_FLAG_CMOV)
#define CPUFLAG_3DNOW    (AV_CPU_FLAG_3DNOW    | AV_CPU_FLAG_MMX)
#define CPUFLAG_3DNOWEXT (AV_CPU_FLAG_3DNOWEXT | CPUFLAG_3DNOW)
#define CPUFLAG_SSE      (AV_CPU_FLAG_SSE      | CPUFLAG_MMXEXT)
#define CPUFLAG_SSE2     (AV_CPU_FLAG_SSE2     | CPUFLAG_SSE)
#define CPUFLAG_SSE2SLOW (AV_CPU_FLAG_SSE2SLOW | CPUFLAG_SSE2)
#define CPUFLAG_SSE3     (AV_CPU_FLAG_SSE3     | CPUFLAG_SSE2)
#define CPUFLAG_SSE3SLOW (AV_CPU_FLAG_SSE3SLOW | CPUFLAG_SSE3)
#define CPUFLAG_SSSE3    (AV_CPU_FLAG_SSSE3    | CPUFLAG_SSE3)
#define CPUFLAG_SSE4     (AV_CPU_FLAG_SSE4     | CPUFLAG_SSSE3)
#define CPUFLAG_SSE42    (AV_CPU_FLAG_SSE42    | CPUFLAG_SSE4)
#define CPUFLAG_AVX      (AV_CPU_FLAG_AVX      | CPUFLAG_SSE42)
#define CPUFLAG_AVXSLOW  (AV_CPU_FLAG_AVXSLOW  | CPUFLAG_AVX)
#define CPUFLAG_XOP      (AV_CPU_FLAG_XOP      | CPUFLAG_AVX)
#define CPUFLAG_FMA3     (AV_CPU_FLAG_FMA3     | CPUFLAG_AVX)
#define CPUFLAG_FMA4     (AV_CPU_FLAG_FMA4     | CPUFLAG_AVX)
#define CPUFLAG_AVX2     (AV_CPU_FLAG_AVX2     | CPUFLAG_AVX)
#define CPUFLAG_BMI2     (AV_CPU_FLAG_BMI2     | AV_CPU_FLAG_BMI1)
#define CPUFLAG_AESNI    (AV_CPU_FLAG_AESNI    | CPUFLAG_SSE42)
#define CPUFLAG_AVX512   (AV_CPU_FLAG_AVX512   | CPUFLAG_AVX2)
#if   ARCH_PPC
#elif ARCH_X86
#elif ARCH_ARM
#elif ARCH_AARCH64
#endif
#if   ARCH_PPC
#elif ARCH_X86
#define CPU_FLAG_P2 AV_CPU_FLAG_CMOV | AV_CPU_FLAG_MMX
#define CPU_FLAG_P3 CPU_FLAG_P2 | AV_CPU_FLAG_MMX2 | AV_CPU_FLAG_SSE
#define CPU_FLAG_P4 CPU_FLAG_P3| AV_CPU_FLAG_SSE2
#define CPU_FLAG_K62 AV_CPU_FLAG_MMX | AV_CPU_FLAG_3DNOW
#define CPU_FLAG_ATHLON   CPU_FLAG_K62 | AV_CPU_FLAG_CMOV | AV_CPU_FLAG_3DNOWEXT | AV_CPU_FLAG_MMX2
#define CPU_FLAG_ATHLONXP CPU_FLAG_ATHLON | AV_CPU_FLAG_SSE
#define CPU_FLAG_K8  CPU_FLAG_ATHLONXP | AV_CPU_FLAG_SSE2
#elif ARCH_ARM
#elif ARCH_AARCH64
#endif
#if HAVE_WINRT
#endif
#if HAVE_SCHED_GETAFFINITY && defined(CPU_COUNT)
#elif HAVE_GETPROCESSAFFINITYMASK
#elif HAVE_SYSCTL && defined(HW_NCPU)
#elif HAVE_SYSCONF && defined(_SC_NPROC_ONLN)
#elif HAVE_SYSCONF && defined(_SC_NPROCESSORS_ONLN)
#elif HAVE_WINRT
#endif
