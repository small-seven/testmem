#include "config.h"
#include <stdio.h>
#include <sys/mount.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/syscall.h>
#include <signal.h>
#include "tst_test.h"
#include "inotify.h"
#if defined(HAVE_SYS_INOTIFY_H)
#include <sys/inotify.h>
#define EVENT_MAX 1024
#define EVENT_SIZE (sizeof(struct inotify_event))
#define EVENT_BUF_LEN		(EVENT_MAX * (EVENT_SIZE + 16))
#define BUF_SIZE 1024
#define DIR_MODE	(S_IRWXU | S_IRUSR | S_IXUSR | S_IRGRP | S_IXGRP)
#else
#endif
