#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <sys/syscall.h>
#include <string.h>
#include "test.h"
#include "lapi/syscalls.h"
#include "lapi/rt_sigaction.h"
#define INVAL_SIGSETSIZE -1
