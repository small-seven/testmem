#define _POSIX_C_SOURCE 199309L /* for clock_gettime */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <time.h>
#if defined(HAVE_CONFIG_H) && !defined(PNG_NO_CONFIG_H)
#  include <config.h>
#endif
#ifdef PNG_FREESTANDING_TESTS
#  include <png.h>
#else
#  include "../../png.h"
#endif
#ifdef __cplusplus
#  define voidcast(type, value) static_cast<type>(value)
#else
#  define voidcast(type, value) (value)
#endif /* __cplusplus */
#if defined (CLOCK_PROCESS_CPUTIME_ID) && defined(PNG_STDIO_SUPPORTED) &&\
typedef struct
{
   FILE *input;
   FILE *output;
}  io_data;
#  ifdef PNG_BENIGN_ERRORS_SUPPORTED
#  endif
#ifdef __COVERITY__
#endif
#ifndef __COVERITY__
#else
#endif
#        define OPT(name) else if (strcmp(opt, #name) == 0)\
#else /* !sufficient support */
#endif /* !sufficient support */
