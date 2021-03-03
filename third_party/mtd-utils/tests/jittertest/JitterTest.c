#include <stdio.h>      /* fopen, printf, fprintf, fclose */
#include <string.h>     /* strcpy, strcmp */
#include <stdlib.h>     /* exit, atol, atoi */
#include <sys/time.h>   /* setitimer, settimeofday, gettimeofday */
#include <time.h>	/* time */
#include <signal.h>     /* signal */
#include <sched.h>      /* sched_setscheduler, sched_get_priority_min,*/
#include <unistd.h>     /* gettimeofday, sleep */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#define PROGRAM_NAME "JitterTest"
#include "common.h"
#define EXIT_FILE_OPEN_ERR        (1)     /* error opening output file*/
#define EXIT_REG_SIGALRM_ERR      (2)     /* error registering SIGALRM*/
#define EXIT_REG_SIGINT_ERR       (3)     /* error registering SIGINT */
#define EXIT_INV_INT_PERIOD       (4)     /* error invalid int. period*/
#define EXIT_MIN_PRIORITY_ERR     (5)     /* error, minimum priority  */
#define EXIT_MAX_PRIORITY_ERR     (6)     /* error, maximum priority  */
#define EXIT_INV_SCHED_PRIORITY   (7)     /* error, invalid priority  */
#define EXIT_SET_SCHEDULER_ERR    (8)     /* error, set scheduler     */
#define EXIT_PREV_TIME_OF_DAY_ERR (9)     /* error, init. prev.       */
#define MAX_FILE_NAME_LEN         (32)    /* maximum file name length */
#define STRINGS_EQUAL             ((int) 0) /* strcmp value if equal  */
#define MIN_INT_PERIOD_MILLISEC   (   5L) /* minimum interrupt period */
#define MAX_INT_PERIOD_MILLISEC   (5000L) /* maximum interrupt period */
#define DEF_INT_PERIOD_MILLISEC   (  10L) /* default interrupt period */
#define READ_FILE_MESSAGE "This is a junk file. Must contain at least 1 byte though!\n"
#define MIN_WRITE_BYTES     30
#define DEFAULT_WRITE_BYTES 30
#define MAX_WRITE_BYTES 4096
#define MIN_ASCII 32     /* <SPACE> can be char*/
#define MAX_ASCII 126.0 /* needs to be float. See man rand()  */
#if (DEF_INT_PERIOD_MILLISEC < MIN_INT_PERIOD_MILLISEC)
#error *** Invalid default interrupt period. ***
#endif
#if (DEF_INT_PERIOD_MILLISEC > MAX_INT_PERIOD_MILLISEC)
#error *** Invalid default interrupt period. ***
#endif
#define TRUE                      1  /* Boolean true value       */
#define FALSE                     0
#define MILLISEC_PER_SEC          (1000L) /* milliseconds per second  */
#define MICROSEC_PER_MILLISEC     (1000L) /* microsecs per millisec   */
#define MICROSEC_PER_SEC          (1000000L) /* microsecs per second  */
#define PRIORITY_POLICY           ((int) SCHED_RR) /* If specified iwth "-p" */
