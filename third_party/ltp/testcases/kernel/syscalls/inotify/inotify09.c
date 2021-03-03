#include "config.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#include <signal.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <sys/syscall.h>
#include "tst_test.h"
#include "tst_safe_pthread.h"
#include "tst_fuzzy_sync.h"
#include "inotify.h"
#define FNAME "stress_fname"
#if defined(HAVE_SYS_INOTIFY_H)
#include <sys/inotify.h>
#else
#endif
