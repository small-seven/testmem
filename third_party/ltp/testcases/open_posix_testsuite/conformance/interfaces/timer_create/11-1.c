#include <time.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "posixtest.h"
#define SIGTOTEST SIGALRM
#define TIMERSEC 2
#define ACCEPTABLEDELTA 1
#if _POSIX_THREAD_CPUTIME == -1
#else
#endif
