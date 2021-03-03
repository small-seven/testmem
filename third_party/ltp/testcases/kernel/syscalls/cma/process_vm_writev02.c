#define _GNU_SOURCE
#include <sys/types.h>
#include <sys/uio.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include "test.h"
#include "safe_macros.h"
#include "lapi/syscalls.h"
#define PADDING_SIZE 10
#define DEFAULT_CHAR 53
#if DEBUG
#endif
