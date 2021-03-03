#include "config.h"
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/syscall.h>
#include <limits.h>
#include "tst_test.h"
#include "inotify.h"
#if defined(HAVE_SYS_INOTIFY_H)
#include <sys/inotify.h>
#ifndef IN_MOVE_SELF
#define IN_MOVE_SELF            0x00000800
#endif
#define EVENT_MAX 1024
#define EVENT_SIZE  (sizeof (struct inotify_event))
#define EVENT_BUF_LEN        (EVENT_MAX * (EVENT_SIZE + 16))
#define BUF_SIZE 256
#define FILE_NAME1 "test_file1"
#define FILE_NAME2 "test_file2"
#else
#endif
