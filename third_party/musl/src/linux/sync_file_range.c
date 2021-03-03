#define _GNU_SOURCE
#include <fcntl.h>
#include <errno.h>
#include "syscall.h"
#if defined(SYS_sync_file_range2)
#elif defined(SYS_sync_file_range)
#else
#endif
