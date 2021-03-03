#include <stdio.h>
#include <errno.h>
#include <sched.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "test.h"
#include "safe_macros.h"
#define SCHED_INVALID	99
#define INVALID_PID	999999
