#include "config.h"
#include "tst_test.h"
#ifdef HAVE_LINUX_USERFAULTFD_H
#include <linux/userfaultfd.h>
#include <poll.h>
#include "tst_safe_macros.h"
#include "tst_safe_pthread.h"
#include "lapi/syscalls.h"
#else
#endif
