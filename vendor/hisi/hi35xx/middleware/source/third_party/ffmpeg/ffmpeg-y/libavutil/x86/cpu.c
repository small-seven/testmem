#include <stdlib.h>
#include <string.h>
#include "libavutil/x86/asm.h"
#include "libavutil/x86/cpu.h"
#include "libavutil/cpu.h"
#include "libavutil/cpu_internal.h"
#if HAVE_X86ASM
#define cpuid(index, eax, ebx, ecx, edx)        \
#define xgetbv(index, eax, edx)                 \
#elif HAVE_INLINE_ASM
#define cpuid(index, eax, ebx, ecx, edx)                        \
#define xgetbv(index, eax, edx)                                 \
#define get_eflags(x)                           \
#define set_eflags(x)                           \
#endif /* HAVE_INLINE_ASM */
#if ARCH_X86_64
#define cpuid_test() 1
#elif HAVE_X86ASM
#define cpuid_test ff_cpu_cpuid_test
#elif HAVE_INLINE_ASM
#endif
#ifdef cpuid
#if HAVE_SSE
#if HAVE_AVX
#endif /* HAVE_AVX */
#endif /* HAVE_SSE */
#if HAVE_AVX2
#if HAVE_AVX512 /* F, CD, BW, DQ, VL */
#endif /* HAVE_AVX512 */
#endif /* HAVE_AVX2 */
#endif /* cpuid */
