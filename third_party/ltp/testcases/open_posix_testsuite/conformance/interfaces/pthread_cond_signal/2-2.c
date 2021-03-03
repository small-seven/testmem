#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <errno.h>
#include "posixtest.h"
#define THREAD_NUM  3
#define TIMEOUT     THREAD_NUM * 2
