#define _GNU_SOURCE
#include <stdio.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/mount.h>
#include <linux/limits.h>
#include <errno.h>
#include <linux/unistd.h>
#include "lapi/mkdirat.h"
#include "tst_safe_pthread.h"
#include "tst_safe_stdio.h"
#include "tst_test.h"
#define gettid() syscall(__NR_gettid)
