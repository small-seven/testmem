#include <errno.h>
#include <fcntl.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>
#include "posixtest.h"
#define NAME_SIZE 20
#define SHM_NAME "/posixtest_23-1_%d"
#define SHM_RESULT_NAME "/result_23-1"
#define NPROCESS 1000		/* Number of concurrent processes */
#define NLOOP 1000		/* Number of shared memory object */
