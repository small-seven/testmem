#include "config.h"
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/syscall.h>
#include "tst_test.h"
#include "inotify.h"
#if defined(HAVE_SYS_INOTIFY_H)
#include <sys/inotify.h>
#define EVENT_SIZE  (sizeof(struct inotify_event))
#define EVENT_BUF_LEN (EVENT_SIZE * 16)
#define BUF_SIZE 256
#else
#endif
