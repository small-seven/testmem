#define _GNU_SOURCE
#include <err.h>
#include <pthread.h>
#include "tst_safe_pthread.h"
#include "tst_test.h"
#include "lapi/syscalls.h"
#ifndef __ANDROID__
#define SI_SIGVAL si_sigval
#else
#define SI_SIGVAL _sigval
#endif
