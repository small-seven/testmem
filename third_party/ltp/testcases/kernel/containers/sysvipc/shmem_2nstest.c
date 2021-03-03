#define _GNU_SOURCE 1
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <libclone.h>
#include "test.h"
#include "safe_macros.h"
#include "ipcns_helper.h"
#define TESTKEY    124426L
#define UNSHARESTR "unshare"
#define CLONESTR   "clone"
#define NONESTR    "none"
