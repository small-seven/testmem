#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "posixtest.h"
#define NUMSIGNALS (sizeof(siglist) / sizeof(siglist[0]))
#ifdef SIGPOLL
#endif
#ifdef SIGPROF
#endif
