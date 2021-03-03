#define _GNU_SOURCE
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include "config.h"
#include "test.h"
#include "safe_macros.h"
#include "lapi/syscalls.h"
#define TEST_CASES 6
#ifndef AT_FDCWD
#define AT_FDCWD -100
#endif
#if !defined(HAVE_FSTATAT)
#if (__NR_fstatat64 > 0)
#elif (__NR_newfstatat > 0)
#else
#endif
#endif
#if !defined(HAVE_FSTATAT) && (__NR_fstatat64 > 0)
#else
#endif
