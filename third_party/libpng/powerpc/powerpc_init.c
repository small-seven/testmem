#define _POSIX_SOURCE 1
#include <stdio.h>
#include "../pngpriv.h"
#ifdef PNG_READ_SUPPORTED
#if PNG_POWERPC_VSX_OPT > 0
#ifdef PNG_POWERPC_VSX_CHECK_SUPPORTED /* Do run-time checks */
#ifndef PNG_POWERPC_VSX_FILE
#  ifdef __linux__
#     define  PNG_POWERPC_VSX_FILE "contrib/powerpc-vsx/linux_aux.c"
#  endif
#endif
#ifdef PNG_POWERPC_VSX_FILE
#include <signal.h> /* for sig_atomic_t */
#include PNG_POWERPC_VSX_FILE
#else  /* PNG_POWERPC_VSX_FILE */
#  error "PNG_POWERPC_VSX_FILE undefined: no support for run-time POWERPC VSX checks"
#endif /* PNG_POWERPC_VSX_FILE */
#endif /* PNG_POWERPC_VSX_CHECK_SUPPORTED */
#ifdef PNG_POWERPC_VSX_API_SUPPORTED
#endif /* PNG_POWERPC_VSX_API_SUPPORTED */
#ifdef PNG_POWERPC_VSX_CHECK_SUPPORTED
#ifdef PNG_POWERPC_VSX_API_SUPPORTED
#endif
#endif /* PNG_POWERPC_VSX_CHECK_SUPPORTED */
#ifdef PNG_POWERPC_VSX_API_SUPPORTED
#endif
#endif /* PNG_POWERPC_VSX_OPT > 0 */
#endif /* READ */
