#include "affinity.h"
#include <stdio.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <pthread.h>
#include <sched.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "posixtest.h"
#define ERR_LOG(l, rc)   printf("Failed: %s rc: %d errno: %s\n", \
