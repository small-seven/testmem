#define _GNU_SOURCE 1
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include "pidns_helper.h"
#include "test.h"
#define CINIT_PID       1
#define PARENT_PID      0
#define FAKE_PID	-1
