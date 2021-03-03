#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#include <errno.h>
#include <poll.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "lapi/syscalls.h"
#include "ltp_signal.h"
#include "tst_sig_proc.h"
#include "tst_test.h"
#ifndef POLLRDHUP
#define POLLRDHUP 0x2000
#endif
#define TYPE_NAME(x) .ttype = x, .desc = #x
