#include <fcntl.h>
#include <limits.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/timeb.h>
#include <unistd.h>
#include <string.h>
#ifdef DEBUG			/* compile with this flag for debug, use dprt in code */
#define dprt    printf
#else
#define dprt    noprintf
#endif
#ifndef PID_MAX
#define PID_MAX 0x8000
#endif
#define MAXT 100
#ifdef PTHREAD_THREADS_MAX
#define PIDS PTHREAD_THREADS_MAX	/* maximum thread allowed.                     */
#elif defined(PID_MAX_DEFAULT)
#define PIDS PID_MAX_DEFAULT	/* maximum pids allowed.                       */
#else
#define PIDS PID_MAX		/* alternative way maximum pids may be defined */
#endif
#define UP   1			/* assume UP if no SMP value is specified.     */
#define OPT_MISSING(prog, opt)   do{\
#define SAFE_FREE(p) { if (p) { free(p); (p)=NULL; } }
typedef struct {		/* contains priority and CPU info of the task.        */
	int exp_prio;		/* priority that we wish to set.                      */
	int act_prio;		/* priority set by the scheduler.                     */
	int proc_num;		/* last processor on which this task executed.        */
	int procs_id;		/* pid of this task.                                  */
	int s_policy;		/* scheduling policy for the task.                    */
} thread_sched_t;
