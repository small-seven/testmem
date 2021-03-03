#define _GNU_SOURCE
#include "config.h"
#include <stdio.h>
#include <string.h>
#include <sys/statfs.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include "tst_test.h"
#include "fanotify.h"
#if defined(HAVE_SYS_FANOTIFY_H)
#include <sys/fanotify.h>
#define PATH_LEN 128
#define BUF_SIZE 256
#define DIR_ONE "dir_one"
#define FILE_ONE "file_one"
#define FILE_TWO "file_two"
#define MOUNT_PATH "mntpoint"
#define EVENT_MAX ARRAY_SIZE(objects)
#define DIR_PATH_ONE MOUNT_PATH"/"DIR_ONE
#define FILE_PATH_ONE MOUNT_PATH"/"FILE_ONE
#define FILE_PATH_TWO MOUNT_PATH"/"FILE_TWO
#if defined(HAVE_NAME_TO_HANDLE_AT)
#else
#endif
#else
#endif
