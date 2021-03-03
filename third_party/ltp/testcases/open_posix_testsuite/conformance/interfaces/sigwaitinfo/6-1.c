#define _XOPEN_REALTIME 1
#define SIGTOTEST SIGUSR1
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "posixtest.h"
