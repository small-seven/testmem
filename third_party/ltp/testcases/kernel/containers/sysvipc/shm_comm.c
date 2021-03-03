#define _GNU_SOURCE
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <errno.h>
#include "ipcns_helper.h"
#include "test.h"
#include "safe_macros.h"
#define TESTKEY 124426L
#define SHMSIZE 50
