#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>
#include "posixtest.h"
#include "helpers.h"
#ifndef PR_NSEC_PER_SEC
#define PR_NSEC_PER_SEC 1000000000UL
#endif
#define TESTTIME 1037128358
#define ACCEPTABLEDELTA 1
