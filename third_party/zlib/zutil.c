#include "zutil.h"
#ifndef Z_SOLO
#  include "gzguts.h"
#endif
#ifdef ZLIB_DEBUG
#endif
#if defined(ASMV) || defined(ASMINF)
#endif
#ifdef ZLIB_WINAPI
#endif
#ifdef BUILDFIXED
#endif
#ifdef DYNAMIC_CRC_TABLE
#endif
#ifdef NO_GZCOMPRESS
#endif
#ifdef NO_GZIP
#endif
#ifdef PKZIP_BUG_WORKAROUND
#endif
#ifdef FASTEST
#endif
#if defined(STDC) || defined(Z_HAVE_STDARG_H)
#  ifdef NO_vsnprintf
#    ifdef HAS_vsprintf_void
#    endif
#  else
#    ifdef HAS_vsnprintf_void
#    endif
#  endif
#else
#  ifdef NO_snprintf
#    ifdef HAS_sprintf_void
#    endif
#  else
#    ifdef HAS_snprintf_void
#    endif
#  endif
#endif
#ifdef ZLIB_DEBUG
#include <stdlib.h>
#  ifndef verbose
#    define verbose 0
#  endif
#endif
#if defined(_WIN32_WCE)
#endif
#ifndef HAVE_MEMCPY
#endif
#ifndef Z_SOLO
#ifdef SYS16BIT
#ifdef __TURBOC__
#  define MY_ZCALLOC
#define MAX_PTR 10
typedef struct ptr_table_s {
    voidpf org_ptr;
    voidpf new_ptr;
} ptr_table;
#endif /* __TURBOC__ */
#ifdef M_I86
#  define MY_ZCALLOC
#if (!defined(_MSC_VER) || (_MSC_VER <= 600))
#  define _halloc  halloc
#  define _hfree   hfree
#endif
#endif /* M_I86 */
#endif /* SYS16BIT */
#ifndef MY_ZCALLOC /* Any system without a special alloc function */
#ifndef STDC
#endif
#endif /* MY_ZCALLOC */
#endif /* !Z_SOLO */
