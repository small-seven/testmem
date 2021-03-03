#define _GNU_SOURCE
#include "config.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/fcntl.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <sys/syscall.h>
#include "tst_test.h"
#include "lapi/syscalls.h"
#include "fanotify.h"
#if defined(HAVE_SYS_FANOTIFY_H)
#include <sys/fanotify.h>
#define BUF_SIZE 256
#define MAX_CHILDREN 16
#define MAX_NOT_RESPONDED 4
#else
#endif
