#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/times.h>
#include <sys/wait.h>
#include <sys/ioctl.h>
#include <sys/syscall.h>
#include <linux/unistd.h>
#include "test.h"		/*LTP Specific Include File */
#define WINDOW_START 0x48000000
#if defined (__s390__) || (__s390x__) || (__ia64__)
#endif
