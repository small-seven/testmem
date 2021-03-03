#include <sys/mman.h>
#include <ctype.h>
#include <errno.h>
#include <signal.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#ifndef _LINUX
#include <sys/mode.h>
#include <sys/timers.h>
#else
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/ipc.h>
#endif
#include <sys/msg.h>
#include <sys/resource.h>
#include <sys/select.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "lapi/semun.h"
#define ADBG 0
#define BNDX 1
#define DNDX 2
#define TNDX 3
#define MAXBVAL 70
#define MAXDVAL 11
#define SLOTDIR "./slot/"
#ifdef _LINUX
#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif
#endif
#if defined _LINUX && defined DEBUG
#define prtln()	printf("At line number: %d\n", __LINE__); \
#define dprt(fmt, args...) printf(fmt, ## args)
#else
#define prtln()
#define dprt(fmt, args...)
#endif
#define    AUSDEBUG  (*edat[ADBG].eval.vint)	/* debug value */
#define    BVAL  (*edat[BNDX].eval.vint)	/* # of childern per parent */
#define    DVAL  (*edat[DNDX].eval.vint)	/* depth of process tree */
#define    TVAL  (*edat[TNDX].eval.vint)	/* timer value */
#ifdef _LINUX
typedef long mtyp_t;
#endif

/* structure of information stored about each process in shared memory */
typedef struct proc_info {
#ifdef __64LDT__
	pid_t pid;		/* process id */
	pid_t ppid;		/* parent process id */
#else
	int pid;		/* process id */
	int ppid;		/* parent process id */
#endif
	int msg;		/* parent process id */
	int err;		/* error indicator */
	int *list;		/* pointer to list of parent and sibling slot locations */
} Pinfo;
typedef struct messagebuf {
	mtyp_t mtyp;		/* message type */
	char mtext[80];		/* message text */
} Msgbuf;
#ifndef _LINUX
#else
#define errfp stderr
#define debugfp stderr
#endif
#ifndef _LINUX
#endif
#ifdef __64LDT__
#else
#endif
#ifdef __64LDT__
#else
#endif
#ifdef __64LDT__
#else
#endif
#ifdef __64LDT__
#else
#endif
#ifdef __64LDT__
#else
#endif
#ifdef _LINUX
#else
#endif
#ifdef _LINUX
#else
#endif
#ifdef _LINUX
#else
#endif
#ifndef _LINUX
#else
#endif
#ifdef __64LDT__
#else
#endif
#ifndef _LINUX
#else
#endif
#ifdef __64LDT__
#else
#endif
#ifdef _LINUX
#endif
