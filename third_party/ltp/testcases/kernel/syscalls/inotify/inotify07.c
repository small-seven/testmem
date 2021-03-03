#include "config.h"
#if defined(HAVE_SYS_INOTIFY_H)
# include <sys/inotify.h>
#endif
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/syscall.h>
#include <sys/mount.h>
#include <limits.h>
#include "tst_test.h"
#include "inotify.h"
#if defined(HAVE_SYS_INOTIFY_H)
#define EVENT_MAX 1024
#define EVENT_SIZE  (sizeof (struct inotify_event))
#define EVENT_BUF_LEN        (EVENT_MAX * (EVENT_SIZE + 16))
#define BUF_SIZE 256
#define DIR_NAME "test_dir"
#define DIR_PATH OVL_MNT"/"DIR_NAME
#define FILE_NAME "test_file"
#define FILE_PATH OVL_MNT"/"DIR_NAME"/"FILE_NAME
#else
#endif
