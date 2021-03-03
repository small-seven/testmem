#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <errno.h>
#include <pwd.h>
#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "test.h"
#include "safe_macros.h"
#define TEST_SIG SIGKILL
#ifdef UCLINUX
#endif
#ifdef UCLINUX
#else
#endif
