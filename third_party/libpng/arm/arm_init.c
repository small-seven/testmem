#define _POSIX_SOURCE 1
#include "../pngpriv.h"
#ifdef PNG_READ_SUPPORTED
#if PNG_ARM_NEON_OPT > 0
#ifdef PNG_ARM_NEON_CHECK_SUPPORTED /* Do run-time checks */
#ifndef PNG_ARM_NEON_FILE
#  ifdef __linux__
#     define PNG_ARM_NEON_FILE "contrib/arm-neon/linux.c"
#  endif
#endif
#ifdef PNG_ARM_NEON_FILE
#include <signal.h> /* for sig_atomic_t */
#include PNG_ARM_NEON_FILE
#else  /* PNG_ARM_NEON_FILE */
#  error "PNG_ARM_NEON_FILE undefined: no support for run-time ARM NEON checks"
#endif /* PNG_ARM_NEON_FILE */
#endif /* PNG_ARM_NEON_CHECK_SUPPORTED */
#ifndef PNG_ALIGNED_MEMORY_SUPPORTED
#  error "ALIGNED_MEMORY is required; set: -DPNG_ALIGNED_MEMORY_SUPPORTED"
#endif
#ifdef PNG_ARM_NEON_API_SUPPORTED
#endif /* PNG_ARM_NEON_API_SUPPORTED */
#ifdef PNG_ARM_NEON_CHECK_SUPPORTED
#ifdef PNG_ARM_NEON_API_SUPPORTED
#endif
#endif /* PNG_ARM_NEON_CHECK_SUPPORTED */
#ifdef PNG_ARM_NEON_API_SUPPORTED
#endif
#endif /* PNG_ARM_NEON_OPT > 0 */
#endif /* READ */
