#include <time.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "posixtest.h"
#define SIGTOTEST SIGALRM
#define DATEINPAST 1037128358	//Nov 13, 2002 ~11:13am
#define LONGSLEEPTIME 10
