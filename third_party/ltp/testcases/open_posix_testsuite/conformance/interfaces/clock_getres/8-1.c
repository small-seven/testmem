#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include "posixtest.h"
#define LARGENUM 100000
#if _POSIX_THREAD_CPUTIME != -1
#ifdef DEBUG
#endif
#else
#endif
