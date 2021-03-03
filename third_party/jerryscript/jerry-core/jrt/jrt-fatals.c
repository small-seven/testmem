#include "jmem.h"
#include "jrt.h"
#include "jrt-libc-includes.h"
#ifdef _WIN32
#  ifdef _WIN64
#    define PRI_SIZET "lu"
#    define MSG_SIZE_TYPE unsigned long
#  else
#    define PRI_SIZET "zu"
#    define MSG_SIZE_TYPE size_t
#  endif
#else
#  define PRI_SIZET "zu"
#  define MSG_SIZE_TYPE size_t
#endif
#if ENABLED (JERRY_MEM_STATS)
#endif
#if defined (_WIN32) || defined (_WIN64) || !defined (JERRY_NDEBUG)
#if ENABLED (JERRY_MEM_STATS)
#endif
#endif
#ifndef JERRY_NDEBUG
#endif /* !JERRY_NDEBUG */
