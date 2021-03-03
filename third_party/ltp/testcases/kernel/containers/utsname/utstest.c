#define _GNU_SOURCE 1
#include <sys/wait.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "libclone.h"
#include "test.h"
#include "safe_macros.h"
#define HLEN 100
#define NAME1 "serge1"
#define NAME2 "serge2"
#define UNSHARESTR "unshare"
#define CLONESTR "clone"
