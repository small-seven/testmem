#include <stdio.h>
#include <mqueue.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include "posixtest.h"
#define TEST "2-1"
#define FUNCTION "mq_setattr"
#define NAMESIZE	50
#define MQFLAGS		0
#define MQMAXMSG	666
#define MQMSGSIZE	777
#define MQCURMSGS	555
