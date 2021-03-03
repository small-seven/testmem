#include <stdio.h>
#include <signal.h>
#include <string.h>
#include "posixtest.h"
#define NUMSIGNALS (sizeof(siglist) / sizeof(siglist[0]))
#ifdef SIGPOLL
#endif
#ifdef SIGPROF
#endif
#ifdef DEBUG
#endif
