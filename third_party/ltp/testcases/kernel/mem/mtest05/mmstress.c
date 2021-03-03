#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <pthread.h>
#include <signal.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sched.h>
#include <stdint.h>
#include <getopt.h>
#include "test.h"
#define SIGENDSIG    -1		/* end of signal marker                             */
#define THNUM        0		/* array element pointing to number of threads      */
#define MAPADDR      1		/* array element pointing to map address            */
#define PAGESIZ      2		/* array element pointing to page size              */
#define FLTIPE       3		/* array element pointing to fault type             */
#define READ_FAULT   0		/* instructs routine to simulate read fault         */
#define WRITE_FAULT  1		/* instructs routine to simulate write fault        */
#define COW_FAULT    2		/* instructs routine to simulate copy-on-write fault */
#define NUMTHREAD    32		/* number of threads to spawn default to 32         */
#define NUMPAGES     9999	/* default (random) value of number of pages        */
#ifndef TRUE
#define TRUE         1
#endif
#ifndef FALSE
#define FALSE        0
#endif
#define FAILED       (-1)	/* return status for all funcs indicating failure   */
#define SUCCESS      0		/* return status for all routines indicating success */
#define BRKSZ        512*1024	/* program data space allocation value          */
