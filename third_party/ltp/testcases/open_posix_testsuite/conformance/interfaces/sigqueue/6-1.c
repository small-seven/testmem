#define _XOPEN_REALTIME 1
#define SIGTOTEST SIGRTMIN
#define NUMCALLS 5
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include "posixtest.h"
