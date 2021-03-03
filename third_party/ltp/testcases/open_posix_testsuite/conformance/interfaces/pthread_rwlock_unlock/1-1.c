#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "posixtest.h"
#define NOT_CREATED_THREAD 1
#define ENTERED_THREAD 2
#define PASSED_RLOCK1 3
#define PASSED_RLOCK2 4
#define EXITING_THREAD 5
