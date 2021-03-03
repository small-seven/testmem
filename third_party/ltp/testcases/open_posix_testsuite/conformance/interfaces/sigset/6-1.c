#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "posixtest.h"
#define ERR_MSG(f, rc) printf("Failed: func: %s rc: %u errno: %s\n", \
