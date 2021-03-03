#include <pthread.h>
#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>
#include "posixtest.h"
#define SIGTOTEST SIGABRT
#if 0 && defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
#else
#endif
