#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sem.h>
#include <errno.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include "lapi/semun.h"
#include "test.h"
#define KEY IPC_PRIVATE
#define NUMTHREADS 2
