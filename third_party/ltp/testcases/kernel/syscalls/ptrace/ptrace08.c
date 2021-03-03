#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include <signal.h>
#include "tst_test.h"
#include "tst_safe_stdio.h"
#if defined(__i386__) || defined(__x86_64__)
#define SYMNAME_SIZE 256
#define KERNEL_SYM "do_debug"
#else
#endif
