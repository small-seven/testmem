#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <errno.h>
#include <posixtest.h>
#define ERR_MSG(f, rc)	printf("Failed: function: %s status: %s(%u)\n", \
