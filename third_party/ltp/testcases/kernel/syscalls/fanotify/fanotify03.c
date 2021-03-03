#define _GNU_SOURCE
#include "config.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <sys/syscall.h>
#include <stdlib.h>
#include "tst_test.h"
#include "fanotify.h"
#if defined(HAVE_SYS_FANOTIFY_H)
#include <sys/fanotify.h>
#define EVENT_MAX 1024
#define EVENT_SIZE  (sizeof (struct fanotify_event_metadata))
#define EVENT_BUF_LEN        (EVENT_MAX * EVENT_SIZE)
#define EVENT_SET_MAX 16
#define BUF_SIZE 256
#define TST_TOTAL 3
#define TEST_APP "fanotify_child"
#define MOUNT_PATH "fs_mnt"
#define FILE_EXEC_PATH MOUNT_PATH"/"TEST_APP
#else
#endif
