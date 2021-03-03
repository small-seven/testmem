#define SIGTOTEST SIGUSR1
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "posixtest.h"
#if __FreeBSD__ || __NetBSD__ || __OpenBSD__
#else
#endif
