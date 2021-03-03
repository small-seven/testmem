#define _GNU_SOURCE
#include "config.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <pthread.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/limits.h>
#include "tst_test.h"
#include "tst_safe_pthread.h"
#include "fanotify.h"
#if defined(HAVE_SYS_FANOTIFY_H)
#include <sys/fanotify.h>
#define gettid() syscall(SYS_gettid)
#else
#endif
