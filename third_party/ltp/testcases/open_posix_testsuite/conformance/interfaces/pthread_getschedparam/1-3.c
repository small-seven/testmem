#include <pthread.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sched.h>
#include <errno.h>
#include <posixtest.h>
#define ERR_MSG(f, rc)  printf("Failed: line: %d func: %s rc: %s (%u)\n", \
