#define _XOPEN_REALTIME 1
#define TIMERSIGNAL SIGUSR1
#define SIGTOTEST SIGUSR2
#define TIMERSEC 2
#define SIGTIMEDWAITSEC 0
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#include "posixtest.h"
