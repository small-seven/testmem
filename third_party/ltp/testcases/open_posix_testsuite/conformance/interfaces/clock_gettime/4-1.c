#include <stdio.h>
#include <time.h>
#include <errno.h>
#include <sys/time.h>
#include <unistd.h>
#include "posixtest.h"
#define LARGENUMBER 900000
#if _POSIX_CPUTIME == -1
#else
#ifdef CLOCK_PROCESS_CPUTIME_ID
#else
#endif
#endif
