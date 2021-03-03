#include <setjmp.h>             /* for setjmp(), longjmp(), and jmp_buf */
#include "puff.h"               /* prototype for puff() */
#define local static            /* for local function definitions */
#define MAXBITS 15              /* maximum bits in a code */
#define MAXLCODES 286           /* maximum number of literal/length codes */
#define MAXDCODES 30            /* maximum number of distance codes */
#define MAXCODES (MAXLCODES+MAXDCODES)  /* maximum codes lengths to read */
#define FIXLCODES 288           /* number of fixed literal/length codes */
#ifdef SLOW
#else /* !SLOW */
#endif /* SLOW */
#ifndef INFLATE_ALLOW_INVALID_DISTANCE_TOOFAR_ARRR
#endif
#ifdef INFLATE_ALLOW_INVALID_DISTANCE_TOOFAR_ARRR
#endif
