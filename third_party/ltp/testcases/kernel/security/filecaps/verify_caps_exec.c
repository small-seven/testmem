#include <stdio.h>
#include <unistd.h>
#include <endian.h>
#include <byteswap.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>
#include "config.h"
#if HAVE_SYS_CAPABILITY_H
#include <linux/types.h>
#include <sys/capability.h>
#endif
#include <sys/prctl.h>
#include "test.h"
#include "filecaps_common.h"
#define TSTPATH "print_caps"
#define DROP_PERMS 0
#define KEEP_PERMS 1
#ifdef HAVE_LIBCAP
#if HAVE_DECL_PR_CAPBSET_READ
#else
#endif
#endif
#ifdef HAVE_LIBCAP
#else
#endif
