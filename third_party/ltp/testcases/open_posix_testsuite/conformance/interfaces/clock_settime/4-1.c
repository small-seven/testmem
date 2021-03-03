#include <stdio.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include "posixtest.h"
#include "helpers.h"
#define SLEEPTIME 3
#define TIMEROFFSET 9
#define ACCEPTABLEDELTA 1
#define SIGTOTEST SIGALRM
