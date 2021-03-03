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
#include "inotify.h"
#if defined(HAVE_SYS_INOTIFY_H)
#include <sys/inotify.h>
#define TEARDOWNS 400
#define FILES 5
#else
#endif
