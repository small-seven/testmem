#include <stdio.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "posixtest.h"
#include "helpers.h"
#define TIMERSEC 5
#define CLOCKOFFSET 4
#define SLEEPDELTA 3
#define ACCEPTABLEDELTA 1
#define SHORTTIME 1
#define SIGTOTEST SIGALRM
