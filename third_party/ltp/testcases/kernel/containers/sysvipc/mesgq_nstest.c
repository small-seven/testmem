#define _GNU_SOURCE 1
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <libclone.h>
#include "test.h"
#include "ipcns_helper.h"
#define KEY_VAL		154326L
#define UNSHARESTR	"unshare"
#define CLONESTR	"clone"
#define NONESTR		"none"
