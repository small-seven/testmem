#define _GNU_SOURCE
#include <errno.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "test.h"
#define SHM_MODE	(SHM_R | SHM_W)	/* mode permissions of shared memory */
