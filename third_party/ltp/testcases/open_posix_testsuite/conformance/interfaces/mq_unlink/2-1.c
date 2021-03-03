#include <signal.h>
#include <stdio.h>
#include <errno.h>
#include <mqueue.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "posixtest.h"
#define PIPE_READ  0
#define PIPE_WRITE 1
#define TEST "2-1"
#define FUNCTION "mq_unlink"
#define ERROR_PREFIX "unexpected error: " FUNCTION " " TEST ": "
#define NAMESIZE	50
