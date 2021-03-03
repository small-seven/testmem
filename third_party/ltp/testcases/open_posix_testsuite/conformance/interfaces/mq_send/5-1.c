#include <stdio.h>
#include <mqueue.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <signal.h>
#include <errno.h>
#include "posixtest.h"
#include "mq_send.h"
#define NAMESIZE 50
#define MSGSTR "0123456789"
#define BUFFER 40
#define MAXMSG 5
