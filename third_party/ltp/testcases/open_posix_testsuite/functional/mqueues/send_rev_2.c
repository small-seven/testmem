#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <string.h>
#include <getopt.h>
#include <pthread.h>
#include <limits.h>
#include <mqueue.h>
#include "posixtest.h"
#define MQ_NAME_1       "/testmsg1"
#define MQ_NAME_2       "/testmsg2"
#define MSG_SIZE	128
#define MAX_MSG		3
