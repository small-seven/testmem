#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <dirent.h>
#include <sys/types.h>
#include <pwd.h>
#include <err.h>
#include "../cpuset_lib/common.h"
#include "../cpuset_lib/bitmask.h"
#define MAX_STRING_SIZE	400
#define MAX_NBITS	1024
#define USAGE  ("Usage : %s [-a|s] list1 [list2]\n"			\
