#define _XOPEN_REALTIME 1
#define SIGTOTEST SIGRTMIN
#define VALTOTEST 100		/* Application-defined value sent by sigqueue */
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "posixtest.h"
