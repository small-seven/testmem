#include <errno.h>
#include <signal.h>
#include <sys/prctl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <linux/filter.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include "tst_test.h"
#include "lapi/syscalls.h"
#include "lapi/prctl.h"
#include "config.h"
#include "lapi/seccomp.h"
#define FNAME "filename"
