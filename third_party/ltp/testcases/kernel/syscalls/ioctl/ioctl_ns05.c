#define _GNU_SOURCE
#include <errno.h>
#include <stdio.h>
#include <sched.h>
#include <stdlib.h>
#include "tst_test.h"
#include "lapi/ioctl_ns.h"
#include "lapi/namespaces_constants.h"
#define STACK_SIZE (1024 * 1024)
