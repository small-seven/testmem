#include "test.h"
#include <signal.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#define TEST_SIG SIGKILL
#ifdef UCLINUX
#endif
#ifdef UCLINUX
#else
#endif
