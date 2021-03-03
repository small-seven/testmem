#define _GNU_SOURCE 1
#include <stdio.h>
#include <sys/types.h>
#include <errno.h>
#include <unistd.h>
#define INVAL_FLAG	-1
#include "test.h"
#define test_sysconf(name) _test_sysconf(name, #name)
#ifdef _SC_2_C_VERSION
#else
#endif
