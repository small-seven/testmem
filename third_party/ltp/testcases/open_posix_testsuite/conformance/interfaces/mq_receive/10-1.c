#include <stdio.h>
#include <errno.h>
#include <mqueue.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "posixtest.h"
#define TEST "10-1"
#define FUNCTION "mq_receive"
#define ERROR_PREFIX "unexpected error: " FUNCTION " " TEST ": "
#define NAMESIZE 50
#define BUFFER 40
