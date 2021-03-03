#include <errno.h>
#include "config.h"
#if HAVE_SYS_CAPABILITY_H
#include <linux/types.h>
#include <sys/capability.h>
#endif
#include <sys/prctl.h>
#include <unistd.h>
#include "test.h"
#define PROC_CAP_LAST "/proc/sys/kernel/cap_last_cap"
#ifdef HAVE_LIBCAP
#if HAVE_DECL_PR_CAPBSET_READ
#else
#endif
#if HAVE_DECL_PR_CAPBSET_READ
#else
#endif
#define INSANE 63
#define max(x,y) (x > y ? x : y)
#if HAVE_DECL_PR_CAPBSET_READ
#else
#endif
#else
#endif
