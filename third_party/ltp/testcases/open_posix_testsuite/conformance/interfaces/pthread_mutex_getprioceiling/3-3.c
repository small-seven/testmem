#include <pthread.h>
#include <errno.h>
#include <pwd.h>
#include <sched.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "posixtest.h"
#if defined(_SC_PRIORITY_SCHEDULING)
#else
#endif
