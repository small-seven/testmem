#define _XOPEN_SOURCE 500
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "test.h"
#include "ipcmsg.h"
#include "../lib/libmsgctl.h"
#define MAXNREPS	1000
#ifndef CONFIG_COLDFIRE
#define MAXNPROCS	 1000000	/* This value is set to an arbitrary high limit. */
#else
#define MAXNPROCS	 100000	/* Coldfire can't deal with 1000000 */
#endif
#define MAXNKIDS	10
#define DEFNKIDS	2
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
