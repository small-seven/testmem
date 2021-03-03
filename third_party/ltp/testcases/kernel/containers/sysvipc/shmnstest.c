#define _GNU_SOURCE 1
#include <sys/wait.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "ipcns_helper.h"
#include "test.h"
#define TESTKEY 0xEAEAEA
#define UNSHARESTR "unshare"
#define CLONESTR "clone"
#define NONESTR "none"
