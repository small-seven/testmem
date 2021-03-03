#define _GNU_SOURCE 1
#include <sys/wait.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "pidns_helper.h"
#include "test.h"
#include "safe_macros.h"
#define INIT_PID	1
#define CINIT_PID	1
#define PARENT_PID	0
#define MAX_DEPTH	5
