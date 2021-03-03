#include <stdio.h>
#include <mqueue.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include "posixtest.h"
#define TEST "2-1"
#define FUNCTION "mq_getattr"
#define ERROR_PREFIX "unexpected error: " FUNCTION " " TEST ": "
#define NAMESIZE	50
#define MQFLAGS		O_NONBLOCK
