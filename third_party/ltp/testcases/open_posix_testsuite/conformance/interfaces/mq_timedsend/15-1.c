#include <stdio.h>
#include <mqueue.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>
#include <time.h>
#include <stdlib.h>
#include "posixtest.h"
#define NAMESIZE 50
#define MSGSTR "0123456789"
#define TIMEOUT 5
#define DELTA 1
#define BUFFER 40
#define MAXMSG 5
