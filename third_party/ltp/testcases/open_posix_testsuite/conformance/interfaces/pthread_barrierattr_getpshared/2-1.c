#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include "posixtest.h"
#define LOOP_NUM 10
#ifndef PTHREAD_PROCESS_SHARED
#endif
