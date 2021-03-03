#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/utsname.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#define		SIZE	16*1024
#include "test.h"
