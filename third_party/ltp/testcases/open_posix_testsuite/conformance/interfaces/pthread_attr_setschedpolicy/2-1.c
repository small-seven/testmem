#include "affinity.h"
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <posixtest.h>
#define PRIO_HIGH	20
#define PRIO_MED	10
#define PRIO_LOW	5
#define PRIO_MAIN	1
#define FAIL_AND_EXIT(f, rc) { \
