#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "test.h"
#include "safe_macros.h"
#ifdef __linux__
#endif
#define SIGCANCEL 32
#define SIGTIMER 33
#define TRUE  1
#define FALSE 0
#ifndef DEBUG
#define DEBUG 0
#endif
#define CHILD_EXIT(VAL) ((VAL >> 8) & 0377)	/* exit value of child process */
#define CHILD_SIG(VAL)   (VAL & 0377)	/* signal value of child proc */
#define MAXMESG 512		/* the size of the message string */
#define READY "ready"		/* signal to parent that child is set up */
#define TIMEOUT 30		/* time (sec) used in the alarm calls */
#define EXIT_OK    0
#define SIG_CAUGHT 8
#define WRITE_BROK 16
#define HANDLE_ERR 32
#ifndef NUMSIGS
#define NUMSIGS NSIG
#endif
#ifdef UCLINUX
#endif
#ifdef UCLINUX
#else
#endif
#if DEBUG > 1
#endif
#if DEBUG > 0
#endif
#if DEBUG > 0
#endif
#if DEBUG > 1
#endif
#if DEBUG > 1
#endif
#if DEBUG > 0
#endif
#if DEBUG > 0
#endif
#if DEBUG > 0
#endif
#if DEBUG > 0
#endif
#ifdef VAX
#endif
#ifdef SIGNOBDM
#endif
#ifdef SIGTTIN
#endif
#ifdef SIGTTOU
#endif
#ifdef  SIGPTINTR
#endif
#ifdef  SIGSWAP
#endif
