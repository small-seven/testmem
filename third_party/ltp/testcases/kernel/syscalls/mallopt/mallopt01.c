#ifdef CONFIG_COLDFIRE
#define __MALLOC_STANDARD__
#endif
#include <errno.h>
#include <malloc.h>
#include <stdio.h>
#include "test.h"
#include "safe_macros.h"
#define FAILED 0
#define PASSED 1
#define MAX_FAST_SIZE	(80 * sizeof(size_t) / 4)
#if defined(__GLIBC__)
#else
#endif
