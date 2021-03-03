#include "config.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <syscall.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tst_test.h"
#include "lapi/syscalls.h"
#include "lapi/membarrier.h"
#define passed_ok(_test)						       \
#define passed_unexpec(_test)						       \
#define failed_ok(_test)						       \
#define failed_ok_unsupported(_test)					       \
#define failed_not_ok(_test, _gotret, _goterr)				       \
#define failed_unexpec(_test, _gotret, _goterr) 			       \
#define skipped(_test)							       \
#define skipped_fail(_test)						       \
