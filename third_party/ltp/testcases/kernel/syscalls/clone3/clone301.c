#define _GNU_SOURCE
#include <stdlib.h>
#include <sys/wait.h>
#include "tst_test.h"
#include "lapi/clone.h"
#include "lapi/pidfd_send_signal.h"
#define CHILD_SIGNAL	SIGUSR1
#define DATA	777
