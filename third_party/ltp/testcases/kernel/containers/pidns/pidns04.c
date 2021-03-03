#define _GNU_SOURCE 1
#include <sys/wait.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#define CLEANUP cleanup
#include "pidns_helper.h"
#include "test.h"
#define INIT_PID	1
#define CHILD_PID       1
#define PARENT_PID      0
