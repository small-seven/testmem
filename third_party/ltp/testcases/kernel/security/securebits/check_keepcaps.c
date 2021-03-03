#include <errno.h>
#include "config.h"
#if HAVE_SYS_CAPABILITY_H
#include <linux/types.h>
#include <sys/capability.h>
#endif
#include <sys/prctl.h>
#include "test.h"
#ifndef SECBIT_KEEP_CAPS
#define SECBIT_KEEP_CAPS (1<<4)
#endif
#if (HAVE_LINUX_SECUREBITS_H && HAVE_LIBCAP)
#include <linux/securebits.h>
#define EXPECT_NOPRIVS 0
#define EXPECT_PRIVS 1
#else
#endif /* HAVE_LIBCAP */
