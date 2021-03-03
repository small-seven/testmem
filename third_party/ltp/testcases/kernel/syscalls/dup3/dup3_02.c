#define _GNU_SOURCE
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include "test.h"
#include "safe_macros.h"
#include "lapi/fcntl.h"
#include "lapi/syscalls.h"
#define INVALID_FLAG	-1
