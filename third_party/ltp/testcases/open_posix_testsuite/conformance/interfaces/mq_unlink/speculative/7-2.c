#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <mqueue.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "posixtest.h"
#define TEST "7-2"
#define FUNCTION "mq_unlink"
