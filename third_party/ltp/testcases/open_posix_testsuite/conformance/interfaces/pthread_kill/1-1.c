#include <pthread.h>
#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>
#include "posixtest.h"
#define INTHREAD 0
#define INMAIN 1
#define SIGTOTEST SIGABRT
