#define _GNU_SOURCE
#include <sys/wait.h>
#include <sys/mount.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include "pidns_helper.h"
#include "test.h"
#include "safe_macros.h"
#define PROCDIR "proc"
