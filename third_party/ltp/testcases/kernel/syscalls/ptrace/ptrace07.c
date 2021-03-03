#include <errno.h>
#include <inttypes.h>
#include <sched.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/uio.h>
#include <sys/wait.h>
#include "config.h"
#include "ptrace.h"
#include "tst_test.h"
#ifndef PTRACE_GETREGSET
# define PTRACE_GETREGSET 0x4204
#endif
#ifndef PTRACE_SETREGSET
# define PTRACE_SETREGSET 0x4205
#endif
#ifndef NT_X86_XSTATE
# define NT_X86_XSTATE 0x202
#endif
#ifdef __x86_64__
#else /* !__x86_64__ */
#endif /* __x86_64__ */
