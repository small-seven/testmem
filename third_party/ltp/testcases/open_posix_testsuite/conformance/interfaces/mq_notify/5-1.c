#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <mqueue.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include "posixtest.h"
#define TEST "5-1"
#define FUNCTION "mq_notify"
#define ERROR_PREFIX "unexpected error: " FUNCTION " " TEST ": "
#define NAMESIZE	50
#define MSG_SIZE	40
#define BUFFER 40
