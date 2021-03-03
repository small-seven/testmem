#include <stdio.h>
#include <errno.h>
#include <mqueue.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include "posixtest.h"
#define TEST "5-1"
#define FUNCTION "mq_setattr"
#define ERROR_PREFIX "unexpected error: " FUNCTION " " TEST ": "
#define MQFLAGS		1
#define NAMESIZE	50
