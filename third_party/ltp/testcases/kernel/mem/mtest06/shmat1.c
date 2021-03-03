#include <stdio.h>		/* definitions for standard I/O               */
#include <unistd.h>		/* required by usleep()                       */
#include <errno.h>		/* definitions for errno                      */
#include <sched.h>		/* definitions for sched_yield()              */
#include <stdlib.h>		/* definitions for WEXIT macros               */
#include <signal.h>		/* required by sigaction & sig handling fncs  */
#include <sys/time.h>		/* definitions of settimer()                  */
#include <sys/wait.h>		/* definitions of itimer structure            */
#include <pthread.h>		/* definitions for pthread_create etc         */
#include <setjmp.h>		/* required by setjmp longjmp                 */
#include <sys/ucontext.h>	/* required by the signal handler             */
#include <sys/ipc.h>		/* required by shmat shmget etc               */
#include <sys/shm.h>		/* required by shmat shmget etc               */
#include <string.h>		/* required by strncmp                        */
#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif
#define prtln() printf(" I AM HERE ==> %s %d\n", __FILE__, __LINE__);
#define STR_SHMAT  "  "
#define STR_WRITER "    "
#define STR_READER "      "
#ifdef __i386__
#endif
#ifdef __i386__
#else
#endif
