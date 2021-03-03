#define _GNU_SOURCE
#include <signal.h>
#include <stdlib.h>
#include "lapi/pidfd_send_signal.h"
#include "tst_safe_pthread.h"
#define SIGNAL  SIGUSR1
#define DATA	777
