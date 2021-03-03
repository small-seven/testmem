#define _GNU_SOURCE
#include <pwd.h>
#include <signal.h>
#include "lapi/pidfd_send_signal.h"
#include "tst_safe_pthread.h"
#define CORRECT_SIGNAL		SIGUSR1
#define DIFFERENT_SIGNAL	SIGUSR2
