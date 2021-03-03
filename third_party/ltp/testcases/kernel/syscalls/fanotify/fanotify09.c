#define _GNU_SOURCE
#include "config.h"
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/mount.h>
#include <sys/syscall.h>
#include <stdint.h>
#include "tst_test.h"
#include "fanotify.h"
#if defined(HAVE_SYS_FANOTIFY_H)
#include <sys/fanotify.h>
#define EVENT_MAX 1024
#define EVENT_SIZE  (sizeof (struct fanotify_event_metadata))
#define EVENT_BUF_LEN        (EVENT_MAX * EVENT_SIZE)
#define NUM_GROUPS 3
#define BUF_SIZE 256
#define MOUNT_NAME "mntpoint"
#define DIR_NAME "testdir"
#else
#endif
