#include <time.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "posixtest.h"
#define SIGTOTEST SIGALRM
#define TIMERVALUESEC 2
#define TIMERINTERVALSEC 5
#define INCREMENT 1
#define ACCEPTABLEDELTA 1
#define NUMTESTS 6
