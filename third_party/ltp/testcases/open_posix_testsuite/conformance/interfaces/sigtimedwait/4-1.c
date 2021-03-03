#define _XOPEN_REALTIME 1
#define SIGTOTEST SIGUSR1
#include <sys/wait.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "posixtest.h"
