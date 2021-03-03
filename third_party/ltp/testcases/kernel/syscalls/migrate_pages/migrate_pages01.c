#include <sys/types.h>
#include <sys/syscall.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>
#include "test.h"
#include "safe_macros.h"
#include "lapi/syscalls.h"
#include "numa_helper.h"
#include "migrate_pages_common.h"
#ifdef HAVE_NUMA_V2
#else
#endif
