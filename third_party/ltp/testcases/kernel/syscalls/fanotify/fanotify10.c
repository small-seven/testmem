#define _GNU_SOURCE
#include "config.h"
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/mount.h>
#include <sys/syscall.h>
#include "tst_test.h"
#include "fanotify.h"
#if defined(HAVE_SYS_FANOTIFY_H)
#include <sys/fanotify.h>
#define EVENT_MAX 1024
#define EVENT_SIZE  (sizeof (struct fanotify_event_metadata))
#define EVENT_BUF_LEN        (EVENT_MAX * EVENT_SIZE)
#define FANOTIFY_PRIORITIES ARRAY_SIZE(fanotify_prio)
#define GROUPS_PER_PRIO 3
#define MOUNT_PATH "fs_mnt"
#define MNT2_PATH "mntpoint"
#define FILE_NAME "testfile"
#define FILE2_NAME "testfile2"
#define TEST_APP "fanotify_child"
#define TEST_APP2 "fanotify_child2"
#define FILE_PATH MOUNT_PATH"/"FILE_NAME
#define FILE2_PATH MOUNT_PATH"/"FILE2_NAME
#define FILE_EXEC_PATH MOUNT_PATH"/"TEST_APP
#define FILE2_EXEC_PATH MOUNT_PATH"/"TEST_APP2
#define FILE_MNT2 MNT2_PATH"/"FILE_NAME
#define FILE2_MNT2 MNT2_PATH"/"FILE2_NAME
#define FILE_EXEC_PATH2 MNT2_PATH"/"TEST_APP
#define FILE2_EXEC_PATH2 MNT2_PATH"/"TEST_APP2
#else
#endif
