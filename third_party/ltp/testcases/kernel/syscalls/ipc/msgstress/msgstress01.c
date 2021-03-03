#define _XOPEN_SOURCE 500
#include <signal.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <values.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "test.h"
#include "ipcmsg.h"
#include "../lib/libmsgctl.h"
#ifndef CONFIG_COLDFIRE
#define MAXNPROCS	1000000	/* This value is set to an arbitrary high limit. */
#else
#define MAXNPROCS	 100000	/* Coldfire can't deal with 1000000 */
#endif
#define MAXNREPS	100000
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
