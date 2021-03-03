#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include "test.h"
#include "lapi/syscalls.h"
#include "lapi/rt_sigaction.h"
#define TEST_SIG SIGRTMIN+1
