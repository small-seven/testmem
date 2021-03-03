#include "tfloat.h"
#include "test.h"
#define SAFE_FREE(p) { if (p) { free(p); (p)=NULL; } }
#define exit(x) myexit(x)
#ifndef	PATH_MAX
#define PATH_MAX		1024
#endif
#ifndef PTHREAD_THREADS_MAX
#define PTHREAD_THREADS_MAX	1024
#endif
#define DEFAULT_NUM_THREADS	20
