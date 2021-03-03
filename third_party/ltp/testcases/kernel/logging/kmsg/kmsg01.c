#define _GNU_SOURCE
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "config.h"
#include "tst_test.h"
#include "lapi/syscalls.h"
#define MSG_PREFIX "LTP kmsg01 "
#define MAX_MSGSIZE 4096
#define NUM_READ_MSGS 3
#define NUM_READ_RETRY 10
#define NUM_OVERWRITE_MSGS 1024
#define PRINTK "/proc/sys/kernel/printk"
#define CONSOLE_LOGLEVEL_QUIET   4
#ifdef SEEK_DATA
#endif
