#include <time.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "posixtest.h"
#define TIMERSEC 2
#define SLEEPDELTA 4
#define ACCEPTABLEDELTA 1
#define CHILDSUCCESS 1
#define CHILDFAILURE 0
