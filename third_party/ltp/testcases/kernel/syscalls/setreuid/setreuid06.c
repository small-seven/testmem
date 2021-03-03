#include <sys/wait.h>
#include <limits.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>
#include <pwd.h>
#include <sys/param.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "test.h"
#include "safe_macros.h"
#include "compat_16.h"
#define INVAL_USER		 (USHRT_MAX-2)
