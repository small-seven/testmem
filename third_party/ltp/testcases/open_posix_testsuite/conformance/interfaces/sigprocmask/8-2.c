#include <signal.h>
#include <stdio.h>
#include "posixtest.h"
#define NUMSIGNALS (sizeof(siglist) / sizeof(siglist[0]))
#ifdef SIGPOLL
#endif
#ifdef SIGPROF
#endif
