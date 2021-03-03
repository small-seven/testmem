#define _GNU_SOURCE
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include "config.h"
#include "tst_test.h"
#include "lapi/syscalls.h"
#if defined(__NR_readahead)
#else /* __NR_readahead */
#endif
