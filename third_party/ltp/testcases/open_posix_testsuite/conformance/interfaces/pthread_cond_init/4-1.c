#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/resource.h>
#include <stdarg.h>
#include <posixtest.h>
#define ERR_MSG(f, rc) printf("Failed: func: %s rc: %s (%u)\n", \
#define MAX_MEM	((1<<20))
