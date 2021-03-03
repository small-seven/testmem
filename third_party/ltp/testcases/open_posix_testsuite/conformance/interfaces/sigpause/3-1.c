#include <pthread.h>
#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>
#include "posixtest.h"
#define SIGTOTEST SIGABRT
#define INTHREAD 0
#define INMAIN 1
