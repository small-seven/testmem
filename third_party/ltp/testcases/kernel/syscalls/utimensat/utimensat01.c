#define _GNU_SOURCE
#define _ATFILE_SOURCE
#include <stdio.h>
#include <time.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include "test.h"
#include "lapi/syscalls.h"
#define cleanup tst_exit
#ifndef AT_FDCWD
#define AT_FDCWD -100
#endif
#ifndef AT_SYMLINK_NOFOLLOW
#define AT_SYMLINK_NOFOLLOW 0x100
#endif
#define EXIT_bad_usage 3
#define EXIT_failed_syscall 3
#define errExit(msg)    do { perror(msg); exit(EXIT_failed_syscall); \
#define UTIME_NOW      ((1l << 30) - 1l)
#define UTIME_OMIT     ((1l << 30) - 2l)
