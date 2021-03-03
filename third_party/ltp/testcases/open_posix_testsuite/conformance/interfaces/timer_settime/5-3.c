#include <time.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "posixtest.h"
#define SIGTOTEST SIGALRM
#define LONGSLEEPTIME 5
#define NUMTESTS 30
#define SUBTRACTAMOUNT 1000
