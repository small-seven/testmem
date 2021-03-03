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
#define MAXNPROCS	10000	/*These should be sufficient */
#define MAXNREPS	10000	/*Else they srewup the system un-necessarily */
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
