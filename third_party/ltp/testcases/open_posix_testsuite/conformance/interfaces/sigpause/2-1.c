#include <pthread.h>
#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>
#include "posixtest.h"
#define SIGTOTEST SIGABRT
#define INMAIN 0
#define INTHREAD 1
