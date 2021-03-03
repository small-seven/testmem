#include "config.h"
#include "tst_test.h"
#if defined(HAVE_SYS_USTAT_H) || defined(HAVE_LINUX_TYPES_H)
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "lapi/syscalls.h"
#include "lapi/ustat.h"
#ifndef UCLINUX
#endif
#else
#endif
