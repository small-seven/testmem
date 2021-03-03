#include <stddef.h>             /* for NULL */
#include <setjmp.h>             /* for setjmp(), longjmp(), and jmp_buf */
#include "blast.h"              /* prototype for blast() */
#define local static            /* for local function definitions */
#define MAXBITS 13              /* maximum code length */
#define MAXWIN 4096             /* maximum window size */
#ifdef TEST
#include <stdio.h>
#include <stdlib.h>
#define CHUNK 16384
#endif
