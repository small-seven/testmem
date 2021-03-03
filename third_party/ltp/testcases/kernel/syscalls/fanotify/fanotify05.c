#define _GNU_SOURCE
#include "config.h"
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/syscall.h>
#include "tst_test.h"
#include "fanotify.h"
#if defined(HAVE_SYS_FANOTIFY_H)
#include <sys/fanotify.h>
#define MOUNT_PATH "fs_mnt"
#define MAX_EVENTS 16384
#define BUF_SIZE 256
#else
#endif
