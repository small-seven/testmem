#define _GNU_SOURCE
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/syscall.h>
#include <linux/unistd.h>
#include "tst_test.h"
#include "lapi/syscalls.h"
#define WINDOW_START 0x48000000
#if defined (__s390__) || (__s390x__) || (__ia64__)
#endif
