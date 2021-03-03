#define _GNU_SOURCE
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "lapi/pidfd_send_signal.h"
#include "tst_safe_pthread.h"
#define PIDTRIES	3
