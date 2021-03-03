#include <errno.h>
#include <pwd.h>
#include <sys/types.h>
#include <unistd.h>
#include <linux/unistd.h>
#include <sys/syscall.h>
#include "test.h"
#include "safe_macros.h"
#define UNEXP_RET_VAL	-1
#define syslog(arg1, arg2, arg3) syscall(__NR_syslog, arg1, arg2, arg3)
