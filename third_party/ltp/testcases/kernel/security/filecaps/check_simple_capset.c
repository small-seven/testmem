#include <stdio.h>
#include "config.h"
#if HAVE_SYS_CAPABILITY_H
#include <linux/types.h>
#include <sys/capability.h>
#endif
#ifdef HAVE_LIBCAP
#else
#endif
