#include <stdio.h>
#include <mqueue.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdint.h>
#include <limits.h>
#include "posixtest.h"
#define NAMESIZE 50
#ifndef _POSIX_OPEN_MAX
#else
#ifndef _POSIX_MQ_OPEN_MAX
#else
#endif
#endif
