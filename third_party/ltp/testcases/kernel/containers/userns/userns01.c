#define _GNU_SOURCE
#include <sys/wait.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "userns_helper.h"
#include "test.h"
#include "config.h"
#if HAVE_SYS_CAPABILITY_H
#include <sys/capability.h>
#endif
#define OVERFLOWUIDPATH "/proc/sys/kernel/overflowuid"
#define OVERFLOWGIDPATH "/proc/sys/kernel/overflowgid"
#ifdef HAVE_LIBCAP
#endif
#ifdef HAVE_LIBCAP
#else
#endif
