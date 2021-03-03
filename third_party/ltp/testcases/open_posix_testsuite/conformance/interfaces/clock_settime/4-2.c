#include <stdio.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "posixtest.h"
#include "helpers.h"
#define TIMEROFFSET 9
#define CLOCKOFFSET 4
#define SHORTTIME 1
#define SIGTOTEST SIGALRM
