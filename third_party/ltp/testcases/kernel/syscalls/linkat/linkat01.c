#define _GNU_SOURCE
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <inttypes.h>
#include <limits.h>
#include "test.h"
#include "lapi/syscalls.h"
#include "safe_macros.h"
#ifndef AT_FDCWD
#define AT_FDCWD -100
#endif
#ifndef AT_SYMLINK_FOLLOW
#define AT_SYMLINK_FOLLOW 0x400
#endif
#define TEST_DIR1 "olddir"
#define TEST_DIR2 "newdir"
#define TEST_DIR3 "deldir"
#define TEST_FILE1 "oldfile"
#define TEST_FILE2 "newfile"
#define TEST_FIFO "fifo"
#define DPATHNAME_FMT	"%s/" TEST_DIR2 "/" TEST_FILE1
#define SPATHNAME_FMT	"%s/" TEST_DIR1 "/" TEST_FILE1
