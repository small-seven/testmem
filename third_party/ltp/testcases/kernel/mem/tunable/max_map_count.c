#define _GNU_SOURCE
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>
#include "mem.h"
#define MAP_COUNT_DEFAULT	1024
#define MAX_MAP_COUNT		65536L
#if defined(__x86_64__) || defined(__x86__)
#elif defined(__ia64__)
#elif defined(__arm__)
#endif
