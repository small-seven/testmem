#include <pthread.h>		/* required by pthread functions                      */
#include <stdio.h>		/* required by fprintf()                              */
#include <stdlib.h>		/* required by exit(), atoi()                         */
#include <string.h>		/* required by strncpy()                              */
#include <unistd.h>		/* required by getopt(), mmap()                       */
#include <sys/types.h>		/* required by open(), shmat(), shmdt()               */
#include <sys/stat.h>		/* required by open()                                 */
#include <sys/ipc.h>		/* required by shmat() shmdt(), shmctl()              */
#include <sys/shm.h>		/* required by shmat() shmdt(), shmctl()              */
#include <sys/mman.h>		/* required by mmap()                                 */
#include <fcntl.h>		/* required by open()                                 */
#include <stdint.h>		/* required by uintptr_t                              */
#ifdef DEBUG
#define dprt	printf
#else
#define dprt	noprintf
#endif
#define PTHREAD_EXIT(val)    do {\
#define OPT_MISSING(prog, opt)   do{\
#define MAXT	30		/* default number of threads to create.               */
#define MAXR	1000		/* default number of repatetions to execute           */
