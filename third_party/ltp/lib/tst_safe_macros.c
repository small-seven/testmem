#define _GNU_SOURCE
#include <unistd.h>
#include <errno.h>
#include <sched.h>
#include <sys/ptrace.h>
#include "config.h"
#ifdef HAVE_SYS_FANOTIFY_H
# include <sys/fanotify.h>
#endif
#define TST_NO_DEFAULT_MAIN
#include "tst_test.h"
#include "lapi/setns.h"
#include "tst_safe_macros.h"
#include "lapi/personality.h"
#ifdef HAVE_SYS_FANOTIFY_H
#else
#endif /* HAVE_SYS_FANOTIFY_H */
