#include <unistd.h>
#include <math.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
#include <sys/syscall.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <unistd.h>
#include "../libcontrollers/libcontrollers.h"
#include "test.h"		/* LTP harness APIs */
#include "safe_macros.h"
#define TIME_INTERVAL	30	/* Time interval in seconds */
#define NUM_INTERVALS	3	/* How many iterations of TIME_INTERVAL */
