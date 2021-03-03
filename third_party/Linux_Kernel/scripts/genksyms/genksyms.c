#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <stdarg.h>
#ifdef __GNU_LIBRARY__
#include <getopt.h>
#endif				/* __GNU_LIBRARY__ */
#include "genksyms.h"
#define HASH_BUCKETS  4096
	[SYM_TYPEDEF]    = {'t', "typedef"},
	[SYM_ENUM]       = {'e', "enum"},
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#ifdef __GNU_LIBRARY__
#else				/* __GNU_LIBRARY__ */
#endif				/* __GNU_LIBRARY__ */
#ifdef __GNU_LIBRARY__
#else				/* __GNU_LIBRARY__ */
#endif				/* __GNU_LIBRARY__ */
