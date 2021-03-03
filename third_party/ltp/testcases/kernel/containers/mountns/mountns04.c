#define _GNU_SOURCE
#include <sys/wait.h>
#include <sys/mount.h>
#include <stdio.h>
#include <errno.h>
#include "mountns_helper.h"
#include "test.h"
#include "safe_macros.h"
#if defined(MS_SHARED) && defined(MS_PRIVATE) \
#else
#endif
