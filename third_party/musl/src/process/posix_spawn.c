#define _GNU_SOURCE
#include <spawn.h>
#include <sched.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <unsupported_api.h>
#include "syscall.h"
#include "pthread_impl.h"
#include "fdop.h"
#ifdef SYS_dup2
#else
#endif
