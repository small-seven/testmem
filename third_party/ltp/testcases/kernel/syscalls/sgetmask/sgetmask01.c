# Sometime the returned "Oops"in this case don't mean anything for
# correct or error, we check the result between different kernel and
# try to find if there exist different returned code in different kernel
#
#include <stdio.h>
#include <signal.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include "test.h"
#include "lapi/syscalls.h"
