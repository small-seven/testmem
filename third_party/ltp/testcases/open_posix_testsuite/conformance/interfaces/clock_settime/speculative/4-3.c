#include <stdio.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "posixtest.h"
#include "../helpers.h"
#define TIMEROFFSET 3
#define TIMERINTERVAL 5
#define EXPECTEDOVERRUNS 3
#define SHORTTIME 1
#define SIGTOTEST SIGALRM
