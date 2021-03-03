#include <signal.h>
#include <stdio.h>
#include <mqueue.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include "posixtest.h"
#define TEST "2-1"
#define FUNCTION "mq_close"
#define ERROR_PREFIX "unexpected error: " FUNCTION " " TEST ": "
#define PIPE_READ  0
#define PIPE_WRITE 1
