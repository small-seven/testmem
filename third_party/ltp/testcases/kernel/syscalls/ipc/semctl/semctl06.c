#define DEBUG 0
#ifdef UCLINUX
#define _GNU_SOURCE
#include <stdio.h>
#endif
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <signal.h>
#include "test.h"
#include <sys/wait.h>
#include "ipcsem.h"
#define NREPS	500
#define NPROCS	3
#define NKIDS	5
#define NSEMS	5
#define HVAL	1000
#define LVAL	100
#define FAILED	0
