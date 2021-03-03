#define _GNU_SOURCE
#include <sys/syscall.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <setjmp.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "test.h"
#define MAX_TRY_TIME 5
#ifdef DEBUG_LATE_BADBOY
#else
#endif
#if 0
#endif
#define STATUS_MAX 256
#ifdef SIGTRAP
#endif
#ifdef SIGBUS
#endif
#ifdef SIGIOT
#endif
#ifdef SIGEMT
#endif
#ifdef SIGALRM
#endif
#ifdef SIGTRAP
#endif
#ifdef SIGBUS
#endif
#ifdef SIGIOT
#endif
#ifdef SIGEMT
#endif
#ifdef SIGALRM
#endif
#if defined(__ia64__)
#else
#if defined(__NR_vfork) && __NR_vfork
#elif defined(__NR_fork) && __NR_fork
#endif
#endif /* __ia64__ */
#if defined(__NR_clone) && __NR_clone
#endif
#if defined(__NR_vhangup) && __NR_vhangup
#endif
