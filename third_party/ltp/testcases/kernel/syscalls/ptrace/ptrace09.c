#include <stdlib.h>
#include <stddef.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include <signal.h>
#include "tst_test.h"
#if defined(__i386__) || defined(__x86_64__)
#else
#endif
