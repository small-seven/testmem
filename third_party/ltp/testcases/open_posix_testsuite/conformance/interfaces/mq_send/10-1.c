#include <stdio.h>
#include <mqueue.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>
#include "posixtest.h"
#define NAMESIZE 50
#define MESSAGESIZE 50
#define BUFFER 40
#define MAXMSG 10
