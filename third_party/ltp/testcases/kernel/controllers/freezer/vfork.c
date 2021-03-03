#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include "test.h"
#include "config.h"
#include "../../syscalls/ptrace/ptrace.h"
#define str_expand(s) str(s)
#define str(s) #s
#define debug(s) \
#if HAVE_DECL_PTRACE_GETSIGINFO
#else
#endif
#if HAVE_DECL_PTRACE_SETOPTIONS && HAVE_DECL_PTRACE_O_TRACEVFORKDONE
#else
#endif
