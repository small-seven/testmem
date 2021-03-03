#include <stdio.h>
#include <errno.h>
#include <pthread.h>
#include <semaphore.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>
#include "../testfrmw/testfrmw.h"
#include "../testfrmw/testfrmw.c"
#include "../testfrmw/threads_scenarii.c"
#include "safe_helpers.h"
#define RUN_TIME_USEC (2*1000*1000)
#define SIGNALS_WITHOUT_DELAY 100
