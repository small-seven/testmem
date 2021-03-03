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
#include "tst_test.h"
#include "fanotify.h"
#if defined(HAVE_SYS_FANOTIFY_H)
#include <sys/fanotify.h>
#include <sys/inotify.h>
#define EVENT_MAX 10
#define EVENT_SIZE (sizeof(struct fanotify_event_metadata) + \
#define EVENT_BUF_LEN (EVENT_MAX * EVENT_SIZE * 3)
#define BUF_SIZE 256
#ifdef HAVE_NAME_TO_HANDLE_AT
#define DIR_NAME1 "test_dir1"
#define DIR_NAME2 "test_dir2"
#define FILE_NAME1 "test_file1"
#define FILE_NAME2 "test_file2"
#define MOUNT_PATH "fs_mnt"
#else
#endif
#else
#endif
