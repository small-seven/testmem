#include <pthread.h>
#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include "posixtest.h"
#define NUMSIGNALS (sizeof(siglist) / sizeof(siglist[0]))
#ifdef SIGPOLL
#endif
#ifdef SIGPROF
#endif
