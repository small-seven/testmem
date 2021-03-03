#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "posixtest.h"
#include <sched.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "proc.h"
#define TEST "sem_post_8-1"
#ifndef _POSIX_PRIORITY_SCHEDULING
#endif
