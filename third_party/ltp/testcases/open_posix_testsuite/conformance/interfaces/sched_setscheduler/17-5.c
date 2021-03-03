#include <sched.h>
#include <stdio.h>
#include <limits.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include "posixtest.h"
#define ERR_MSG(f, rc)  printf("Failed: %s rc: %d errno: %s\n", \
