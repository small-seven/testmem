#define _GNU_SOURCE
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include "test.h"
#include "safe_macros.h"
#include "lapi/syscalls.h"
#define TEST_CASES 7
#ifndef AT_FDCWD
#define AT_FDCWD -100
#endif
#ifndef AT_REMOVEDIR
#define AT_REMOVEDIR 0x200
#endif
