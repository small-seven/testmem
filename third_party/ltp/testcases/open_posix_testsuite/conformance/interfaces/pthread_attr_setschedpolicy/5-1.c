#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "posixtest.h"
#define ERR_MSG(p, f, rc) printf("Failed: %s function: %s error: %s (%u)\n", \
