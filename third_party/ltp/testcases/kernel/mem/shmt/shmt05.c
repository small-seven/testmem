#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/utsname.h>
#include <errno.h>
#include <time.h>
#include "test.h"
#define		 SIZE		 (2*SHMLBA)
