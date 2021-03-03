#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "posixtest.h"
#define ERR_MSG(f, rc) printf("Failed: func: %s rc: %s (%u)\n", \
