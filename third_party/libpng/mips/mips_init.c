#define _POSIX_SOURCE 1
#include <stdio.h>
#include "../pngpriv.h"
#ifdef PNG_READ_SUPPORTED
#if PNG_MIPS_MSA_OPT > 0
#ifdef PNG_MIPS_MSA_CHECK_SUPPORTED /* Do run-time checks */
#ifndef PNG_MIPS_MSA_FILE
#  ifdef __linux__
#     define PNG_MIPS_MSA_FILE "contrib/mips-msa/linux.c"
#  endif
#endif
#ifdef PNG_MIPS_MSA_FILE
#include <signal.h> /* for sig_atomic_t */
#include PNG_MIPS_MSA_FILE
#else  /* PNG_MIPS_MSA_FILE */
#  error "PNG_MIPS_MSA_FILE undefined: no support for run-time MIPS MSA checks"
#endif /* PNG_MIPS_MSA_FILE */
#endif /* PNG_MIPS_MSA_CHECK_SUPPORTED */
#ifndef PNG_ALIGNED_MEMORY_SUPPORTED
#  error "ALIGNED_MEMORY is required; set: -DPNG_ALIGNED_MEMORY_SUPPORTED"
#endif
#ifdef PNG_MIPS_MSA_API_SUPPORTED
#endif /* PNG_MIPS_MSA_API_SUPPORTED */
#ifdef PNG_MIPS_MSA_CHECK_SUPPORTED
#ifdef PNG_MIPS_MSA_API_SUPPORTED
#endif
#endif /* PNG_MIPS_MSA_CHECK_SUPPORTED */
#ifdef PNG_MIPS_MSA_API_SUPPORTED
#endif
#endif /* PNG_MIPS_MSA_OPT > 0 */
#endif /* READ */
